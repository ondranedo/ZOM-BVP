#ifdef ZOM_WINDOWS

#include "WWindow.h"
#include "events/KeyEvents.h"
#include "events/MouseEvents.h"
#include "events/WindowEvents.h"

namespace ZOM {
	WWindow::WWindow(const WindowParam& param) : m_WindowParam(param), m_WindowPtr(nullptr) { init(); }
	WWindow::~WWindow() {}
	int WWindow::getWidth() const { return m_WindowParam.width; }
	int WWindow::getHeight() const { return m_WindowParam.height; }
	bool WWindow::isVsync() const { return m_WindowParam.vsync; }
	std::string WWindow::getName() const { return m_WindowParam.name; }

	void WWindow::setEventCallbackFn(const eventCallbackFn& fun)
	{
		m_WindowParam.eventFunc = fun;
	}

	void WWindow::setVsync(bool state)
	{
		if (state)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void WWindow::resize(const std::pair<int, int>& dims)
	{
		glfwSetWindowSize(m_WindowPtr, dims.first, dims.second);
		m_WindowParam.width = dims.first;
		m_WindowParam.height = dims.second;
	}
	
	void WWindow::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_WindowPtr);
	}

	void WWindow::init()
	{
		glfwInit();
		m_WindowPtr = glfwCreateWindow(m_WindowParam.width, 
									   m_WindowParam.height,
			                           m_WindowParam.name.c_str(),
			                           NULL, NULL);
		glfwMakeContextCurrent(m_WindowPtr);
		glfwSetWindowUserPointer(m_WindowPtr, (void*)&m_WindowParam );

		setCallBacks();
	}


	void WWindow::setCallBacks()
	{
		glfwSetWindowCloseCallback(m_WindowPtr, [](GLFWwindow* window)
		{
			WindowParam* param = (WindowParam*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
		
			param->eventFunc(event);
		});

		glfwSetWindowSizeCallback(m_WindowPtr, [](GLFWwindow* window,int w, int h)
		{
			WindowParam* param = (WindowParam*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(w, h);

			param->eventFunc(event);
		});

		glfwSetKeyCallback(m_WindowPtr, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowParam* param = (WindowParam*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0); param->eventFunc(event); break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1); param->eventFunc(event); break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);   param->eventFunc(event); break;
			}
			}
		});

		glfwSetCursorPosCallback(m_WindowPtr, [](GLFWwindow* window, double x, double y)
		{
			WindowParam* param = (WindowParam*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event(x, y);
			param->eventFunc(event);
		});

		glfwSetScrollCallback(m_WindowPtr, [](GLFWwindow* window, double x, double y)
		{
			WindowParam* param = (WindowParam*)glfwGetWindowUserPointer(window);
			MouseScrollEvent event(x, y);
			param->eventFunc(event);
		});


		glfwSetMouseButtonCallback(m_WindowPtr, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowParam* param = (WindowParam*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				param->eventFunc(event);
			}
			break;
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				param->eventFunc(event);
			}
			break;
			}
		});
	}

	Window* Window::createWindow(const WindowParam& param)
	{
		return new WWindow(param);
	}
}

#endif