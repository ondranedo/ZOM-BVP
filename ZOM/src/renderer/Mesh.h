#pragma once

#include "Shader.h"
#include "VertexArray.h"

namespace ZOM
{
	struct ZOM_API meshCreationData {
		void* m_VertexBuffer;        // On HEAP !!
		unsigned int* m_IndexBuffer; // On HEAP !!
		size_t m_VertexBufferSize;
		size_t m_IndexBufferCount;
		VertexBufferLayout m_VertexBufferLayout;
		std::string m_ShaderName;

		static meshCreationData triangle(const std::string& shader_name);
		static meshCreationData square(const std::string& shader_name);
		static meshCreationData background(const std::string& shader_name);
		static meshCreationData createMcdBuffers(
			const void* vertex_buffer,
			const size_t vertex_buffer_size,
			const unsigned int* index_buffer,
			const size_t index_buffer_count,
			const VertexBufferLayout& layout);
	};

	class ZOM_API Mesh {
	public:
		virtual ~Mesh() {};
		virtual size_t getIndexCount() const = 0;
		virtual void bind() const = 0;
		virtual void setUniform(const std::string& name, void* data) const = 0;

		static std::unique_ptr<Mesh> create(const meshCreationData&);

	protected:
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;
		meshCreationData m_Data = { nullptr };
	};
}
