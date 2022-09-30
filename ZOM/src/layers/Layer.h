#pragma once

#include "events/EventQueue.h"

namespace ZOM {

	class ZOM_API Layer {
	public:
		Layer(std::string name = "blank")
			:m_Name(name){}

		virtual ~Layer(){}

		virtual void onUpdate() = 0;
		virtual void onEvent(Event&) = 0;

		std::string getName() { return m_Name; }
	private:
		std::string m_Name;
	};
}

