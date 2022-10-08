#include "OpenGLRenderContext.h"

namespace ZOM {

	OpengGLRenderContex::OpengGLRenderContex(void* window_ptr):m_WindowPtr((GLFWwindow*)window_ptr)
	{
		ZOM_TRACE("New OpenGL context created");
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
		ZOM_WARNING("OpenGL context destroyed");
	}

	void OpengGLRenderContex::swap()
	{
		glfwSwapBuffers(m_WindowPtr);
	}

}
