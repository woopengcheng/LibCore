/************************************
FileName	:	RpcRegister.cpp
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-09-16 00:04:34
Description	:	注册每个函数.以及检测网络传递的消息是否是正确的参数.
************************************/
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "CUtil/inc/Chunk.h"
#include "MsgNameDefine.h"
#include "DBClient.h"
#include "GlobalRpc.h"

namespace Client
{
	//5 defaultParams define here.
	static int g_rpcDefaultParam_int = 0;
	static short g_rpcDefaultParam_short = 0;
	static long g_rpcDefaultParam_long = 0;
	static char g_rpcDefaultParam_char = char(0);
	static unsigned int g_rpcDefaultParam_unsigned_int = 0;
	static unsigned short g_rpcDefaultParam_unsigned_short = 0;
	static unsigned char g_rpcDefaultParam_unsigned_char = 0;
	static std::string g_rpcDefaultParam_std__string = std::string();
	static time_t g_rpcDefaultParam_time_t = 0;
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static double g_rpcDefaultParam_double = 0.0f;
	static float g_rpcDefaultParam_float = 0.0f;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static CUtilChunk g_rpcDefaultParam_CUtilChunk = CUtil::Chunk();
	static TestRpcData g_rpcDefaultParam_TestRpcData = TestRpcData();
	static TestRpcData2 g_rpcDefaultParam_TestRpcData2 = TestRpcData2();
	static std::vector<INT32> g_rpcDefaultParam_std__vector_INT32_;

	void DBClient::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		static Client::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		//5 testMulitServerNode generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk , g_rpcDefaultParam_int , g_rpcDefaultParam_unsigned_int , g_rpcDefaultParam_char);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("testMulitServerNode", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("testMulitServerNode", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_sztestMulitServerNode_RpcClient , &GlobalRpc::testMulitServerNode_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_sztestMulitServerNode_RpcTimeout ,&GlobalRpc::testMulitServerNode_RpcTimeout); 
		}

		//5 testParamsAndRpcDatas generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_TestRpcData , g_rpcDefaultParam_TestRpcData2 , g_rpcDefaultParam_std__vector_INT32_);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("testParamsAndRpcDatas", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("testParamsAndRpcDatas", objReturnParams);
		}

		//5 HandleUserAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleUserAuth", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleUserAuth_RpcClient , &GlobalRpc::HandleUserAuth_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleUserAuth_RpcTimeout ,&GlobalRpc::HandleUserAuth_RpcTimeout); 
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleSelectDatabase_RpcClient , &GlobalRpc::HandleSelectDatabase_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleSelectDatabase_RpcTimeout ,&GlobalRpc::HandleSelectDatabase_RpcTimeout); 
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateDatabase_RpcClient , &GlobalRpc::HandleCreateDatabase_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateDatabase_RpcTimeout ,&GlobalRpc::HandleCreateDatabase_RpcTimeout); 
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteDatabase_RpcClient , &GlobalRpc::HandleDeleteDatabase_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteDatabase_RpcTimeout ,&GlobalRpc::HandleDeleteDatabase_RpcTimeout); 
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleShowDatabases", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleShowDatabases_RpcClient , &GlobalRpc::HandleShowDatabases_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleShowDatabases_RpcTimeout ,&GlobalRpc::HandleShowDatabases_RpcTimeout); 
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleCreateUser", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateUser_RpcClient , &GlobalRpc::HandleCreateUser_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleCreateUser_RpcTimeout ,&GlobalRpc::HandleCreateUser_RpcTimeout); 
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDeleteUser", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteUser_RpcClient , &GlobalRpc::HandleDeleteUser_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDeleteUser_RpcTimeout ,&GlobalRpc::HandleDeleteUser_RpcTimeout); 
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleModifyUser", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleModifyUser_RpcClient , &GlobalRpc::HandleModifyUser_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleModifyUser_RpcTimeout ,&GlobalRpc::HandleModifyUser_RpcTimeout); 
		}

		//5 HandleHSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSet", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSet_RpcClient , &GlobalRpc::HandleHSet_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSet_RpcTimeout ,&GlobalRpc::HandleHSet_RpcTimeout); 
		}

		//5 HandleHSetNX generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetNX", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetNX_RpcClient , &GlobalRpc::HandleHSetNX_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetNX_RpcTimeout ,&GlobalRpc::HandleHSetNX_RpcTimeout); 
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetOW", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetOW_RpcClient , &GlobalRpc::HandleHSetOW_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetOW_RpcTimeout ,&GlobalRpc::HandleHSetOW_RpcTimeout); 
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGet", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGet_RpcClient , &GlobalRpc::HandleHGet_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGet_RpcTimeout ,&GlobalRpc::HandleHGet_RpcTimeout); 
		}

		//5 HandleHDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDel", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDel_RpcClient , &GlobalRpc::HandleHDel_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDel_RpcTimeout ,&GlobalRpc::HandleHDel_RpcTimeout); 
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncr", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncr_RpcClient , &GlobalRpc::HandleHSetIncr_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncr_RpcTimeout ,&GlobalRpc::HandleHSetIncr_RpcTimeout); 
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncrFloat_RpcClient , &GlobalRpc::HandleHSetIncrFloat_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHSetIncrFloat_RpcTimeout ,&GlobalRpc::HandleHSetIncrFloat_RpcTimeout); 
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeys", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeys_RpcClient , &GlobalRpc::HandleHGetKeys_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeys_RpcTimeout ,&GlobalRpc::HandleHGetKeys_RpcTimeout); 
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetVals", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetVals_RpcClient , &GlobalRpc::HandleHGetVals_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetVals_RpcTimeout ,&GlobalRpc::HandleHGetVals_RpcTimeout); 
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeyVals_RpcClient , &GlobalRpc::HandleHGetKeyVals_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHGetKeyVals_RpcTimeout ,&GlobalRpc::HandleHGetKeyVals_RpcTimeout); 
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHScan", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHScan_RpcClient , &GlobalRpc::HandleHScan_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHScan_RpcTimeout ,&GlobalRpc::HandleHScan_RpcTimeout); 
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHCount", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHCount_RpcClient , &GlobalRpc::HandleHCount_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHCount_RpcTimeout ,&GlobalRpc::HandleHCount_RpcTimeout); 
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHDrop", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDrop_RpcClient , &GlobalRpc::HandleHDrop_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHDrop_RpcTimeout ,&GlobalRpc::HandleHDrop_RpcTimeout); 
		}

		//5 HandleHList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHList", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHList_RpcClient , &GlobalRpc::HandleHList_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHList_RpcTimeout ,&GlobalRpc::HandleHList_RpcTimeout); 
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiSet", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiSet_RpcClient , &GlobalRpc::HandleHMultiSet_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiSet_RpcTimeout ,&GlobalRpc::HandleHMultiSet_RpcTimeout); 
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiGet", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiGet_RpcClient , &GlobalRpc::HandleHMultiGet_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiGet_RpcTimeout ,&GlobalRpc::HandleHMultiGet_RpcTimeout); 
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleHMultiDel", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiDel_RpcClient , &GlobalRpc::HandleHMultiDel_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleHMultiDel_RpcTimeout ,&GlobalRpc::HandleHMultiDel_RpcTimeout); 
		}

		//5 HandleZSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZSet", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZSet_RpcClient , &GlobalRpc::HandleZSet_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZSet_RpcTimeout ,&GlobalRpc::HandleZSet_RpcTimeout); 
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZGet", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZGet_RpcClient , &GlobalRpc::HandleZGet_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZGet_RpcTimeout ,&GlobalRpc::HandleZGet_RpcTimeout); 
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDel", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDel_RpcClient , &GlobalRpc::HandleZDel_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDel_RpcTimeout ,&GlobalRpc::HandleZDel_RpcTimeout); 
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZTop", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZTop_RpcClient , &GlobalRpc::HandleZTop_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZTop_RpcTimeout ,&GlobalRpc::HandleZTop_RpcTimeout); 
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZRTop", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZRTop_RpcClient , &GlobalRpc::HandleZRTop_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZRTop_RpcTimeout ,&GlobalRpc::HandleZRTop_RpcTimeout); 
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZDrop", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDrop_RpcClient , &GlobalRpc::HandleZDrop_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZDrop_RpcTimeout ,&GlobalRpc::HandleZDrop_RpcTimeout); 
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZCount", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZCount_RpcClient , &GlobalRpc::HandleZCount_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZCount_RpcTimeout ,&GlobalRpc::HandleZCount_RpcTimeout); 
		}

		//5 HandleZList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleZList", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZList_RpcClient , &GlobalRpc::HandleZList_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleZList_RpcTimeout ,&GlobalRpc::HandleZList_RpcTimeout); 
		}

		//5 HandleDump generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::g_pRpcCheckParams->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("HandleDump", objReturnParams);
			
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDump_RpcClient , &GlobalRpc::HandleDump_RpcClient); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc >(Msg::g_szHandleDump_RpcTimeout ,&GlobalRpc::HandleDump_RpcTimeout); 
		}

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncMasterHandler", objReturnParams);
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveStartAuth", objReturnParams);
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveSelectDB", objReturnParams);
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SlaveRequestSync", objReturnParams);
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("MasterStartSync", objReturnParams);
		}

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::g_pRpcCheckParams->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("SyncDataToSlave", objReturnParams);
		}

		Client::GlobalRpc::InitObjectFuncs();
	}

	CollectionObjectFuncsT Client::GlobalRpc::s_setFuncs;
}//Client

