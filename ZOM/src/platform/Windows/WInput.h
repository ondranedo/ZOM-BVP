#pragma once 

#ifdef ZOM_WINDOWS

#include "Input.h"

namespace ZOM {
	class WInput : public Input {

	protected:
		bool isPressedImpl(int zom_key_code) override;
	};
}

#endif