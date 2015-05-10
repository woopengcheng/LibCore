#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "Common/Chunk.h"
#include "GlobalRpc.h"
#include "MsgNameDefine.h"
#include "DBMaster.h"
#include "MasterHandler.h"

namespace Server
{
	//5 defaultParams define here.
	static std_string g_rpcDefaultParam_std_string = std::string();
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static LibCore_Chunk g_rpcDefaultParam_LibCore_Chunk = LibCore::Chunk();
	static float g_rpcDefaultParam_float = 0.0f;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static double g_rpcDefaultParam_double = 0.0f;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;

	void DBMaster::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 HandleHSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcServer , &MasterHandler::SlaveRequestSync_RpcServer); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szMasterStartSync_RpcTimeout , &Msg::GlobalRpc::MasterStartSync_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szMasterStartSync_RpcClient , &Msg::GlobalRpc::MasterStartSync_RpcClient); 
		}

		//5 HandleHSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSet_RpcServer , &ServerHandler::HandleHSet_RpcServer); 
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGet_RpcServer , &ServerHandler::HandleHGet_RpcServer); 
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveRequestSync_RpcTimeout , &Msg::GlobalRpc::SlaveRequestSync_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveRequestSync_RpcClient , &Msg::GlobalRpc::SlaveRequestSync_RpcClient); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<SlaveHandler >(Msg::g_szMasterStartSync_RpcServer , &SlaveHandler::MasterStartSync_RpcServer); 
		}

	}

}

