#pragma once

namespace ZOM {
	class Shader {
	public:

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual bool compile() = 0;
		virtual void release() = 0;

		static std::shared_ptr<Shader> create(const std::string& path);

	protected:
		unsigned int m_ID;
	};
}