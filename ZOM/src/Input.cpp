#include "Input.h"

namespace ZOM {
	std::unique_ptr<Input> Input::s_Instance = Input::create();
}