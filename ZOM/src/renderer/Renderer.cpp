#include "Renderer.h"

#include "renderingAPI/opengl/OpenGLRenderApplication.h"
#include "renderingAPI/opengl/OpenGLRenderContext.h"

#include "window/MainWindow.h"

#include "Shader.h"

namespace ZOM {
	void Renderer::init()
	{
		ZOM_FUNCTION_TIMER();
		ZOM_TRACE("Renderer initialization started");

		setBeforeInitRenderingApi(Config::renderingAPI());

		switch (s_RendreringApi)
		{
		case RenderingAPI::OPENGL:
			s_RenderContext = std::make_unique<OpenGLRenderContex>();
			s_RenderApplication = std::make_unique<OpenGLRenderApplication>();
			s_Created = true;
		break;

		default:
			ZOM_CRITICAL("Unkown rendering api when creating renderer");
		}

		s_ShaderMgr.setShaderPaths(Config::shaderPaths());

		ZOM_TRACE("Renderer initialization ended");
	}

	void Renderer::release()
	{
		ZOM_FUNCTION_TIMER();
		if (s_Created)
		{
			ZOM_TRACE("Renderer release started");
			s_ShaderMgr.deleteAllShaders();
			s_RenderContext.reset();
			s_RenderApplication.reset();
			ZOM_TRACE("Renderer release ended");
			s_Created = false;
		}
		else
		{
			ZOM_TRACE("Can't release renderer, you have to initialize it first");
		}
	}

	void Renderer::preRunInit()
	{
		ZOM_FUNCTION_TIMER();

		if (s_Created)
		{
			s_ShaderMgr.compileAllShaders();
		}
		else
		{
			ZOM_TRACE("Can't preRunInit renderer, you have to initialize it first");
		}
	}

	void Renderer::clear()
	{
		ZOM_FUNCTION_TIMER();

		if (s_Created)
			s_RenderApplication->clear();
		else
			ZOM_ERROR("Have to initialize renderer, in order to clear");
	}

	void Renderer::draw(const std::shared_ptr<Mesh>& mesh)
	{
		ZOM_FUNCTION_TIMER();

		if (s_Created)
			s_RenderApplication->draw(mesh);
		else
			ZOM_ERROR("Have to initialize renderer, in order to draw mesh");
	}

	void Renderer::setBeforeInitRenderingApi(RenderingAPI api)
	{
		if (!s_Created)
			s_RendreringApi = api;
		else
			ZOM_ERROR("Renderer already created when trying to set before init rendering api");
	}

	RenderingAPI Renderer::getAPI()
	{
		return s_RendreringApi;
	}

	std::shared_ptr<Shader> Renderer::getShader(const std::string& name)
	{
		return s_ShaderMgr.getShader(name);
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
		ZOM_FUNCTION_TIMER();

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

	std::string getStrRenderingApi(RenderingAPI rapi)
	{
		
		switch (rapi)
		{
			case RenderingAPI::OPENGL: return "OpenGL";
		}

		ZOM_WARNING("Unsuported RendreringAPI in getStrRenderingApi");
		return "";
	}

	bool Renderer::s_Created = false;
	ZOM::RenderingAPI Renderer::s_RendreringApi = RenderingAPI::OPENGL;
	std::unique_ptr<RenderContext> Renderer::s_RenderContext = nullptr;
	std::unique_ptr<RenderApplication> Renderer::s_RenderApplication = nullptr;
	ShaderManager Renderer::s_ShaderMgr;
}