#pragma once

namespace ZOM {
	class ZOM_API WindowResizeEvent: public Event {
	public:
		WindowResizeEvent(int width, int height):
			m_Width(width), m_Height(height){}
		~WindowResizeEvent(){}

		std::pair<int, int> getDims() const { return { m_Width, m_Height }; }

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret = "";
			ret += "Window resized to: ";
			ret += std::to_string(m_Width);
			ret += " ";
			ret += std::to_string(m_Height);
			return ret;
		}
#endif
		ZOM_EVENT_IMPLEMENTATION(WINDOW_RESIZED);
	private:
		int m_Width, m_Height;
	};

	class ZOM_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {};
		~WindowCloseEvent(){};

#ifdef ZOM_DEBUG
		std::string toString() override
		{
			std::string ret = "";
			ret += "Window closed";
			return ret;
		}
#endif
		ZOM_EVENT_IMPLEMENTATION(WINDOW_CLOSE);
	};
}