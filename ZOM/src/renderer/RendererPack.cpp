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
		m_Context->swap();
	}

	void RendererPack::contextInitialize(Window* window)
	{
		m_Context->init(window->getContextCreationAdr());
	}

	RenderApplication* RendererPack::getRenderApplication()
	{
		return m_RenderApplication;
	}

	void RendererPack::beginScene()
	{
	}

	void RendererPack::endScene()
	{
	}

	void RendererPack::clear(const glm::vec4& color)
	{
		m_RenderApplication->clear(color);
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