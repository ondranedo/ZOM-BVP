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
	void OpenGLVertexArray::setVertex(std::shared_ptr<VertexBuffer>& vb)
	{ 
		bind();
		m_VB = vb;
		m_VB->bind();

		auto layoutVec = m_VB->getLayout().getAttribVec();

		for (size_t i = 0; i < (int)layoutVec.size(); i++)
		{
			ZOM_GL_CALL(glEnableVertexAttribArray((GLsizei)i));

			ZOM_GL_CALL(glVertexAttribPointer((GLuint)i,
				(GLint)ZOMInShaderDataTypeComponentCount(layoutVec[0].type),
				(GLenum)ZOMInShaderDataTypeComponentToGLType(layoutVec[0].type),
				(GLboolean)GL_FALSE, 
				(GLsizei)m_VB->getLayout().getSize(),
				(const void*)layoutVec[0].offset));
		}

	}

	size_t OpenGLVertexArray::getIndexCount() const
	{
		return m_IB->getIndexCount();
	}

}