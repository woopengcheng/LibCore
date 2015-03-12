#include "BsonToCpp.h"

namespace LibCore
{

	void BsonToCpp(bool& var,_bson::bsonelement& be)
	{
		if(be.isBoolean())
		{
			var = be.boolean();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to bool:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(UINT8& var,_bson::bsonelement& be)
	{
		if(be.isNumber())
		{
			var = (UINT8)be.numberInt();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to UINT8:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(INT16& var,_bson::bsonelement& be)
	{
		if(be.isNumber())
		{
			var = (INT16)be.numberInt();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to INT16:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(float& var,_bson::bsonelement& be)
	{
		if(be.isNumber())
		{
			var = (float)be.numberDouble();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to float:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(double& var,_bson::bsonelement& be)
	{
		if(be.isNumber())
		{
			var = be.numberDouble();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to double:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(INT32& var,_bson::bsonelement& be)
	{
		if(be.isNumber())
		{
			var = be.numberInt();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to INT32:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(INT64& var,_bson::bsonelement& be)
	{
		if(be.isNumber())
		{
			var = be.numberLong();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to INT64:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(std::string& var,_bson::bsonelement& be)
	{
		if(be.type() == _bson::String)
		{
			var = std::string(be.valuestrsafe(),be.valuestrsize()-1);
			return;
		}
		else if(be.type() == _bson::BinData)
		{
			int len = 0;
			const char* data = be.binData(len);
			var.clear();
			var.append(data,len);
			return;
		}
		MsgAssert(false,__FUNCTION__ << " to string:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp(StringExBase& var,_bson::bsonelement& be)
	{
		if(be.type() == _bson::String)
		{
			var.Init(be.valuestrsafe(),be.valuestrsize());
			return;
		}
		MsgAssert(false,__FUNCTION__ << " to fixed_string_base:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp( UINT32& var,_bson::bsonelement& be )
	{
		if(be.isNumber())
		{
			var = (UINT32)be.numberInt();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to UINT32:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}

	void BsonToCpp( UINT64& var,_bson::bsonelement& be )
	{
		if(be.isNumber())
		{
			var = (UINT64)be.numberInt();
			return ;
		}
		MsgAssert(false,__FUNCTION__ << " to UINT64:" << be.toString());
		Assert(false && "BsonToCpp: invalid convert");
	}
}