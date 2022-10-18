#include "Engine.h"
#include "Window/MainWindow.h"
#include "Config.h"

int main(int argc, char** argv)
{	
	ZOM::Logger::init();
	ZOM::Config::init();
	ZOM::Engine::init();
	ZOM::Renderer::init();
	ZOM::MainWindow::init();

	ZOM::Engine::run();

	ZOM::Engine::release();
	ZOM::Renderer::release();
	ZOM::MainWindow::release();
	ZOM::Logger::release();
	ZOM::Config::release();

	std::cin.get();
	return 0;

}