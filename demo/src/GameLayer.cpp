#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	 
	std::shared_ptr<ZOM::VertexBuffer>vb = ZOM::VertexBuffer::create(m_Triangle.getVertex(), m_Triangle.getVertexSize());
	std::shared_ptr<ZOM::IndexBuffer>ib = ZOM::IndexBuffer::create(m_Triangle.getIndex(), m_Triangle.getIndexSize());
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

	m_Triangle.onUpdate();

	if (ZOM::Input::isPressed(ZOM_KEY_W)) m_Triangle.moveTop(); 
	if (ZOM::Input::isPressed(ZOM_KEY_A)) m_Triangle.moveLeft(); 
	if (ZOM::Input::isPressed(ZOM_KEY_S)) m_Triangle.moveBottom(); 
	if (ZOM::Input::isPressed(ZOM_KEY_D)) m_Triangle.moveRight(); 
	if (ZOM::Input::isPressed(ZOM_KEY_R)) m_Triangle.moveReset(); 
	if (ZOM::Input::isPressed(ZOM_KEY_KP_ADD)) m_Triangle.speedUp(); 
	if (ZOM::Input::isPressed(ZOM_KEY_KP_SUBTRACT)) m_Triangle.speedDown(); 

	ZOM::Renderer::beginScene();

	va->bind();

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

	ZOM::Renderer::endScene();
}


void GameLayer::onEvent(ZOM::Event& event)
{
	ZOM::EventDispatcher d(event);

	d.dispatchEvent<ZOM::WindowCloseEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onCloseEvent));

	d.dispatchEvent<ZOM::KeyPressedEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onKey));

	d.dispatchEvent<ZOM::KeyReleasedEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onKeyRelease));
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
	m_Triangle.moveStop();

	return true;
}
