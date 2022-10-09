#include "RendererPack.h"

#include "renderingAPI/opengl/OpenGLRenderApplication.h"
#include "renderingAPI/opengl/OpenGLRenderContext.h"

namespace ZOM {

	RendererPack::RendererPack(RenderingAPI api) : m_RenderAPI(api)
	{
		ZOM_TRACE("Renderer created");

		switch (api)
		{
		case ZOM::RenderingAPI::OPENGL:
			m_RenderApplication = new OpenGLRenderApplication;
			m_Context = new OpenGLRenderContex;
			break;
		default:
			ZOM_ERROR("Unknown rendering api");
		}
	}

	RendererPack::~RendererPack()
	{
		delete m_RenderApplication;
		delete m_Context;

		ZOM_TRACE("Renderer destroyed");
	}

	void RendererPack::renderLoop()
	{
		//m_RenderApplication->clear();

		//m_Context->swap();
	}

	void RendererPack::contextInitialize(Window* window)
	{
		m_Context->init(window->getContextCreationAdr());
	}

	void RendererPack::begin()
	{
		m_RenderApplication->clear();
	}

	void RendererPack::end()
	{
		m_Context->swap();
	}

	RenderContext* RendererPack::getContext()
	{
		return m_Context;
	}

	RenderingAPI RendererPack::getRenderingAPI()
	{
		return m_RenderAPI;
	}
}