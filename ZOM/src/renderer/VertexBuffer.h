#pragma once

#include "VertexBufferLayout.h"

namespace ZOM {
	class ZOM_API VertexBuffer {
	public:
		virtual ~VertexBuffer(){}
		
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		
		virtual void setLayout(const VertexBufferLayout& vbl) = 0;
		virtual const VertexBufferLayout& getLayout() const = 0;

		static std::shared_ptr<VertexBuffer> create(void* data, size_t size);

	protected:
		unsigned int m_ID = 0;
		VertexBufferLayout m_VBL;
	};
};