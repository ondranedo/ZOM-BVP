#include "Mousecodes.h"

namespace ZOM {
	int glfwToZOMMouseCode(int code)
	{
		return code;
	}

	std::string ZOMMouseCodeToString(int code)
	{
		switch (code)
		{
		case ZOM_MOUSE_BUTTON_1: return "MOUSE_BUTTON_LEFT";
		case ZOM_MOUSE_BUTTON_2: return "MOUSE_BUTTON_RIGHT";
		case ZOM_MOUSE_BUTTON_3: return "MOUSE_BUTTON_MIDDLE";
		case ZOM_MOUSE_BUTTON_4: return "MOUSE_BUTTON_4";
		case ZOM_MOUSE_BUTTON_5: return "MOUSE_BUTTON_5";
		case ZOM_MOUSE_BUTTON_6: return "MOUSE_BUTTON_6";
		case ZOM_MOUSE_BUTTON_7: return "MOUSE_BUTTON_7";
		case ZOM_MOUSE_BUTTON_8: return "MOUSE_BUTTON_8";
		}

		ZOM_ASSERT(false, "None specified mouse button");

		return "Error ZOMMouseCodeToString";
	}
}