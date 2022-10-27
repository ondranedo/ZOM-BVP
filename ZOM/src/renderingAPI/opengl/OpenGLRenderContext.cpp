#include "OpenGLRenderContext.h"

#include "platform/Windows/WWindow.h"

namespace ZOM
{
	OpenGLRenderContext::OpenGLRenderContext()
		: m_WindowPtr(nullptr)
	{
		ZOM_TRACE("Blank OpenGL context created");
	}

	OpenGLRenderContext::~OpenGLRenderContext()
	{
		ZOM_TRACE("OpenGL context destroyed");
	}

	void OpenGLRenderContext::init(void* window_ptr)
	{
		if(!m_WindowPtr) {
			m_WindowPtr     = static_cast<GLFWwindow*>(window_ptr);
			const auto data = static_cast<wWindowData*>(glfwGetWindowUserPointer(m_WindowPtr));

			int error;
			glfwMakeContextCurrent(m_WindowPtr);
			ZOM_ASSERT(error = gladLoadGL(glfwGetProcAddress), "glad error[{}], loaded unsuccesfuly", error);
			ZOM_TRACE("OpenGL context initialized for window: {}", data->m_Param.m_Name);
		}
		else {
			ZOM_ERROR("OpenGL context already initialized");
		}
	}

	void OpenGLRenderContext::destroy()
	{
		ZOM_TRACE("OpenGL context destroyed");
	}

	void OpenGLRenderContext::swap() const
	{
		if(m_WindowPtr != nullptr) glfwSwapBuffers(m_WindowPtr);
	}
}
