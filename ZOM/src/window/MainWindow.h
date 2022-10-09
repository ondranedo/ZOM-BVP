#pragma once

#include "Window.h"

namespace ZOM {

	class ZOM_API EventQueue;

	class ZOM_API MainWindow {
	public:
		static void init();
		static void release();

		static void setBeforeInitWindowParam(const WindowParam& param);

		static void setEventQueue(EventQueue& event_queue);
		static void pollEvents();

		static Window* windowPtr();

	private:
		static Window* s_Window;
		static bool s_Created;
		static WindowParam s_WindowParam;
	};
}