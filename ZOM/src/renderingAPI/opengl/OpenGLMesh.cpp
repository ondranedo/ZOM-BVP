#include "OpenGLMesh.h"

#include "renderer/ShaderManager.h"

namespace ZOM {

	OpenGLMesh::OpenGLMesh(const MeshCreationData& mcd)
	{
		m_Data = mcd;

		std::shared_ptr<VertexBuffer> vertexB = VertexBuffer::create((void*)mcd.vertex_buffer,mcd.vertex_buffer_size);
		std::shared_ptr<IndexBuffer> indexB = IndexBuffer::create((unsigned int*)mcd.index_buffer, mcd.index_buffer_count);

		delete mcd.index_buffer;
		delete mcd.vertex_buffer;

		m_VertexArray = VertexArray::create();
		m_Shader = Renderer::getShader(mcd.shader_name);
		
		if (m_Shader->getLayout() != mcd.vertex_buffer_layout)
			ZOM_ERROR("Mismatch of vertex buffer layout and shader layout, for shader {}", mcd.shader_name);
	
		vertexB->setLayout(m_Shader->getLayout());

		m_VertexArray->setIndex(indexB);
		m_VertexArray->setVertex(vertexB);

		m_VertexArray->unbind();
		indexB->unbind();
		vertexB->unbind();
		
	}

	size_t OpenGLMesh::getIndexCount() const
	{
		return m_VertexArray->getIndexCount();
	}

	void OpenGLMesh::bind() const
	{
		m_Shader->bind();

		m_VertexArray->bind();
	}

}	