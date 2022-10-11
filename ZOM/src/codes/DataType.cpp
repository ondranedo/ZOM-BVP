#include "DataType.h"

size_t ZOM::ZOMDataTypeSize(ZOM::dataType type)
{
	switch (type)
	{
		case dataType::Null:	  return 0;
		case dataType::Int1:	  return sizeof(int8_t);
		case dataType::Int2:	  return sizeof(int16_t);
		case dataType::Int4:	  return sizeof(int32_t);
		case dataType::Int8:	  return sizeof(int64_t);
		case dataType::UInt1:	  return sizeof(uint8_t);
		case dataType::UInt2:	  return sizeof(uint16_t);
		case dataType::UInt4:	  return sizeof(uint32_t);
		case dataType::UInt8:	  return sizeof(uint64_t);
		case dataType::F4:		  return sizeof(float);
		case dataType::F8:		  return sizeof(double);
		case dataType::F16:		  return sizeof(long double);
		case dataType::Bool:	  return sizeof(bool);
	}

	ZOM_ERROR("Unkown data type passed in to fucntion: ZOMDataTypeSize(ZOM::dataType type)");
	return 0;
}

