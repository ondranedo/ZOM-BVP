#include "IndexBuffer.h"

#include "renderingAPI/opengl/buffers/OpenGLIndexBuffer.h"

namespace ZOM
{
	std::shared_ptr<IndexBuffer> IndexBuffer::create(unsigned int* data,const size_t count)
	{
		switch(Renderer::getAPI()) {
			case renderingAPI::opengl: return std::make_shared<OpenGLIndexBuffer>(data, count);
			default:
				ZOM_ERROR("Unkown rendering API when creating index buffer");
		}

		return nullptr;
	}
}
