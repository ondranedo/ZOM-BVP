#pragma once

#include "events/Event.h"

namespace ZOM {
	class ZOM_API Input {
	public:
		void init();
		static bool isPressed(int zom_key_code) { return s_Instance->isPressedImpl(zom_key_code); }

	protected:
		virtual bool isPressedImpl(int zom_key_code) = 0;

		static std::unique_ptr<Input> create();

	private:
		static std::unique_ptr<Input> s_Instance;
	};
};