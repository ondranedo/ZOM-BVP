#include "Keycodes.h"

namespace ZOM
{
	int glfwToZOMKeyCode(const int code)
	{
		return code;
	}

	std::string zomKeyCodeToString(const int code)
	{
		switch(code) {
			case ZOM_KEY_SPACE: return "KEY_SPACE";
			case ZOM_KEY_APOSTROPHE: return "KEY_APOSTROPHE";
			case ZOM_KEY_COMMA: return "KEY_COMMA";
			case ZOM_KEY_MINUS: return "KEY_MINUS";
			case ZOM_KEY_PERIOD: return "KEY_PERIOD";
			case ZOM_KEY_SLASH: return "KEY_SLASH";
			case ZOM_KEY_0: return "KEY_0";
			case ZOM_KEY_1: return "KEY_1";
			case ZOM_KEY_2: return "KEY_2";
			case ZOM_KEY_3: return "KEY_3";
			case ZOM_KEY_4: return "KEY_4";
			case ZOM_KEY_5: return "KEY_5";
			case ZOM_KEY_6: return "KEY_6";
			case ZOM_KEY_7: return "KEY_7";
			case ZOM_KEY_8: return "KEY_8";
			case ZOM_KEY_9: return "KEY_9";
			case ZOM_KEY_SEMICOLON: return "KEY_SEMICOLON";
			case ZOM_KEY_EQUAL: return "KEY_EQUAL";
			case ZOM_KEY_A: return "KEY_A";
			case ZOM_KEY_B: return "KEY_B";
			case ZOM_KEY_C: return "KEY_C";
			case ZOM_KEY_D: return "KEY_D";
			case ZOM_KEY_E: return "KEY_E";
			case ZOM_KEY_F: return "KEY_F";
			case ZOM_KEY_G: return "KEY_G";
			case ZOM_KEY_H: return "KEY_H";
			case ZOM_KEY_I: return "KEY_I";
			case ZOM_KEY_J: return "KEY_J";
			case ZOM_KEY_K: return "KEY_K";
			case ZOM_KEY_L: return "KEY_L";
			case ZOM_KEY_M: return "KEY_M";
			case ZOM_KEY_N: return "KEY_N";
			case ZOM_KEY_O: return "KEY_O";
			case ZOM_KEY_P: return "KEY_P";
			case ZOM_KEY_Q: return "KEY_Q";
			case ZOM_KEY_R: return "KEY_R";
			case ZOM_KEY_S: return "KEY_S";
			case ZOM_KEY_T: return "KEY_T";
			case ZOM_KEY_U: return "KEY_U";
			case ZOM_KEY_V: return "KEY_V";
			case ZOM_KEY_W: return "KEY_W";
			case ZOM_KEY_X: return "KEY_X";
			case ZOM_KEY_Y: return "KEY_Y";
			case ZOM_KEY_Z: return "KEY_Z";
			case ZOM_KEY_LEFT_BRACKET: return "KEY_LEFT_BRACKET";
			case ZOM_KEY_BACKSLASH: return "KEY_BACKSLASH";
			case ZOM_KEY_RIGHT_BRACKET: return "KEY_RIGHT_BRACKET";
			case ZOM_KEY_GRAVE_ACCENT: return "KEY_GRAVE_ACCENT";
			case ZOM_KEY_ESCAPE: return "KEY_ESCAPE";
			case ZOM_KEY_ENTER: return "KEY_ENTER";
			case ZOM_KEY_TAB: return "KEY_TAB";
			case ZOM_KEY_BACKSPACE: return "KEY_BACKSPACE";
			case ZOM_KEY_INSERT: return "KEY_INSERT";
			case ZOM_KEY_DELETE: return "KEY_DELETE";
			case ZOM_KEY_RIGHT: return "KEY_RIGHT";
			case ZOM_KEY_LEFT: return "KEY_LEFT";
			case ZOM_KEY_DOWN: return "KEY_DOWN";
			case ZOM_KEY_UP: return "KEY_UP";
			case ZOM_KEY_PAGE_UP: return "KEY_PAGE_UP";
			case ZOM_KEY_PAGE_DOWN: return "KEY_PAGE_DOWN";
			case ZOM_KEY_HOME: return "KEY_HOME";
			case ZOM_KEY_END: return "KEY_END";
			case ZOM_KEY_CAPS_LOCK: return "KEY_CAPS_LOCK";
			case ZOM_KEY_SCROLL_LOCK: return "KEY_SCROLL_LOCK";
			case ZOM_KEY_NUM_LOCK: return "KEY_NUM_LOCK";
			case ZOM_KEY_PRINT_SCREEN: return "KEY_PRINT_SCREEN";
			case ZOM_KEY_PAUSE: return "KEY_PAUSE";
			case ZOM_KEY_F1: return "KEY_F1";
			case ZOM_KEY_F2: return "KEY_F2";
			case ZOM_KEY_F3: return "KEY_F3";
			case ZOM_KEY_F4: return "KEY_F4";
			case ZOM_KEY_F5: return "KEY_F5";
			case ZOM_KEY_F6: return "KEY_F6";
			case ZOM_KEY_F7: return "KEY_F7";
			case ZOM_KEY_F8: return "KEY_F8";
			case ZOM_KEY_F9: return "KEY_F9";
			case ZOM_KEY_F10: return "KEY_F10";
			case ZOM_KEY_F11: return "KEY_F11";
			case ZOM_KEY_F12: return "KEY_F12";
			case ZOM_KEY_F13: return "KEY_F13";
			case ZOM_KEY_F14: return "KEY_F14";
			case ZOM_KEY_F15: return "KEY_F15";
			case ZOM_KEY_F16: return "KEY_F16";
			case ZOM_KEY_F17: return "KEY_F17";
			case ZOM_KEY_F18: return "KEY_F18";
			case ZOM_KEY_F19: return "KEY_F19";
			case ZOM_KEY_F20: return "KEY_F20";
			case ZOM_KEY_F21: return "KEY_F21";
			case ZOM_KEY_F22: return "KEY_F22";
			case ZOM_KEY_F23: return "KEY_F23";
			case ZOM_KEY_F24: return "KEY_F24";
			case ZOM_KEY_F25: return "KEY_F25";
			case ZOM_KEY_KP_0: return "KEY_KP_0";
			case ZOM_KEY_KP_1: return "KEY_KP_1";
			case ZOM_KEY_KP_2: return "KEY_KP_2";
			case ZOM_KEY_KP_3: return "KEY_KP_3";
			case ZOM_KEY_KP_4: return "KEY_KP_4";
			case ZOM_KEY_KP_5: return "KEY_KP_5";
			case ZOM_KEY_KP_6: return "KEY_KP_6";
			case ZOM_KEY_KP_7: return "KEY_KP_7";
			case ZOM_KEY_KP_8: return "KEY_KP_8";
			case ZOM_KEY_KP_9: return "KEY_KP_9";
			case ZOM_KEY_KP_DECIMAL: return "KEY_KP_DECIMAL";
			case ZOM_KEY_KP_DIVIDE: return "KEY_KP_DIVIDE";
			case ZOM_KEY_KP_MULTIPLY: return "KEY_KP_MULTIPLY";
			case ZOM_KEY_KP_SUBTRACT: return "KEY_KP_SUBTRACT";
			case ZOM_KEY_KP_ADD: return "KEY_KP_ADD";
			case ZOM_KEY_KP_ENTER: return "KEY_KP_ENTER";
			case ZOM_KEY_KP_EQUAL: return "KEY_KP_EQUAL";
			case ZOM_KEY_LEFT_SHIFT: return "KEY_LEFT_SHIFT";
			case ZOM_KEY_LEFT_CONTROL: return "KEY_LEFT_CONTROL";
			case ZOM_KEY_LEFT_ALT: return "KEY_LEFT_ALT";
			case ZOM_KEY_LEFT_SUPER: return "KEY_LEFT_SUPER";
			case ZOM_KEY_RIGHT_SHIFT: return "KEY_RIGHT_SHIFT";
			case ZOM_KEY_RIGHT_CONTROL: return "KEY_RIGHT_CONTROL";
			case ZOM_KEY_RIGHT_ALT: return "KEY_RIGHT_ALT";
			case ZOM_KEY_RIGHT_SUPER: return "KEY_RIGHT_SUPER";
			case ZOM_KEY_MENU: return "KEY_MENU";
		}

		ZOM_ASSERT(false, "None specified  button");
		return "zomKeyCodeToString ERROR";
	}
}
