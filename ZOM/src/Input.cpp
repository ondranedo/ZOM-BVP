#include "Input.h"

namespace ZOM {
	Input* Input::s_Instance = Input::create();

	Input::~Input()
	{
		delete s_Instance;
	}
}