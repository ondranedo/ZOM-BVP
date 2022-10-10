#include "Engine.h"
#include "Window/MainWindow.h"

int main(int argc, char** argv)
{
    ZOM::Logger::init();
	ZOM::Engine::init();
	ZOM::Renderer::init();
	ZOM::MainWindow::init();

	ZOM::Engine::run();

	ZOM::Engine::release();
	ZOM::Renderer::release();
	ZOM::MainWindow::release();
	ZOM::Logger::release();

	return 0;
}