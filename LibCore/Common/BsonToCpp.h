#ifndef __libcore_bson_to_cpp_h__
#define __libcore_bson_to_cpp_h__
#include "Common/Common.h"
#include "Common/StringEx.h"
#include "bson/bson.h"

namespace LibCore
{
	extern void DLL_EXPORT BsonToCpp(UINT8 & var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(INT16& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(INT32& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(UINT32& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(INT64& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(UINT64& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(float& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(double& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(bool& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(std::string& var,mongo::BSONElement& be);
	extern void DLL_EXPORT  BsonToCpp(StringExBase & var,mongo::BSONElement& be);

	template<typename T>
	struct HashMake
	{
		INT64 operator()(const T & t , INT64 llSeed)
		{
			return LibCore::CityHash(&t , sizeof(T) , llSeed);
		}
	};

	template<>
	struct HashMake<std::string>
	{
		INT64  operator()(const std::string & t , INT64 llSeed)
		{
			return LibCore::CityHash(t.c_str() , t.length() , llSeed);
		}
	};

	template<>
	struct HashMake<StringExBase>
	{
		INT64 operator()(const StringExBase & t , INT64 llSeed)
		{
			return LibCore::CityHash(t.c_str() , t.length() , llSeed);
		}
	};
}

#endif