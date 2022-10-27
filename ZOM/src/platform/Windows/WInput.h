#pragma once

#ifdef ZOM_WINDOWS

#include "Input.h"

namespace ZOM
{
	class WInput : public Input {
	protected:
		virtual bool isPressedImpl(const int zom_key_code) override;
	};
}

#endif
