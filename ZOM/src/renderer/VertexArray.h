#pragma once 

#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace ZOM {
	class VertexArray {
	public:
		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setIndex(std::shared_ptr<IndexBuffer>& ib) = 0;
		virtual const std::shared_ptr<IndexBuffer>& getIndex() const = 0;
		virtual void setVertex(std::shared_ptr<VertexBuffer>& vb) = 0;
		virtual const std::shared_ptr<VertexBuffer>& getVertex() const = 0;

		static VertexArray* create();

	protected:	
		unsigned int m_ID;
		std::shared_ptr<VertexBuffer> m_VB;
		std::shared_ptr<IndexBuffer>  m_IB;
	};
}