#include "VertexArray.h"

#include "renderingAPI/opengl/OpenGLVertexArray.h"

namespace ZOM {
	std::shared_ptr<VertexArray> VertexArray::create()
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::shared_ptr<VertexArray>(new OpenGLVertexArray);
		default:
			ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}