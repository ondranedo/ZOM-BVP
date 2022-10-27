#pragma once

#include "Window.h"

namespace ZOM
{
	class ZOM_API EventQueue;

	class ZOM_API MainWindow {
	public:
		static void init();
		static void release();

		static void setBeforeInitWindowParam(const windowParam& param);

		static glm::vec2 getDims();

		static void setEventQueue(EventQueue& event_queue);
		static void pollEvents();

		static void* getContextCreationAdr();

	private:
		static std::unique_ptr<Window> m_SWindow;
		static bool m_SCreated;
		static windowParam m_SWindowParam;
	};
}
