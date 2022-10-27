#pragma once

namespace ZOM
{
	class ZOM_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(const int width, const int height): m_Width(width), m_Height(height) {}

		virtual ~WindowResizeEvent() override = default;

		std::pair<int, int> getDims() const { return {m_Width, m_Height}; }

#ifdef ZOM_DEBUG
		virtual std::string toString() override
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
		virtual ~WindowCloseEvent() override = default;

#ifdef ZOM_DEBUG
		virtual std::string toString() override
		{
			std::string ret = "";
			ret += "Window closed";
			return ret;
		}
#endif
		ZOM_EVENT_IMPLEMENTATION(WINDOW_CLOSE);
	};
}
