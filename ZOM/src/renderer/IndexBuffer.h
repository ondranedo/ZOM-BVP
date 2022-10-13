#pragma once

namespace ZOM {
	class ZOM_API IndexBuffer {
	public:
		virtual ~IndexBuffer(){}
		
		virtual void bind() = 0;
		virtual void unbind() = 0;

		static std::shared_ptr<IndexBuffer> create(unsigned int* data, size_t count);

	protected:
		size_t m_Count;
		unsigned int m_ID = 0;
	};
};