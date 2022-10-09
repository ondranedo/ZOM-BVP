#include "Renderer.h"

#include "RendererPack.h"


namespace ZOM {
	
	void Renderer::create(RenderingAPI api)
	{
		if (!s_Created)
		{
			s_Created = true;
			s_RenderPack = new RendererPack(api);
		}
	}

	void Renderer::terminate()
	{
		if (s_Created)
		{
			s_Created = false;
			delete s_RenderPack;
		}
	}

	void Renderer::contextInitialize(Window* window)
	{
		if (s_Created)
			s_RenderPack->contextInitialize(window);
		else
			ZOM_ERROR("You have to create renderer in order to initialize context");
	}

	RenderApplication* Renderer::getRenderApplication()
	{
		if (s_Created)
			return s_RenderPack->getRenderApplication();
		else
			ZOM_ERROR("You have to create renderer in order to return render application");
	}

	void Renderer::renderLoop()
	{
		s_RenderPack->renderLoop();
	}


	void Renderer::beginScene()
	{
		s_RenderPack->beginScene();
	}

	void Renderer::endScene()
	{
		s_RenderPack->endScene();
	}

	RendererPack* Renderer::s_RenderPack;
	bool Renderer::s_Created = false;
}