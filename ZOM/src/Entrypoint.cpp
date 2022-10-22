#include "Engine.h"
#include "Window/MainWindow.h"
#include "Config.h"
#include "Profiling.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

int main(int argc, char** argv)
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ZOM::Logger::init();
	ZOM::Config::init();
	ZOM::ChromeProfiling::init();

	ZOM::Engine::init();
	ZOM::Renderer::init();
	ZOM::MainWindow::init();
	//
	ZOM::Engine::run();
	//
	ZOM::Engine::release();
	ZOM::Renderer::release();
	ZOM::MainWindow::release();
	ZOM::ChromeProfiling::release();
	ZOM::Config::release();
	ZOM::Logger::release();

	return 0;
}