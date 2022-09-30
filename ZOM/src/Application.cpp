#include "Application.h"

#include "events/Event.h"
#include "events/MouseEvents.h"
#include "events/KeyEvents.h"

namespace ZOM {
	ZOMGameEngine::ZOMGameEngine():
		m_Running(false),
		m_Window(nullptr)
	{
		ZOM_ASSERT(Log::init(),"Can't init. logger");

		m_Window = Window::createWindow();
		//ZOM_INFO("Window \"{}\" has been created", m_Window->name());

#ifdef ZOM_DEBUG
    ZOM_CLIENT_ERROR("Debug build");
#elif  ZOM_RELEASE
    ZOM_CLIENT_WARNING("Release build");
#elif ZOM_DISTRIBUTE
    ZOM_CLIENT_INFO("Distribute build");
#endif

		m_Window->setEventCallbackFn(std::bind(&ZOMGameEngine::onEvent, this, std::placeholders::_1)); 
	}

	void ZOMGameEngine::run()
	{
		m_Running = true;

		ZOM_TRACE("Starting main loop");

		while (m_Running)
			onFrame();

		ZOM_TRACE("Ending main loop");
	}

	void ZOMGameEngine::onFrame()
	{


		m_Window->update();
	}

	void ZOMGameEngine::onEvent(Event& event)
	{
		ZOM_TRACE(event.toString());

		if (event.type() == EventTypes::WINDOW_CLOSE)
		{
			ZOM_WARNING("Window close event happend");
			ZOM_WARNING(event.toString());
			m_Running = false;
		}
	}

	ZOMGameEngine::~ZOMGameEngine()
	{
		ZOM_WARNING("Destroying engine");

		delete m_Window;
	}
}

