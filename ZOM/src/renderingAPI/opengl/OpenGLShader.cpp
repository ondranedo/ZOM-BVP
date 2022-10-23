#include "OpenGLShader.h"

namespace ZOM {
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

	OpenGLShader::OpenGLShader(const std::string& path) : m_Path(path)
	{
		ZOM_GL_CALL(m_ID = glCreateProgram());
		ZOM_ASSERT(m_ID, "failed to create shader program");
		m_Created = true;
	}

	OpenGLShader::OpenGLShader() : m_Path("none@none")
	{
		ZOM_GL_CALL(m_ID = glCreateProgram());
		ZOM_ASSERT(m_ID, "failed to create default shader program");
		m_Created = true;
	}

	OpenGLShader::~OpenGLShader()
	{
		if (m_Created)
		{
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
		unsigned int shaders[8];
		GLsizei count;

		ZOM_GL_CALL(glGetAttachedShaders(m_ID, 8, &count, shaders));
		ZOM_GL_CALL(glDeleteProgram(m_ID));

		m_Created = false;
	}

	bool OpenGLShader::compile()
	{	
		OpenGLSubShadersSources sources;

		if (m_Path == "none@none")
			sources = { default_vertex_shader, default_fragment_shader };
		else
			sources = readShaderFile();

		OpenGLSubShadersID shaders = attatchShaders(sources);

		bool succes = compileShaders(shaders);

		ZOM_GL_CALL(glLinkProgram(m_ID));
	    ZOM_GL_CALL(glValidateProgram(m_ID));		

		deleteShaders(shaders);
		
		mapUniforms();

		return succes;
	}

	VertexBufferLayout OpenGLShader::getLayout()
	{
		return m_Layout;
	}

	void OpenGLShader::setUniform(const std::string& name, void* data)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool OpenGLShader::compileShaders(const OpenGLSubShadersID& shader_ids)
	{
		bool succes = true;
		ZOM_GL_CALL(glCompileShader(shader_ids.m_FragmentID));
		ZOM_GL_CALL(glCompileShader(shader_ids.m_VertexID));

		succes &= checkCompilation(shader_ids.m_FragmentID);
		succes &= checkCompilation(shader_ids.m_VertexID);



		return succes;
	}

	unsigned int OpenGLShader::createShader(GLenum id, const std::string& source)
	{
		unsigned int shader_id = ZOM_GL_CALL(glCreateShader(id));
		const char* c_source = source.c_str();
		ZOM_GL_CALL(glShaderSource(shader_id, 1, &c_source, NULL));
		return shader_id;

	}

	bool OpenGLShader::checkCompilation(unsigned int shader_id)
	{
		int shader_error;
		ZOM_GL_CALL(glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shader_error));

		if (shader_error != GL_TRUE)
		{
			int error_length;

			ZOM_GL_CALL(glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &error_length));

			char* buff = (char*)malloc(sizeof(char) * error_length);

			ZOM_GL_CALL(glGetShaderInfoLog(shader_id, error_length * sizeof(char), &error_length, buff));

			ZOM_ERROR("Error when shader: {}", buff);
			
			free(buff);

			return false;
		}

		return true;
	}

	void OpenGLShader::deleteShaders(const OpenGLSubShadersID& shader_ids)
	{
		ZOM_GL_CALL(glDetachShader(m_ID, shader_ids.m_VertexID));
		ZOM_GL_CALL(glDetachShader(m_ID, shader_ids.m_FragmentID));

		ZOM_GL_CALL(glDeleteShader(shader_ids.m_VertexID));
		ZOM_GL_CALL(glDeleteShader(shader_ids.m_FragmentID));
	}

	OpenGLSubShadersSources OpenGLShader::readShaderFile()
	{
		enum : short { NONE = 0, VERTEX, FRAGMENT } shader = NONE;

		OpenGLSubShadersSources sources;
		
		FILE* fr;
		fopen_s(&fr, m_Path.c_str(), "r");
		if (!fr)
		{
			ZOM_ERROR("Can't load shader file {}, loading default shader", m_Path);
			sources.m_FragmentSrc = default_fragment_shader;
			sources.m_VertexSrc = default_vertex_shader;
			return sources;
		}

		const size_t buffSize = 256;
		char linebuff[buffSize] = { 0 };

		while (fgets(linebuff, buffSize, fr))
		{
		
			if (strstr(linebuff, "#shader vertex")) { shader = VERTEX; continue; }
			if (strstr(linebuff, "#shader fragment")) { shader = FRAGMENT; continue; }
			if (strstr(linebuff, "location")) { readAndAddVBL(linebuff, buffSize); } // reading VBL
			if (strstr(linebuff, "uniform")) { readAndAddUnifrom(linebuff, buffSize); } // reading Uniform
		
			if(shader == VERTEX)   sources.m_VertexSrc += linebuff;
			if(shader == FRAGMENT) sources.m_FragmentSrc += linebuff;
		}

		createBufferLayout();

		return sources;
	}

	void OpenGLShader::readAndAddVBL(char* buff, size_t size)
	{
		int location = readLayoutLocation(buff, size);
		InShaderDataType dataType = readLayoutType(buff, size);
		std::string name = readLayoutName(buff, size);

		m_LayoutVector.push_back({ location,dataType, name});
	}

	int OpenGLShader::readLayoutLocation(char* buff, size_t size)
	{
		std::string str(buff, size);
		std::size_t pos = str.find("=");
		std::size_t end = str.find(")");
		std::string number = str.substr(pos + 1, end - pos - 1);
		number.erase(std::remove_if(number.begin(), number.end(), ::isspace), number.end());
		return (int)*number.c_str()-'0';
	}

	InShaderDataType OpenGLShader::readLayoutType(char* buff, size_t size)
	{
		std::string spec;
		{
			std::string str(buff, size);
			spec = str.substr(
				str.find("in") + 2, str.find(";") - str.find("in") - 2);
		}
		
		removeSpacesBefore(spec);

		std::string dataType = spec.substr(0, spec.find(' '));

		return strToZOMInShaderDataType(dataType);
	}

	void OpenGLShader::removeSpacesBefore(std::string& spec)
	{
		for (size_t i = 0; i < spec.size(); i++)
		{
			if (spec[i] != ' ')
			{
				spec.erase(0, i);
				break;
			}
		}
	}

	void OpenGLShader::createBufferLayout()
	{
		for (size_t i = 0; i < m_LayoutVector.size(); i++)
		{
			for (auto[location,dt,name] : m_LayoutVector)
				if (location == i) m_Layout.add(dt, name);
		}
	}

	std::string OpenGLShader::readLayoutName(char* buff, size_t size)
	{
		std::string spec;
		{
			std::string str(buff, size);
			spec = str.substr(
				str.find("in") + 2, str.find(";") - str.find("in") - 2);
		}

		removeSpacesBefore(spec);

		std::string dataType = spec.substr(0, spec.find(' '));

		spec.erase(0, dataType.size());
	
		removeSpacesBefore(spec);

		std::string name;
		{
			size_t name_size = 0;
			while (name_size < spec.size())
			{
				if (spec[name_size] == ' ') break;
				else name_size++;
			}
			name = spec.substr(0, name_size); 
		}

		return name;
	}

	void OpenGLShader::readAndAddUnifrom(char* linebuff, size_t buffSize)
	{
		std::string name = readUniformName(linebuff, buffSize);
		InShaderDataType type = readUniformType(linebuff, buffSize);

		m_UnifromVector.push_back({ type, name });
	}

	std::string OpenGLShader::readUniformName(char* linebuff, size_t buffSize)
	{
		std::string name;
		{
			std::string str(linebuff, buffSize);
			name = str.erase(str.find("uniform"), str.find("uniform") + 8);
		}
		removeSpacesBefore(name);
		name = name.erase(0, name.find(' '));
		removeSpacesBefore(name);

		if(name.find(' ') > name.find(';'))
			name = name.substr(0, name.find(';'));
		else
			name = name.substr(0, name.find(' '));

		return name;
	}

	ZOM::InShaderDataType OpenGLShader::readUniformType(char* linebuff, size_t buffSize)
	{
		std::string type;
		{
			std::string str(linebuff, buffSize);
			type = str.erase(str.find("uniform"), str.find("uniform") + 8);
		}
		removeSpacesBefore(type);
		type = type.substr(0, type.find(' ')); \

		return strToZOMInShaderDataType(type);
	}

	void OpenGLShader::mapUniforms()
	{
		for (auto[dataType, name]: m_UnifromVector)
		{
			if (!isUniformStored(name))
			{
				unsigned int id = ZOM_GL_CALL(glGetUniformLocation(m_ID, name.c_str()));
				if (!id)
					ZOM_ERROR("Can't find uniform[{}] location", name);
				m_UnifromMap[name] = { dataType,id };
			}
		}
	}

	bool OpenGLShader::isUniformStored(const std::string& name)
	{
		if (m_UnifromMap.find(name) != m_UnifromMap.end())
			return true;

		return false;
	}

	OpenGLSubShadersID OpenGLShader::attatchShaders(const OpenGLSubShadersSources& sources)
	{
		unsigned int vertex_id = createShader(GL_VERTEX_SHADER, sources.m_VertexSrc);
		unsigned int fragment_id = createShader(GL_FRAGMENT_SHADER, sources.m_FragmentSrc);
	
		ZOM_GL_CALL(glAttachShader(m_ID, vertex_id));
		ZOM_GL_CALL(glAttachShader(m_ID, fragment_id));

		return { vertex_id, fragment_id };
	}
}