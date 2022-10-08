#pragma once

#include "RenderContext.h"

namespace ZOM {
	enum class ZOM_API RenderingAPI {
		OPENGL
	};
class ZOM_API Renderer {	
public:
	virtual ~Renderer() {};

	static inline RenderingAPI getRenderingAPI() { return  m_RenderAPI; }

private:
	static RenderingAPI m_RenderAPI;

};
}