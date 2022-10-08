#include "Engine.h"

#include <glad/gl.h>

namespace ZOM {
	ZOMGameEngine::ZOMGameEngine():
		m_Running(false),
		m_Window(nullptr),
		m_LayerManager("./events.log")
	{
		m_Window = Window::createWindow();

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
		//m_Renderer->clear();
		glClear(GL_COLOR_BUFFER_BIT);

		m_Window->pollEvents();
		m_LayerManager.handleEvents(&m_EventQueue);

		m_LayerManager.updateLayers();
		 
		//m_Renderer->render();

		m_Window->swapBuffers(); // in render loop
	}

	ZOMGameEngine::~ZOMGameEngine()
	{
		ZOM_TRACE("Destroying engine");

		delete m_Window;
	}
}

