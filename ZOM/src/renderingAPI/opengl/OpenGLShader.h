#pragma once

#include "renderer/Shader.h"

namespace ZOM {
	struct OpenGLSubShadersID {
		unsigned int m_VertexID;
		unsigned int m_FragmentID;
	};

	class OpenGLShader : public Shader {
		
	public:
		OpenGLShader();
		~OpenGLShader();

		void bind() const override;
		void unbind() const override;


		void compile() override;
	private:

		unsigned int createShader(GLenum id, const std::string& source);
		OpenGLSubShadersID attatchShaders(const std::string& vertex_source, const std::string& fragment_source);
		void compileShaders(const OpenGLSubShadersID& shader_ids);
		bool checkCompilation(unsigned int shader_id);
		void deleteShaders(const OpenGLSubShadersID& shader_ids);
	};
};