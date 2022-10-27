#include "Input.h"

namespace ZOM
{
	std::unique_ptr<Input> Input::m_SInstance = create();
}
