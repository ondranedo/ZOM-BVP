#pragma once

#include "renderer/buffers/VertexBuffer.h"

namespace ZOM
{
	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		virtual ~OpenGLVertexBuffer() override;
		OpenGLVertexBuffer(const void* data,const size_t size);

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void setLayout(const VertexBufferLayout& vbl) override;
		virtual const VertexBufferLayout& getLayout() const override;
	};
}
