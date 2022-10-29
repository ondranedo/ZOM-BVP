#pragma once

#include "Camera.h"

namespace ZOM
{
	class ZOM_API OrthographicCamera final : public Camera {
	public:
		OrthographicCamera(const cameraMovement& movement);
	};
}
