#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	std::shared_ptr<ZOM::Mesh> background = ZOM::Mesh::create(ZOM::MeshCreationData::background("mandelbrot"));

	glm::fvec2 dims = {640, 480};
	background->setUniform("resolution", &dims);
	background->setUniform("time", &m_Time);

	ZOM::Renderer::draw(background);

	ZOM::Renderer::endScene();
	m_Time += 0.004 * m_Time;
}


void GameLayer::onEvent(ZOM::Event& event)
{
	ZOM::EventDispatcher d(event);

	d.dispatchEvent<ZOM::WindowCloseEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onCloseEvent));

	d.dispatchEvent<ZOM::KeyPressedEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onKey));

	d.dispatchEvent<ZOM::KeyReleasedEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onKeyRelease));
}

void GameLayer::onCreate()
{

}

bool GameLayer::onCloseEvent(ZOM::WindowCloseEvent& wce)
{
	ZOM::Engine::close();

	return true;
}

bool GameLayer::onKey(ZOM::KeyPressedEvent& kpe)
{
	return true;
}

bool GameLayer::onKeyRelease(ZOM::KeyReleasedEvent& kpe)
{
	return true;
}
