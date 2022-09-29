#ifdef ZOM_WINDOWS

#pragma once
#include "Window.h"

#include <GLFW/glfw3.h>

namespace ZOM {
	class ZOM_API WWindow : public Window {
	public:
		WWindow(const WindowParam& param);
		~WWindow();
		int getWidth() const override;
		int getHeight() const override;
		bool isVsync() const override;
		std::string getName() const override;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) override;
		virtual void setVsync(bool state) override;
		virtual void resize(const std::pair<int, int>& dims) override;

		virtual void update() override;
	private:
		void init();
		void setCallBacks();

	private:
		WindowParam m_WindowParam;
		GLFWwindow* m_WindowPtr;
	};
}

#endif