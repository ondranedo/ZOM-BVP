#pragma once

#include "RendererPack.h"


namespace ZOM {
	class ZOM_API Renderer {
	public:
		static void create(RenderingAPI api);
		static void terminate();

		static void contextInitialize(Window*);
		static void renderLoop();

		static void begin();
		static void end();

	private:
		static RendererPack* s_RenderPack;
		static bool s_Created;
	};
}