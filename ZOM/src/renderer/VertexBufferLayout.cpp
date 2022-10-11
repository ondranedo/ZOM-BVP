#include "VertexBufferLayout.h"

namespace ZOM {

	VertexBufferLayout::VertexBufferLayout(const AttribVec& vec) :
		m_AttribVec(vec)
	{

	}

	void VertexBufferLayout::add(size_t size, dataType type)
	{
		switch (type)
		{
		case dataType::INT1: m_AttribVec.push_back({ size,type,true }); break;
		case dataType::INT2: m_AttribVec.push_back({ size,type,true }); break;
		case dataType::INT4: m_AttribVec.push_back({ size,type,true }); break;
		case dataType::INT8: m_AttribVec.push_back({ size,type,true }); break;

		case dataType::UINT1: m_AttribVec.push_back({ size,type,true }); break;
		case dataType::UINT2: m_AttribVec.push_back({ size,type,true }); break;
		case dataType::UINT4: m_AttribVec.push_back({ size,type,true }); break;
		case dataType::UINT8: m_AttribVec.push_back({ size,type,true }); break;

		case dataType::F4: m_AttribVec.push_back({ size,type, false }); break;
		case dataType::F8: m_AttribVec.push_back({ size,type, false }); break;
		case dataType::F16: m_AttribVec.push_back({ size,type, false }); break;
		}
	}
}