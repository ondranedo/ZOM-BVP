#pragma once

#include "renderer/Mesh.h"

namespace ZOM
{
	class OpenGLMesh final : public Mesh {
	public:
		OpenGLMesh(const meshCreationData& pm);
		virtual size_t getIndexCount() const override;
		virtual void bind() const override;
		virtual void setUniform(const std::string& name, void* data) const override;

	};
}
