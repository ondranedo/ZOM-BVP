#pragma once

namespace ZOM {
	enum class ZOM_API InShaderDataType {
		Null, 
		VecF1, VecF2, VecF3, VecF4,
		VecI1, VecI2, VecI3, VecI4,
		Mat1, Mat2, Mat3, Mat4, Bool
	};

	extern size_t ZOMInShaderDataTypeSize(InShaderDataType isdt);
	extern size_t ZOMInShaderDataTypeComponentCount(InShaderDataType isdt);
}