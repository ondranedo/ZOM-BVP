#pragma once

#include "events/Event.h"

namespace ZOM {
	class ZOM_API Input {
	public:
		static bool isPressed(int zom_key_code) { return s_Instance->isPressedImpl(zom_key_code); }
		~Input();

	protected:
		virtual bool isPressedImpl(int zom_key_code) = 0;
		
		static Input* create();

	private:
		static Input* s_Instance;
	};
};