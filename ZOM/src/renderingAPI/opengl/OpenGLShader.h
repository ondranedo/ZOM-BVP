#pragma once

#include "renderer/Shader.h"

namespace ZOM {
	class OpenGLShader : public Shader {
		
	public:
		~OpenGLShader();

		void bind() const override;
		void unbind() const override;


		void compile() override;

	};
};