#include "OpenGLShader.h"

namespace ZOM
{
	static const char* default_vertex_shader =
		"#version 330 core\n"
		"layout(location = 0) in vec4 position;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";

	static const char* default_fragment_shader =
		"#version 330 core\n"
		"out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0f,5.0f,1.0f,1.0f);\n"
		"}\n";

	OpenGLShader::OpenGLShader(const std::string& path)
		: m_Path(path)
	{
		ZOM_GL_CALL(m_ID = glCreateProgram());
		ZOM_ASSERT(m_ID, "failed to create shader program");
		m_Created = true;
	}

	OpenGLShader::OpenGLShader()
		: m_Path("default")
	{
		ZOM_GL_CALL(m_ID = glCreateProgram());
		ZOM_ASSERT(m_ID, "failed to create default shader program");
		m_Created = true;
	}

	OpenGLShader::~OpenGLShader()
	{
		if(m_Created) {
			ZOM_ERROR("Shader {} shloud be deleted, can't delete shader now", m_Path);
		}
	}

	void OpenGLShader::bind() const
	{
		ZOM_GL_CALL(glUseProgram(m_ID));
	}

	void OpenGLShader::unbind() const
	{
		ZOM_GL_CALL(glUseProgram(0));
	}

	void OpenGLShader::release()
	{
		unsigned int shader[8];
		GLsizei count;

		ZOM_GL_CALL(glGetAttachedShaders(m_ID, 8, &count, shader));
		ZOM_GL_CALL(glDeleteProgram(m_ID));

		m_Created = false;
	}

	bool OpenGLShader::compile()
	{
		const openGLSubShaderSources sources = readShaderFile();
		openGLSubShaderID shader             = attachShader(sources);

		const bool success = compileShader(shader);

		ZOM_GL_CALL(glLinkProgram(m_ID));
		ZOM_GL_CALL(glValidateProgram(m_ID));

		deleteShader(shader);

		return success;
	}

	VertexBufferLayout OpenGLShader::getLayout()
	{
		return m_Layout;
	}

	void OpenGLShader::setUniform(const std::string& name, void* data)
	{
		if(isUniformStored(name)) {
			auto [dt, id] = m_UniformMap[name];
			sendToUniform(id, dt, data);
			m_UniformSets[name] = true;
		}
		else {
			ZOM_ERROR("Unknown uniform[{}] in shader {}", name, m_Path);
		}
	}

	bool OpenGLShader::compileShader(const openGLSubShaderID& shader_ids)
	{
		auto success = true;
		ZOM_GL_CALL(glCompileShader(shader_ids.m_FragmentID));
		ZOM_GL_CALL(glCompileShader(shader_ids.m_VertexID));

		success &= checkCompilation(shader_ids.m_FragmentID);
		success &= checkCompilation(shader_ids.m_VertexID);

		return success;
	}

	unsigned int OpenGLShader::createShader(const GLenum id, const std::string& source)
	{
		const unsigned int shader_id = ZOM_GL_CALL(glCreateShader(id));
		const char* c_source         = source.c_str();
		ZOM_GL_CALL(glShaderSource(shader_id, 1, &c_source, NULL));
		return shader_id;
	}

	bool OpenGLShader::checkCompilation(const unsigned int shader_id)
	{
		int shader_error;
		ZOM_GL_CALL(glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shader_error));

		if(shader_error != GL_TRUE) {
			int error_length;

			ZOM_GL_CALL(glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &error_length));

			auto buff = static_cast<char*>(malloc(sizeof(char) * error_length));

			ZOM_GL_CALL(glGetShaderInfoLog(shader_id, error_length * sizeof(char), &error_length, buff));

			ZOM_ERROR("Error with {} shader: {}", m_Path, buff);

			free(buff);

			return false;
		}

		return true;
	}

	void OpenGLShader::deleteShader(const openGLSubShaderID& shader_ids)
	{
		ZOM_GL_CALL(glDetachShader(m_ID, shader_ids.m_VertexID));
		ZOM_GL_CALL(glDetachShader(m_ID, shader_ids.m_FragmentID));

		ZOM_GL_CALL(glDeleteShader(shader_ids.m_VertexID));
		ZOM_GL_CALL(glDeleteShader(shader_ids.m_FragmentID));
	}

	openGLSubShaderSources OpenGLShader::readShaderFile()
	{
		enum : short { none = 0, vertex, fragment } shader = none;

		openGLSubShaderSources sources;

		FILE* fr;
		int err = fopen_s(&fr, m_Path.c_str(), "r");
		if(!fr) {
			if(m_Path != "default")
				ZOM_ERROR("Can't load shader file {}, loading default shader", m_Path);
			sources.m_FragmentSrc = default_fragment_shader;
			sources.m_VertexSrc   = default_vertex_shader;
			return sources;
		}

		constexpr size_t buff_size = 256;
		char buffer[buff_size]     = {0};

		while(fgets(buffer, buff_size, fr)) {

			if(strstr(buffer, "#shader vertex")) {
				shader = vertex;
				continue;
			}
			if(strstr(buffer, "#shader fragment")) {
				shader = fragment;
				continue;
			}
			if(strstr(buffer, "location")) { readAndAddVbl(buffer, buff_size); }    // reading VBL
			if(strstr(buffer, "uniform")) { readAndAddUniform(buffer, buff_size); } // reading Uniform

			if(shader == vertex) sources.m_VertexSrc += buffer;
			if(shader == fragment) sources.m_FragmentSrc += buffer;
		}

		createBufferLayout();

		return sources;
	}

	void OpenGLShader::readAndAddVbl(char* buff, const size_t size)
	{
		int location               = readLayoutLocation(buff, size);
		InShaderDataType data_type = readLayoutType(buff, size);
		std::string name           = readLayoutName(buff, size);

		m_LayoutVector.push_back({location, data_type, name});
	}

	int OpenGLShader::readLayoutLocation(const char* buff, const size_t size) const
	{
		std::string str(buff, size);
		const std::size_t pos = str.find('=');
		const std::size_t end = str.find(')');
		std::string number    = str.substr(pos + 1, end - pos - 1);
		number.erase(std::remove_if(number.begin(), number.end(), isspace), number.end());
		return static_cast<int>(*number.c_str()) - '0';
	}

	InShaderDataType OpenGLShader::readLayoutType(const char* buff, const size_t size)
	{
		std::string spec;
		{
			const std::string str(buff, size);
			spec = str.substr(
				str.find("in") + 2, str.find(';') - str.find("in") - 2);
		}

		removeSpacesBefore(spec);

		const std::string data_type = spec.substr(0, spec.find(' '));

		return strToZomInShaderDataType(data_type);
	}

	void OpenGLShader::removeSpacesBefore(std::string& str)
	{
		for(size_t i = 0 ; i < str.size() ; i++) {
			if(str[i] != ' ') {
				str.erase(0, i);
				break;
			}
		}
	}

	void OpenGLShader::createBufferLayout()
	{
		for(size_t i = 0 ; i < m_LayoutVector.size() ; i++) {
			for(auto [location,dt,name] : m_LayoutVector) if(location == i) m_Layout.add(dt, name);
		}
	}

	std::string OpenGLShader::readLayoutName(const char* buff, const size_t size)
	{
		std::string spec;
		{
			const std::string str(buff, size);
			spec = str.substr(
				str.find("in") + 2, str.find(';') - str.find("in") - 2);
		}

		removeSpacesBefore(spec);

		const std::string data_type = spec.substr(0, spec.find(' '));

		spec.erase(0, data_type.size());

		removeSpacesBefore(spec);

		std::string name;
		{
			size_t name_size = 0;
			while(name_size < spec.size()) {
				if(spec[name_size] == ' ') break;
				name_size++;
			}
			name = spec.substr(0, name_size);
		}

		return name;
	}

	void OpenGLShader::readAndAddUniform(const char* line_buffer, const size_t buffer_size)
	{
		std::string name      = readUniformName(line_buffer, buffer_size);
		InShaderDataType type = readUniformType(line_buffer, buffer_size);

		m_UniformVector.push_back({type, name});
		m_UniformSets[name] = false;
	}

	std::string OpenGLShader::readUniformName(const char* line_buffer, const size_t buffer_size)
	{
		std::string name;
		{
			std::string str(line_buffer, buffer_size);
			name = str.erase(str.find("uniform"), str.find("uniform") + 8);
		}
		removeSpacesBefore(name);
		name = name.erase(0, name.find(' '));
		removeSpacesBefore(name);

		if(name.find(' ') > name.find(';')) name = name.substr(0, name.find(';'));
		else name                                = name.substr(0, name.find(' '));

		return name;
	}

	InShaderDataType OpenGLShader::readUniformType(const char* line_buffer, const size_t buffer_size)
	{
		std::string type;
		{
			std::string str(line_buffer, buffer_size);
			type = str.erase(str.find("uniform"), str.find("uniform") + 8);
		}
		removeSpacesBefore(type);
		type = type.substr(0, type.find(' '));

		return strToZomInShaderDataType(type);
	}

	void OpenGLShader::mapUniforms()
	{
		for(auto [dataType, name] : m_UniformVector) {
			if(!isUniformStored(name)) {
				std::string uniform = name + '\0';
				int id              = ZOM_GL_CALL(glGetUniformLocation(m_ID, uniform.c_str()));
				if(id < 0)
					ZOM_ERROR("Uniform[{}] in shader[{}] is probably not being used", name, m_Path);
				m_UniformMap[name] = {dataType, id};
			}
		}
	}

	bool OpenGLShader::isUniformStored(const std::string& name)
	{
		if(m_UniformMap.find(name) != m_UniformMap.end()) return true;

		return false;
	}

	void OpenGLShader::sendToUniform(const unsigned int id, const InShaderDataType dt, void* data)
	{
		switch(dt) {
			case InShaderDataType::Null: break;
			case InShaderDataType::VecF1: glUniform1fv(static_cast<GLint>(id), 1, static_cast<GLfloat*>(data));
				break;

			case InShaderDataType::VecF2: glUniform2fv(static_cast<GLint>(id), 1,
			                                           &(*static_cast<glm::fvec2*>(data))[0]);
				break;
			case InShaderDataType::VecF3: glUniform3fv(static_cast<GLint>(id), 1,
			                                           &(*static_cast<glm::fvec2*>(data))[0]);
				break;
			case InShaderDataType::VecF4: glUniform4fv(static_cast<GLint>(id), 1,
			                                           &(*static_cast<glm::fvec2*>(data))[0]);
				break;

			case InShaderDataType::VecI1: glUniform1iv(static_cast<GLint>(id), 1, static_cast<GLint*>(data));
				break;

			case InShaderDataType::VecI2: glUniform2iv(static_cast<GLint>(id), 1,
			                                           &(*static_cast<glm::ivec2*>(data))[0]);
				break;
			case InShaderDataType::VecI3: glUniform3iv(static_cast<GLint>(id), 1,
			                                           &(*static_cast<glm::ivec2*>(data))[0]);
				break;
			case InShaderDataType::VecI4: glUniform4iv(static_cast<GLint>(id), 1,
			                                           &(*static_cast<glm::ivec2*>(data))[0]);
				break;

			case InShaderDataType::Mat2: glUniformMatrix2fv(static_cast<GLint>(id), 1, GL_FALSE,
			                                                static_cast<GLfloat*>(data));
				break;
			case InShaderDataType::Mat3: glUniformMatrix3fv(static_cast<GLint>(id), 1, GL_FALSE,
			                                                static_cast<GLfloat*>(data));
				break;
			case InShaderDataType::Mat4: glUniformMatrix4fv(static_cast<GLint>(id), 1, GL_FALSE,
			                                                static_cast<GLfloat*>(data));
				break;

			case InShaderDataType::Bool: glUniform1iv(static_cast<GLint>(id), 1, static_cast<GLint*>(data));
				break;
			default:
				ZOM_ERROR("Unsuported InShaderDataType in sendToUniform function");
		}
	}

	openGLSubShaderID OpenGLShader::attachShader(const openGLSubShaderSources& sources)
	{
		const unsigned int vertex_id   = createShader(GL_VERTEX_SHADER, sources.m_VertexSrc);
		const unsigned int fragment_id = createShader(GL_FRAGMENT_SHADER, sources.m_FragmentSrc);

		ZOM_GL_CALL(glAttachShader(m_ID, vertex_id));
		ZOM_GL_CALL(glAttachShader(m_ID, fragment_id));

		return {vertex_id, fragment_id};
	}

	void OpenGLShader::checkIfUniformAreSet() const
	{
		for(const auto& [name, isSet] : m_UniformSets) {
			if(!isSet)
				ZOM_ERROR("Uniform[{}] in shader[{}] is unset", name, m_Path);
		}
	}
}
