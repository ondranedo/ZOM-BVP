#pragma once

#include "codes/Mousecodes.h"

namespace ZOM {
	class ZOM_API MouseMovedEvent: public Event {
	public:
		MouseMovedEvent(double x, double y) : m_X(x), m_Y(y) {};
		~MouseMovedEvent() {};
		
		std::pair<double, double> getCoords() const { return { m_X, m_Y }; }

#ifdef ZOM_DEBUG	
		std::string toString() override
		{
			std::string ret = "";
			ret += "Mouse moved to: ";
			ret += std::to_string((int)m_X);
			ret += " ";
			ret += std::to_string((int)m_Y);
			return ret;
		}
#endif
		ZOM_EVENT_IMPLEMENTATION(MOUSE_MOVED);
	private:
		double m_X, m_Y;
	};

	class ZOM_API MouseButtonPressedEvent: public Event {
	public:
		MouseButtonPressedEvent(int button) : m_Button(button) {};
		~MouseButtonPressedEvent(){}

		int getButton() const { return m_Button; }

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret = "";
			ret += "Mouse button ";
			ret += ZOMMouseCodeToString(m_Button);
			ret += " pressed";
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(MOUSE_BUTTON_PRESSED);
	private:
		int m_Button;
	};

	class ZOM_API MouseButtonReleasedEvent : public Event {
	public:
		MouseButtonReleasedEvent(int button) : m_Button(button) {};
		~MouseButtonReleasedEvent() {}

		int getButton() const { return m_Button; }

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret = "";
			ret += "Mouse button ";
			ret += ZOMMouseCodeToString(m_Button);
			ret += " released";
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(MOUSE_BUTTON_RELEASED);
	private:
		int m_Button;
	};

	class ZOM_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(double x_offset, double y_offst) : m_X(x_offset), m_Y(y_offst) {};
		~MouseScrollEvent(){}

		std::pair<double, double> getOffset() const { return { m_X, m_Y }; }

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret;
			ret += "Mouse scroll with offset: ";
			ret += std::to_string(m_X);
			ret += " ";
			ret += std::to_string(m_Y);
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(MOUSE_SCROLL);
	private:
		double m_X, m_Y;
	};
}