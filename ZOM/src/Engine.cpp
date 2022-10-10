#include "Engine.h"

#include "window/MainWindow.h"

extern ZOM::Game* createGame();

namespace ZOM {

	void Engine::init()
	{
		ZOM_TRACE("Engine initialization stared");

		s_LayerManager.init("./events.log");
		
		s_Game = createGame();

		Renderer::setBeforeInitRenderingApi(RenderingAPI::OPENGL);

		ZOM_TRACE("Engine initialization ended");
	}

	void Engine::release()
	{
		ZOM_TRACE("Engine release started");
		s_LayerManager.release();

		delete s_Game;
		delete s_Window;

		ZOM_TRACE("Engine release ended");
	}

	void Engine::run()
	{
		s_Running = true;

		ZOM::MainWindow::setEventQueue(s_EventQueue);

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
		
		MainWindow::pollEvents();
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

