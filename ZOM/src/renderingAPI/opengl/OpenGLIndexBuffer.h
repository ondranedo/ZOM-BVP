#pragma once 

#include "renderer/IndexBuffer.h"

namespace ZOM {
	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		~OpenGLIndexBuffer();
		OpenGLIndexBuffer(unsigned int* data, size_t count);

		void bind() const override;
		void unbind() override;

		size_t getIndexCount() const override;

	};
}