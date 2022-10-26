#pragma once

#include "codes/Keycodes.h"

namespace ZOM {
	class ZOM_API KeyPressedEvent : public Event {
	public:
		KeyPressedEvent(int keycode, int repeatcount):
			m_KeyCode(keycode),
			m_RepeatCount(repeatcount){}
		~KeyPressedEvent(){} 

		int getKeyCode() const { return m_KeyCode; }
		int getRepeatcount() const { return m_RepeatCount; }

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret = "";
			ret += "Key ";
			ret += ZOMKeyCodeToString(m_KeyCode);
			ret += " pressed ";
			if(m_RepeatCount != 0)
				ret += "[repeat]";
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(KEY_PRESSED);
	private:
		int m_KeyCode;
		int m_RepeatCount;
	};

	class ZOM_API KeyReleasedEvent : public Event {
	public:
		KeyReleasedEvent(int keycode) :
			m_KeyCode(keycode){}
		~KeyReleasedEvent() {}

		int getKeyCode() const { return m_KeyCode; }

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret = "";
			ret += "Key ";
			ret += ZOMKeyCodeToString(m_KeyCode);
			ret += " released";
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(KEY_RELEASED);
	private:
		int m_KeyCode;
	};
}