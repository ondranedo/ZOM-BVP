#pragma once

#include "renderer/VertexArray.h"

namespace ZOM {
	class OpenGLVertexArray : public VertexArray {

	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void setIndex(std::shared_ptr<IndexBuffer>&) override;
		//const std::shared_ptr<IndexBuffer>& getIndex() const override;

		virtual void setVertex(std::shared_ptr<VertexBuffer>&) override;
		//const std::shared_ptr<VertexBuffer>& getVertex() const override;

		virtual size_t getIndexCount() const override;

	};
}