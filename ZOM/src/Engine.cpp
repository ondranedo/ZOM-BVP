#include "Engine.h"

#include <glad/gl.h>

namespace ZOM {
	ZOMGameEngine::ZOMGameEngine():
		m_Running(false),
		m_Window(nullptr),
		m_LayerManager("./events.log")
	{
		Renderer::create(RenderingAPI::OPENGL);

		m_Window = Window::createWindow();

		m_Window->init();

		m_Window->setEventCallbackFn(m_EventQueue.getEventCallBack());

	}

	void ZOMGameEngine::run()
	{
		m_Running = true;

		ZOM_TRACE("Starting main loop");

		while (m_Running)
			onFrame();

		ZOM_TRACE("Ending main loop");
	}

	void ZOMGameEngine::addLayer(Layer* layer)
	{
		m_LayerManager.addLayerOnTop(layer);
	}

	void ZOMGameEngine::close()
	{
		ZOM_WARNING("Engine close function has been called");

		m_Running = false;
	}

	bool ZOMGameEngine::isRunning()
	{
		return m_Running;
	}

	void ZOMGameEngine::onFrame()
	{
		m_Window->pollEvents();
		m_LayerManager.handleEvents(&m_EventQueue);

		m_LayerManager.updateLayers();

		Renderer::renderLoop();
	}

	ZOMGameEngine::~ZOMGameEngine()
	{
		ZOM_TRACE("Destroying engine");

		Renderer::terminate();

		delete m_Window;
	}
}

