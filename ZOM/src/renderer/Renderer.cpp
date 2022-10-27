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

		switch (m_SRenderingApi)
		{
		case renderingAPI::opengl:
			m_SRenderContext = std::make_unique<OpenGLRenderContext>();
			m_SRenderApplication = std::make_unique<OpenGLRenderApplication>();
			m_SCreated = true;
		break;

		default:
			ZOM_CRITICAL("Unkown rendering api when creating renderer");
		}

		m_SShaderMgr.setShaderPaths(Config::shaderPaths());

		ZOM_TRACE("Renderer initialization ended");
	}

	void Renderer::release()
	{
		ZOM_FUNCTION_TIMER();
		if (m_SCreated)
		{
			ZOM_TRACE("Renderer release started");
			m_SShaderMgr.deleteAllShader();
			m_SRenderContext.reset();
			m_SRenderApplication.reset();
			ZOM_TRACE("Renderer release ended");
			m_SCreated = false;
		}
		else
		{
			ZOM_TRACE("Can't release renderer, you have to initialize it first");
		}
	}

	void Renderer::preRunInit()
	{
		ZOM_FUNCTION_TIMER();

		if (m_SCreated)
		{
			m_SShaderMgr.compileAllShader();
		}
		else
		{
			ZOM_TRACE("Can't preRunInit renderer, you have to initialize it first");
		}
	}

	void Renderer::clear()
	{
		ZOM_FUNCTION_TIMER();

		if (m_SCreated)
			m_SRenderApplication->clear();
		else
			ZOM_ERROR("Have to initialize renderer, in order to clear");
	}

	void Renderer::draw(const std::shared_ptr<Mesh>& mesh)
	{
		ZOM_FUNCTION_TIMER();

		if (m_SCreated)
			m_SRenderApplication->draw(mesh);
		else
			ZOM_ERROR("Have to initialize renderer, in order to draw mesh");
	}

	void Renderer::setBeforeInitRenderingApi(renderingAPI api)
	{
		if (!m_SCreated)
			m_SRenderingApi = api;
		else
			ZOM_ERROR("Renderer already created when trying to set before init rendering api");
	}

	renderingAPI Renderer::getAPI()
	{
		return m_SRenderingApi;
	}

	std::shared_ptr<Shader> Renderer::getShader(const std::string& name)
	{
		return m_SShaderMgr.getShader(name);
	}

	void Renderer::contextInitialize(Window* window)
	{
		if (m_SCreated)
			m_SRenderContext->init(window->getContextCreationAdr());
		else
			ZOM_ERROR("Can't intialize context, you have to initialize renderer first");
	}

	void Renderer::renderLoop()
	{
		ZOM_FUNCTION_TIMER();

		if (m_SCreated)
		{
			// m_SRenderApplication->clear();

			m_SRenderContext->swap();
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

	std::string getStrRenderingApi(renderingAPI rapi)
	{
		
		switch (rapi)
		{
			case renderingAPI::opengl: return "OpenGL";
		}

		ZOM_WARNING("Unsuported RendreringAPI in getStrRenderingApi");
		return "";
	}

	bool Renderer::m_SCreated = false;
	ZOM::renderingAPI Renderer::m_SRenderingApi = renderingAPI::opengl;
	std::unique_ptr<RenderContext> Renderer::m_SRenderContext = nullptr;
	std::unique_ptr<RenderApplication> Renderer::m_SRenderApplication = nullptr;
	ShaderManager Renderer::m_SShaderMgr;
}