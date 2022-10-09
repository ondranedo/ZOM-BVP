#pragma once

#include "RenderApplication.h"
#include "RenderContext.h"

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

		void begin();
		void end();

		inline RenderContext* getContext();
		inline RenderingAPI getRenderingAPI();
	private:
		RenderingAPI m_RenderAPI;
		RenderContext* m_Context;
		RenderApplication* m_RenderApplication;
	};
}