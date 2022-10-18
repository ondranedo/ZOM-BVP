#pragma once

#include "renderer/Shader.h"

namespace ZOM {
	struct OpenGLSubShadersID {
		unsigned int m_VertexID;
		unsigned int m_FragmentID;
	};

	struct OpenGLSubShadersSources {
		std::string m_VertexSrc;
		std::string m_FragmentSrc;
	};

	class OpenGLShader : public Shader {
		
	public:
		OpenGLShader(const std::string& path);
		~OpenGLShader();

		void bind() const override;
		void unbind() const override;

		void release() override;

		bool compile() override;
	private:

		unsigned int createShader(GLenum id, const std::string& source);
		OpenGLSubShadersID attatchShaders(const OpenGLSubShadersSources& vertex_source);
		bool compileShaders(const OpenGLSubShadersID& shader_ids);
		bool checkCompilation(unsigned int shader_id);
		void deleteShaders(const OpenGLSubShadersID& shader_ids);
		OpenGLSubShadersSources readShaderFile() const;

	private:
		std::string m_Path;
		bool m_Created = false;
		void deleteShader();
	};
};