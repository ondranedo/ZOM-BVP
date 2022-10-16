#include "OpenGLShader.h"

namespace ZOM {
	
	static const char* default_vertex_shader =
		"#version 330 core\n"
		"layout(location = 0) in vec4 position;\n"
		"out vec4 vertexColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"	vertexColor = vec4(cos(position.y)*sin(position.x),cos(position.x)*sin(position.y),tan(position.y)*sin(position.x),0);\n"
		"}\n";


		static const char* default_fragment_shader =
		"#version 330 core\n"
		"out vec4 color;\n"
		"in vec4 vertexColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vertexColor;\n"
		"}\n";
		

	OpenGLShader::OpenGLShader()
	{
		ZOM_GL_CALL(m_ID = glCreateProgram());
		ZOM_ASSERT(m_ID, "failed to create shader program");
	}

	OpenGLShader::~OpenGLShader()
	{
		ZOM_GL_CALL(glDeleteProgram(m_ID));
	}

	void OpenGLShader::bind() const
	{
		ZOM_GL_CALL(glUseProgram(m_ID));
	}

	void OpenGLShader::unbind() const
	{
		ZOM_GL_CALL(glUseProgram(0));
	}

	void OpenGLShader::compile()
	{		
		OpenGLSubShadersID shaders = attatchShaders(default_vertex_shader, default_fragment_shader);

		compileShaders(shaders);

		ZOM_GL_CALL(glLinkProgram(m_ID));
	    ZOM_GL_CALL(glValidateProgram(m_ID));		

		deleteShaders(shaders);
	}

	void OpenGLShader::compileShaders(const OpenGLSubShadersID& shader_ids)
	{
		ZOM_GL_CALL(glCompileShader(shader_ids.m_FragmentID));
		ZOM_GL_CALL(glCompileShader(shader_ids.m_VertexID));

		checkCompilation(shader_ids.m_FragmentID);
		checkCompilation(shader_ids.m_VertexID);
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
		ZOM_GL_CALL(glDeleteShader(shader_ids.m_VertexID));
		ZOM_GL_CALL(glDeleteShader(shader_ids.m_FragmentID));
	}

	OpenGLSubShadersID OpenGLShader::attatchShaders(const std::string& vertex_source, const std::string& fragment_source)
	{
		unsigned int vertex_id = createShader(GL_VERTEX_SHADER, vertex_source);
		unsigned int fragment_id = createShader(GL_FRAGMENT_SHADER, fragment_source);

		ZOM_GL_CALL(glAttachShader(m_ID, vertex_id));
		ZOM_GL_CALL(glAttachShader(m_ID, fragment_id));

		return { vertex_id, fragment_id };
	}
}