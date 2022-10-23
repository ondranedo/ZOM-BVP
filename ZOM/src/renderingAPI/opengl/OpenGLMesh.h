#pragma once

#include "renderer/Mesh.h"

namespace ZOM {
	class OpenGLMesh : public Mesh {
	public:
		OpenGLMesh(const MeshCreationData& pm);
		size_t getIndexCount() const override;
		void bind() const override;
		void setUniform(const std::string& name, void* data) const override;

	};
}