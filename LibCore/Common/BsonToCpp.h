#ifndef __libcore_bson_to_cpp_h__
#define __libcore_bson_to_cpp_h__
#include "Common/Common.h"
#include "Common/StringEx.h"
#include "bson/bson.h"

namespace LibCore
{
	extern void BsonToCpp(UINT8 & var,mongo::BSONElement& be);
	extern void BsonToCpp(INT16& var,mongo::BSONElement& be);
	extern void BsonToCpp(INT32& var,mongo::BSONElement& be);
	extern void BsonToCpp(UINT32& var,mongo::BSONElement& be);
	extern void BsonToCpp(INT64& var,mongo::BSONElement& be);
	extern void BsonToCpp(UINT64& var,mongo::BSONElement& be);
	extern void BsonToCpp(float& var,mongo::BSONElement& be);
	extern void BsonToCpp(double& var,mongo::BSONElement& be);
	extern void BsonToCpp(bool& var,mongo::BSONElement& be);
	extern void BsonToCpp(std::string& var,mongo::BSONElement& be);
	extern void BsonToCpp(StringExBase & var,mongo::BSONElement& be);
}

#endif