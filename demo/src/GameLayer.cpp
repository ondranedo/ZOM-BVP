#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	const std::shared_ptr<ZOM::Mesh> background = ZOM::Mesh::create(ZOM::meshCreationData::background("mandelbrot"));
	const std::shared_ptr<ZOM::Mesh> tri = ZOM::Mesh::create(ZOM::meshCreationData::triangle("basic"));

	if (ZOM::Input::isPressed(ZOM_KEY_Q)) m_Zoom -= 0.01f;
	if (ZOM::Input::isPressed(ZOM_KEY_E)) m_Zoom += 0.01f;
	if (ZOM::Input::isPressed(ZOM_KEY_W)) m_Position.y -= 0.02f / static_cast<float>(pow(m_Zoom,5));
	if (ZOM::Input::isPressed(ZOM_KEY_A)) m_Position.x += 0.02f / static_cast<float>(pow(m_Zoom,5));
	if (ZOM::Input::isPressed(ZOM_KEY_S)) m_Position.y += 0.02f / static_cast<float>(pow(m_Zoom,5));
	if (ZOM::Input::isPressed(ZOM_KEY_D)) m_Position.x -= 0.02f / static_cast<float>(pow(m_Zoom,5));
	if (ZOM::Input::isPressed(ZOM_KEY_LEFT)) m_Pos.x -= 0.01f;
	if (ZOM::Input::isPressed(ZOM_KEY_RIGHT)) m_Pos.x += 0.01f;

	glm::fvec2 dims = {640, 480};
	background->setUniform("resolution", &dims);
	background->setUniform("move_dir", &m_Position);
	background->setUniform("zoom", &m_Zoom);
	glm::fvec4 color = {0.1f,0.8f,0.5f,1.0f};
	tri->setUniform("color", &color);
	tri->setUniform("pos", &m_Pos);
	ZOM::Renderer::draw(background);
	ZOM::Renderer::draw(tri);

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
