#include "OpenGLRenderContext.h"

#include <glad/gl.h>

namespace ZOM {

	OpengGLRenderContex::OpengGLRenderContex()
	{
		ZOM_TRACE("New OpenGL context created");
	}

	OpengGLRenderContex::~OpengGLRenderContex()
	{
		destroy();
	}

	void OpengGLRenderContex::init(ZOMProcFun procAddres)
	{
		int error;

		ZOM_ASSERT(error = gladLoadGL((GLADloadfunc)procAddres), "glad error[{}] loaded unsuccesfuly", error);
	}

	void OpengGLRenderContex::destroy()
	{
		ZOM_WARNING("OpenGL context destroyed");
	}
}
