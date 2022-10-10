#include "OpenGLRenderContext.h"

#include "platform/Windows/WWindow.h"

namespace ZOM {

	OpenGLRenderContex::OpenGLRenderContex(): m_WindowPtr(nullptr)
	{
		ZOM_TRACE("Blank OpenGL context created");
	}

	OpenGLRenderContex::~OpenGLRenderContex()
	{
		destroy();
	}

	void OpenGLRenderContex::init(void* window_ptr) 
	{
		if (!m_WindowPtr)
		{
			m_WindowPtr = (GLFWwindow*)window_ptr;
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(m_WindowPtr);

			int error;
			glfwMakeContextCurrent(m_WindowPtr);
			ZOM_ASSERT(error = gladLoadGL(glfwGetProcAddress), "glad error[{}], loaded unsuccesfuly", error);
			ZOM_TRACE("OpenGL context initialized for window: {}", data->param.name);
		}
		else
		{
			ZOM_ERROR("OpenGL context already initialized");
		}
	}

	void OpenGLRenderContex::destroy()
	{
		ZOM_TRACE("OpenGL context destroyed");
	}

	void OpenGLRenderContex::swap() const
	{
		if(m_WindowPtr != NULL)
			glfwSwapBuffers(m_WindowPtr);
	}

}
