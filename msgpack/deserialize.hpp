#pragma once

#include "Arduino.h"
#include "utilities.hpp"
#include "DataType.hpp"

namespace msgpack {
	inline DataType getNextDataTypeUnsafely(Stream &);
	inline bool getNextDataType(Stream &, DataType &, bool safely = true);
	inline bool nextDataTypeIs(Stream &, const DataType &, bool safely = true);

	bool readNil(Stream &, bool safely = true);

	bool readMapSize(Stream &, size_t &, bool safely = true);
	bool readArraySize(Stream &, size_t &, bool safely = true);

	//use these when you care what the encoded format int value is
	bool readIntU7(Stream &, uint8_t &, bool safely = true);
	bool readIntU8(Stream &, uint8_t &, bool safely = true);
	bool readIntU16(Stream &, uint16_t &, bool safely = true);
	bool readIntU32(Stream &, uint32_t &, bool safely = true);
	bool readIntU64(Stream &, uint64_t &, bool safely = true);
	bool readInt5(Stream &, int8_t &, bool safely = true);
	bool readInt8(Stream &, int8_t &, bool safely = true);
	bool readInt6(Stream &, int16_t &, bool safely = true);
	bool readInt32(Stream &, int32_t &, bool safely = true);
	bool readInt64(Stream &, int64_t &, bool safely = true);

	//use this if when you don't care what type the encoded int is and just want it output in your desired format
	template <typename OutputType>
	bool readInt(Stream &, OutputType &, bool safely = true);

	bool readFloat32(Stream &, float, bool safely = true);
	bool readFloat64(Stream &, double, bool safely = true);

	template <typename OutputType>
	bool readFloat(Stream &, OutputType &, bool safely = true);

	bool readString5(Stream &, char *, const uint8_t & allocation, uint8_t & outputSize, bool safely = true);
	bool readString8(Stream &, char *, const uint8_t & allocation, uint8_t & outputSize, bool safely = true);
	bool readString16(Stream &, char *, const uint16_t & allocation, uint16_t & outputSize, bool safely = true);
	bool readString32(Stream &, char *, const uint32_t & allocation, uint32_t & outputSize, bool safely = true);
	bool readString(Stream &, char *, const size_t & allocation, size_t & outputSize, bool safely = true);

	bool readBinary8(Stream &, char *, const uint8_t & allocation, uint8_t & outputSize, bool safely = true);
	bool readBinary16(Stream &, char *, const uint16_t & allocation, uint16_t & outputSize, bool safely = true);
	bool readBinary32(Stream &, char *, const uint32_t & allocation, uint32_t & outputSize, bool safely = true);
	bool readBinary(Stream &, char *, const size_t & allocation, size_t & outputSize, bool safely = true);	
}