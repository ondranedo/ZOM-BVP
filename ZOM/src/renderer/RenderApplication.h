#pragma once

#include "RenderContext.h"

namespace ZOM {
class ZOM_API RenderApplication {	
public:
	virtual ~RenderApplication() {};

	virtual void clear(const glm::vec4& clear_color = { 1.0f,0.0f,1.0f,1.0f }) = 0;
};
}