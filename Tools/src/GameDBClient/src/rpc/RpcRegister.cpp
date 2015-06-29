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
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
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
		//5 HandleUserAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleUserAuth", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleUserAuth_RpcTimeout , &Msg::GlobalRpc::HandleUserAuth_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleUserAuth_RpcClient , &Msg::GlobalRpc::HandleUserAuth_RpcClient); 
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleSelectDatabase_RpcTimeout , &Msg::GlobalRpc::HandleSelectDatabase_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleSelectDatabase_RpcClient , &Msg::GlobalRpc::HandleSelectDatabase_RpcClient); 
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleCreateDatabase_RpcTimeout , &Msg::GlobalRpc::HandleCreateDatabase_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleCreateDatabase_RpcClient , &Msg::GlobalRpc::HandleCreateDatabase_RpcClient); 
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleDeleteDatabase_RpcTimeout , &Msg::GlobalRpc::HandleDeleteDatabase_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleDeleteDatabase_RpcClient , &Msg::GlobalRpc::HandleDeleteDatabase_RpcClient); 
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleShowDatabases", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleShowDatabases_RpcTimeout , &Msg::GlobalRpc::HandleShowDatabases_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleShowDatabases_RpcClient , &Msg::GlobalRpc::HandleShowDatabases_RpcClient); 
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleCreateUser_RpcTimeout , &Msg::GlobalRpc::HandleCreateUser_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleCreateUser_RpcClient , &Msg::GlobalRpc::HandleCreateUser_RpcClient); 
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleDeleteUser_RpcTimeout , &Msg::GlobalRpc::HandleDeleteUser_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleDeleteUser_RpcClient , &Msg::GlobalRpc::HandleDeleteUser_RpcClient); 
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleModifyUser", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleModifyUser_RpcTimeout , &Msg::GlobalRpc::HandleModifyUser_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleModifyUser_RpcClient , &Msg::GlobalRpc::HandleModifyUser_RpcClient); 
		}

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

		//5 HandleHSetNX generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetNX", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetNX_RpcTimeout , &Msg::GlobalRpc::HandleHSetNX_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetNX_RpcClient , &Msg::GlobalRpc::HandleHSetNX_RpcClient); 
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetOW", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetOW_RpcTimeout , &Msg::GlobalRpc::HandleHSetOW_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetOW_RpcClient , &Msg::GlobalRpc::HandleHSetOW_RpcClient); 
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

		//5 HandleHDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHDel_RpcTimeout , &Msg::GlobalRpc::HandleHDel_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHDel_RpcClient , &Msg::GlobalRpc::HandleHDel_RpcClient); 
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncr", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetIncr_RpcTimeout , &Msg::GlobalRpc::HandleHSetIncr_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetIncr_RpcClient , &Msg::GlobalRpc::HandleHSetIncr_RpcClient); 
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetIncrFloat_RpcTimeout , &Msg::GlobalRpc::HandleHSetIncrFloat_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHSetIncrFloat_RpcClient , &Msg::GlobalRpc::HandleHSetIncrFloat_RpcClient); 
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeys", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGetKeys_RpcTimeout , &Msg::GlobalRpc::HandleHGetKeys_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGetKeys_RpcClient , &Msg::GlobalRpc::HandleHGetKeys_RpcClient); 
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGetVals_RpcTimeout , &Msg::GlobalRpc::HandleHGetVals_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGetVals_RpcClient , &Msg::GlobalRpc::HandleHGetVals_RpcClient); 
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGetKeyVals_RpcTimeout , &Msg::GlobalRpc::HandleHGetKeyVals_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHGetKeyVals_RpcClient , &Msg::GlobalRpc::HandleHGetKeyVals_RpcClient); 
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHScan", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHScan_RpcTimeout , &Msg::GlobalRpc::HandleHScan_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHScan_RpcClient , &Msg::GlobalRpc::HandleHScan_RpcClient); 
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHCount_RpcTimeout , &Msg::GlobalRpc::HandleHCount_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHCount_RpcClient , &Msg::GlobalRpc::HandleHCount_RpcClient); 
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHDrop_RpcTimeout , &Msg::GlobalRpc::HandleHDrop_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHDrop_RpcClient , &Msg::GlobalRpc::HandleHDrop_RpcClient); 
		}

		//5 HandleHList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHList", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHList_RpcTimeout , &Msg::GlobalRpc::HandleHList_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHList_RpcClient , &Msg::GlobalRpc::HandleHList_RpcClient); 
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiSet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHMultiSet_RpcTimeout , &Msg::GlobalRpc::HandleHMultiSet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHMultiSet_RpcClient , &Msg::GlobalRpc::HandleHMultiSet_RpcClient); 
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHMultiGet_RpcTimeout , &Msg::GlobalRpc::HandleHMultiGet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHMultiGet_RpcClient , &Msg::GlobalRpc::HandleHMultiGet_RpcClient); 
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHMultiDel_RpcTimeout , &Msg::GlobalRpc::HandleHMultiDel_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleHMultiDel_RpcClient , &Msg::GlobalRpc::HandleHMultiDel_RpcClient); 
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
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZGet_RpcTimeout , &Msg::GlobalRpc::HandleZGet_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZGet_RpcClient , &Msg::GlobalRpc::HandleZGet_RpcClient); 
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDel", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZDel_RpcTimeout , &Msg::GlobalRpc::HandleZDel_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZDel_RpcClient , &Msg::GlobalRpc::HandleZDel_RpcClient); 
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
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
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZRTop_RpcTimeout , &Msg::GlobalRpc::HandleZRTop_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZRTop_RpcClient , &Msg::GlobalRpc::HandleZRTop_RpcClient); 
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDrop", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZDrop_RpcTimeout , &Msg::GlobalRpc::HandleZDrop_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZDrop_RpcClient , &Msg::GlobalRpc::HandleZDrop_RpcClient); 
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZCount", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZCount_RpcTimeout , &Msg::GlobalRpc::HandleZCount_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZCount_RpcClient , &Msg::GlobalRpc::HandleZCount_RpcClient); 
		}

		//5 HandleZList generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams );
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_LibCore_Chunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZList", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZList_RpcTimeout , &Msg::GlobalRpc::HandleZList_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szHandleZList_RpcClient , &Msg::GlobalRpc::HandleZList_RpcClient); 
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

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
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

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
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
		}

	}

}

