/************************************
FileName	:	RPCDefines.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-15 10:09:23
Description	:	RPCº¯Êý¶¨Òå
************************************/
#ifndef __msg_Client_rpc_defines_h__
#define __msg_Client_rpc_defines_h__
#include "RpcDatas.h" 

namespace Client
{

#define  RPC_DEFINE_GlobalRpc public:\
	Msg::ObjectMsgCall * testMulitServerNode_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * testMulitServerNode_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0));\
	Msg::ObjectMsgCall * HandleUserAuth_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleUserAuth_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * HandleSelectDatabase_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleSelectDatabase_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleCreateDatabase_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleCreateDatabase_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleDeleteDatabase_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleDeleteDatabase_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleShowDatabases_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleShowDatabases_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleCreateUser_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleCreateUser_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0);\
	Msg::ObjectMsgCall * HandleDeleteUser_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleDeleteUser_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string());\
	Msg::ObjectMsgCall * HandleModifyUser_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleModifyUser_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0);\
	Msg::ObjectMsgCall * HandleHSet_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHSet_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHSetNX_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHSetNX_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHSetOW_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHSetOW_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHGet_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHGet_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleHDel_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHDel_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleHSetIncr_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleHSetIncr_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0);\
	Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , double res = 0);\
	Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f);\
	Msg::ObjectMsgCall * HandleHGetKeys_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHGetKeys_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHGetVals_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHGetVals_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHGetKeyVals_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHGetKeyVals_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHScan_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHScan_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10);\
	Msg::ObjectMsgCall * HandleHCount_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleHCount_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHDrop_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleHDrop_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHList_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHList_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleHMultiSet_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHMultiSet_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiGet_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiGet_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiDel_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleHMultiDel_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZSet_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 resCode = 0);\
	Msg::ObjectMsgCall * HandleZSet_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZGet_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZGet_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleZDel_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZDel_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleZTop_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZTop_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0);\
	Msg::ObjectMsgCall * HandleZRTop_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZRTop_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0);\
	Msg::ObjectMsgCall * HandleZDrop_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * HandleZDrop_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleZCount_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT64 res = 0);\
	Msg::ObjectMsgCall * HandleZCount_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleZList_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleZList_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
	Msg::ObjectMsgCall * HandleDump_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , CUtilChunk & res = CUtil::Chunk());\
	Msg::ObjectMsgCall * HandleDump_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) );\
public:\
	static CollectionObjectFuncsT s_setFuncs;\
	static void InitObjectFuncs()\
	{\
		GlobalRpc::s_setFuncs.insert("testMulitServerNode");\
		GlobalRpc::s_setFuncs.insert("HandleUserAuth");\
		GlobalRpc::s_setFuncs.insert("HandleSelectDatabase");\
		GlobalRpc::s_setFuncs.insert("HandleCreateDatabase");\
		GlobalRpc::s_setFuncs.insert("HandleDeleteDatabase");\
		GlobalRpc::s_setFuncs.insert("HandleShowDatabases");\
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

