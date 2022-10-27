#pragma once

#include "renderer/IndexBuffer.h"

namespace ZOM
{
	class OpenGLIndexBuffer final : public IndexBuffer {
	public:
		virtual ~OpenGLIndexBuffer() override;
		OpenGLIndexBuffer(const unsigned int* data, size_t count);

		virtual void bind() const override;
		virtual void unbind() override;

		virtual size_t getIndexCount() const override;

	};
}
