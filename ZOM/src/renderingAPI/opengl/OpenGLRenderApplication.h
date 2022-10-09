#pragma once

#include "renderer/RendererPack.h"

namespace ZOM {

	class ZOM_API OpenGLRenderApplication : public RenderApplication
	{
	public:
		OpenGLRenderApplication();
		~OpenGLRenderApplication();
		void clear(const glm::vec4& color) override;
	};
}