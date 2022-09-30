#pragma once

#define ZOM_MOUSE_BUTTON_1         0
#define ZOM_MOUSE_BUTTON_2         1
#define ZOM_MOUSE_BUTTON_3         2
#define ZOM_MOUSE_BUTTON_4         3
#define ZOM_MOUSE_BUTTON_5         4
#define ZOM_MOUSE_BUTTON_6         5
#define ZOM_MOUSE_BUTTON_7         6
#define ZOM_MOUSE_BUTTON_8         7
#define ZOM_MOUSE_BUTTON_LEFT      ZOM_MOUSE_BUTTON_1
#define ZOM_MOUSE_BUTTON_RIGHT     ZOM_MOUSE_BUTTON_2
#define ZOM_MOUSE_BUTTON_MIDDLE    ZOM_MOUSE_BUTTON_3

namespace ZOM {
	extern int glfwToZOMMouseCode(int code);

	extern std::string ZOMMouseCodeToString(int code);
}