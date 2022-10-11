#pragma once

namespace ZOM {
	enum class ZOM_API dataType {
		INT1, INT2, INT4, INT8,
		UINT1, UINT2, UINT4, UINT8,
		F4,F8,F16
	};

	using ZOMInt1 = int8_t;
	using ZOMInt2 = int16_t;
	using ZOMInt4 = int32_t;
	using ZOMInt8 = int64_t;

	using ZOMUInt1 = uint8_t;
	using ZOMUInt2 = uint16_t;
	using ZOMUInt4 = uint32_t;
	using ZOMUInt8 = uint64_t;

	using ZOMFloat4 = float;
	using ZOMFloat8 = double;
	using ZOMFloat16 = long double;

	extern size_t ZOM_API ZOMDataTypeSize(dataType type);
}