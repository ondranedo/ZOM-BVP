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
	case ZOM::InShaderDataType::Mat2:  return 2 * 2;
	case ZOM::InShaderDataType::Mat3:  return 3 * 3;
	case ZOM::InShaderDataType::Mat4:  return 4 * 4;
	case ZOM::InShaderDataType::Bool:  return 1;
	}

	ZOM_ERROR("Unkown data type passed in to fucntion: ZOMInShaderDataTypeComponentCount(ZOM::InShaderDataType type)");
	return 0;
}

extern InShaderDataType strToZOMInShaderDataType(const std::string& str)
{
	
	if (str == "Null")  return ZOM::InShaderDataType::Null;
	if (str == "float") return ZOM::InShaderDataType::VecF1;
	if (str == "vec2")  return ZOM::InShaderDataType::VecF2;
	if (str == "vec3")  return ZOM::InShaderDataType::VecF3;
	if (str == "vec4")  return ZOM::InShaderDataType::VecF4;
	if (str == "int")   return ZOM::InShaderDataType::VecI1;
	if (str == "ivec2") return ZOM::InShaderDataType::VecI2;
	if (str == "ivec3") return ZOM::InShaderDataType::VecI3;
	if (str == "ivec4") return ZOM::InShaderDataType::VecI4;
	if (str == "mat2")  return ZOM::InShaderDataType::Mat2;
	if (str == "mat3")  return ZOM::InShaderDataType::Mat3;
	if (str == "mat4")  return ZOM::InShaderDataType::Mat4;
	if (str == "bool")  return ZOM::InShaderDataType::Bool;

	ZOM_ERROR("Unkown data type passed in to fucntion: ZOMInShaderDataTypeComponentCount(ZOM::InShaderDataType type)");
	return ZOM::InShaderDataType::Null;
}
}


