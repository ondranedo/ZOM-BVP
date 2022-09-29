#include "Application.h"

#include <iostream>


namespace ZOM {
	Application::Application()
	{
#if   ZOM_DEBUG
		std::cout << "Application debug created" << std::endl;
#elif ZOM_RELEASE
		std::cout << "Application release created" << std::endl;
#elif ZOM_DISTRIBUTE
		std::cout << "Application distribute created" << std::endl;
#endif
	}

	Application::~Application()
	{
		std::cout << "Application destroyed" << std::endl;
	}
}

