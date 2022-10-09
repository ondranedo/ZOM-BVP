#include "GameLayer.h"

#include <glad/gl.h>

void GameLayer::onUpdate()
{
	ZOM::Renderer::beginScene();

	{
		//	m_Triangle.onUpdate();
		//
		//	unsigned int id_ver;
		//	unsigned int id_ind;
		//	unsigned int id_varr;
		//	
		//	// Vertex Array
		//	glGenVertexArrays(1, &id_varr);
		//	glBindVertexArray(id_varr);
		//
		//	// Vertex buffer
		//	glGenBuffers(1, &id_ver);
		//	glBindBuffer(GL_ARRAY_BUFFER, id_ver);
		//	glBufferData(GL_ARRAY_BUFFER, m_Triangle.getVertexSize(), m_Triangle.getVertex(), GL_DYNAMIC_DRAW);
		//
		//
		//	// Index buffer
		//	glGenBuffers(1, &id_ind);
		//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_ind);
		//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Triangle.getIndexSize(), m_Triangle.getIndex(), GL_DYNAMIC_DRAW);
		//
		//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
		//	glEnableVertexAttribArray(0);
		//
		//	//glDrawArrays(GL_TRIANGLES, 0, 3);
		//	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
		//
		//	glDeleteBuffers(1, &id_ver);
		//	glDeleteBuffers(1, &id_ind);
		//	glDeleteVertexArrays(1, &id_varr);
	}

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
