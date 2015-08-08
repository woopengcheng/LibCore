/************************************
FileName	:	RpcDatas.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-04 23:18:38
Description	:	网络消息的数据域.
************************************/
#ifndef __Client_rpc_datas_h__
#define __Client_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"
#include "MsgLib/inc/Parameter.h"
#include "MsgLib/inc/ParameterHelper.h"

namespace Client
{
	class TestRpcData
	{ 
		public:
		int p1;
		unsigned int p2;
		char p3;
		unsigned char p4;
		std::vector<INT32> p5;
		long p6;
		time_t p7;
		short p8;
		unsigned short p9;
		double p10;
		float p11;
		std_string p12;
		LibCore_Chunk p13;

		TestRpcData()
			: p1( 111 ) 
			, p2( 21 ) 
			, p3( 0 ) 
			, p4( 0 ) 
			, p5( std::vector<INT32>(1) ) 
			, p6( 0 ) 
			, p7( 0 ) 
			, p8( 0 ) 
			, p9( 0 ) 
			, p10( 1.0f ) 
			, p11( 1.0f ) 
			, p12( std::string() ) 
			, p13( LibCore::Chunk() ) 
			{}
	}; 
 
	class TestRpcData2
	{ 
		public:
		SINT8 p1;
		UINT8 p2;
		INT16 p3;
		UINT16 p4;
		INT32 p6;
		UINT32 p7;
		INT64 p8;
		UINT64 p9;

		TestRpcData2()
			: p1( 0 ) 
			, p2( 0 ) 
			, p3( 0 ) 
			, p4( 0 ) 
			, p6( 0 ) 
			, p7( 0 ) 
			, p8( 0 ) 
			, p9( 0 ) 
			{}
	}; 
 
}//Client

namespace Msg
{ 
	enum PARAMETER_TYPE_USER_DEFINES 
	{ 
		PARAMETER_TYPE_USER_DEFINE_FIRST = Msg::PARAMETER_TYPE_USER_DEFINE  ,
		PARAMETER_TYPE_USER_DEFINE_TestRpcData,
		PARAMETER_TYPE_USER_DEFINE_TestRpcData2,
	}; 
 
	template<> class Msg::ParameterHelper<Client::TestRpcData>
	{ 
	public:
		static UINT32 GetParameterType()
		{ 
			return PARAMETER_TYPE_USER_DEFINE_TestRpcData;
		} 

		static Client::TestRpcData GetParameterValue(Parameter & objParam)
		{ 
			INT32 unType = 0;
			Client::TestRpcData val;

			objParam.GetParamStream() >> unType  >> val.p1 >> val.p2 >> val.p3 >> val.p4 >> val.p5 >> val.p6 >> val.p7 >> val.p8 >> val.p9 >> val.p10 >> val.p11 >> val.p12 >> val.p13;
			MsgAssert_Re(unType == PARAMETER_TYPE_USER_DEFINE_TestRpcData , val , "get param error.");

			return val;
		}

		static void MakeParameter(Parameter & objParam , Client::TestRpcData val)
		{ 
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_USER_DEFINE_TestRpcData << val.p1 << val.p2 << val.p3 << val.p4 << val.p5 << val.p6 << val.p7 << val.p8 << val.p9 << val.p10 << val.p11 << val.p12 << val.p13;
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{ 
			if (objParam.GetType() == PARAMETER_TYPE_USER_DEFINE_TestRpcData)
			{ 
				return TRUE; 
			} 

			return FALSE; 
		} 

	}; 
 
	template<> class Msg::ParameterHelper<Client::TestRpcData&>
	{ 
	public:
		static UINT32 GetParameterType()
		{ 
			return PARAMETER_TYPE_USER_DEFINE_TestRpcData;
		} 

		static Client::TestRpcData GetParameterValue(Parameter & objParam)
		{ 
			return ParameterHelper<Client::TestRpcData>::GetParameterValue(objParam);

		} 
		static void MakeParameter(Parameter & objParam , Client::TestRpcData val)
		{ 
			return ParameterHelper<Client::TestRpcData>::MakeParameter(objParam , val);
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{ 
			if (objParam.GetType() == PARAMETER_TYPE_USER_DEFINE_TestRpcData)
			{ 
				return TRUE; 
			} 

			return FALSE; 
		} 

	}; 
 
	template<> class Msg::ParameterHelper<Client::TestRpcData2>
	{ 
	public:
		static UINT32 GetParameterType()
		{ 
			return PARAMETER_TYPE_USER_DEFINE_TestRpcData2;
		} 

		static Client::TestRpcData2 GetParameterValue(Parameter & objParam)
		{ 
			INT32 unType = 0;
			Client::TestRpcData2 val;

			objParam.GetParamStream() >> unType  >> val.p1 >> val.p2 >> val.p3 >> val.p4 >> val.p6 >> val.p7 >> val.p8 >> val.p9;
			MsgAssert_Re(unType == PARAMETER_TYPE_USER_DEFINE_TestRpcData2 , val , "get param error.");

			return val;
		}

		static void MakeParameter(Parameter & objParam , Client::TestRpcData2 val)
		{ 
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_USER_DEFINE_TestRpcData2 << val.p1 << val.p2 << val.p3 << val.p4 << val.p6 << val.p7 << val.p8 << val.p9;
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{ 
			if (objParam.GetType() == PARAMETER_TYPE_USER_DEFINE_TestRpcData2)
			{ 
				return TRUE; 
			} 

			return FALSE; 
		} 

	}; 
 
	template<> class Msg::ParameterHelper<Client::TestRpcData2&>
	{ 
	public:
		static UINT32 GetParameterType()
		{ 
			return PARAMETER_TYPE_USER_DEFINE_TestRpcData2;
		} 

		static Client::TestRpcData2 GetParameterValue(Parameter & objParam)
		{ 
			return ParameterHelper<Client::TestRpcData2>::GetParameterValue(objParam);

		} 
		static void MakeParameter(Parameter & objParam , Client::TestRpcData2 val)
		{ 
			return ParameterHelper<Client::TestRpcData2>::MakeParameter(objParam , val);
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{ 
			if (objParam.GetType() == PARAMETER_TYPE_USER_DEFINE_TestRpcData2)
			{ 
				return TRUE; 
			} 

			return FALSE; 
		} 

	}; 
 
}

#endif
