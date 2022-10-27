#pragma once

namespace ZOM
{
	class OpenGLRenderApplication final: public RenderApplication {
	public:
		OpenGLRenderApplication();
		virtual ~OpenGLRenderApplication() override;
		virtual void clear(const glm::vec4& color) override;

		virtual void draw(const std::shared_ptr<Mesh>& mesh) override;
	};
}
