#include "WInput.h"

#ifdef ZOM_WINDOWS

#include "GLFW/glfw3.h"
#include "window/MainWindow.h"

namespace ZOM {

	bool WInput::isPressedImpl(int zom_key_code)
	{
		int state = glfwGetKey((GLFWwindow*)MainWindow::windowPtr()->getContextCreationAdr(), zom_key_code);
		if (state == GLFW_REPEAT || state == GLFW_PRESS)
			return true;
		else
			return false;
	}
}

#endif