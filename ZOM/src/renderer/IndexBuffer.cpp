#include "IndexBuffer.h"

#include "renderingAPI/opengl/OpenGLIndexBuffer.h"

namespace ZOM {
	IndexBuffer* IndexBuffer::create(unsigned int* data, size_t size)
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return new OpenGLIndexBuffer(data, size);
		default:
			ZOM_ERROR("Unkown rendering API when creating index buffer");
		}

		return nullptr;
	}
}