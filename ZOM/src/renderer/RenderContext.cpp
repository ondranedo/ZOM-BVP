#include "renderer/Rendrerer.h"

#include "renderingAPI/opengl/OpenGLRenderContext.h"


namespace ZOM {
	RenderContext* RenderContext::createContext()
	{
		switch (Renderer::getRenderingAPI())
		{
		case RenderingAPI::OPENGL:
			return new OpengGLRenderContex;
			break;

		default:
				ZOM_WARNING("Unkown rendering api when creating render context");
			break;
		}
	}
}