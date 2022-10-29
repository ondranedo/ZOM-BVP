#include "Camera.h"
#include "OrthographicCamera.h"

namespace  ZOM
{
	const glm::mat4& ZOM::Camera::getViewProjection() const
	{
		return m_ViewProj;
	}

	std::shared_ptr<Camera> Camera::createOrthographicCamera(const cameraMovement& movement)
	{
		return std::make_shared<OrthographicCamera>(movement);
	}
}
