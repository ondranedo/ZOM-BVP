#pragma once

#include "buffers/IndexBuffer.h"
#include "buffers/VertexBuffer.h"

namespace ZOM
{
	class VertexArray {
	public:
		virtual ~VertexArray() {}
		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setIndex(std::shared_ptr<IndexBuffer>& ib) = 0;
		virtual void setVertex(std::shared_ptr<VertexBuffer>& vb) = 0;

		static std::shared_ptr<VertexArray> create();
		virtual size_t getIndexCount() const = 0;

	protected:
		unsigned int m_ID;
		std::shared_ptr<VertexBuffer> m_VB;
		std::shared_ptr<IndexBuffer> m_IB;
	};
}
