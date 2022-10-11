#pragma once

namespace ZOM {
	class ZOM_API IndexBuffer {
	public:
		virtual ~IndexBuffer(){}
		
		virtual void bind() = 0;
		virtual void unbind() = 0;

		static IndexBuffer* create(unsigned int* data, size_t size);

	protected:
		unsigned int m_ID = 0;
	};
};