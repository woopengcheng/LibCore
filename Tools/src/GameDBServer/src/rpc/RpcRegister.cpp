/************************************
FileName	:	RpcRegister.cpp
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.1.116
Version		:	0.0.1
Date		:	2016-01-18 23:23:39
Description	:	注册每个函数.以及检测网络传递的消息是否是正确的参数.
************************************/
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "CUtil/inc/Chunk.h"
#include "MsgNameDefine.h"
#include "DBServer.h"
#include "DBMaster.h"
#include "DBSlave.h"
#include "ServerHandler.h"
#include "MasterHandler.h"
#include "GlobalRpc.h"
#include "SlaveHandler.h"

namespace Server
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
	static CUtilChunk g_rpcDefaultParam_CUtilChunk = CUtil::Chunk();
	static TestRpcData g_rpcDefaultParam_TestRpcData = TestRpcData();
	static TestRpcData2 g_rpcDefaultParam_TestRpcData2 = TestRpcData2();
	static std::vector<INT32> g_rpcDefaultParam_std__vector_INT32_;

	void DBServer::OnRegisterRpcs( void )
	{
		Assert(m_pRpcManager && Msg::RpcCheckParams::GetInstance());	
		static Server::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcManager); 

		//5 testMulitServerNode generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk , g_rpcDefaultParam_int , g_rpcDefaultParam_unsigned_int , g_rpcDefaultParam_char);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testMulitServerNode", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testMulitServerNode", objReturnParams);
			
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_sztestMulitServerNode_RpcServerProxy , &ServerHandler::testMulitServerNode_RpcServerProxy); 
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_sztestMulitServerNode_RpcClientProxy , &ServerHandler::testMulitServerNode_RpcClientProxy); 
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_sztestMulitServerNode_RpcTimeoutProxy ,&ServerHandler::testMulitServerNode_RpcTimeoutProxy); 
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_sztestMulitServerNode_RpcServer , &ServerHandler::testMulitServerNode_RpcServer); 
		}

		//5 testParamsAndRpcDatas generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_TestRpcData , g_rpcDefaultParam_TestRpcData2 , g_rpcDefaultParam_std__vector_INT32_);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testParamsAndRpcDatas", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testParamsAndRpcDatas", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_sztestParamsAndRpcDatas_RpcServer , &ServerHandler::testParamsAndRpcDatas_RpcServer); 
		}

		//5 HandleUserAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleUserAuth", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleUserAuth_RpcServer , &ServerHandler::HandleUserAuth_RpcServer); 
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleSelectDatabase", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleSelectDatabase_RpcServer , &ServerHandler::HandleSelectDatabase_RpcServer); 
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateDatabase", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleCreateDatabase_RpcServer , &ServerHandler::HandleCreateDatabase_RpcServer); 
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleDeleteDatabase_RpcServer , &ServerHandler::HandleDeleteDatabase_RpcServer); 
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowDatabases", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleShowDatabases_RpcServer , &ServerHandler::HandleShowDatabases_RpcServer); 
		}

		//5 HandleShowUsers generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowUsers", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowUsers", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleShowUsers_RpcServer , &ServerHandler::HandleShowUsers_RpcServer); 
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateUser", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleCreateUser_RpcServer , &ServerHandler::HandleCreateUser_RpcServer); 
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteUser", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleDeleteUser_RpcServer , &ServerHandler::HandleDeleteUser_RpcServer); 
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleModifyUser", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleModifyUser_RpcServer , &ServerHandler::HandleModifyUser_RpcServer); 
		}

		//5 HandleHSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSet", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSet_RpcServer , &ServerHandler::HandleHSet_RpcServer); 
		}

		//5 HandleHSetNX generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetNX", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetNX_RpcServer , &ServerHandler::HandleHSetNX_RpcServer); 
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetOW", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetOW_RpcServer , &ServerHandler::HandleHSetOW_RpcServer); 
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGet", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGet_RpcServer , &ServerHandler::HandleHGet_RpcServer); 
		}

		//5 HandleHDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDel", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHDel_RpcServer , &ServerHandler::HandleHDel_RpcServer); 
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncr", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetIncr_RpcServer , &ServerHandler::HandleHSetIncr_RpcServer); 
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHSetIncrFloat_RpcServer , &ServerHandler::HandleHSetIncrFloat_RpcServer); 
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeys", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGetKeys_RpcServer , &ServerHandler::HandleHGetKeys_RpcServer); 
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetVals", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGetVals_RpcServer , &ServerHandler::HandleHGetVals_RpcServer); 
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHGetKeyVals_RpcServer , &ServerHandler::HandleHGetKeyVals_RpcServer); 
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHScan", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHScan_RpcServer , &ServerHandler::HandleHScan_RpcServer); 
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHCount", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHCount_RpcServer , &ServerHandler::HandleHCount_RpcServer); 
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDrop", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHDrop_RpcServer , &ServerHandler::HandleHDrop_RpcServer); 
		}

		//5 HandleHList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHList", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHList_RpcServer , &ServerHandler::HandleHList_RpcServer); 
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiSet", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHMultiSet_RpcServer , &ServerHandler::HandleHMultiSet_RpcServer); 
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiGet", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHMultiGet_RpcServer , &ServerHandler::HandleHMultiGet_RpcServer); 
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiDel", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleHMultiDel_RpcServer , &ServerHandler::HandleHMultiDel_RpcServer); 
		}

		//5 HandleZSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZSet", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZSet_RpcServer , &ServerHandler::HandleZSet_RpcServer); 
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZGet", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZGet_RpcServer , &ServerHandler::HandleZGet_RpcServer); 
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDel", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZDel_RpcServer , &ServerHandler::HandleZDel_RpcServer); 
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZTop", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZTop_RpcServer , &ServerHandler::HandleZTop_RpcServer); 
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZRTop", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZRTop_RpcServer , &ServerHandler::HandleZRTop_RpcServer); 
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDrop", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZDrop_RpcServer , &ServerHandler::HandleZDrop_RpcServer); 
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZCount", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZCount_RpcServer , &ServerHandler::HandleZCount_RpcServer); 
		}

		//5 HandleZList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZList", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleZList_RpcServer , &ServerHandler::HandleZList_RpcServer); 
		}

		//5 HandleDump generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDump", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szHandleDump_RpcServer , &ServerHandler::HandleDump_RpcServer); 
		}

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncMasterHandler", objReturnParams);
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveStartAuth", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szSlaveStartAuth_RpcServer , &ServerHandler::SlaveStartAuth_RpcServer); 
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveSelectDB", objReturnParams);
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveRequestSync", objReturnParams);
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szSlaveRequestSync_RpcServer , &ServerHandler::SlaveRequestSync_RpcServer); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("MasterStartSync", objReturnParams);
		}

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncDataToSlave", objReturnParams);
			
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szSyncDataToSlave_RpcClient , &ServerHandler::SyncDataToSlave_RpcClient); 
			m_pRpcManager->RegisterFunc<ServerHandler >(Msg::g_szSyncDataToSlave_RpcTimeout ,&ServerHandler::SyncDataToSlave_RpcTimeout); 
		}

		Server::ServerHandler::InitObjectFuncs();
	}

	void DBMaster::OnRegisterRpcs( void )
	{
		Assert(m_pRpcManager && Msg::RpcCheckParams::GetInstance());	
		static Server::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcManager); 

		//5 testMulitServerNode generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk , g_rpcDefaultParam_int , g_rpcDefaultParam_unsigned_int , g_rpcDefaultParam_char);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testMulitServerNode", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testMulitServerNode", objReturnParams);
			
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_sztestMulitServerNode_RpcServerProxy , &MasterHandler::testMulitServerNode_RpcServerProxy); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_sztestMulitServerNode_RpcClientProxy , &MasterHandler::testMulitServerNode_RpcClientProxy); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_sztestMulitServerNode_RpcTimeoutProxy ,&MasterHandler::testMulitServerNode_RpcTimeoutProxy); 
		}

		//5 testParamsAndRpcDatas generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_TestRpcData , g_rpcDefaultParam_TestRpcData2 , g_rpcDefaultParam_std__vector_INT32_);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testParamsAndRpcDatas", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testParamsAndRpcDatas", objReturnParams);
			
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_sztestParamsAndRpcDatas_RpcClient , &MasterHandler::testParamsAndRpcDatas_RpcClient); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_sztestParamsAndRpcDatas_RpcTimeout ,&MasterHandler::testParamsAndRpcDatas_RpcTimeout); 
		}

		//5 HandleUserAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleUserAuth", objReturnParams);
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleSelectDatabase", objReturnParams);
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateDatabase", objReturnParams);
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowDatabases", objReturnParams);
		}

		//5 HandleShowUsers generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowUsers", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowUsers", objReturnParams);
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateUser", objReturnParams);
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteUser", objReturnParams);
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleModifyUser", objReturnParams);
		}

		//5 HandleHSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSet", objReturnParams);
		}

		//5 HandleHSetNX generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetNX", objReturnParams);
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetOW", objReturnParams);
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGet", objReturnParams);
		}

		//5 HandleHDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDel", objReturnParams);
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncr", objReturnParams);
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeys", objReturnParams);
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetVals", objReturnParams);
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHScan", objReturnParams);
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHCount", objReturnParams);
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDrop", objReturnParams);
		}

		//5 HandleHList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHList", objReturnParams);
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiSet", objReturnParams);
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiGet", objReturnParams);
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiDel", objReturnParams);
		}

		//5 HandleZSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZSet", objReturnParams);
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZGet", objReturnParams);
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDel", objReturnParams);
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZTop", objReturnParams);
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZRTop", objReturnParams);
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDrop", objReturnParams);
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZCount", objReturnParams);
		}

		//5 HandleZList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZList", objReturnParams);
		}

		//5 HandleDump generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDump", objReturnParams);
		}

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncMasterHandler", objReturnParams);
			
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSyncMasterHandler_RpcClient , &MasterHandler::SyncMasterHandler_RpcClient); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSyncMasterHandler_RpcTimeout ,&MasterHandler::SyncMasterHandler_RpcTimeout); 
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveStartAuth", objReturnParams);
			
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveStartAuth_RpcServerProxy , &MasterHandler::SlaveStartAuth_RpcServerProxy); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveStartAuth_RpcClientProxy , &MasterHandler::SlaveStartAuth_RpcClientProxy); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveStartAuth_RpcTimeoutProxy ,&MasterHandler::SlaveStartAuth_RpcTimeoutProxy); 
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveSelectDB", objReturnParams);
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveSelectDB_RpcServer , &MasterHandler::SlaveSelectDB_RpcServer); 
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveRequestSync", objReturnParams);
			
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcServerProxy , &MasterHandler::SlaveRequestSync_RpcServerProxy); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcClientProxy , &MasterHandler::SlaveRequestSync_RpcClientProxy); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szSlaveRequestSync_RpcTimeoutProxy ,&MasterHandler::SlaveRequestSync_RpcTimeoutProxy); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("MasterStartSync", objReturnParams);
			
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szMasterStartSync_RpcClient , &MasterHandler::MasterStartSync_RpcClient); 
			m_pRpcManager->RegisterFunc<MasterHandler >(Msg::g_szMasterStartSync_RpcTimeout ,&MasterHandler::MasterStartSync_RpcTimeout); 
		}

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncDataToSlave", objReturnParams);
			
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szSyncDataToSlave_RpcServerProxy , &GlobalRpc::SyncDataToSlave_RpcServerProxy); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szSyncDataToSlave_RpcClientProxy , &GlobalRpc::SyncDataToSlave_RpcClientProxy); 
			m_pRpcManager->RegisterFunc<GlobalRpc >(Msg::g_szSyncDataToSlave_RpcTimeoutProxy ,&GlobalRpc::SyncDataToSlave_RpcTimeoutProxy); 
		}

		Server::MasterHandler::InitObjectFuncs();
		Server::GlobalRpc::InitObjectFuncs();
	}

	void DBSlave::OnRegisterRpcs( void )
	{
		Assert(m_pRpcManager && Msg::RpcCheckParams::GetInstance());	
		static Server::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcManager); 

		//5 testMulitServerNode generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk , g_rpcDefaultParam_int , g_rpcDefaultParam_unsigned_int , g_rpcDefaultParam_char);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testMulitServerNode", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testMulitServerNode", objReturnParams);
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_sztestMulitServerNode_RpcServer , &SlaveHandler::testMulitServerNode_RpcServer); 
		}

		//5 testParamsAndRpcDatas generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_TestRpcData , g_rpcDefaultParam_TestRpcData2 , g_rpcDefaultParam_std__vector_INT32_);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("testParamsAndRpcDatas", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("testParamsAndRpcDatas", objReturnParams);
		}

		//5 HandleUserAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleUserAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleUserAuth", objReturnParams);
		}

		//5 HandleSelectDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleSelectDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleSelectDatabase", objReturnParams);
		}

		//5 HandleCreateDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateDatabase", objReturnParams);
		}

		//5 HandleDeleteDatabase generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteDatabase", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteDatabase", objReturnParams);
		}

		//5 HandleShowDatabases generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowDatabases", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowDatabases", objReturnParams);
		}

		//5 HandleShowUsers generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleShowUsers", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleShowUsers", objReturnParams);
		}

		//5 HandleCreateUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleCreateUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleCreateUser", objReturnParams);
		}

		//5 HandleDeleteUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDeleteUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDeleteUser", objReturnParams);
		}

		//5 HandleModifyUser generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_SINT8);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleModifyUser", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleModifyUser", objReturnParams);
		}

		//5 HandleHSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSet", objReturnParams);
		}

		//5 HandleHSetNX generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetNX", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetNX", objReturnParams);
		}

		//5 HandleHSetOW generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetOW", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetOW", objReturnParams);
		}

		//5 HandleHGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGet", objReturnParams);
		}

		//5 HandleHDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDel", objReturnParams);
		}

		//5 HandleHSetIncr generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncr", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncr", objReturnParams);
		}

		//5 HandleHSetIncrFloat generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_double);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_double);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHSetIncrFloat", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHSetIncrFloat", objReturnParams);
		}

		//5 HandleHGetKeys generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeys", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeys", objReturnParams);
		}

		//5 HandleHGetVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetVals", objReturnParams);
		}

		//5 HandleHGetKeyVals generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHGetKeyVals", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHGetKeyVals", objReturnParams);
		}

		//5 HandleHScan generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHScan", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHScan", objReturnParams);
		}

		//5 HandleHCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHCount", objReturnParams);
		}

		//5 HandleHDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHDrop", objReturnParams);
		}

		//5 HandleHList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHList", objReturnParams);
		}

		//5 HandleHMultiSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiSet", objReturnParams);
		}

		//5 HandleHMultiGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiGet", objReturnParams);
		}

		//5 HandleHMultiDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleHMultiDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleHMultiDel", objReturnParams);
		}

		//5 HandleZSet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZSet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZSet", objReturnParams);
		}

		//5 HandleZGet generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZGet", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZGet", objReturnParams);
		}

		//5 HandleZDel generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDel", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDel", objReturnParams);
		}

		//5 HandleZTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZTop", objReturnParams);
		}

		//5 HandleZRTop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT64);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZRTop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZRTop", objReturnParams);
		}

		//5 HandleZDrop generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZDrop", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZDrop", objReturnParams);
		}

		//5 HandleZCount generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT64);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZCount", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZCount", objReturnParams);
		}

		//5 HandleZList generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleZList", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleZList", objReturnParams);
		}

		//5 HandleDump generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams );
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_CUtilChunk);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("HandleDump", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("HandleDump", objReturnParams);
		}

		//5 SyncMasterHandler generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_INT32);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncMasterHandler", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncMasterHandler", objReturnParams);
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSyncMasterHandler_RpcServer , &SlaveHandler::SyncMasterHandler_RpcServer); 
		}

		//5 SlaveStartAuth generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveStartAuth", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveStartAuth", objReturnParams);
			
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSlaveStartAuth_RpcClient , &SlaveHandler::SlaveStartAuth_RpcClient); 
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSlaveStartAuth_RpcTimeout ,&SlaveHandler::SlaveStartAuth_RpcTimeout); 
		}

		//5 SlaveSelectDB generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveSelectDB", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveSelectDB", objReturnParams);
			
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSlaveSelectDB_RpcClient , &SlaveHandler::SlaveSelectDB_RpcClient); 
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSlaveSelectDB_RpcTimeout ,&SlaveHandler::SlaveSelectDB_RpcTimeout); 
		}

		//5 SlaveRequestSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SlaveRequestSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SlaveRequestSync", objReturnParams);
			
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSlaveRequestSync_RpcClient , &SlaveHandler::SlaveRequestSync_RpcClient); 
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSlaveRequestSync_RpcTimeout ,&SlaveHandler::SlaveRequestSync_RpcTimeout); 
		}

		//5 MasterStartSync generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("MasterStartSync", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("MasterStartSync", objReturnParams);
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szMasterStartSync_RpcServer , &SlaveHandler::MasterStartSync_RpcServer); 
		}

		//5 SyncDataToSlave generate default deliver and return check param here
		{
			CUtil::Parameters objDeliverParams , objReturnParams;
			CUtil::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_std_string , g_rpcDefaultParam_CUtilChunk);
			CUtil::GenMsgHelper::GenMsgParams(objReturnParams  , g_rpcDefaultParam_INT32);
			Msg::RpcCheckParams::GetInstance()->InsertDeliverParams("SyncDataToSlave", objDeliverParams);
			Msg::RpcCheckParams::GetInstance()->InsertReturnParams("SyncDataToSlave", objReturnParams);
			m_pRpcManager->RegisterFunc<SlaveHandler >(Msg::g_szSyncDataToSlave_RpcServer , &SlaveHandler::SyncDataToSlave_RpcServer); 
		}

		Server::SlaveHandler::InitObjectFuncs();
	}

	CollectionObjectFuncsT Server::GlobalRpc::s_setFuncs;
	CollectionObjectFuncsT Server::ServerHandler::s_setFuncs;
	CollectionObjectFuncsT Server::MasterHandler::s_setFuncs;
	CollectionObjectFuncsT Server::SlaveHandler::s_setFuncs;
}//Server

