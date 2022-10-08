#pragma once

#include "renderer/RenderContext.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace ZOM {
	class ZOM_API OpengGLRenderContex : public RenderContext
	{
	public:
		OpengGLRenderContex(void* window_ptr);
		~OpengGLRenderContex();

		virtual void init() override;
		virtual void swap() override;
		virtual void destroy() override;

	private:
		GLFWwindow* m_WindowPtr;
	};
}