#pragma once

#include "Window.h"

namespace ZOM {
	class ZOM_API ZOMGameEngine {
	public:
		ZOMGameEngine();
		virtual ~ZOMGameEngine();

		void run();

	private:
		void onFrame();
		void onEvent(Event& event);

	private:
		bool m_Running;
		Window* m_Window;
	};
}