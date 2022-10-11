#include "ComplexDataType.h"

namespace ZOM {
size_t ZOMInShaderDataTypeSize(InShaderDataType isdt)
{
	switch (isdt)
	{
	case ZOM::InShaderDataType::Null: return 0;
	case ZOM::InShaderDataType::VecF1: return ZOMDataTypeSize(dataType::F4) * 1;
	case ZOM::InShaderDataType::VecF2: return ZOMDataTypeSize(dataType::F4) * 2;
	case ZOM::InShaderDataType::VecF3: return ZOMDataTypeSize(dataType::F4) * 3;
	case ZOM::InShaderDataType::VecF4: return ZOMDataTypeSize(dataType::F4) * 4;
	case ZOM::InShaderDataType::VecI1: return ZOMDataTypeSize(dataType::Int4) * 1;
	case ZOM::InShaderDataType::VecI2: return ZOMDataTypeSize(dataType::Int4) * 2;
	case ZOM::InShaderDataType::VecI3: return ZOMDataTypeSize(dataType::Int4) * 3;
	case ZOM::InShaderDataType::VecI4: return ZOMDataTypeSize(dataType::Int4) * 4;
	case ZOM::InShaderDataType::Mat1:  return ZOMDataTypeSize(dataType::F4) * 1 * 1;
	case ZOM::InShaderDataType::Mat2:  return ZOMDataTypeSize(dataType::F4) * 2 * 2;
	case ZOM::InShaderDataType::Mat3:  return ZOMDataTypeSize(dataType::F4) * 3 * 3;
	case ZOM::InShaderDataType::Mat4:  return ZOMDataTypeSize(dataType::F4) * 4 * 4;
	case ZOM::InShaderDataType::Bool:  return ZOMDataTypeSize(dataType::Bool);
	}

	ZOM_ERROR("Unkown data type passed in to fucntion: ZOMinShaderDataTypeSizes(ZOM::InShaderDataType type)");
	return 0;
}

size_t ZOMInShaderDataTypeComponentCount(InShaderDataType isdt)
{
	switch (isdt)
	{
	case ZOM::InShaderDataType::Null:  return 0;
	case ZOM::InShaderDataType::VecF1: return 1;
	case ZOM::InShaderDataType::VecF2: return 2;
	case ZOM::InShaderDataType::VecF3: return 3;
	case ZOM::InShaderDataType::VecF4: return 4;
	case ZOM::InShaderDataType::VecI1: return 1;
	case ZOM::InShaderDataType::VecI2: return 2;
	case ZOM::InShaderDataType::VecI3: return 3;
	case ZOM::InShaderDataType::VecI4: return 4;
	case ZOM::InShaderDataType::Mat1:  return 1 * 1;
	case ZOM::InShaderDataType::Mat2:  return 2 * 2;
	case ZOM::InShaderDataType::Mat3:  return 3 * 3;
	case ZOM::InShaderDataType::Mat4:  return 4 * 4;
	case ZOM::InShaderDataType::Bool:  return 1;
	}

	ZOM_ERROR("Unkown data type passed in to fucntion: ZOMInShaderDataTypeComponentCount(ZOM::InShaderDataType type)");
	return 0;
}
}


