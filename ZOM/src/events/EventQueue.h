#pragma once

#include "EventQueue.h"

namespace ZOM {
	class ZOM_API EventQueue {
	public:
		EventQueue();
		void addEvent(Event* heap_event_addr);
		void clearAll();

		Event* getTopEvent();
		size_t getEventCount() const;
		eventCallbackFn getEventCallBack();
		
	private:
		std::queue<Event*> m_EventQueue;
	};
}
