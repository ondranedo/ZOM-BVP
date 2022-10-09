#pragma once

#include "RenderApplication.h"
#include "RenderContext.h"

#include "window/Window.h"

namespace ZOM {
	enum class ZOM_API RenderingAPI {
		OPENGL
	};

	class ZOM_API RendererPack {
	public:
		RendererPack(RenderingAPI api);	
		~RendererPack();

		void renderLoop();
		void contextInitialize(Window* window);
		RenderApplication* getRenderApplication();

		void beginScene();
		void endScene();
		void clear(const glm::vec4& color);

		inline RenderContext* getContext();
		inline RenderingAPI getRenderingAPI();

	private:
		RenderingAPI m_RenderAPI;

		RenderContext* m_Context;
		RenderApplication* m_RenderApplication;
	};
}