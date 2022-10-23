#pragma once

#include "Shader.h"
#include "VertexArray.h"

namespace ZOM {
	struct ZOM_API MeshCreationData {
		void* vertex_buffer;		// On HEAP !!
		unsigned int* index_buffer; // On HEAP !!
		size_t vertex_buffer_size;
		size_t index_buffer_count;
		VertexBufferLayout vertex_buffer_layout;
		std::string shader_name;

		static MeshCreationData triangle(const std::string& shader_name);
		static MeshCreationData square(const std::string& shader_name);
		static MeshCreationData background(const std::string& shader_name);
		static MeshCreationData createMCDBuffers(void* vertex_buffer, size_t vertex_buffer_size, unsigned int* index, size_t index_count, const VertexBufferLayout& layout);
	};

	class ZOM_API Mesh {
	public:
		virtual ~Mesh(){};
		virtual size_t getIndexCount() const = 0;
		virtual void bind() const = 0;
		virtual void setUniform(const std::string& name, void* data) const = 0;

		static std::unique_ptr<Mesh> create(const MeshCreationData&);

	protected:
		std::shared_ptr<Shader>m_Shader;
		std::shared_ptr<VertexArray>m_VertexArray;
		MeshCreationData m_Data;
	};
}