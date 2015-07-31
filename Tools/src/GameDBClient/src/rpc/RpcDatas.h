/************************************
FileName	:	RpcDatas.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-01 00:59:19
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
		int userid1;
		unsigned int localid2;
		char userid3;
		unsigned char localid4;
		long localid6;
		time_t userid7;
		short localid8;
		unsigned short userid9;
		double localid10;
		float localid11;
		std_string localid12;
		LibCore_Chunk localid13;

		TestRpcData()
			: userid1( 111 ) 
			, localid2( 21 ) 
			, userid3( 0 ) 
			, localid4( 0 ) 
			, localid6( 0 ) 
			, userid7( 0 ) 
			, localid8( 0 ) 
			, userid9( 0 ) 
			, localid10( 1.0f ) 
			, localid11( 1.0f ) 
			, localid12( std::string() ) 
			, localid13( LibCore::Chunk() ) 
			{}
	}; 
 
	class TestRpcData2
	{ 
		public:
		SINT8 userid1;
		UINT8 localid2;
		INT16 userid3;
		UINT16 localid4;
		INT32 localid6;
		UINT32 userid7;
		INT64 localid8;
		UINT64 userid9;
		double localid10;
		float localid11;
		std_string localid12;
		LibCore_Chunk localid13;

		TestRpcData2()
			: userid1( 0 ) 
			, localid2( 0 ) 
			, userid3( 0 ) 
			, localid4( 0 ) 
			, localid6( 0 ) 
			, userid7( 0 ) 
			, localid8( 0 ) 
			, userid9( 0 ) 
			, localid10( 1.0f ) 
			, localid11( 1.0f ) 
			, localid12( std::string() ) 
			, localid13( LibCore::Chunk() ) 
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

			objParam.GetParamStream() >> unType  >> val.userid1 >> val.localid2 >> val.userid3 >> val.localid4 >> val.localid6 >> val.userid7 >> val.localid8 >> val.userid9 >> val.localid10 >> val.localid11 >> val.localid12 >> val.localid13;
			MsgAssert_Re(unType == PARAMETER_TYPE_USER_DEFINE_TestRpcData , val , "get param error.");

			return val;
		}

		static void MakeParameter(Parameter & objParam , Client::TestRpcData val)
		{ 
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_USER_DEFINE_TestRpcData << val.userid1 << val.localid2 << val.userid3 << val.localid4 << val.localid6 << val.userid7 << val.localid8 << val.userid9 << val.localid10 << val.localid11 << val.localid12 << val.localid13;
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

			objParam.GetParamStream() >> unType  >> val.userid1 >> val.localid2 >> val.userid3 >> val.localid4 >> val.localid6 >> val.userid7 >> val.localid8 >> val.userid9 >> val.localid10 >> val.localid11 >> val.localid12 >> val.localid13;
			MsgAssert_Re(unType == PARAMETER_TYPE_USER_DEFINE_TestRpcData2 , val , "get param error.");

			return val;
		}

		static void MakeParameter(Parameter & objParam , Client::TestRpcData2 val)
		{ 
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_USER_DEFINE_TestRpcData2 << val.userid1 << val.localid2 << val.userid3 << val.localid4 << val.localid6 << val.userid7 << val.localid8 << val.userid9 << val.localid10 << val.localid11 << val.localid12 << val.localid13;
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
