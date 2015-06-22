#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "Common/Chunk.h"
#include "GlobalRpc.h"
#include "MsgNameDefine.h"
#include "DBServer.h"
#include "DBMaster.h"
#include "DBSlave.h"
#include "ServerHandler.h"
#include "MasterHandler.h"
#include "SlaveHandler.h"

namespace Server
{
	//5 defaultParams define here.
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static float g_rpcDefaultParam_float = 0.0f;
	static double g_rpcDefaultParam_double = 0.0f;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static LibCore_Chunk g_rpcDefaultParam_LibCore_Chunk = LibCore::Chunk();

	void DBServer::OnRegisterRpcs( void )
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

		//5 HandleZSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZSet_RpcServer , &ServerHandler::HandleZSet_RpcServer); 
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleCreateUser_RpcServer , &ServerHandler::HandleCreateUser_RpcServer); 
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZGet_RpcServer , &ServerHandler::HandleZGet_RpcServer); 
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZTop_RpcServer , &ServerHandler::HandleZTop_RpcServer); 
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZRTop_RpcServer , &ServerHandler::HandleZRTop_RpcServer); 
		}

		//5 HandleDump generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDump", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleDump_RpcServer , &ServerHandler::HandleDump_RpcServer); 
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveStartAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szSlaveStartAuth_RpcServer , &ServerHandler::SlaveStartAuth_RpcServer); 
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

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szSlaveRequestSync_RpcServer , &ServerHandler::SlaveRequestSync_RpcServer); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

	}

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

		//5 HandleZSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleDump generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDump", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveStartAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveStartAuth_RpcServerProxy , &MasterHandler::SlaveStartAuth_RpcServerProxy); 
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveStartAuth_RpcClientProxy , &MasterHandler::SlaveStartAuth_RpcClientProxy); 
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveStartAuth_RpcTimeoutProxy ,&MasterHandler::SlaveStartAuth_RpcTimeoutProxy); 
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveSelectDB", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveSelectDB_RpcServer , &MasterHandler::SlaveSelectDB_RpcServer); 
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcServerProxy , &MasterHandler::SlaveRequestSync_RpcServerProxy); 
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcClientProxy , &MasterHandler::SlaveRequestSync_RpcClientProxy); 
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcTimeoutProxy ,&MasterHandler::SlaveRequestSync_RpcTimeoutProxy); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szMasterStartSync_RpcTimeout , &Msg::GlobalRpc::MasterStartSync_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szMasterStartSync_RpcClient , &Msg::GlobalRpc::MasterStartSync_RpcClient); 
		}

	}

	void DBSlave::OnRegisterRpcs( void )
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

		//5 HandleZSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleDump generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDump", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveStartAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveStartAuth_RpcTimeout , &Msg::GlobalRpc::SlaveStartAuth_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveStartAuth_RpcClient , &Msg::GlobalRpc::SlaveStartAuth_RpcClient); 
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveSelectDB", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveSelectDB_RpcTimeout , &Msg::GlobalRpc::SlaveSelectDB_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveSelectDB_RpcClient , &Msg::GlobalRpc::SlaveSelectDB_RpcClient); 
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveRequestSync_RpcTimeout , &Msg::GlobalRpc::SlaveRequestSync_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSlaveRequestSync_RpcClient , &Msg::GlobalRpc::SlaveRequestSync_RpcClient); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<SlaveHandler >(Msg::g_szMasterStartSync_RpcServer , &SlaveHandler::MasterStartSync_RpcServer); 
		}

	}

}

