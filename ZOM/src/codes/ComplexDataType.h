#pragma once

namespace ZOM {
	enum class ZOM_API InShaderDataType {
		Null, 
		VecF1, VecF2, VecF3, VecF4,
		VecI1, VecI2, VecI3, VecI4,
	    Mat2, Mat3, Mat4, Bool
	};

	extern size_t zomInShaderDataTypeSize(const InShaderDataType type);
	extern size_t zomInShaderDataTypeComponentCount(const InShaderDataType type);
	extern InShaderDataType strToZomInShaderDataType(const std::string& str);
}