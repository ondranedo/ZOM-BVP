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
		OpenGLSubShadersSources sources = readShaderFile();

		OpenGLSubShadersID shaders = attatchShaders(sources);

		bool succes = compileShaders(shaders);

		ZOM_GL_CALL(glLinkProgram(m_ID));
	    ZOM_GL_CALL(glValidateProgram(m_ID));		

		deleteShaders(shaders);
		
		return succes;
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

	OpenGLSubShadersSources OpenGLShader::readShaderFile() const
	{
		enum : short { NONE = 0, VERTEX, FRAGMENT } shader = NONE;

		OpenGLSubShadersSources sources;
		
		FILE* fr = fopen(m_Path.c_str(), "r");
		if (!fr)
		{
			ZOM_ERROR("Can't load shader file {}, loading default shader", m_Path);
			sources.m_FragmentSrc = default_fragment_shader;
			sources.m_VertexSrc = default_vertex_shader;
			return sources;
		}

		char linebuff[256] = { 0 };

		while (fgets(linebuff,256, fr))
		{
		
			if (strstr(linebuff, "#shader vertex")) { shader = VERTEX; continue; }
			if (strstr(linebuff, "#shader fragment")) { shader = FRAGMENT; continue; }
		
			if(shader == VERTEX)   sources.m_VertexSrc += linebuff;
			if(shader == FRAGMENT) sources.m_FragmentSrc += linebuff;
		}

		return sources;
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