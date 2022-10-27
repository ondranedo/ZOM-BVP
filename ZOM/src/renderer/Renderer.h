#pragma once

#include "window/window.h"
#include "RenderContext.h"
#include "RenderApplication.h"

#include "Shader.h"
#include "ShaderManager.h"
#include "Mesh.h"

namespace ZOM
{
	enum class ZOM_API renderingAPI {
		opengl
	};

	std::string getStrRenderingApi(renderingAPI api);

	class ZOM_API Renderer {
	public:
		static void init();
		static void release();

		static void preRunInit();
		static void setBeforeInitRenderingApi(renderingAPI api);

		static renderingAPI getAPI();


		// Shaders
		static std::shared_ptr<Shader> getShader(const std::string& name);

		// Context management
		static void contextInitialize(Window* window);

		// Render commands
		static void renderLoop();
		static void clear();
		static void draw(const std::shared_ptr<Mesh>& mesh);

		// Scene methods
		static void beginScene();
		static void endScene();

	private:
		static bool m_SCreated;
		static renderingAPI m_SRenderingApi;
		static std::unique_ptr<RenderContext> m_SRenderContext;
		static std::unique_ptr<RenderApplication> m_SRenderApplication;
		static ShaderManager m_SShaderMgr;
	};
}
