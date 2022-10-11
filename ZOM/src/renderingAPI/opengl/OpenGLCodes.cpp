#include "OpenGLCodes.h"

namespace ZOM {

	int ZOM_API ZOMInShaderDataTypeComponentToGLType(InShaderDataType isdt)
	{
		switch (isdt)
		{
		case InShaderDataType::Null:  return 0;
		case InShaderDataType::VecF1: return GL_FLOAT;
		case InShaderDataType::VecF2: return GL_FLOAT;
		case InShaderDataType::VecF3: return GL_FLOAT;
		case InShaderDataType::VecF4: return GL_FLOAT;
		case InShaderDataType::VecI1: return GL_INT;
		case InShaderDataType::VecI2: return GL_INT;
		case InShaderDataType::VecI3: return GL_INT;
		case InShaderDataType::VecI4: return GL_FLOAT;
		case InShaderDataType::Mat1:  return GL_FLOAT;
		case InShaderDataType::Mat2:  return GL_FLOAT;
		case InShaderDataType::Mat3:  return GL_FLOAT;
		case InShaderDataType::Mat4:  return GL_FLOAT;
		case InShaderDataType::Bool:  return GL_BOOL;
		}

		ZOM_ERROR("Unkown data type passed in to fucntion: ZOMInShaderDataTypeComponentToGLType(ZOM::InShaderDataType type)");
		return 0;
	}
};