#include "Engine.h"

#include "window/MainWindow.h"

#include "config.h"

extern ZOM::Game* createGame();

namespace ZOM {

	void Engine::init()
	{
		ZOM_FUNCTION_TIMER();
		ZOM_TRACE("Engine initialization stared");

		s_LayerManager.init();
		
		s_Game = createGame();

		Renderer::setBeforeInitRenderingApi(RenderingAPI::OPENGL);

		ZOM_TRACE("Engine initialization ended");
	}

	void Engine::release()
	{
		ZOM_FUNCTION_TIMER();
		ZOM_TRACE("Engine release started");
		s_LayerManager.release();

		delete s_Game;

		ZOM_TRACE("Engine release ended");
	}

	void Engine::run()
	{
		ZOM_FUNCTION_TIMER();
		Renderer::preRunInit();

		s_Running = true;

		MainWindow::setEventQueue(s_EventQueue);

		s_LayerManager.onCreateLayers();

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
		ZOM_FUNCTION_TIMER();

		Renderer::clear();
		
		MainWindow::pollEvents();
	 	s_LayerManager.handleEvents(&s_EventQueue);

	 	s_LayerManager.updateLayers();
		
    	Renderer::renderLoop();
	 }
	
	bool Engine::s_Running = false;
	Game* Engine::s_Game;
	EventQueue Engine::s_EventQueue;
	LayerManager Engine::s_LayerManager;
}

