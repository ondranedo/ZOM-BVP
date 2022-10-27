#ifdef ZOM_WINDOWS

#include "WWindow.h"

namespace ZOM
{
	WWindow::WWindow(const windowParam& param)
		: m_WindowData(wWindowData(param))
	{
		ZOM_TRACE("Windows Window \"{}\" has been created", m_WindowData.m_Param.m_Name);
	}


	inline std::string WWindow::name() const { return m_WindowData.m_Param.m_Name; }
	inline std::pair<int, int> WWindow::dime() const { return m_WindowData.m_Param.m_Dimensions; }
	inline bool WWindow::isVSync() const { return m_WindowData.m_IsVSync; }

	void* WWindow::getContextCreationAdr()
	{
		return m_WindowData.m_WindowPtr;
	}

	void WWindow::setEventCallbackFn(const eventCallbackFn& fun) { m_WindowData.m_Ecf = fun; }

	void WWindow::setVSync(const bool state)
	{
		if(state) {
			glfwSwapInterval(1);
			ZOM_CLIENT_TRACE("VSync enabled");
		}
		else {
			glfwSwapInterval(0);
			ZOM_CLIENT_TRACE("VSync disabled");
		}
	}

	void WWindow::setWindowParam(const windowParam& param)
	{
		glfwSetWindowSize(m_WindowData.m_WindowPtr, param.m_Dimensions.first, param.m_Dimensions.second);
		glfwSetWindowTitle(m_WindowData.m_WindowPtr, param.m_Name.c_str());

		m_WindowData.m_Param = param;
	}

	void WWindow::pollEvents()
	{
		glfwPollEvents();
	}

	void WWindow::init()
	{
		glfwInit();
		m_WindowData.m_WindowPtr = glfwCreateWindow(m_WindowData.m_Param.m_Dimensions.first,
		                                            m_WindowData.m_Param.m_Dimensions.second,
		                                            m_WindowData.m_Param.m_Name.c_str(),
		                                            nullptr, nullptr);

		glfwSetWindowUserPointer(m_WindowData.m_WindowPtr, &m_WindowData);

		Renderer::contextInitialize(this);

		setCallBacks();
	}

	void WWindow::release()
	{
		terminate();
	}

	void WWindow::terminate()
	{
		ZOM_TRACE("Destroying \"{}\" Windows Window", name());

		glfwDestroyWindow(m_WindowData.m_WindowPtr);

		m_WindowData.m_WindowPtr = nullptr;

		glfwTerminate();
	}

	void WWindow::setCallBacks()
	{
		glfwSetWindowCloseCallback(m_WindowData.m_WindowPtr, [](GLFWwindow* window)->void{
			const auto data  = static_cast<wWindowData*>(glfwGetWindowUserPointer(window));
			const auto event = new WindowCloseEvent;

			data->m_Ecf(event);
		});

		glfwSetWindowSizeCallback(m_WindowData.m_WindowPtr, [](GLFWwindow* window, const int w, const int h)->void{
			const auto data  = static_cast<wWindowData*>(glfwGetWindowUserPointer(window));
			const auto event = new WindowResizeEvent(w, h);

			data->m_Ecf(event);
		});

		glfwSetKeyCallback(m_WindowData.m_WindowPtr,
		                   [](GLFWwindow* window, int key, int, const int action, int mods)->void{
			                   const auto data = static_cast<wWindowData*>(glfwGetWindowUserPointer(window));

			                   key = glfwToZOMKeyCode(key);

			                   switch(action) {
				                   case GLFW_PRESS:
				                   {
					                   const auto event = new KeyPressedEvent(key, 0);
					                   data->m_Ecf(event);
				                   }
				                   break;
				                   case GLFW_REPEAT:
				                   {
					                   const auto event = new KeyPressedEvent(key, 1);
					                   data->m_Ecf(event);
				                   }
				                   break;
				                   case GLFW_RELEASE:
				                   {
					                   const auto event = new KeyReleasedEvent(key);
					                   data->m_Ecf(event);
				                   }
				                   break;
			                   }
		                   });

		glfwSetCursorPosCallback(m_WindowData.m_WindowPtr, [](GLFWwindow* window, const double x, const double y)->void{
			const auto data  = static_cast<wWindowData*>(glfwGetWindowUserPointer(window));
			const auto event = new MouseMovedEvent(x, y);
			data->m_Ecf(event);
		});

		glfwSetScrollCallback(m_WindowData.m_WindowPtr, [](GLFWwindow* window, const double x, const double y)->void{
			const auto data  = static_cast<wWindowData*>(glfwGetWindowUserPointer(window));
			const auto event = new MouseScrollEvent(x, y);
			data->m_Ecf(event);
		});


		glfwSetMouseButtonCallback(m_WindowData.m_WindowPtr,
		                           [](GLFWwindow* window, int button, const int action, int mods)->void{
			                           const auto data = static_cast<wWindowData*>(glfwGetWindowUserPointer(window));

			                           button = glfwToZOMMouseCode(button);

			                           switch(action) {
				                           case GLFW_PRESS:
				                           {
					                           const auto event = new MouseButtonPressedEvent(button);
					                           data->m_Ecf(event);
				                           }
				                           break;
				                           case GLFW_RELEASE:
				                           {
					                           const auto event = new MouseButtonReleasedEvent(button);
					                           data->m_Ecf(event);
				                           }
				                           break;
			                           }
		                           });
	}

	std::unique_ptr<Window> Window::createWindow(const windowParam& param)
	{
		return std::make_unique<WWindow>(param);
	}
}

#endif
