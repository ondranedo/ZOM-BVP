#ifdef ZOM_WINDOWS

#include "WWindow.h"
#include "events/KeyEvents.h"
#include "events/MouseEvents.h"
#include "events/WindowEvents.h"

namespace ZOM {
	WWindow::WWindow(const WindowParam& param) : 
		m_WindowData(WWindowData(param))
	{ init(); }
	WWindow::~WWindow() {  }

	inline std::string WWindow::name() const { return m_WindowData.param.name; }
	inline std::pair<int,int> WWindow::dime() const { return m_WindowData.param.dimensions; }
	inline bool WWindow::isVsync() const { return m_WindowData.isVsync; }

	void WWindow::setEventCallbackFn(const eventCallbackFn& fun) { m_WindowData.ecf = fun; }

	void WWindow::setVsync(bool state) {
		if (state) glfwSwapInterval(1);
		else       glfwSwapInterval(0);
	}

	void WWindow::resize(const std::pair<int, int>& dims) {
		glfwSetWindowSize(m_WindowData.windowPtr, dims.first, dims.second);
		m_WindowData.param.dimensions = dims;
	}
	
	// Runs every frame
	void WWindow::update() {
		glfwPollEvents();
		glfwSwapBuffers(m_WindowData.windowPtr);
	}

	void WWindow::init()
	{
		glfwInit();
		m_WindowData.windowPtr = glfwCreateWindow(m_WindowData.param.dimensions.first,
			                                      m_WindowData.param.dimensions.second,
			                                      m_WindowData.param.name.c_str(),
									              NULL, NULL);

		glfwMakeContextCurrent(m_WindowData.windowPtr);

		glfwSetWindowUserPointer(m_WindowData.windowPtr, (void*)&m_WindowData);

		setCallBacks();
	}

	void WWindow::terminate()
	{
		ZOM_TRACE("Destroying \"{}\ window", name());

		glfwDestroyWindow(m_WindowData.windowPtr);
	}

	void WWindow::setCallBacks()
	{
		glfwSetWindowCloseCallback(m_WindowData.windowPtr, [](GLFWwindow* window)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
		
			data->ecf(event);
		});

		glfwSetWindowSizeCallback(m_WindowData.windowPtr, [](GLFWwindow* window,int w, int h)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(w, h);

			data->ecf(event);
		});

		glfwSetKeyCallback(m_WindowData.windowPtr, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
			case GLFW_PRESS: {
				KeyPressedEvent event(key, 0);
				data->ecf(event); }
			break;
			case GLFW_REPEAT: {
				KeyPressedEvent event(key, 1); 
				data->ecf(event); }
			break;
			case GLFW_RELEASE: {
				KeyReleasedEvent event(key);   
				data->ecf(event); }
				break;
			}
		});

		glfwSetCursorPosCallback(m_WindowData.windowPtr, [](GLFWwindow* window, double x, double y)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event(x, y);
			data->ecf(event);
		});

		glfwSetScrollCallback(m_WindowData.windowPtr, [](GLFWwindow* window, double x, double y)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			MouseScrollEvent event(x, y);
			data->ecf(event);
		});


		glfwSetMouseButtonCallback(m_WindowData.windowPtr, [](GLFWwindow* window, int button, int action, int mods)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data->ecf(event);
			}
			break;
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data->ecf(event);
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