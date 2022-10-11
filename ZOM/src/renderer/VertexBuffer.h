#pragma once

#include "VertexBufferLayout.h"

namespace ZOM {
	class ZOM_API VertexBuffer {
	public:
		virtual ~VertexBuffer(){}
		
		virtual void bind() = 0;
		virtual void unbind() = 0;

		void setLayout(const VertexBufferLayout& vbl);
		const VertexBufferLayout& getLayout();

		static VertexBuffer* create(void* data, size_t size);

	protected:
		unsigned int m_ID = 0;
		VertexBufferLayout m_VBL;
	};
};