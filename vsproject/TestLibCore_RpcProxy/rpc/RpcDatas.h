/************************************
FileName	:	RpcDatas.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-03 00:23:57
Description	:	网络消息的数据域.
************************************/
#ifndef __Proxy_rpc_datas_h__
#define __Proxy_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"
#include "MsgLib/inc/Parameter.h"
#include "MsgLib/inc/ParameterHelper.h"

namespace Proxy
{
	class UserLogin
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
		CUtilChunk localid13;

		UserLogin()
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
			, localid13( CUtil::Chunk() ) 
			{}
	}; 
 
}//Proxy

namespace Msg
{ 
	enum PARAMETER_TYPE_USER_DEFINES 
	{ 
		PARAMETER_TYPE_USER_DEFINE_FIRST = Msg::PARAMETER_TYPE_USER_DEFINE  ,
		PARAMETER_TYPE_USER_DEFINE_UserLogin,
	}; 
 
	template<> class Msg::ParameterHelper<Proxy::UserLogin>
	{ 
	public:
		static UINT32 GetParameterType()
		{ 
			return PARAMETER_TYPE_USER_DEFINE_UserLogin;
		} 

		static Proxy::UserLogin GetParameterValue(Parameter & objParam)
		{ 
			INT32 unType = 0;
			Proxy::UserLogin val;

			objParam.GetParamStream() >> unType  >> val.userid1 >> val.localid2 >> val.userid3 >> val.localid4 >> val.localid6 >> val.userid7 >> val.localid8 >> val.userid9 >> val.localid10 >> val.localid11 >> val.localid12 >> val.localid13;
			MsgAssert_Re(unType == PARAMETER_TYPE_USER_DEFINE_UserLogin , val , "get param error.");

			return val;
		}

		static void MakeParameter(Parameter & objParam , Proxy::UserLogin val)
		{ 
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_USER_DEFINE_UserLogin << val.userid1 << val.localid2 << val.userid3 << val.localid4 << val.localid6 << val.userid7 << val.localid8 << val.userid9 << val.localid10 << val.localid11 << val.localid12 << val.localid13;
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{ 
			if (objParam.GetType() == PARAMETER_TYPE_USER_DEFINE_UserLogin)
			{ 
				return TRUE; 
			} 

			return FALSE; 
		} 

	}; 
 
	template<> class Msg::ParameterHelper<Proxy::UserLogin&>
	{ 
	public:
		static UINT32 GetParameterType()
		{ 
			return PARAMETER_TYPE_USER_DEFINE_UserLogin;
		} 

		static Proxy::UserLogin GetParameterValue(Parameter & objParam)
		{ 
			return ParameterHelper<Proxy::UserLogin>::GetParameterValue(objParam);

		} 
		static void MakeParameter(Parameter & objParam , Proxy::UserLogin val)
		{ 
			return ParameterHelper<Proxy::UserLogin>::MakeParameter(objParam , val);
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{ 
			if (objParam.GetType() == PARAMETER_TYPE_USER_DEFINE_UserLogin)
			{ 
				return TRUE; 
			} 

			return FALSE; 
		} 

	}; 
 
}

#endif
