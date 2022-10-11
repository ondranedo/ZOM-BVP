#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{

	std::shared_ptr<ZOM::VertexBuffer>vb;
	std::shared_ptr<ZOM::IndexBuffer>ib;
	unsigned int id_varr;

	{
		vb.reset(ZOM::VertexBuffer::create((void*)m_Triangle.getVertex(), m_Triangle.getVertexSize()));
		ib.reset(ZOM::IndexBuffer::create(m_Triangle.getIndex(), m_Triangle.getIndexSize()));
	}
	
	m_Triangle.onUpdate();
	
	glGenVertexArrays(1, &id_varr);
	{
		glBindVertexArray(id_varr);
		vb->bind();

		ib->bind();
		
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
		glEnableVertexAttribArray(0);

		/**
		* API:
		*	vbl->add(4,ZOM_FLOAT);
		*	vbl->add(3,ZOM_CHAR);
		*	vbl->add(3,ZOM_FLOAT);
		* 
		**/
		ZOM::VertexBufferLayout vbl;
		vbl.add(2, ZOM::dataType::F4);


		ZOM_TRACE("SIZE: {}", vbl.getAttribVec().size());
	}

	ZOM::Renderer::beginScene();

	glBindVertexArray(id_varr);

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	
	ZOM::Renderer::endScene();
	
	glDeleteVertexArrays(1, &id_varr);
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
	if (kpe.getKeyCode() == ZOM_KEY_W){ m_Triangle.moveTop(); }
	if (kpe.getKeyCode() == ZOM_KEY_A){ m_Triangle.moveLeft(); }
	if (kpe.getKeyCode() == ZOM_KEY_S){ m_Triangle.moveBottom();}
	if (kpe.getKeyCode() == ZOM_KEY_D){ m_Triangle.moveRight();}
	if (kpe.getKeyCode() == ZOM_KEY_R){ m_Triangle.moveReset();}
	if (kpe.getKeyCode() == ZOM_KEY_KP_ADD) { m_Triangle.speedUp(); }
	if (kpe.getKeyCode() == ZOM_KEY_KP_SUBTRACT ){ m_Triangle.speedDown();}

	return true;
}

bool GameLayer::onKeyRelease(ZOM::KeyReleasedEvent& kpe)
{
	m_Triangle.moveStop();

	return true;
}
