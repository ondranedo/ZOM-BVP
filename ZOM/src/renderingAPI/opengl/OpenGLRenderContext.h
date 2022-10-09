#pragma once

#include "renderer/RenderContext.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace ZOM {
	class ZOM_API OpenGLRenderContex : public RenderContext
	{
	public:
		OpenGLRenderContex();
		~OpenGLRenderContex();

		virtual void init(void* window_ptr) override;
		virtual void swap() const override;
		virtual void destroy() override;

	private:
		GLFWwindow* m_WindowPtr;
	};
}