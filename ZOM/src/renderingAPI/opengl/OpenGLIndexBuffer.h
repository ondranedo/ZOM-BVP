#pragma once 

#include "renderer/IndexBuffer.h"

namespace ZOM {
	class ZOM_API OpenGLIndexBuffer : public IndexBuffer {
	public:
		~OpenGLIndexBuffer();
		OpenGLIndexBuffer(unsigned int* data, size_t size);

		void bind() const override;
		void unbind() override;
	};
}