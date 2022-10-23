#pragma once

#include "RenderContext.h"
#include "Mesh.h"

namespace ZOM {
class ZOM_API RenderApplication {	
public:
	virtual ~RenderApplication() {};

	virtual void clear(const glm::vec4& clear_color = { 1.0f,0.0f,1.0f,1.0f }) = 0;
	virtual void draw(const std::shared_ptr<Mesh>& mesh) = 0;
};
}