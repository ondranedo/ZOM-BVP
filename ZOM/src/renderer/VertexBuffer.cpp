#include "VertexBuffer.h"

#include "renderingAPI/opengl/OpenGLVertexBuffer.h"

namespace ZOM
{
	std::shared_ptr<VertexBuffer> VertexBuffer::create(void* data, size_t size)
	{
		switch(Renderer::getAPI()) {
			case renderingAPI::opengl: return std::make_shared<OpenGLVertexBuffer>(data, size);
			default:
				ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}
