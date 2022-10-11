#pragma once

namespace ZOM {
	enum class ZOM_API dataType {
		Null,
		Int1, Int2, Int4, Int8,
		UInt1, UInt2, UInt4, UInt8,
		F4,F8,F16,
		Bool
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

	using ZOMBool = bool;

	extern size_t ZOM_API ZOMDataTypeSize(dataType type);
}