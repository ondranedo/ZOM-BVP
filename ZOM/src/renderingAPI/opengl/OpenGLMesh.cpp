#include "OpenGLMesh.h"

#include "renderer/ShaderManager.h"

namespace ZOM {

	OpenGLMesh::OpenGLMesh(const meshCreationData& mcd)
	{
		m_Data = mcd;

		std::shared_ptr<VertexBuffer> vertex_b = VertexBuffer::create((void*)mcd.m_VertexBuffer,mcd.m_VertexBufferSize);
		std::shared_ptr<IndexBuffer> index_b = IndexBuffer::create((unsigned int*)mcd.m_IndexBuffer, mcd.m_IndexBufferCount);

		delete mcd.m_IndexBuffer;
		delete mcd.m_VertexBuffer;

		m_VertexArray = VertexArray::create();
		m_Shader = Renderer::getShader(mcd.m_ShaderName);
		
		if (m_Shader->getLayout() != mcd.m_VertexBufferLayout)
			ZOM_ERROR("Mismatch of vertex buffer layout and shader layout, for shader {}", mcd.m_ShaderName);
	
		vertex_b->setLayout(m_Shader->getLayout());

		m_VertexArray->setIndex(index_b);
		m_VertexArray->setVertex(vertex_b);

		m_VertexArray->unbind();
		index_b->unbind();
		vertex_b->unbind();
		
	}

	size_t OpenGLMesh::getIndexCount() const
	{
		return m_VertexArray->getIndexCount();
	}

	void OpenGLMesh::bind() const
	{
		m_Shader->bind();
		m_Shader->checkIfUniformAreSet();
		m_VertexArray->bind();
	}

	void OpenGLMesh::setUniform(const std::string& name, void* data) const
	{
		m_Shader->bind();
		m_Shader->setUniform(name, data);
	}

}	