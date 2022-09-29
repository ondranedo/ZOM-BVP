#include "Application.h"

#include "events/Event.h"
#include "events/MouseEvents.h"

namespace ZOM {
	ZOMGameEngine::ZOMGameEngine():
		m_Running(false),
		m_Window(nullptr)
	{
		ZOM_ASSERT(Log::init(),"Can't init. logger");

		m_Window = Window::createWindow();
		m_Window->setEventCallbackFn(std::bind(&ZOMGameEngine::onEvent, this, std::placeholders::_1));
	}

	void ZOMGameEngine::run()
	{
		m_Running = true;

		ZOM_TRACE("Starting main loop");

		while (m_Running)
		{
			onFrame();
		}
	}

	void ZOMGameEngine::onFrame()
	{
		m_Window->update();
	}

	void ZOMGameEngine::onEvent(Event& event)
	{
		ZOM_TRACE("Event occured!");
	}

	ZOMGameEngine::~ZOMGameEngine()
	{
		delete m_Window;
	}
}

