#pragma once

namespace ZOM {

	class OpenGLRenderApplication : public RenderApplication
	{
	public:
		OpenGLRenderApplication();
		~OpenGLRenderApplication();
		void clear(const glm::vec4& color) override;
	};
}