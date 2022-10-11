#pragma once 

#include "renderer/VertexBuffer.h"

namespace ZOM {
	class ZOM_API OpenGLVertexBuffer : public VertexBuffer {
	public:
		~OpenGLVertexBuffer();
		OpenGLVertexBuffer(void* data, size_t size);

		void bind() const override;
		void unbind() const override;

		void setLayout(const VertexBufferLayout& vbl) override;
		const VertexBufferLayout& getLayout() const override;
	};
}