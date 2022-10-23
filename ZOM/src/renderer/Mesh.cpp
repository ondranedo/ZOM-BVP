#include "Mesh.h"

#include "renderingAPI/opengl/OpenGLMesh.h"

namespace ZOM {
	std::unique_ptr<ZOM::Mesh> Mesh::create(const MeshCreationData& mcd)
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::make_unique<OpenGLMesh>(mcd);
			break;
		}
		ZOM_ERROR("Unkown rendering api when creating a mesh");
		return NULL;
	}

	MeshCreationData MeshCreationData::triangle(const std::string& shader_name)
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

		MeshCreationData mcd = createMCDBuffers(
			vertex, sizeof(vertex), index, sizeof(index) / sizeof(unsigned int),vbl);
		mcd.shader_name = shader_name;

		return mcd;
	}

	ZOM::MeshCreationData MeshCreationData::square(const std::string& shader_name)
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

		MeshCreationData mcd = createMCDBuffers(
			vertex, sizeof(vertex), index, sizeof(index) / sizeof(unsigned int),vbl);
		mcd.shader_name = shader_name;

		return mcd;
	}

	MeshCreationData MeshCreationData::background(const std::string& shader_name)
	{
		float vertex[]{
			-1.0f,-1.0f,
			-1.0f, 1.0f,
			 1.0f, 1.0f,
			 1.0f,-1.0f,
		};
		unsigned int index[]
		{
			0,1,2,
			0,2,3
		};
		VertexBufferLayout vbl;
		vbl.add(InShaderDataType::VecF2, "position");


		MeshCreationData mcd = createMCDBuffers(
			vertex, sizeof(vertex), index, sizeof(index)/sizeof(unsigned int), vbl);
		mcd.shader_name = shader_name;

		return mcd;
	}

	ZOM::MeshCreationData MeshCreationData::createMCDBuffers
	(
		void* vertex_buffer, 
		size_t vertex_buffer_size, 
		unsigned int* index_buffer, 
		size_t index_buffer_count, 
		const VertexBufferLayout& layout
	)
	{
		MeshCreationData mcd;

		mcd.vertex_buffer = new char[vertex_buffer_size];
		mcd.index_buffer = new unsigned int[index_buffer_count];
		memcpy(mcd.vertex_buffer, vertex_buffer, vertex_buffer_size);
		memcpy(mcd.index_buffer, index_buffer, index_buffer_count*sizeof(unsigned int));
		mcd.vertex_buffer_size = vertex_buffer_size;
		mcd.index_buffer_count = index_buffer_count;
		mcd.vertex_buffer_layout = layout;

		return mcd;
	}

}