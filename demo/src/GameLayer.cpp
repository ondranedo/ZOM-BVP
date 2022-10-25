#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	std::shared_ptr<ZOM::Mesh> background = ZOM::Mesh::create(ZOM::MeshCreationData::background("mandelbrot"));

	if (ZOM::Input::isPressed(ZOM_KEY_Q)) m_Zoom -= 0.01;
	if (ZOM::Input::isPressed(ZOM_KEY_E)) m_Zoom += 0.01;
	if (ZOM::Input::isPressed(ZOM_KEY_W)) m_Position.y -= 0.02 / pow(m_Zoom,5);
	if (ZOM::Input::isPressed(ZOM_KEY_A)) m_Position.x += 0.02 / pow(m_Zoom,5);
	if (ZOM::Input::isPressed(ZOM_KEY_S)) m_Position.y += 0.02 / pow(m_Zoom,5);
	if (ZOM::Input::isPressed(ZOM_KEY_D)) m_Position.x -= 0.02 / pow(m_Zoom,5);

	glm::fvec2 dims = {640, 480};
	background->setUniform("resolution", &dims);
	background->setUniform("move_dir", &m_Position);
	background->setUniform("zoom", &m_Zoom);

	ZOM::Renderer::draw(background);

	ZOM::Renderer::endScene();
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
