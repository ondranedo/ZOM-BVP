#pragma once

#include "renderer/VertexArray.h"

namespace ZOM {
	class OpenGLVertexArray : public VertexArray {

	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void bind() const override;
		void unbind() const override;

		void setIndex(std::shared_ptr<IndexBuffer>&) override;
		//const std::shared_ptr<IndexBuffer>& getIndex() const override;

		void setVertex(std::shared_ptr<VertexBuffer>&) override;
		//const std::shared_ptr<VertexBuffer>& getVertex() const override;

		size_t getIndexCount() const override;

	};
}