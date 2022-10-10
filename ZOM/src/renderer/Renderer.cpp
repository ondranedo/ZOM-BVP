#include "Renderer.h"

#include "renderingAPI/opengl/OpenGLRenderApplication.h"
#include "renderingAPI/opengl/OpenGLRenderContext.h"


namespace ZOM {
	void Renderer::init()
	{
		ZOM_TRACE("Renderer initialization started");

		switch (s_RendreringApi)
		{
		case RenderingAPI::OPENGL:
			s_RenderContext = new OpenGLRenderContex;
			s_RenderApplication = new OpenGLRenderApplication;
			s_Created = true;
		break;

		default:
			ZOM_CRITICAL("Unkown rendering api when creating renderer");
		}

		ZOM_TRACE("Renderer initialization ended");
	}

	void Renderer::release()
	{
		if (s_Created)
		{
			ZOM_TRACE("Renderer release started");
			delete s_RenderApplication;
			delete s_RenderContext;
			ZOM_TRACE("Renderer release ended");
			s_Created = false;
		}
		else
		{
			ZOM_TRACE("Can't release renderer, you have to initialize it first");
		}
	}

	RenderApplication* Renderer::getRenderApplication()
	{
		if (s_Created)
			return s_RenderApplication;
		else
			ZOM_ERROR("Have to initialize renderer, in order to get renderer application");
		return nullptr;
	}

	void Renderer::setBeforeInitRenderingApi(RenderingAPI api)
	{
		if (!s_Created)
			s_RendreringApi = api;
		else
			ZOM_ERROR("Renderer already created");
	}

	void Renderer::contextInitialize(Window* window)
	{
		if (s_Created)
			s_RenderContext->init(window->getContextCreationAdr());
		else
			ZOM_ERROR("Can't intialize context, you have to initialize renderer first");
	}

	void Renderer::renderLoop()
	{
		if (s_Created)
		{
			// s_RenderApplication->clear();

			s_RenderContext->swap();
		}
		else
			ZOM_ERROR("Can't start render loop, initialize context");
	}

	void Renderer::beginScene()
	{

	}

	void Renderer::endScene()
	{

	}

	bool Renderer::s_Created = false;
	ZOM::RenderingAPI Renderer::s_RendreringApi = RenderingAPI::OPENGL;
	RenderContext* Renderer::s_RenderContext = nullptr;
	RenderApplication* Renderer::s_RenderApplication = nullptr;
}