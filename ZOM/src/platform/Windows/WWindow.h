#ifdef ZOM_WINDOWS

#pragma once
#include "Window.h"

#include <GLFW/glfw3.h>

namespace ZOM {
	struct ZOM_API WWindowData {
		WindowParam param;
		GLFWwindow* windowPtr;
		bool isVsync;
		eventCallbackFn ecf;

		WWindowData(const WindowParam& _param):
			param(_param),
			windowPtr(nullptr),
			isVsync(true),
			ecf([](Event&) { ZOM_ERROR("None event callback function!"); })
		{}
	};

	class ZOM_API WWindow : public Window {
	public:
		WWindow(const WindowParam& param);
		~WWindow();

		virtual inline std::string name() const override;
		virtual inline std::pair<int, int> dime() const override;
		virtual inline bool isVsync() const override;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) override;
		virtual void setVsync(bool state) override;
		virtual void resize(const std::pair<int, int>& dims) override;

		// Runs every frame
		virtual void update() override;

	private:
		void init();
		void terminate();
		void setCallBacks();

	private:
		WWindowData m_WindowData;
	};
}

#endif