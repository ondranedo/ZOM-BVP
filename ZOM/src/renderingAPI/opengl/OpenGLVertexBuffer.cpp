#include "OpenGLVertexBuffer.h"

namespace ZOM {
	
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		ZOM_GL_CALL(glDeleteBuffers(1, &m_ID));
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(void* data, size_t size)
	{
		ZOM_GL_CALL(glGenBuffers(1, &m_ID));
		ZOM_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
		ZOM_GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	void OpenGLVertexBuffer::bind()
	{
		ZOM_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
	}

	void OpenGLVertexBuffer::unbind()
	{
		ZOM_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

}