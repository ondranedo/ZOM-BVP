#pragma once

#include "codes/ComplexDataType.h"

namespace ZOM {
	struct ZOM_API VertexBufferLayoutAttrib {
		std::string name = "";
		InShaderDataType type = InShaderDataType::Null;
		size_t size = 0;
		size_t offset = 0;
	};

	using AttribVec = std::vector<VertexBufferLayoutAttrib>;

	class ZOM_API VertexBufferLayout {
	public:
		VertexBufferLayout(const AttribVec& vecarr);
		VertexBufferLayout(){}

		const AttribVec& getAttribVec() const { return m_AttribVec; }

		void add(InShaderDataType t, const std::string& name);
		size_t getSize() const;

	private:
		AttribVec m_AttribVec;
		size_t m_Size = 0;
	};
}