#include "Application.h"

extern ZOM::ZOMGameEngine* createApp();

int main(int argc, char** argv)
{
	ZOM::Log::init();

	ZOM::ZOM_INFO("Logger initialized");

#ifdef ZOM_DEBUG
	ZOM::ZOM_CLIENT_ERROR("Debug build");
#elif  ZOM_RELEASE
	ZOM::ZOM_CLIENT_WARNING("Release build");
#elif ZOM_DISTRIBUTE
	ZOM::ZOM_CLIENT_INFO("Distribute build");
#endif

	ZOM::ZOMGameEngine* app = createApp();

	app->run();

	delete app;

	return 0;
}