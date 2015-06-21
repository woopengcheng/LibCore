#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "Common/Chunk.h"
#include "GlobalRpc.h"
#include "MsgNameDefine.h"
#include "DBClient.h"

namespace Client
{
	//5 defaultParams define here.
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static float g_rpcDefaultParam_float = 0.0f;
	static double g_rpcDefaultParam_double = 0.0f;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static LibCore_Chunk g_rpcDefaultParam_LibCore_Chunk = LibCore::Chunk();

	void DBClient::OnRegisterRpcs( void )
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
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSet_RpcTimeout , &Msg::GlobalRpc::HandleHSet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSet_RpcClient , &Msg::GlobalRpc::HandleHSet_RpcClient); 
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGet_RpcTimeout , &Msg::GlobalRpc::HandleHGet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGet_RpcClient , &Msg::GlobalRpc::HandleHGet_RpcClient); 
		}

		//5 HandleZSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZSet_RpcTimeout , &Msg::GlobalRpc::HandleZSet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZSet_RpcClient , &Msg::GlobalRpc::HandleZSet_RpcClient); 
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZGet_RpcTimeout , &Msg::GlobalRpc::HandleZGet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZGet_RpcClient , &Msg::GlobalRpc::HandleZGet_RpcClient); 
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZTop_RpcTimeout , &Msg::GlobalRpc::HandleZTop_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZTop_RpcClient , &Msg::GlobalRpc::HandleZTop_RpcClient); 
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZRTop_RpcTimeout , &Msg::GlobalRpc::HandleZRTop_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZRTop_RpcClient , &Msg::GlobalRpc::HandleZRTop_RpcClient); 
		}

		//5 HandleDump generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDump", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleDump_RpcTimeout , &Msg::GlobalRpc::HandleDump_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleDump_RpcClient , &Msg::GlobalRpc::HandleDump_RpcClient); 
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

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveStartAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveSelectDB", objReturnParams);
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

	}

}

