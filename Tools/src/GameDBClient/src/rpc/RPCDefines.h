/************************************
FileName	:	RPCDefines.h
Author		:	generate by tools
HostName	:	devuser-PC
IP			:	10.236.41.54
Version		:	0.0.1
Description	:	RPC��������
************************************/
#ifndef __msg_Client_rpc_defines_h__
#define __msg_Client_rpc_defines_h__
#include "RpcDatas.h" 

namespace Client
{

#define  RPC_DEFINE_GlobalRpc public:\
	Msg::ObjectMsgCall * testMulitServerNode_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * testMulitServerNode_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0));\
	Msg::ObjectMsgCall * SyncServerHandler_RpcServer(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleUserAuth_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleUserAuth_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * HandleSelectDatabase_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleSelectDatabase_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleCreateDatabase_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleCreateDatabase_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleDeleteDatabase_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleDeleteDatabase_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleShowDatabases_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleShowDatabases_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleShowUsers_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleShowUsers_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleCreateUser_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleCreateUser_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0);\
	Msg::ObjectMsgCall * HandleDeleteUser_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleDeleteUser_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string());\
	Msg::ObjectMsgCall * HandleModifyUser_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleModifyUser_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0);\
	Msg::ObjectMsgCall * HandleHSet_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHSet_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHSetNX_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHSetNX_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHSetOW_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHSetOW_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHGet_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHGet_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleHDel_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHDel_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleHSetIncr_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleHSetIncr_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0);\
	Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , double res = 0);\
	Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f);\
	Msg::ObjectMsgCall * HandleHGetKeys_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHGetKeys_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHGetVals_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHGetVals_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHGetKeyVals_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHGetKeyVals_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHScan_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHScan_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10);\
	Msg::ObjectMsgCall * HandleHCount_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleHCount_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHDrop_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleHDrop_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHList_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHList_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleHMultiSet_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHMultiSet_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiGet_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiGet_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiDel_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHMultiDel_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZSet_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 resCode = 0);\
	Msg::ObjectMsgCall * HandleZSet_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZGet_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZGet_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleZDel_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZDel_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleZTop_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZTop_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0);\
	Msg::ObjectMsgCall * HandleZRTop_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZRTop_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0);\
	Msg::ObjectMsgCall * HandleZDrop_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleZDrop_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleZCount_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleZCount_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleZList_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZList_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleDump_RpcClient(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleDump_RpcTimeout(INT32 nSessionID, Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
public:\
	static CollectionObjectFuncsT s_setFuncs;\
	static void InitObjectFuncs()\
	{\
		GlobalRpc::s_setFuncs.insert("testMulitServerNode");\
		GlobalRpc::s_setFuncs.insert("SyncServerHandler");\
		GlobalRpc::s_setFuncs.insert("HandleUserAuth");\
		GlobalRpc::s_setFuncs.insert("HandleSelectDatabase");\
		GlobalRpc::s_setFuncs.insert("HandleCreateDatabase");\
		GlobalRpc::s_setFuncs.insert("HandleDeleteDatabase");\
		GlobalRpc::s_setFuncs.insert("HandleShowDatabases");\
		GlobalRpc::s_setFuncs.insert("HandleShowUsers");\
		GlobalRpc::s_setFuncs.insert("HandleCreateUser");\
		GlobalRpc::s_setFuncs.insert("HandleDeleteUser");\
		GlobalRpc::s_setFuncs.insert("HandleModifyUser");\
		GlobalRpc::s_setFuncs.insert("HandleHSet");\
		GlobalRpc::s_setFuncs.insert("HandleHSetNX");\
		GlobalRpc::s_setFuncs.insert("HandleHSetOW");\
		GlobalRpc::s_setFuncs.insert("HandleHGet");\
		GlobalRpc::s_setFuncs.insert("HandleHDel");\
		GlobalRpc::s_setFuncs.insert("HandleHSetIncr");\
		GlobalRpc::s_setFuncs.insert("HandleHSetIncrFloat");\
		GlobalRpc::s_setFuncs.insert("HandleHGetKeys");\
		GlobalRpc::s_setFuncs.insert("HandleHGetVals");\
		GlobalRpc::s_setFuncs.insert("HandleHGetKeyVals");\
		GlobalRpc::s_setFuncs.insert("HandleHScan");\
		GlobalRpc::s_setFuncs.insert("HandleHCount");\
		GlobalRpc::s_setFuncs.insert("HandleHDrop");\
		GlobalRpc::s_setFuncs.insert("HandleHList");\
		GlobalRpc::s_setFuncs.insert("HandleHMultiSet");\
		GlobalRpc::s_setFuncs.insert("HandleHMultiGet");\
		GlobalRpc::s_setFuncs.insert("HandleHMultiDel");\
		GlobalRpc::s_setFuncs.insert("HandleZSet");\
		GlobalRpc::s_setFuncs.insert("HandleZGet");\
		GlobalRpc::s_setFuncs.insert("HandleZDel");\
		GlobalRpc::s_setFuncs.insert("HandleZTop");\
		GlobalRpc::s_setFuncs.insert("HandleZRTop");\
		GlobalRpc::s_setFuncs.insert("HandleZDrop");\
		GlobalRpc::s_setFuncs.insert("HandleZCount");\
		GlobalRpc::s_setFuncs.insert("HandleZList");\
		GlobalRpc::s_setFuncs.insert("HandleDump");\
	}\
	virtual BOOL IsHasFunc(const std::string & strFunc)\
	{\
		CollectionObjectFuncsT::iterator iter = GlobalRpc::s_setFuncs.find(strFunc);\
		if (iter != GlobalRpc::s_setFuncs.end())\
		{\
			return TRUE;\
		}\
	return FALSE;\
	}\



}

#endif

