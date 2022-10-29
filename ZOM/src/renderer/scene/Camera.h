#pragma once

#include "CameraMovement.h"

namespace ZOM
{
	class ZOM_API Camera {
	public:
		const glm::mat4& getViewProjection() const;

		static std::shared_ptr<Camera> createOrthographicCamera(const cameraMovement& movement);

		//TODO:
		//	- moving camera
		//  - adding every mesh to the scene
		//	- adding camera to the scene
		//  - adding model projection to the mesh
		//  - adding scene projection

	protected:
		glm::mat4 m_ViewProj = glm::mat4();
		cameraMovement m_Movement = cameraMovement();
		float m_Speed = 0.01;
	};
}
