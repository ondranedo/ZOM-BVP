#include "Engine.h"

#include <glad/gl.h>

extern ZOM::Game* createGame();

namespace ZOM {

	void Engine::init()
	{
		s_LayerManager.init("./events.log");

		Renderer::create(RenderingAPI::OPENGL);

		s_Window = Window::createWindow();

		s_Window->init();

		s_Window->setEventCallbackFn(s_EventQueue.getEventCallBack());

		s_Game = createGame();

		ZOM_TRACE("Engine initialized");
	}

	void Engine::release()
	{
		s_LayerManager.release();
		delete s_Game;

		Renderer::terminate();

		delete s_Window;

		ZOM_TRACE("Engine released");
	}

	void Engine::run()
	{
		s_Running = true;

		ZOM_TRACE("Starting main loop");

		while (s_Running)
			onFrame();

		ZOM_TRACE("Ending main loop");
	}
	 
	 void Engine::addLayer(Layer* layer)
	 {
		 s_LayerManager.addLayerOnTop(layer);
	 }

	 void Engine::close()
	 {
		 ZOM_WARNING("Engine close function has been called");

		 s_Running = false;
	 }

	 bool Engine::isRunning()
	 {
		 return s_Running;
	 }
	 
	 void Engine::onFrame()
	 {
	 	Renderer::getRenderApplication()->clear();
	
	 	s_Window->pollEvents();

	 	s_LayerManager.handleEvents(&s_EventQueue);
	 
	 	s_LayerManager.updateLayers();
	
    	Renderer::renderLoop();
	 }
	
	bool Engine::s_Running = false;
	Window* Engine::s_Window = nullptr;
	Game* Engine::s_Game;
	EventQueue Engine::s_EventQueue;
	LayerManager Engine::s_LayerManager;
}

