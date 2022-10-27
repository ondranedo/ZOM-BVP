#pragma once

#include "codes/Mousecodes.h"

namespace ZOM
{
	class ZOM_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(const double x, const double y) : m_X(x), m_Y(y) {}
		virtual ~MouseMovedEvent() override {}

		std::pair<double, double> getCoords() const { return {m_X, m_Y}; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret = "";
			ret += "Mouse moved to: ";
			ret += std::to_string(static_cast<int>(m_X));
			ret += " ";
			ret += std::to_string(static_cast<int>(m_Y));
			return ret;
		}
#endif
		ZOM_EVENT_IMPLEMENTATION(MOUSE_MOVED)
	private:
		double m_X, m_Y;
	};

	class ZOM_API MouseButtonPressedEvent : public Event {
	public:
		MouseButtonPressedEvent(const int button) : m_Button(button) {}
		virtual ~MouseButtonPressedEvent() override {}

		int getButton() const { return m_Button; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret = "";
			ret += "Mouse button ";
			ret += zomMouseCodeToString(m_Button);
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
		MouseButtonReleasedEvent(const int button) : m_Button(button) {}
		virtual ~MouseButtonReleasedEvent() override {}

		int getButton() const { return m_Button; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret = "";
			ret += "Mouse button ";
			ret += zomMouseCodeToString(m_Button);
			ret += " released";
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(MOUSE_BUTTON_RELEASED)
	private:
		int m_Button;
	};

	class ZOM_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(const double x_offset, const double y_offst) : m_X(x_offset), m_Y(y_offst) {}
		virtual ~MouseScrollEvent() override {}

		std::pair<double, double> getOffset() const { return {m_X, m_Y}; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret;
			ret += "Mouse scroll with offset: ";
			ret += std::to_string(m_X);
			ret += " ";
			ret += std::to_string(m_Y);
			return ret;
		}
#endif

		ZOM_EVENT_IMPLEMENTATION(MOUSE_SCROLL)
	private:
		double m_X, m_Y;
	};
}
