#include "VertexArray.h"

#include "renderingAPI/opengl/OpenGLVertexArray.h"

namespace ZOM
{
	std::shared_ptr<VertexArray> VertexArray::create()
	{
		switch(Renderer::getAPI()) {
			case renderingAPI::opengl: return std::make_shared<OpenGLVertexArray>();
			default:
				ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}
