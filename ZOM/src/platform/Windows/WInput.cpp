#include "WInput.h"

#ifdef ZOM_WINDOWS

#include "GLFW/glfw3.h"
#include "window/MainWindow.h"

namespace ZOM
{
	bool WInput::isPressedImpl(const int zom_key_code)
	{
		const int state = glfwGetKey(static_cast<GLFWwindow*>(MainWindow::getContextCreationAdr()), zom_key_code);
		if(state == GLFW_REPEAT || state == GLFW_PRESS) return true;
		return false;
	}

	std::unique_ptr<Input> Input::create()
	{
		return std::make_unique<WInput>();
	}
}

#endif
