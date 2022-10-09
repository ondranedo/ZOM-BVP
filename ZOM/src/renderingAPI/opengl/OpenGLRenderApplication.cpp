#include "OpenGLRenderApplication.h"

namespace ZOM {
	void OpenGLRenderApplication::clear(const glm::vec4& color)
	{
	//	ZOM_GL_CALL(glClearColor({ color.r,color.g,color.b,color.a}));
		ZOM_GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}
}

