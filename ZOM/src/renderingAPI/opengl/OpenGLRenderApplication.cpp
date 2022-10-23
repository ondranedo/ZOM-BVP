#include "OpenGLRenderApplication.h"

namespace ZOM {

	OpenGLRenderApplication::OpenGLRenderApplication()
	{
		ZOM_TRACE("OpenGL render application created");
	}

	OpenGLRenderApplication::~OpenGLRenderApplication()
	{
		ZOM_TRACE("OpenGL render application destroyed");
	}

	void OpenGLRenderApplication::clear(const glm::vec4& color)
	{
		ZOM_FUNCTION_TIMER();
		ZOM_GL_CALL(glClearColor(
				(GLfloat)color.r,
				(GLfloat)color.g,
				(GLfloat)color.b,
				(GLfloat)color.a
			));
		ZOM_GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}
	void OpenGLRenderApplication::draw(const std::shared_ptr<Mesh>& mesh)
	{
		mesh->bind();
		ZOM_GL_CALL(glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, nullptr));
	}
}

