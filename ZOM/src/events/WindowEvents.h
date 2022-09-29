#pragma once

namespace ZOM {
	class ZOM_API WindowResizeEvent: public Event {
	public:
		WindowResizeEvent(float width, float height):
			m_Width(width), m_Height(height){}
		~WindowResizeEvent(){}

		std::pair<float, float> getDims() const { return { m_Width, m_Height }; }

		std::string toString() override
		{
			std::string ret = "";
			ret += "Window resized to: ";
			ret += std::to_string(m_Width);
			ret += " ";
			ret += std::to_string(m_Height);
			return ret;
		}
		ZOM_EVENT_IMPLEMENTATION(WINDOW_RESIZED);
	private:
		float m_Width, m_Height;
	};

	class ZOM_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {};
		~WindowCloseEvent(){};
		std::string toString() override
		{
			std::string ret = "";
			ret += "Window closed";
			return ret;
		}
		ZOM_EVENT_IMPLEMENTATION(WINDOW_CLOSE);
	};
}