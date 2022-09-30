#pragma once

#define ZOM_EVENT_IMPLEMENTATION(x)\
	static EventTypes getStaticType(){ return EventTypes::x; }\
	EventTypes type() override { return getStaticType(); }

namespace ZOM {
	enum class ZOM_API EventTypes {
		WINDOW_RESIZED, WINDOW_CLOSE,
		MOUSE_MOVED, MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_SCROLL,
		KEY_PRESSED, KEY_RELEASED
	};

	class ZOM_API Event {
	public:
		virtual ~Event() {}
		virtual EventTypes type() = 0;

#ifdef ZOM_DEBUG
		virtual std::string toString() = 0;
#else
		std::string toString() { return "event.toString(); Not a Debug profile!"; }
#endif

	protected:
		bool m_Handled = false;
	};
}