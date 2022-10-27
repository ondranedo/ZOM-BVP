#pragma once

#include "codes/Keycodes.h"

namespace ZOM
{
	class ZOM_API KeyPressedEvent : public Event {
	public:
		KeyPressedEvent(const int keycode,const int repeat_count)
			: m_KeyCode(keycode),
			  m_RepeatCount(repeat_count) {}

		virtual ~KeyPressedEvent() override = default;

		int getKeyCode() const { return m_KeyCode; }
		int getRepeatCount() const { return m_RepeatCount; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret = "";
			ret += "Key ";
			ret += zomKeyCodeToString(m_KeyCode);
			ret += " pressed ";
			if(m_RepeatCount != 0) ret += "[repeat]";
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
		KeyReleasedEvent(const int keycode) : m_KeyCode(keycode) {}

		virtual ~KeyReleasedEvent() override = default;

		int getKeyCode() const { return m_KeyCode; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret = "";
			ret += "Key ";
			ret += zomKeyCodeToString(m_KeyCode);
			ret += " released";
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(KEY_RELEASED);
	private:
		int m_KeyCode;
	};
}
