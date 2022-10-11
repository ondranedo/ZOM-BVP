#include "VertexBuffer.h"

#include "renderingAPI/opengl/OpenGLVertexBuffer.h"

namespace ZOM {
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