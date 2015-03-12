#ifndef __libcore_bson_to_cpp_h__
#define __libcore_bson_to_cpp_h__
#include "Common/Common.h"
#include "Common/StringEx.h"
#include "bson/bson.h"

namespace LibCore
{
	extern void BsonToCpp(UINT8 & var,_bson::bsonelement& be);
	extern void BsonToCpp(INT16& var,_bson::bsonelement& be);
	extern void BsonToCpp(INT32& var,_bson::bsonelement& be);
	extern void BsonToCpp(UINT32& var,_bson::bsonelement& be);
	extern void BsonToCpp(INT64& var,_bson::bsonelement& be);
	extern void BsonToCpp(UINT64& var,_bson::bsonelement& be);
	extern void BsonToCpp(float& var,_bson::bsonelement& be);
	extern void BsonToCpp(double& var,_bson::bsonelement& be);
	extern void BsonToCpp(bool& var,_bson::bsonelement& be);
	extern void BsonToCpp(std::string& var,_bson::bsonelement& be);
	extern void BsonToCpp(StringExBase & var,_bson::bsonelement& be);
}

#endif