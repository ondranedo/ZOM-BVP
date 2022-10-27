#include "Mesh.h"

#include "renderingAPI/opengl/OpenGLMesh.h"

namespace ZOM {
	std::unique_ptr<ZOM::Mesh> Mesh::create(const meshCreationData& mcd)
	{
		switch (Renderer::getAPI())
		{
		case renderingAPI::opengl:
			return std::make_unique<OpenGLMesh>(mcd);
		}
		ZOM_ERROR("Unkown rendering api when creating a mesh");
		return nullptr;
	}

	meshCreationData meshCreationData::triangle(const std::string& shader_name)
	{
		float vertex[]{
			-0.5f,-0.5f,
			 0.0f, 0.5f,
			 0.5f,-0.5f
		};
		unsigned int index[]
		{
			0,1,2
		};
		VertexBufferLayout vbl;
		vbl.add(InShaderDataType::VecF2, "position");

		meshCreationData mcd = createMcdBuffers(
			vertex, sizeof(vertex), index, sizeof(index) / sizeof(unsigned int),vbl);
		mcd.m_ShaderName = shader_name;

		return mcd;
	}

	ZOM::meshCreationData meshCreationData::square(const std::string& shader_name)
	{
		float vertex[]{
			-0.4,-0.4f,
			-0.4, 0.4f,
			 0.4, 0.4f,
			 0.4,-0.4f
		};
		unsigned int index[]
		{
			0,1,2,
			0,2,3
		};
		VertexBufferLayout vbl;
		vbl.add(InShaderDataType::VecF2, "position");

		meshCreationData mcd = createMcdBuffers(
			vertex, sizeof(vertex), index, sizeof(index) / sizeof(unsigned int),vbl);
		mcd.m_ShaderName = shader_name;

		return mcd;
	}

	meshCreationData meshCreationData::background(const std::string& shader_name)
	{
		const float vertex[]{
			-1.0f,-1.0f,
			-1.0f, 1.0f,
			 1.0f, 1.0f,
			 1.0f,-1.0f,
		};
		const unsigned int index[]
		{
			0,1,2,
			0,2,3
		};
		VertexBufferLayout vbl;
		vbl.add(InShaderDataType::VecF2, "position");


		meshCreationData mcd = createMcdBuffers(
			vertex, sizeof(vertex), index, sizeof(index)/sizeof(unsigned int), vbl);
		mcd.m_ShaderName = shader_name;

		return mcd;
	}

	ZOM::meshCreationData meshCreationData::createMcdBuffers
	(
		const void* vertex_buffer, 
		const size_t vertex_buffer_size, 
		const unsigned int* index_buffer, 
		const size_t index_buffer_count, 
		const VertexBufferLayout& layout
	)
	{
		meshCreationData mcd;

		mcd.m_VertexBuffer = new char[vertex_buffer_size];
		mcd.m_IndexBuffer = new unsigned int[index_buffer_count];
		memcpy(mcd.m_VertexBuffer, vertex_buffer, vertex_buffer_size);
		memcpy(mcd.m_IndexBuffer, index_buffer, index_buffer_count*sizeof(unsigned int));
		mcd.m_VertexBufferSize = vertex_buffer_size;
		mcd.m_IndexBufferCount = index_buffer_count;
		mcd.m_VertexBufferLayout = layout;

		return mcd;
	}

}