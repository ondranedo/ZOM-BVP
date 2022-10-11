#pragma once

#include "window/window.h"
#include "RenderContext.h"
#include "RenderApplication.h"

namespace ZOM {
	enum class ZOM_API RenderingAPI {
		OPENGL
	};

	class ZOM_API Renderer {
	public:
		static void init();
		static void release();

		static RenderApplication* getRenderApplication();
		static void setBeforeInitRenderingApi(RenderingAPI api);

		static RenderingAPI getAPI();

		// Context management
		static void contextInitialize(Window* window);

		// Render commands
		static void renderLoop();
		
		// Scene methods
		static void beginScene();
		static void endScene();

	private:
		static bool s_Created;
		static RenderingAPI s_RendreringApi;
		static RenderContext* s_RenderContext;
		static RenderApplication* s_RenderApplication;
	};
}