#pragma once

namespace ZOM
{
#include "events/Event.h"

	struct ZOM_API windowParam {
		std::string m_Name;
		std::pair<int, int> m_Dimensions;

		windowParam()
			: m_Name("blank"),
			  m_Dimensions({640, 480}) {}
	};

	class ZOM_API Window {
	public:
		virtual ~Window() {};

		virtual inline std::string name() const = 0;
		virtual inline std::pair<int, int> dime() const = 0;
		virtual inline bool isVSync() const = 0;
		virtual inline void* getContextCreationAdr() = 0;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) = 0;
		virtual void setVSync(const bool state) = 0;
		virtual void setWindowParam(const windowParam& param) = 0;

		virtual void pollEvents() = 0;

		virtual void init() = 0;
		virtual void release() = 0;

		static std::unique_ptr<Window> createWindow(const windowParam& param);
	};
}
