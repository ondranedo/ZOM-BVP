#include "EventQueue.h"

namespace ZOM {

	EventQueue::EventQueue()
	{
	}

	void EventQueue::addEvent(Event* heap_event_addr)
	{
		m_EventQueue.push(heap_event_addr);
	}

	void EventQueue::clearAll()
	{
		for (size_t i = 0; i < m_EventQueue.size(); i++)
		{
			Event* event = getTopEvent();

			delete event;
		}
	}

	Event* EventQueue::getTopEvent()
	{
		Event* event = m_EventQueue.front();
		m_EventQueue.pop();
		return event;
	}

	size_t EventQueue::getEventCount() const
	{
		return m_EventQueue.size();
	}

	eventCallbackFn EventQueue::getEventCallBack()
	{
		return ZOM_BIND_CLASS_FUNC(EventQueue::addEvent);
	}

}