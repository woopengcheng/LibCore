/************************************
FileName	:	RpcRegister.cpp
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-03 00:23:57
Description	:	注册每个函数.以及检测网络传递的消息是否是正确的参数.
************************************/
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "Common/Chunk.h"
#include "GlobalRpc.h"
#include "MsgNameDefine.h"
#include "RpcInstance.h"

namespace Proxy
{
	//5 defaultParams define here.
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static double g_rpcDefaultParam_double = 0.0f;
	static float g_rpcDefaultParam_float = 0.0f;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static LibCore_Chunk g_rpcDefaultParam_LibCore_Chunk = LibCore::Chunk();
	static UserLogin g_rpcDefaultParam_UserLogin = UserLogin();

	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		static Msg::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 TestObject generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_SINT8 , g_rpcDefaultParam_INT16 , g_rpcDefaultParam_UINT16 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_UINT32 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_UINT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("TestObject", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("TestObject", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 TestObject1 generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_SINT8 , g_rpcDefaultParam_UINT8 , g_rpcDefaultParam_INT16 , g_rpcDefaultParam_UINT16 , g_rpcDefaultParam_double , g_rpcDefaultParam_float , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("TestObject1", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("TestObject1", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

	}

}//Proxy

CollectionObjectFuncsT Msg::GlobalRpc::s_setFuncs;
