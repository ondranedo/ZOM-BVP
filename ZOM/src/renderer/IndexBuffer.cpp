#include "IndexBuffer.h"

#include "renderingAPI/opengl/OpenGLIndexBuffer.h"

namespace ZOM {
	std::shared_ptr<IndexBuffer> IndexBuffer::create(unsigned int* data, size_t size)
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::shared_ptr<IndexBuffer>(new OpenGLIndexBuffer(data, size));
		default:
			ZOM_ERROR("Unkown rendering API when creating index buffer");
		}

		return nullptr;
	}
}