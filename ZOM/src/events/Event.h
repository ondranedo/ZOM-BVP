#pragma once

#define ZOM_EVENT_IMPLEMENTATION(x)\
	static eventTypes getStaticType(){ return eventTypes::x; }\
	eventTypes type() override { return getStaticType(); }

namespace ZOM
{
	enum class ZOM_API eventTypes {
		WINDOW_RESIZED, WINDOW_CLOSE,
		MOUSE_MOVED, MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_SCROLL,
		KEY_PRESSED, KEY_RELEASED
	};

	class ZOM_API Event {
	public:
		virtual ~Event() {}
		virtual eventTypes type() = 0;
		bool isHandled() const { return m_Handled; }
		void handled() { m_Handled = true; }

#ifdef ZOM_DEBUG
		virtual std::string toString() = 0;
#else
		std::string toString() { return "event.toString(); Not a Debug profile!"; }
#endif

	protected:
		bool m_Handled = false;
	};

	using eventCallbackFn = std::function<void(Event*)>;

	class ZOM_API EventDispatcher {
	public:
		EventDispatcher(Event& event): m_Event(event) {}

		template<class T>
		void dispatchEvent(const std::function<bool(T&)>& fun)
		{
			if(T::getStaticType() == m_Event.type())
				if(!m_Event.isHandled())
					if(fun(static_cast<T&>(m_Event))) m_Event.handled();
		}

	private:
		Event& m_Event;
	};
}
