#include "Engine.h"
#include "Window/MainWindow.h"

int main(int argc, char** argv)
{
/*
#ifdef ZOM_DEBUG
		ZOM_CLIENT_ERROR("Debug build");
#elif  ZOM_RELEASE
		ZOM_CLIENT_WARNING("Release build");
#elif ZOM_DISTRIBUTE
		ZOM_CLIENT_INFO("Distribute build");
#endif

#ifdef ZOM_WINDOWS
		ZOM_CLIENT_INFO("Building on Windows");

#elif  ZOM_LINUX
		ZOM_CLIENT_CRITICAL("Building on Linux, not supported... quitting.");
		return -1;

#elif ZOM_MACOS
		ZOM_CLIENT_CRITICAL("Building on MacOS, not supported... quitting.");
		return -1;
#else
		ZOM_CLIENT_CRITICAL("Building on unknown device... quitting.");
		return -1;
#endif
*/
	    ZOM::Logger::init();
		ZOM::MainWindow::init();
		ZOM::Engine::init();
		//	ZOM::Renderer::init();

		ZOM::Engine::run();

		ZOM::Engine::release();
		ZOM::MainWindow::release();
		ZOM::Logger::release();
	//	ZOM::Renderer::release();

	return 0;
}