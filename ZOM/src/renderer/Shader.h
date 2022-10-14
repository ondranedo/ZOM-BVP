#pragma once

namespace ZOM {
	class Shader {
	public:

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void compile() = 0;
		
		static std::shared_ptr<Shader> create();

	protected:
		unsigned int m_ID = 0;
	};
}