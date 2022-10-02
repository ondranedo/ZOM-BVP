#include "Application.h"

extern ZOM::ZOMGameEngine* createApp();

int main(int argc, char** argv)
{
	ZOM::Log::init();

	ZOM_INFO("Logger initialized");

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
	ZOM_CLIENT_CRITICAL("Building on unkonw device... quitting.");
	return -1;
#endif

	ZOM::ZOMGameEngine* app = createApp();

	app->run();

	delete app;

	return 0;
}