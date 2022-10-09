#pragma once

#include "RendererPack.h"

#include "window/window.h"

namespace ZOM {
	class ZOM_API Renderer {
	public:
		static void create(RenderingAPI api);
		static void terminate();
		
		// Context management
		static void contextInitialize(Window*);

		// Renderer commands
		static RenderApplication* getRenderApplication();
		static void renderLoop();

		// For scene
		static void beginScene();
		static void endScene();

	private:
		static RendererPack* s_RenderPack;
		static bool s_Created;
	};
}