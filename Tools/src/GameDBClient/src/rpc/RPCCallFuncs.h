/************************************
FileName	:	RpcCallFuncs.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-15 10:09:23
Description	:	�ͻ��˵��õ�rpc.
************************************/
#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "RpcDatas.h"
#include "DBClient.h"

namespace Client
{
	static INT32  rpc_testMulitServerNode(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_5((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_sztestMulitServerNode_RpcCall , dbname , value , value2 , value22 , valChar, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_testMulitServerNode(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_testMulitServerNode( pSessionName ,vecTargets , objSrc , dbname , value , value2 , value22 , valChar, usPriority , objSyncType);
	}

	static INT32  rpc_testMulitServerNode(const char * pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		return rpc_testMulitServerNode( pSessionName , 0 , objSrc , dbname , value , value2 , value22 , valChar, usPriority , objSyncType);
	}

	static INT32  rpc_testMulitServerNode(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_5((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_sztestMulitServerNode_RpcCall , dbname , value , value2 , value22 , valChar, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_testMulitServerNode(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_testMulitServerNode( pSessionName ,vecTargets , objSrc , dbname , value , value2 , value22 , valChar, usPriority , objSyncType);
	}

	static INT32  rpc_testMulitServerNode(const std::string & pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		return rpc_testMulitServerNode( pSessionName , 0 , objSrc , dbname , value , value2 , value22 , valChar, usPriority , objSyncType);
	}

	static INT32  rpc_testMulitServerNode(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_5((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_sztestMulitServerNode_RpcCall , dbname , value , value2 , value22 , valChar, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_testMulitServerNode(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_testMulitServerNode( nSessionID ,vecTargets , objSrc , dbname , value , value2 , value22 , valChar, usPriority , objSyncType);
	}

	static INT32  rpc_testMulitServerNode(INT32 nSessionID , Msg::Object objSrc , std_string & dbname = std::string() , CUtilChunk & value = CUtil::Chunk() , int value2 = 0 , unsigned int value22 = 0 , char valChar = char(0) , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		return rpc_testMulitServerNode( nSessionID , 0 , objSrc , dbname , value , value2 , value22 , valChar, usPriority , objSyncType);
	}

	static INT32  rpc_HandleUserAuth(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleUserAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleUserAuth(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleUserAuth( pSessionName ,vecTargets , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_HandleUserAuth(const char * pSessionName , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleUserAuth( pSessionName , 0 , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_HandleUserAuth(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleUserAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleUserAuth(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleUserAuth( pSessionName ,vecTargets , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_HandleUserAuth(const std::string & pSessionName , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleUserAuth( pSessionName , 0 , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_HandleUserAuth(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleUserAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleUserAuth(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleUserAuth( nSessionID ,vecTargets , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_HandleUserAuth(INT32 nSessionID , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleUserAuth( nSessionID , 0 , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleSelectDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleSelectDatabase(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleSelectDatabase( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(const char * pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleSelectDatabase( pSessionName , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleSelectDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleSelectDatabase(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleSelectDatabase( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(const std::string & pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleSelectDatabase( pSessionName , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleSelectDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleSelectDatabase(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleSelectDatabase( nSessionID ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(INT32 nSessionID , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleSelectDatabase( nSessionID , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateDatabase(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateDatabase( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(const char * pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleCreateDatabase( pSessionName , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateDatabase(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateDatabase( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(const std::string & pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleCreateDatabase( pSessionName , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleCreateDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateDatabase(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateDatabase( nSessionID ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(INT32 nSessionID , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleCreateDatabase( nSessionID , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDeleteDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteDatabase(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteDatabase( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(const char * pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDeleteDatabase( pSessionName , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDeleteDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteDatabase(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteDatabase( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(const std::string & pSessionName , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDeleteDatabase( pSessionName , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleDeleteDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteDatabase(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteDatabase( nSessionID ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(INT32 nSessionID , Msg::Object objSrc , std_string & dbname = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDeleteDatabase( nSessionID , 0 , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleShowDatabases_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleShowDatabases(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleShowDatabases( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(const char * pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleShowDatabases( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleShowDatabases_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleShowDatabases(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleShowDatabases( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(const std::string & pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleShowDatabases( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleShowDatabases_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleShowDatabases(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleShowDatabases( nSessionID ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(INT32 nSessionID , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleShowDatabases( nSessionID , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateUser(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateUser( pSessionName ,vecTargets , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(const char * pSessionName , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleCreateUser( pSessionName , 0 , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateUser(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateUser( pSessionName ,vecTargets , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(const std::string & pSessionName , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleCreateUser( pSessionName , 0 , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleCreateUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateUser(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateUser( nSessionID ,vecTargets , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(INT32 nSessionID , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleCreateUser( nSessionID , 0 , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDeleteUser_RpcCall , name, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteUser(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteUser( pSessionName ,vecTargets , objSrc , name, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(const char * pSessionName , Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDeleteUser( pSessionName , 0 , objSrc , name, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDeleteUser_RpcCall , name, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteUser(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteUser( pSessionName ,vecTargets , objSrc , name, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(const std::string & pSessionName , Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDeleteUser( pSessionName , 0 , objSrc , name, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleDeleteUser_RpcCall , name, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteUser(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteUser( nSessionID ,vecTargets , objSrc , name, usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(INT32 nSessionID , Msg::Object objSrc , std_string & name = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDeleteUser( nSessionID , 0 , objSrc , name, usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleModifyUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleModifyUser(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleModifyUser( pSessionName ,vecTargets , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(const char * pSessionName , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleModifyUser( pSessionName , 0 , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleModifyUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleModifyUser(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleModifyUser( pSessionName ,vecTargets , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(const std::string & pSessionName , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleModifyUser( pSessionName , 0 , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleModifyUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleModifyUser(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleModifyUser( nSessionID ,vecTargets , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(INT32 nSessionID , Msg::Object objSrc , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleModifyUser( nSessionID , 0 , objSrc , name , pwd , issys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSet_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSet(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSet( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSet( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSet_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSet(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSet( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSet( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHSet_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSet(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSet( nSessionID ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSet( nSessionID , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetNX_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetNX(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetNX( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetNX( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetNX_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetNX(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetNX( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetNX( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHSetNX_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetNX(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetNX( nSessionID ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetNX( nSessionID , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetOW_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetOW(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetOW( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetOW( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetOW_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetOW(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetOW( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetOW( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHSetOW_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetOW(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetOW( nSessionID ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetOW( nSessionID , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGet(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGet( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGet( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGet(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGet( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGet( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGet(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGet( nSessionID ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGet( nSessionID , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDel(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDel( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHDel( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDel(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDel( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHDel( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDel(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDel( nSessionID ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHDel( nSessionID , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetIncr_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncr(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncr( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetIncr( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetIncr_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncr(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncr( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetIncr( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHSetIncr_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncr(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncr( nSessionID ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetIncr( nSessionID , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetIncrFloat_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncrFloat(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncrFloat( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetIncrFloat( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetIncrFloat_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncrFloat(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncrFloat( pSessionName ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetIncrFloat( pSessionName , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHSetIncrFloat_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncrFloat(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncrFloat( nSessionID ,vecTargets , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHSetIncrFloat( nSessionID , 0 , objSrc , table , key , value, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetKeys_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeys(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeys( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetKeys( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetKeys_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeys(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeys( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetKeys( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHGetKeys_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeys(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeys( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetKeys( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetVals(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetVals( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetVals( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetVals(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetVals( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetVals( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHGetVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetVals(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetVals( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetVals( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetKeyVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeyVals(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeyVals( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetKeyVals( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetKeyVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeyVals(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeyVals( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetKeyVals( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHGetKeyVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeyVals(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeyVals( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHGetKeyVals( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHScan_RpcCall , table , start , regexp , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHScan(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHScan( pSessionName ,vecTargets , objSrc , table , start , regexp , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHScan( pSessionName , 0 , objSrc , table , start , regexp , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHScan_RpcCall , table , start , regexp , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHScan(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHScan( pSessionName ,vecTargets , objSrc , table , start , regexp , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHScan( pSessionName , 0 , objSrc , table , start , regexp , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHScan_RpcCall , table , start , regexp , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHScan(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHScan( nSessionID ,vecTargets , objSrc , table , start , regexp , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHScan( nSessionID , 0 , objSrc , table , start , regexp , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHCount(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHCount( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHCount( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHCount(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHCount( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHCount( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHCount(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHCount( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHCount( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDrop(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDrop( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHDrop( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDrop(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDrop( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHDrop( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDrop(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDrop( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHDrop( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHList(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHList( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(const char * pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHList( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHList(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHList( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(const std::string & pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHList( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHList(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHList( nSessionID ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(INT32 nSessionID , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHList( nSessionID , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiSet_RpcCall , table , keyvalues, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiSet(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiSet( pSessionName ,vecTargets , objSrc , table , keyvalues, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiSet( pSessionName , 0 , objSrc , table , keyvalues, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiSet_RpcCall , table , keyvalues, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiSet(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiSet( pSessionName ,vecTargets , objSrc , table , keyvalues, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiSet( pSessionName , 0 , objSrc , table , keyvalues, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHMultiSet_RpcCall , table , keyvalues, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiSet(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiSet( nSessionID ,vecTargets , objSrc , table , keyvalues, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keyvalues = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiSet( nSessionID , 0 , objSrc , table , keyvalues, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiGet_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiGet(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiGet( pSessionName ,vecTargets , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiGet( pSessionName , 0 , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiGet_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiGet(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiGet( pSessionName ,vecTargets , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiGet( pSessionName , 0 , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHMultiGet_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiGet(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiGet( nSessionID ,vecTargets , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiGet( nSessionID , 0 , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiDel_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiDel(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiDel( pSessionName ,vecTargets , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiDel( pSessionName , 0 , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiDel_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiDel(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiDel( pSessionName ,vecTargets , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiDel( pSessionName , 0 , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleHMultiDel_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiDel(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiDel( nSessionID ,vecTargets , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , CUtilChunk & keys = CUtil::Chunk() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleHMultiDel( nSessionID , 0 , objSrc , table , keys, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZSet_RpcCall , table , key , score, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZSet(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZSet( pSessionName ,vecTargets , objSrc , table , key , score, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZSet( pSessionName , 0 , objSrc , table , key , score, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZSet_RpcCall , table , key , score, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZSet(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZSet( pSessionName ,vecTargets , objSrc , table , key , score, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZSet( pSessionName , 0 , objSrc , table , key , score, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZSet_RpcCall , table , key , score, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZSet(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZSet( nSessionID ,vecTargets , objSrc , table , key , score, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZSet( nSessionID , 0 , objSrc , table , key , score, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZGet(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZGet( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZGet( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZGet(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZGet( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZGet( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZGet(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZGet( nSessionID ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZGet( nSessionID , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDel(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDel( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZDel( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDel(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDel( pSessionName ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZDel( pSessionName , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDel(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDel( nSessionID ,vecTargets , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , std_string & key = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZDel( nSessionID , 0 , objSrc , table , key, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZTop(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZTop( pSessionName ,vecTargets , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZTop( pSessionName , 0 , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZTop(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZTop( pSessionName ,vecTargets , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZTop( pSessionName , 0 , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZTop(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZTop( nSessionID ,vecTargets , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZTop( nSessionID , 0 , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZRTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZRTop(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZRTop( pSessionName ,vecTargets , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZRTop( pSessionName , 0 , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZRTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZRTop(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZRTop( pSessionName ,vecTargets , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZRTop( pSessionName , 0 , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZRTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZRTop(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZRTop( nSessionID ,vecTargets , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0 , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZRTop( nSessionID , 0 , objSrc , table , start , end , limit, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDrop(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDrop( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZDrop( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDrop(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDrop( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZDrop( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDrop(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDrop( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZDrop( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZCount(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZCount( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(const char * pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZCount( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZCount(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZCount( pSessionName ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(const std::string & pSessionName , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZCount( pSessionName , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZCount(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZCount( nSessionID ,vecTargets , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(INT32 nSessionID , Msg::Object objSrc , std_string & table = std::string() , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZCount( nSessionID , 0 , objSrc , table, usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZList(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZList( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(const char * pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZList( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZList(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZList( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(const std::string & pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZList( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleZList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZList(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZList( nSessionID ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(INT32 nSessionID , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleZList( nSessionID , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDump_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDump(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDump( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(const char * pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDump( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDump_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDump(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDump( pSessionName ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(const std::string & pSessionName , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDump( pSessionName , 0 , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , nSessionID , Msg::g_szHandleDump_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDump(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDump( nSessionID ,vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(INT32 nSessionID , Msg::Object objSrc  , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		return rpc_HandleDump( nSessionID , 0 , objSrc , usPriority , objSyncType);
	}

}

#endif
