#include "renderer/Rendrerer.h"

#include "renderingAPI/opengl/OpenGLRenderContext.h"


namespace ZOM {
	RenderContext* RenderContext::createContext(Window* window)
	{
		switch (Renderer::getRenderingAPI())
		{
		case RenderingAPI::OPENGL:
			return new OpengGLRenderContex(window->getContextCreationAdr());
			
		default:
				ZOM_ERROR("Unkown rendering api when creating render context");
			break;
		}
	}
}