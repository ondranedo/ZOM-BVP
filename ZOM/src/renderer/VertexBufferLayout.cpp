#include "VertexBufferLayout.h"

namespace ZOM {

	VertexBufferLayout::VertexBufferLayout(const AttribVec& vec) :
		m_AttribVec(vec)
	{

	}

	void VertexBufferLayout::add(InShaderDataType type, const std::string& name)
	{
		size_t offset = 0;
		if (m_AttribVec.size() != 0)
		{
			size_t index = m_AttribVec.size();
	
			offset = m_AttribVec[index-1].offset + m_AttribVec[index - 1].size;
		}

		m_AttribVec.push_back({name, type, ZOMInShaderDataTypeSize(type), offset});
	}
}