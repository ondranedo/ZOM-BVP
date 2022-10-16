#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	 
	std::shared_ptr<ZOM::VertexBuffer>vb = ZOM::VertexBuffer::create(m_Mesh.getVertex(), m_Mesh.getVertexSize());
	std::shared_ptr<ZOM::IndexBuffer>ib = ZOM::IndexBuffer::create(m_Mesh.getIndex(), m_Mesh.getIndexSize());
	std::shared_ptr<ZOM::VertexArray>va = ZOM::VertexArray::create();
	
	{
		ZOM::VertexBufferLayout vbl;

		vbl.add(ZOM::InShaderDataType::VecF2, "test");

		vb->setLayout(vbl);

		va->setIndex(ib);
		va->setVertex(vb);

		va->unbind();
		ib->unbind();
	}

	m_Mesh.onUpdate();

	if (ZOM::Input::isPressed(ZOM_KEY_W)) m_Mesh.moveTop();
	if (ZOM::Input::isPressed(ZOM_KEY_A)) m_Mesh.moveLeft(); 
	if (ZOM::Input::isPressed(ZOM_KEY_S)) m_Mesh.moveBottom(); 
	if (ZOM::Input::isPressed(ZOM_KEY_D)) m_Mesh.moveRight(); 
	if (ZOM::Input::isPressed(ZOM_KEY_R)) m_Mesh.moveReset(); 
	if (ZOM::Input::isPressed(ZOM_KEY_KP_ADD)) m_Mesh.speedUp(); 
	if (ZOM::Input::isPressed(ZOM_KEY_KP_SUBTRACT)) m_Mesh.speedDown(); 

	//////////////////


	ZOM::Renderer::beginScene();

	shader->bind();

	va->bind();

	glDrawElements(GL_TRIANGLES, m_Mesh.g_IndexCount, GL_UNSIGNED_INT, nullptr);

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
	shader = ZOM::Shader::create();
	shader->compile();
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
	m_Mesh.moveStop();

	return true;
}
