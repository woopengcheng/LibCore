/************************************
FileName	:	RpcRegister.cpp
Author		:	generate by tools
HostName	:	devuser-PC
IP			:	10.236.41.54
Version		:	0.0.1
Description	:	注册每个函数.以及检测网络传递的消息是否是正确的参数.
************************************/
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "CUtil/inc/Chunk.h"
#include "MsgNameDefine.h"
#include "GlobalRpc.h"
#include "DBClient.h"
#include "GlobalRpc.h"

namespace Client
{
	//tool defaultParams define here.
	static int g_rpcDefaultParam_int = 0;
	static short g_rpcDefaultParam_short = 0;
	static long g_rpcDefaultParam_long = 0;
	static char g_rpcDefaultParam_char = char(0);
	static unsigned int g_rpcDefaultParam_unsigned_int = 0;
	static unsigned short g_rpcDefaultParam_unsigned_short = 0;
	static unsigned char g_rpcDefaultParam_unsigned_char = 0;
	static std::string g_rpcDefaultParam_std__string = std::string();
	static time_t g_rpcDefaultParam_time_t = 0;
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static double g_rpcDefaultParam_double = 0.0f;
	static float g_rpcDefaultParam_float = 0.0f;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static CUtilChunk g_rpcDefaultParam_CUtilChunk = CUtil::Chunk();
	static TestRpcData g_rpcDefaultParam_TestRpcData = TestRpcData();
	static TestRpcData2 g_rpcDefaultParam_TestRpcData2 = TestRpcData2();
	static std::vector<INT32> g_rpcDefaultParam_std__vector_INT32_;

	void DBClient::OnRegisterRpcs( void )
	{
		Assert(m_pRpcManager && Msg::RpcCheckParams::GetInstance());	
		static Client::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcManager); 

		//tool testMulitServerNode generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk , g_rpcDefaultParam_int , g_rpcDefaultParam_unsigned_int , g_rpcDefaultParam_char);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testMulitServerNode", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testMulitServerNode", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_sztestMulitServerNode_RpcClient , &GlobalRpc::testMulitServerNode_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_sztestMulitServerNode_RpcTimeout ,&GlobalRpc::testMulitServerNode_RpcTimeout); 
		}

		//tool testParamsAndRpcDatas generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_TestRpcData , g_rpcDefaultParam_TestRpcData2 , g_rpcDefaultParam_std__vector_INT32_);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testParamsAndRpcDatas", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testParamsAndRpcDatas", objReturnParams);
		}

		//tool SyncServerHandler generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams );
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncServerHandler", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncServerHandler", objReturnParams);
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szSyncServerHandler_RpcServer , &GlobalRpc::SyncServerHandler_RpcServer); 
		}

		//tool HandleUserAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleUserAuth", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleUserAuth_RpcClient , &GlobalRpc::HandleUserAuth_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleUserAuth_RpcTimeout ,&GlobalRpc::HandleUserAuth_RpcTimeout); 
		}

		//tool HandleSelectDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleSelectDatabase_RpcClient , &GlobalRpc::HandleSelectDatabase_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleSelectDatabase_RpcTimeout ,&GlobalRpc::HandleSelectDatabase_RpcTimeout); 
		}

		//tool HandleCreateDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateDatabase_RpcClient , &GlobalRpc::HandleCreateDatabase_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateDatabase_RpcTimeout ,&GlobalRpc::HandleCreateDatabase_RpcTimeout); 
		}

		//tool HandleDeleteDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteDatabase_RpcClient , &GlobalRpc::HandleDeleteDatabase_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteDatabase_RpcTimeout ,&GlobalRpc::HandleDeleteDatabase_RpcTimeout); 
		}

		//tool HandleShowDatabases generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams );
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowDatabases", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleShowDatabases_RpcClient , &GlobalRpc::HandleShowDatabases_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleShowDatabases_RpcTimeout ,&GlobalRpc::HandleShowDatabases_RpcTimeout); 
		}

		//tool HandleShowUsers generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams );
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowUsers", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowUsers", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleShowUsers_RpcClient , &GlobalRpc::HandleShowUsers_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleShowUsers_RpcTimeout ,&GlobalRpc::HandleShowUsers_RpcTimeout); 
		}

		//tool HandleCreateUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateUser", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateUser_RpcClient , &GlobalRpc::HandleCreateUser_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateUser_RpcTimeout ,&GlobalRpc::HandleCreateUser_RpcTimeout); 
		}

		//tool HandleDeleteUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteUser", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteUser_RpcClient , &GlobalRpc::HandleDeleteUser_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteUser_RpcTimeout ,&GlobalRpc::HandleDeleteUser_RpcTimeout); 
		}

		//tool HandleModifyUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleModifyUser", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleModifyUser_RpcClient , &GlobalRpc::HandleModifyUser_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleModifyUser_RpcTimeout ,&GlobalRpc::HandleModifyUser_RpcTimeout); 
		}

		//tool HandleHSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSet", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSet_RpcClient , &GlobalRpc::HandleHSet_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSet_RpcTimeout ,&GlobalRpc::HandleHSet_RpcTimeout); 
		}

		//tool HandleHSetNX generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetNX", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetNX_RpcClient , &GlobalRpc::HandleHSetNX_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetNX_RpcTimeout ,&GlobalRpc::HandleHSetNX_RpcTimeout); 
		}

		//tool HandleHSetOW generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetOW", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetOW_RpcClient , &GlobalRpc::HandleHSetOW_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetOW_RpcTimeout ,&GlobalRpc::HandleHSetOW_RpcTimeout); 
		}

		//tool HandleHGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGet", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGet_RpcClient , &GlobalRpc::HandleHGet_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGet_RpcTimeout ,&GlobalRpc::HandleHGet_RpcTimeout); 
		}

		//tool HandleHDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDel", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDel_RpcClient , &GlobalRpc::HandleHDel_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDel_RpcTimeout ,&GlobalRpc::HandleHDel_RpcTimeout); 
		}

		//tool HandleHSetIncr generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncr", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncr_RpcClient , &GlobalRpc::HandleHSetIncr_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncr_RpcTimeout ,&GlobalRpc::HandleHSetIncr_RpcTimeout); 
		}

		//tool HandleHSetIncrFloat generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncrFloat_RpcClient , &GlobalRpc::HandleHSetIncrFloat_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncrFloat_RpcTimeout ,&GlobalRpc::HandleHSetIncrFloat_RpcTimeout); 
		}

		//tool HandleHGetKeys generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeys", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeys_RpcClient , &GlobalRpc::HandleHGetKeys_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeys_RpcTimeout ,&GlobalRpc::HandleHGetKeys_RpcTimeout); 
		}

		//tool HandleHGetVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetVals", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetVals_RpcClient , &GlobalRpc::HandleHGetVals_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetVals_RpcTimeout ,&GlobalRpc::HandleHGetVals_RpcTimeout); 
		}

		//tool HandleHGetKeyVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeyVals_RpcClient , &GlobalRpc::HandleHGetKeyVals_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeyVals_RpcTimeout ,&GlobalRpc::HandleHGetKeyVals_RpcTimeout); 
		}

		//tool HandleHScan generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHScan", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHScan_RpcClient , &GlobalRpc::HandleHScan_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHScan_RpcTimeout ,&GlobalRpc::HandleHScan_RpcTimeout); 
		}

		//tool HandleHCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHCount", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHCount_RpcClient , &GlobalRpc::HandleHCount_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHCount_RpcTimeout ,&GlobalRpc::HandleHCount_RpcTimeout); 
		}

		//tool HandleHDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDrop", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDrop_RpcClient , &GlobalRpc::HandleHDrop_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDrop_RpcTimeout ,&GlobalRpc::HandleHDrop_RpcTimeout); 
		}

		//tool HandleHList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams );
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHList", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHList_RpcClient , &GlobalRpc::HandleHList_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHList_RpcTimeout ,&GlobalRpc::HandleHList_RpcTimeout); 
		}

		//tool HandleHMultiSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiSet", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiSet_RpcClient , &GlobalRpc::HandleHMultiSet_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiSet_RpcTimeout ,&GlobalRpc::HandleHMultiSet_RpcTimeout); 
		}

		//tool HandleHMultiGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiGet", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiGet_RpcClient , &GlobalRpc::HandleHMultiGet_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiGet_RpcTimeout ,&GlobalRpc::HandleHMultiGet_RpcTimeout); 
		}

		//tool HandleHMultiDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiDel", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiDel_RpcClient , &GlobalRpc::HandleHMultiDel_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiDel_RpcTimeout ,&GlobalRpc::HandleHMultiDel_RpcTimeout); 
		}

		//tool HandleZSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZSet", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZSet_RpcClient , &GlobalRpc::HandleZSet_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZSet_RpcTimeout ,&GlobalRpc::HandleZSet_RpcTimeout); 
		}

		//tool HandleZGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZGet", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZGet_RpcClient , &GlobalRpc::HandleZGet_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZGet_RpcTimeout ,&GlobalRpc::HandleZGet_RpcTimeout); 
		}

		//tool HandleZDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDel", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDel_RpcClient , &GlobalRpc::HandleZDel_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDel_RpcTimeout ,&GlobalRpc::HandleZDel_RpcTimeout); 
		}

		//tool HandleZTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZTop", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZTop_RpcClient , &GlobalRpc::HandleZTop_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZTop_RpcTimeout ,&GlobalRpc::HandleZTop_RpcTimeout); 
		}

		//tool HandleZRTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZRTop", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZRTop_RpcClient , &GlobalRpc::HandleZRTop_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZRTop_RpcTimeout ,&GlobalRpc::HandleZRTop_RpcTimeout); 
		}

		//tool HandleZDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDrop", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDrop_RpcClient , &GlobalRpc::HandleZDrop_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDrop_RpcTimeout ,&GlobalRpc::HandleZDrop_RpcTimeout); 
		}

		//tool HandleZCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZCount", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZCount_RpcClient , &GlobalRpc::HandleZCount_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZCount_RpcTimeout ,&GlobalRpc::HandleZCount_RpcTimeout); 
		}

		//tool HandleZList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams );
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZList", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZList_RpcClient , &GlobalRpc::HandleZList_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZList_RpcTimeout ,&GlobalRpc::HandleZList_RpcTimeout); 
		}

		//tool HandleDump generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams );
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDump", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDump_RpcClient , &GlobalRpc::HandleDump_RpcClient); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDump_RpcTimeout ,&GlobalRpc::HandleDump_RpcTimeout); 
		}

		//tool SyncMasterHandler generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncMasterHandler", objReturnParams);
		}

		//tool SlaveStartAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveStartAuth", objReturnParams);
		}

		//tool SlaveSelectDB generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveSelectDB", objReturnParams);
		}

		//tool SlaveRequestSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveRequestSync", objReturnParams);
		}

		//tool MasterStartSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("MasterStartSync", objReturnParams);
		}

		//tool SyncDataToSlave generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenParamHelper::GenParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenParamHelper::GenParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncDataToSlave", objReturnParams);
		}

		Client::GlobalRpc::InitObjectFuncs();
	}

	CollectionObjectFuncsT Client::GlobalRpc::s_setFuncs;
}//Client

