#include "OpenGLRenderContext.h"

#include "platform/Windows/WWindow.h"

namespace ZOM {

	OpengGLRenderContex::OpengGLRenderContex(void* window_ptr):m_WindowPtr((GLFWwindow*)window_ptr)
	{
		WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(m_WindowPtr);

		ZOM_TRACE("OpenGL context created for window: {}",data->param.name);
	}

	OpengGLRenderContex::~OpengGLRenderContex()
	{
		destroy();
	}

	void OpengGLRenderContex::init()
	{
		int error;

		glfwMakeContextCurrent(m_WindowPtr);

		ZOM_ASSERT(error = gladLoadGL(glfwGetProcAddress), "glad error[{}], loaded unsuccesfuly", error);
	}

	void OpengGLRenderContex::destroy()
	{
		WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(m_WindowPtr);

		ZOM_TRACE("OpenGL context destroyed for window: {}", data->param.name);
	}

	void OpengGLRenderContex::swap()
	{
		glfwSwapBuffers(m_WindowPtr);
	}

}
