﻿#include "Application.h"

#include <glad/gl.h>

namespace ZOM {
	ZOMGameEngine::ZOMGameEngine():
		m_Running(false),
		m_Window(nullptr)
	{
		m_Window = Window::createWindow();

		ZOM_TRACE("Window \"{}\" has been created", m_Window->name());

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
		m_Running = false;
	}

	void ZOMGameEngine::onFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		m_LayerManager.handleEvents(&m_EventQueue);

		m_LayerManager.updateLayers();

		m_Window->update();
	}

	ZOMGameEngine::~ZOMGameEngine()
	{
		ZOM_WARNING("Destroying engine");

		delete m_Window;
	}
}

