#include "OpenGlVertexArray.h"

#include "OpenGLCodes.h"

namespace ZOM {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		ZOM_GL_CALL(glGenVertexArrays(1, &m_ID));
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		ZOM_GL_CALL(glDeleteVertexArrays(1, &m_ID));
	}

	void OpenGLVertexArray::bind() const { ZOM_GL_CALL(glBindVertexArray(m_ID)); }

	void OpenGLVertexArray::unbind() const { ZOM_GL_CALL(glBindVertexArray(0));  }

	void OpenGLVertexArray::setIndex(std::shared_ptr<IndexBuffer>& ib)
	{ 
		bind();
		m_IB = ib;
		m_IB->bind();
	}
	const std::shared_ptr<IndexBuffer>& OpenGLVertexArray::getIndex() const    { return m_IB; }

	void OpenGLVertexArray::setVertex(std::shared_ptr<VertexBuffer>& vb)
	{ 
		bind();
		m_VB = vb;
		m_VB->bind();

		auto layoutVec = m_VB->getLayout().getAttribVec();

		for (size_t i = 0; i < layoutVec.size(); i++)
		{
			ZOM_GL_CALL(glBindVertexArray(i));
			// (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer)
			ZOM_GL_CALL(glVertexAttribPointer(i,
				ZOMInShaderDataTypeComponentCount(layoutVec[0].type), 
				ZOMInShaderDataTypeComponentToGLType(layoutVec[0].type),
				GL_FALSE, 
				m_VB->getLayout().getSize(),
				(const void*)layoutVec[0].offset));
		}
	}
	const std::shared_ptr<VertexBuffer>& OpenGLVertexArray::getVertex() const  { return m_VB; }

}