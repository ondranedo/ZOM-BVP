#ifdef ZOM_WINDOWS

#include "WWindow.h"

namespace ZOM {
	WWindow::WWindow(const WindowParam& param) : 
		m_WindowData(WWindowData(param))
	{ 
		ZOM_TRACE("Windows Window \"{}\" has been created", m_WindowData.param.name);
	}
	WWindow::~WWindow() { terminate(); }

	inline std::string WWindow::name() const { return m_WindowData.param.name; }
	inline std::pair<int,int> WWindow::dime() const { return m_WindowData.param.dimensions; }
	inline bool WWindow::isVsync() const { return m_WindowData.isVsync; }

	void* WWindow::getContextCreationAdr()
	{
		return (void*) m_WindowData.windowPtr;
	}

	void WWindow::setEventCallbackFn(const eventCallbackFn& fun) { m_WindowData.ecf = fun; }

	void WWindow::setVsync(bool state) {
		if (state)
		{
			glfwSwapInterval(1);
			ZOM_CLIENT_TRACE("VSync enabled");
		}
		else
		{
			glfwSwapInterval(0);
			ZOM_CLIENT_TRACE("VSync disabled");
		}
	}

	void WWindow::resize(const std::pair<int, int>& dims) {
		glfwSetWindowSize(m_WindowData.windowPtr, dims.first, dims.second);
		m_WindowData.param.dimensions = dims;
	}
	
	void WWindow::pollEvents()
	{
		glfwPollEvents();
	}

	void WWindow::init()
	{
		glfwInit();
		m_WindowData.windowPtr = glfwCreateWindow(m_WindowData.param.dimensions.first,
			                                      m_WindowData.param.dimensions.second,
			                                      m_WindowData.param.name.c_str(),
									              nullptr, nullptr);

		glfwSetWindowUserPointer(m_WindowData.windowPtr, (void*)&m_WindowData);

		Renderer::contextInitialize(this);

		setCallBacks();
	}

	void WWindow::terminate() const
	{
		ZOM_TRACE("Destroying \"{}\" Windows Window", name());

		glfwDestroyWindow(m_WindowData.windowPtr);
	}

	void WWindow::setCallBacks()
	{
		glfwSetWindowCloseCallback(m_WindowData.windowPtr, [](GLFWwindow* window)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent* event = new WindowCloseEvent;
		
			data->ecf(event);
		});

		glfwSetWindowSizeCallback(m_WindowData.windowPtr, [](GLFWwindow* window,int w, int h)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			WindowResizeEvent* event = new WindowResizeEvent(w, h);

			data->ecf(event);
		});

		glfwSetKeyCallback(m_WindowData.windowPtr, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);

			key = glfwToZOMKeyCode(key);

			switch (action)
			{
			case GLFW_PRESS: {
				KeyPressedEvent* event = new KeyPressedEvent(key, 0);
				data->ecf(event); }
			break;
			case GLFW_REPEAT: {
				KeyPressedEvent* event = new KeyPressedEvent(key, 1);
				data->ecf(event); }
			break;
			case GLFW_RELEASE: {
				KeyReleasedEvent* event = new KeyReleasedEvent(key);
				data->ecf(event); }
				break;
			}
		});

		glfwSetCursorPosCallback(m_WindowData.windowPtr, [](GLFWwindow* window, double x, double y)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent* event = new MouseMovedEvent(x, y);
			data->ecf(event);
		});

		glfwSetScrollCallback(m_WindowData.windowPtr, [](GLFWwindow* window, double x, double y)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			MouseScrollEvent* event = new MouseScrollEvent(x, y);
			data->ecf(event);
		});


		glfwSetMouseButtonCallback(m_WindowData.windowPtr, [](GLFWwindow* window, int button, int action, int mods)
		{
			WWindowData* data = (WWindowData*)glfwGetWindowUserPointer(window);
			
			button = glfwToZOMMouseCode(button);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent* event = new MouseButtonPressedEvent(button);
				data->ecf(event);
			}
			break;
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent* event = new MouseButtonReleasedEvent(button);
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