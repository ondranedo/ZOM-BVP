#include "VertexBuffer.h"

#include "renderingAPI/opengl/OpenGLVertexBuffer.h"

namespace ZOM {
	
	void VertexBuffer::setLayout(const VertexBufferLayout& vbl)
	{
		m_VBL = vbl;
	}

	const VertexBufferLayout& VertexBuffer::getLayout()
	{
		return m_VBL;
	}

	VertexBuffer* VertexBuffer::create(void* data, size_t size)
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return new OpenGLVertexBuffer(data, size);
		default:
			ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}