#pragma once

#define ZOM_EVENT_IMPLEMENTATION(x)\
	static EventTypes getStaticType(){ return EventTypes::##x; }\
	EventTypes getType() override { return getStaticType(); }\
	virtual std::string getStringType() override { return #x; }

namespace ZOM {
	enum class ZOM_API EventTypes {
		WINDOW_RESIZED, WINDOW_CLOSE,
		MOUSE_MOVED, MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_SCROLL,
		KEY_PRESSED, KEY_RELEASED
	};

	class ZOM_API Event {
	public:
		virtual ~Event() {}
		virtual std::string getStringType() = 0;
		virtual EventTypes getType() = 0;
		virtual std::string toString() = 0;

	protected:
		bool m_Handled = false;
	};
}