#include "ComplexDataType.h"

namespace ZOM
{
	size_t zomInShaderDataTypeSize(const InShaderDataType type)
	{
		switch(type) {
			case InShaderDataType::Null: return 0;
			case InShaderDataType::VecF1: return zomDataTypeSize(dataType::F4) * 1;
			case InShaderDataType::VecF2: return zomDataTypeSize(dataType::F4) * 2;
			case InShaderDataType::VecF3: return zomDataTypeSize(dataType::F4) * 3;
			case InShaderDataType::VecF4: return zomDataTypeSize(dataType::F4) * 4;
			case InShaderDataType::VecI1: return zomDataTypeSize(dataType::Int4) * 1;
			case InShaderDataType::VecI2: return zomDataTypeSize(dataType::Int4) * 2;
			case InShaderDataType::VecI3: return zomDataTypeSize(dataType::Int4) * 3;
			case InShaderDataType::VecI4: return zomDataTypeSize(dataType::Int4) * 4;
			case InShaderDataType::Mat2: return zomDataTypeSize(dataType::F4) * 2 * 2;
			case InShaderDataType::Mat3: return zomDataTypeSize(dataType::F4) * 3 * 3;
			case InShaderDataType::Mat4: return zomDataTypeSize(dataType::F4) * 4 * 4;
			case InShaderDataType::Bool: return zomDataTypeSize(dataType::Bool);
		}

		ZOM_ERROR("Unkown data type passed in to fucntion: ZOMinShaderDataTypeSizes(ZOM::InShaderDataType type)");
		return 0;
	}

	size_t zomInShaderDataTypeComponentCount(const InShaderDataType type)
	{
		switch(type) {
			case InShaderDataType::Null: return 0;
			case InShaderDataType::VecF1: return 1;
			case InShaderDataType::VecF2: return 2;
			case InShaderDataType::VecF3: return 3;
			case InShaderDataType::VecF4: return 4;
			case InShaderDataType::VecI1: return 1;
			case InShaderDataType::VecI2: return 2;
			case InShaderDataType::VecI3: return 3;
			case InShaderDataType::VecI4: return 4;
			case InShaderDataType::Mat2: return 2 * 2;
			case InShaderDataType::Mat3: return 3 * 3;
			case InShaderDataType::Mat4: return 4 * 4;
			case InShaderDataType::Bool: return 1;
		}

		ZOM_ERROR(
			"Unkown data type passed in to fucntion: zomInShaderDataTypeComponentCount(ZOM::InShaderDataType type)");
		return 0;
	}

	extern InShaderDataType strToZomInShaderDataType(const std::string& str)
	{
		if(str == "Null") return InShaderDataType::Null;
		if(str == "float") return InShaderDataType::VecF1;
		if(str == "vec2") return InShaderDataType::VecF2;
		if(str == "vec3") return InShaderDataType::VecF3;
		if(str == "vec4") return InShaderDataType::VecF4;
		if(str == "int") return InShaderDataType::VecI1;
		if(str == "ivec2") return InShaderDataType::VecI2;
		if(str == "ivec3") return InShaderDataType::VecI3;
		if(str == "ivec4") return InShaderDataType::VecI4;
		if(str == "mat2") return InShaderDataType::Mat2;
		if(str == "mat3") return InShaderDataType::Mat3;
		if(str == "mat4") return InShaderDataType::Mat4;
		if(str == "bool") return InShaderDataType::Bool;

		ZOM_ERROR(
			"Unkown data type passed in to fucntion: zomInShaderDataTypeComponentCount(ZOM::InShaderDataType type)");
		return InShaderDataType::Null;
	}
}
