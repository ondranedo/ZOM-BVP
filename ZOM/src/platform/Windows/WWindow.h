#ifdef ZOM_WINDOWS

#pragma once
#include "window/Window.h"


#include <GLFW/glfw3.h>

#include "events/KeyEvents.h"
#include "events/MouseEvents.h"
#include "events/WindowEvents.h"

#include "codes/Keycodes.h"
#include "codes/Mousecodes.h"

#include "renderer/Renderer.h"

namespace ZOM {
	struct ZOM_API wWindowData {
		GLFWwindow* m_WindowPtr;
		windowParam m_Param;
		bool m_IsVSync;
		eventCallbackFn m_Ecf;

		wWindowData(const windowParam& param):
			m_WindowPtr(nullptr),
			m_Param(param),
			m_IsVSync(true),
			m_Ecf([](Event*) { ZOM_ERROR("None event callback function!"); })
		{}
	};

	class ZOM_API WWindow final : public Window {
	public:
		WWindow(const windowParam& param);

		virtual inline std::string name() const override;
		virtual inline std::pair<int, int> dime() const override;
		virtual inline bool isVSync() const override;
		virtual inline void* getContextCreationAdr() override;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) override;
		virtual void setVSync(const bool state) override;
		virtual void setWindowParam(const windowParam& param) override;

		virtual void pollEvents() override;

		virtual void init() override;
		virtual void release() override;
private:
		void terminate();
		void setCallBacks();

	private:
		wWindowData m_WindowData;
	};
}

#endif