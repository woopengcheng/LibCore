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
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static float g_rpcDefaultParam_float = 0.0f;
	static double g_rpcDefaultParam_double = 0.0f;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static LibCore_Chunk g_rpcDefaultParam_LibCore_Chunk = LibCore::Chunk();

	void DBServer::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 HandleUserAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleUserAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleUserAuth_RpcServer , &ServerHandler::HandleUserAuth_RpcServer); 
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleSelectDatabase_RpcServer , &ServerHandler::HandleSelectDatabase_RpcServer); 
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleCreateDatabase_RpcServer , &ServerHandler::HandleCreateDatabase_RpcServer); 
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleDeleteDatabase_RpcServer , &ServerHandler::HandleDeleteDatabase_RpcServer); 
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleShowDatabases", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleShowDatabases_RpcServer , &ServerHandler::HandleShowDatabases_RpcServer); 
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleCreateUser_RpcServer , &ServerHandler::HandleCreateUser_RpcServer); 
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleDeleteUser_RpcServer , &ServerHandler::HandleDeleteUser_RpcServer); 
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleModifyUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleModifyUser_RpcServer , &ServerHandler::HandleModifyUser_RpcServer); 
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

		//5 HandleHSetNX generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetNX", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetNX_RpcServer , &ServerHandler::HandleHSetNX_RpcServer); 
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetOW", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetOW_RpcServer , &ServerHandler::HandleHSetOW_RpcServer); 
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

		//5 HandleHDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHDel_RpcServer , &ServerHandler::HandleHDel_RpcServer); 
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncr", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetIncr_RpcServer , &ServerHandler::HandleHSetIncr_RpcServer); 
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetIncrFloat_RpcServer , &ServerHandler::HandleHSetIncrFloat_RpcServer); 
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeys", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGetKeys_RpcServer , &ServerHandler::HandleHGetKeys_RpcServer); 
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGetVals_RpcServer , &ServerHandler::HandleHGetVals_RpcServer); 
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGetKeyVals_RpcServer , &ServerHandler::HandleHGetKeyVals_RpcServer); 
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHScan", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHScan_RpcServer , &ServerHandler::HandleHScan_RpcServer); 
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHCount_RpcServer , &ServerHandler::HandleHCount_RpcServer); 
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHDrop_RpcServer , &ServerHandler::HandleHDrop_RpcServer); 
		}

		//5 HandleHList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHList", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHList_RpcServer , &ServerHandler::HandleHList_RpcServer); 
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHMultiSet_RpcServer , &ServerHandler::HandleHMultiSet_RpcServer); 
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHMultiGet_RpcServer , &ServerHandler::HandleHMultiGet_RpcServer); 
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHMultiDel_RpcServer , &ServerHandler::HandleHMultiDel_RpcServer); 
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

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZGet_RpcServer , &ServerHandler::HandleZGet_RpcServer); 
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZDel_RpcServer , &ServerHandler::HandleZDel_RpcServer); 
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZTop_RpcServer , &ServerHandler::HandleZTop_RpcServer); 
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZRTop_RpcServer , &ServerHandler::HandleZRTop_RpcServer); 
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZDrop_RpcServer , &ServerHandler::HandleZDrop_RpcServer); 
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZCount_RpcServer , &ServerHandler::HandleZCount_RpcServer); 
		}

		//5 HandleZList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZList", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZList_RpcServer , &ServerHandler::HandleZList_RpcServer); 
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

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncMasterHandler", objReturnParams);
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
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc >(Msg::g_szSlaveRequestSync_RpcServer , &Msg::GlobalRpc::SlaveRequestSync_RpcServer); 
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

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncDataToSlave", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSyncDataToSlave_RpcTimeout , &Msg::GlobalRpc::SyncDataToSlave_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSyncDataToSlave_RpcClient , &Msg::GlobalRpc::SyncDataToSlave_RpcClient); 
		}

		//5 testRefers generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("testRefers", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("testRefers", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sztestRefers_RpcTimeout , &Msg::GlobalRpc::testRefers_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sztestRefers_RpcClient , &Msg::GlobalRpc::testRefers_RpcClient); 
		}

	}

	void DBMaster::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 HandleUserAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleUserAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleShowDatabases", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleModifyUser", objReturnParams);
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

		//5 HandleHSetNX generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetNX", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetOW", objReturnParams);
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

		//5 HandleHDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncr", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeys", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHScan", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHList", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiDel", objReturnParams);
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

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZList", objReturnParams);
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

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncMasterHandler", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSyncMasterHandler_RpcTimeout , &Msg::GlobalRpc::SyncMasterHandler_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szSyncMasterHandler_RpcClient , &Msg::GlobalRpc::SyncMasterHandler_RpcClient); 
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

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncDataToSlave", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc >(Msg::g_szSyncDataToSlave_RpcServerProxy , &Msg::GlobalRpc::SyncDataToSlave_RpcServerProxy); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc >(Msg::g_szSyncDataToSlave_RpcClientProxy , &Msg::GlobalRpc::SyncDataToSlave_RpcClientProxy); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc >(Msg::g_szSyncDataToSlave_RpcTimeoutProxy ,&Msg::GlobalRpc::SyncDataToSlave_RpcTimeoutProxy); 
		}

		//5 testRefers generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("testRefers", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("testRefers", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_sztestRefers_RpcServerProxy , &MasterHandler::testRefers_RpcServerProxy); 
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_sztestRefers_RpcClientProxy , &MasterHandler::testRefers_RpcClientProxy); 
			m_pRpcServerManager->RegisterFunc<MasterHandler >(Msg::g_sztestRefers_RpcTimeoutProxy ,&MasterHandler::testRefers_RpcTimeoutProxy); 
		}

	}

	void DBSlave::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 HandleUserAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleUserAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleShowDatabases", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleModifyUser", objReturnParams);
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

		//5 HandleHSetNX generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetNX", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetOW", objReturnParams);
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

		//5 HandleHDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncr", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeys", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHScan", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHList", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiDel", objReturnParams);
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

		//5 HandleZGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
		}

		//5 HandleZList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZList", objReturnParams);
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

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncMasterHandler", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<SlaveHandler >(Msg::g_szSyncMasterHandler_RpcServer , &SlaveHandler::SyncMasterHandler_RpcServer); 
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

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncDataToSlave", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<SlaveHandler >(Msg::g_szSyncDataToSlave_RpcServer , &SlaveHandler::SyncDataToSlave_RpcServer); 
		}

		//5 testRefers generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("testRefers", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("testRefers", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<SlaveHandler >(Msg::g_sztestRefers_RpcServer , &SlaveHandler::testRefers_RpcServer); 
		}

	}

}

