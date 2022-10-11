#pragma once

namespace ZOM {
	struct ZOM_API VertexBufferLayoutAttrib {
		size_t size;
		dataType type;
		bool normalize;
	};

	using AttribVec = std::vector<VertexBufferLayoutAttrib>;

	class ZOM_API VertexBufferLayout {
	public:
		VertexBufferLayout(const AttribVec& vecarr);
		VertexBufferLayout(){}

		const AttribVec& getAttribVec() const { return m_AttribVec; }	
		void add(size_t size, dataType type);

	private:
		AttribVec m_AttribVec;
	};
}