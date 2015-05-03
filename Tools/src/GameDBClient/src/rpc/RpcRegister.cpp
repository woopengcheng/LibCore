#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "GlobalRpc.h"
#include "MsgNameDefine.h"
#include "DBClient.h"

namespace Client
{
	//5 defaultParams define here.
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;

	void DBClient::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 HandleHSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSet_RpcTimeout , &Msg::GlobalRpc::HandleHSet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSet_RpcClient , &Msg::GlobalRpc::HandleHSet_RpcClient); 
		}

	}

}

