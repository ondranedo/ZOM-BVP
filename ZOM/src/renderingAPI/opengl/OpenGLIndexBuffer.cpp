#include "OpenGLIndexBuffer.h"

namespace ZOM {
	
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		ZOM_GL_CALL(glDeleteBuffers(1, &m_ID));
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, size_t count)
	{
		m_Count = count;

		ZOM_GL_CALL(glGenBuffers(1, &m_ID));
		ZOM_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
		ZOM_GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW));
	}

	void OpenGLIndexBuffer::bind() const 
{
		ZOM_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
	}

	void OpenGLIndexBuffer::unbind()
	{
		ZOM_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

}