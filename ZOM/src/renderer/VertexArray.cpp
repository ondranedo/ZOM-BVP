#include "VertexArray.h"

#include "renderingAPI/opengl/OpenGLVertexArray.h"

namespace ZOM {
	ZOM::VertexArray* VertexArray::create()
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return new OpenGLVertexArray;
		default:
			ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}