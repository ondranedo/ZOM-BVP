#include "DataType.h"

size_t ZOM::ZOMDataTypeSize(ZOM::dataType type)
{
	switch (type)
	{
		case dataType::INT1:	  return sizeof(int8_t);
		case dataType::INT2:	  return sizeof(int16_t);
		case dataType::INT4:	  return sizeof(int32_t);
		case dataType::INT8:	  return sizeof(int64_t);
		case dataType::UINT1:	  return sizeof(uint8_t);
		case dataType::UINT2:	  return sizeof(uint16_t);
		case dataType::UINT4:	  return sizeof(uint32_t);
		case dataType::UINT8:	  return sizeof(uint64_t);
		case dataType::F4:		  return sizeof(float);
		case dataType::F8:		  return sizeof(double);
		case dataType::F16:		  return sizeof(long double);
	}
}

