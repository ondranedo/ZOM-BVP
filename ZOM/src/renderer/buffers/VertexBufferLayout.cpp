#include "VertexBufferLayout.h"

namespace ZOM
{
	VertexBufferLayout::VertexBufferLayout(const AttribVec& vec) : m_AttribVec(vec) { }

	void VertexBufferLayout::add(InShaderDataType type, const std::string& name)
	{
		size_t offset = 0;
		if(!m_AttribVec.empty()) {
			const size_t index = m_AttribVec.size();

			offset = m_AttribVec[index - 1].offset + m_AttribVec[index - 1].size;
		}

		m_AttribVec.push_back({name, type, m_Size += zomInShaderDataTypeSize(type), offset});
	}

	size_t VertexBufferLayout::getSize() const
	{
		return m_Size;
	}

	bool VertexBufferLayout::operator!=(const VertexBufferLayout& right) const
	{
		return !(*this == right);
	}

	bool VertexBufferLayout::operator==(const VertexBufferLayout& right) const
	{
		for(size_t i = 0 ; i < m_AttribVec.size() ; i++) {
			if(m_AttribVec[i].type != right.m_AttribVec[i].type) {
				return false;
			}
		}

		return true;
	}
}
