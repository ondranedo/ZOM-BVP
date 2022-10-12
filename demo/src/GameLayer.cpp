#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	// 
	// {
	 	ZOM::VertexBufferLayout vbl;
	// 
		va.reset(ZOM::VertexArray::create());
		vb.reset(ZOM::VertexBuffer::create((void*)m_Triangle.getVertex(), m_Triangle.getVertexSize()));
		ib.reset(ZOM::IndexBuffer::create(m_Triangle.getIndex(), m_Triangle.getIndexSize()));
	// 
	 	vbl.add(ZOM::InShaderDataType::VecF2, "test");
	 
	 	vb->setLayout(vbl);
	// 
	// 	va->setIndex(ib);
	//	va->setVertex(vb);
	// 
	 //	va->unbind();
	 	ib->unbind();
	// }

	m_Triangle.onUpdate();

	// if (ZOM::Input::isPressed(ZOM_KEY_X))
	// {
	//	   ZOM_ERROR("PICO NEMACKEJ X");
	// }

	ZOM::Renderer::beginScene();

	// va->bind();

	// glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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
	if (kpe.getKeyCode() == ZOM_KEY_W) { m_Triangle.moveTop(); }
	if (kpe.getKeyCode() == ZOM_KEY_A) { m_Triangle.moveLeft(); }
	if (kpe.getKeyCode() == ZOM_KEY_S) { m_Triangle.moveBottom(); }
	if (kpe.getKeyCode() == ZOM_KEY_D) { m_Triangle.moveRight(); }
	if (kpe.getKeyCode() == ZOM_KEY_R) { m_Triangle.moveReset(); }
	if (kpe.getKeyCode() == ZOM_KEY_KP_ADD) { m_Triangle.speedUp(); }
	if (kpe.getKeyCode() == ZOM_KEY_KP_SUBTRACT) { m_Triangle.speedDown(); }

	return true;
}

bool GameLayer::onKeyRelease(ZOM::KeyReleasedEvent& kpe)
{
	m_Triangle.moveStop();

	return true;
}
