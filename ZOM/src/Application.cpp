#include "Application.h"

#include <iostream>


namespace ZOM {
	Application::Application()
	{
		std::cout << "Application created" << std::endl;
	}

	Application::~Application()
	{
		std::cout << "Application destroyed" << std::endl;
	}
}

