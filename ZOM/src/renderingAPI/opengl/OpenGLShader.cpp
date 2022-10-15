#include "OpenGLShader.h"

namespace ZOM {
	
	static const char* default_vertex_shader =
		"#version 330 core\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";


		static const char* default_fragment_shader =
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0f,1.0f,0.0f,1.0f);\n"
		"}\n";
		

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_ID);
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
		ZOM_GL_CALL(m_ID = glCreateProgram());
		
		unsigned int vertex_id = ZOM_GL_CALL(glCreateShader(GL_VERTEX_SHADER));
		const size_t vertex_size = sizeof(default_vertex_shader);
		unsigned int fragment_id = ZOM_GL_CALL(glCreateShader(GL_FRAGMENT_SHADER));
		const size_t fragment_size = sizeof(default_fragment_shader);

		ZOM_GL_CALL(glShaderSource(vertex_id, 1, &default_vertex_shader, (const GLint*) &vertex_size));
		ZOM_GL_CALL(glShaderSource(fragment_id, 1, &default_fragment_shader, (const GLint*) &fragment_size));

		ZOM_GL_CALL(glCompileShader(vertex_id));
		ZOM_GL_CALL(glCompileShader(fragment_id));

		int shader_error;
		ZOM_GL_CALL(glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &shader_error));
		if (shader_error != GL_TRUE)
		{
			int error_length;
			ZOM_GL_CALL(glGetShaderiv(vertex_id, GL_INFO_LOG_LENGTH, &error_length));
			char* buff = (char*)malloc(sizeof(char) * error_length);
			ZOM_GL_CALL(glGetShaderInfoLog(vertex_id, error_length * sizeof(char), &error_length, buff));

			ZOM_ERROR("Error when compiling vertex shader: {}", buff);

			free(buff);
		}

		ZOM_GL_CALL(glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &shader_error));
		if (shader_error != GL_TRUE)
		{
			int error_length;
			ZOM_GL_CALL(glGetShaderiv(fragment_id, GL_INFO_LOG_LENGTH, &error_length));
			char* buff = (char*)malloc(sizeof(char) * error_length);
			ZOM_GL_CALL(glGetShaderInfoLog(fragment_id, error_length * sizeof(char), &error_length, buff));

			ZOM_ERROR("Error when compiling fragment shader: {}", buff);
			
			free(buff);
		}

		ZOM_GL_CALL(glAttachShader(m_ID, vertex_id));
		ZOM_GL_CALL(glAttachShader(m_ID, fragment_id));

		ZOM_GL_CALL(glLinkProgram(m_ID));
		
		ZOM_GL_CALL(glValidateProgram(m_ID));
		
		ZOM_GL_CALL(glDeleteShader(vertex_id));
		ZOM_GL_CALL(glDeleteShader(fragment_id));
		
	}

}