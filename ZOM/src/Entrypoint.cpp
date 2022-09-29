#include "Application.h"

extern ZOM::ZOMGameEngine* createApp();

int main(int argc, char** argv)
{
	ZOM::ZOMGameEngine* app = createApp();

	app->run();

	delete app;

	return 0;
}