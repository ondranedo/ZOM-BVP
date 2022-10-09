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
		s_RenderPack->contextInitialize(window);
	}

	void Renderer::renderLoop()
	{
		s_RenderPack->renderLoop();
	}


	void Renderer::begin()
	{
		s_RenderPack->begin();
	}

	void Renderer::end()
	{
		s_RenderPack->end();
	}

	RendererPack* Renderer::s_RenderPack;
	bool Renderer::s_Created;
}