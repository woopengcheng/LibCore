#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "DBClient.h"

namespace Client
{
	static INT32  rpc_HandleUserAuth(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleUserAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleUserAuth(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleUserAuth( pSessionName ,name , pwd, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleSelectDatabase(const char * pSessionName , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleSelectDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleSelectDatabase(const char * pSessionName , std_string & dbname/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleSelectDatabase( pSessionName ,dbname, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateDatabase(const char * pSessionName , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateDatabase(const char * pSessionName , std_string & dbname/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateDatabase( pSessionName ,dbname, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteDatabase(const char * pSessionName , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDeleteDatabase_RpcCall , dbname, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteDatabase(const char * pSessionName , std_string & dbname/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteDatabase( pSessionName ,dbname, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleShowDatabases(const char * pSessionName , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleShowDatabases_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleShowDatabases(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleShowDatabases( pSessionName , vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleCreateUser(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , SINT8 issys/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleCreateUser(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , SINT8 issys/* = 0*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleCreateUser( pSessionName ,name , pwd , issys, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDeleteUser(const char * pSessionName , std_string & name/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDeleteUser_RpcCall , name, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDeleteUser(const char * pSessionName , std_string & name/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDeleteUser( pSessionName ,name, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleModifyUser(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , SINT8 issys/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleModifyUser_RpcCall , name , pwd , issys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleModifyUser(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , SINT8 issys/* = 0*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleModifyUser( pSessionName ,name , pwd , issys, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSet_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSet( pSessionName ,table , key , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetNX(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetNX_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetNX(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetNX( pSessionName ,table , key , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetOW(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetOW_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetOW(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetOW( pSessionName ,table , key , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGet( pSessionName ,table , key, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDel(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDel(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDel( pSessionName ,table , key, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncr(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , INT64 value/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetIncr_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncr(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , INT64 value/* = 0*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncr( pSessionName ,table , key , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHSetIncrFloat(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , double value/* = 0.0f*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSetIncrFloat_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHSetIncrFloat(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , double value/* = 0.0f*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHSetIncrFloat( pSessionName ,table , key , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeys(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetKeys_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeys(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeys( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetVals(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetVals(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetVals( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHGetKeyVals(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGetKeyVals_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHGetKeyVals(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHGetKeyVals( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHScan(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & start/* = std::string()*/ , std_string & regexp/* = std::string()*/ , INT64 limit/* = 10*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHScan_RpcCall , table , start , regexp , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHScan(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & start/* = std::string()*/ , std_string & regexp/* = std::string()*/ , INT64 limit/* = 10*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHScan( pSessionName ,table , start , regexp , limit, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHCount(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHCount(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHCount( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHDrop(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHDrop(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHDrop( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHList(const char * pSessionName , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHList(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHList( pSessionName , vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiSet(const char * pSessionName , std_string & table/* = std::string()*/ , LibCore_Chunk & keyvalues/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiSet_RpcCall , table , keyvalues, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiSet(const char * pSessionName , std_string & table/* = std::string()*/ , LibCore_Chunk & keyvalues/* = LibCore::Chunk()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiSet( pSessionName ,table , keyvalues, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiGet(const char * pSessionName , std_string & table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiGet_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiGet(const char * pSessionName , std_string & table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiGet( pSessionName ,table , keys, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleHMultiDel(const char * pSessionName , std_string & table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHMultiDel_RpcCall , table , keys, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleHMultiDel(const char * pSessionName , std_string & table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleHMultiDel( pSessionName ,table , keys, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZSet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , INT64 score/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZSet_RpcCall , table , key , score, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZSet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , INT64 score/* = 0*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZSet( pSessionName ,table , key , score, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZGet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZGet(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZGet( pSessionName ,table , key, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDel(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZDel_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDel(const char * pSessionName , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDel( pSessionName ,table , key, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZTop(const char * pSessionName , std_string & table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZTop(const char * pSessionName , std_string & table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZTop( pSessionName ,table , start , end , limit, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZRTop(const char * pSessionName , std_string & table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZRTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZRTop(const char * pSessionName , std_string & table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZRTop( pSessionName ,table , start , end , limit, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZDrop(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZDrop_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZDrop(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZDrop( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZCount(const char * pSessionName , std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_1((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZCount_RpcCall , table, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZCount(const char * pSessionName , std_string & table/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZCount( pSessionName ,table, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleZList(const char * pSessionName , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZList_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleZList(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleZList( pSessionName , vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_HandleDump(const char * pSessionName , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDump_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_HandleDump(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_HandleDump( pSessionName , vecTargets , objSrc , usPriority , objSyncType);
	}

}

#endif
