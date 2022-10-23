#pragma once

#include "VertexBufferLayout.h"

namespace ZOM {
	class Shader {
	public:

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual bool compile() = 0;
		virtual void release() = 0;

		virtual void setUniform(const std::string& name, void* data) = 0;
		virtual VertexBufferLayout getLayout() = 0;

		static std::shared_ptr<Shader> create(const std::string& path);
		static std::shared_ptr<Shader> createDefault();

	protected:
		VertexBufferLayout m_VBL;
		std::vector<std::pair<std::string, InShaderDataType>> m_Uniforms;
		unsigned int m_ID;
	};
}