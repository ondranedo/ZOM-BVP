#ifdef ZOM_WINDOWS

#pragma once
#include "Window.h"


#include <GLFW/glfw3.h>

#include "events/KeyEvents.h"
#include "events/MouseEvents.h"
#include "events/WindowEvents.h"

#include "codes/Keycodes.h"
#include "codes/Mousecodes.h"

#include "renderer/Renderer.h"

namespace ZOM {
	struct ZOM_API WWindowData {
		GLFWwindow* windowPtr;
		WindowParam param;
		bool isVsync;
		eventCallbackFn ecf;

		WWindowData(const WindowParam& _param):
			param(_param),
			windowPtr(nullptr),
			isVsync(true),
			ecf([](Event*) { ZOM_ERROR("None event callback function!"); })
		{}
	};

	class ZOM_API WWindow : public Window {
	public:
		WWindow(const WindowParam& param);
		~WWindow();

		virtual inline std::string name() const override;
		virtual inline std::pair<int, int> dime() const override;
		virtual inline bool isVsync() const override;
		virtual inline void* getContextCreationAdr() override;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) override;
		virtual void setVsync(bool state) override;
		virtual void resize(const std::pair<int, int>& dims) override;

		virtual void pollEvents() override;
		virtual void init() override;
private:
		void terminate() const;
		void setCallBacks();

	private:
		WWindowData m_WindowData;
	};
}

#endif