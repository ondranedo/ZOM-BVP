#pragma once

#include "window/window.h"
#include "RenderContext.h"
#include "RenderApplication.h"

#include "Shader.h"
#include "ShaderManager.h"

namespace ZOM {
	enum class ZOM_API RenderingAPI {
		OPENGL
	};
	std::string getStrRenderingApi(RenderingAPI rapi);

	class ZOM_API Renderer {
	public:
		static void init();
		static void release();

		static void preRunInit();

		static void clear();
		static void setBeforeInitRenderingApi(RenderingAPI api);

		static RenderingAPI getAPI();

		// Shaders
		static std::shared_ptr<Shader> getShader(const std::string& name);

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
		static std::unique_ptr<RenderContext> s_RenderContext;
		static std::unique_ptr<RenderApplication> s_RenderApplication;
		static ShaderManager s_ShaderMgr;
	};
}