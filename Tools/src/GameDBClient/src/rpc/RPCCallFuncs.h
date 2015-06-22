#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "DBClient.h"

namespace Client
{
	static INT32  local_call_HandleHSet(const char * pSessionName , std_string table/* = std::string()*/ , std_string key/* = std::string()*/ , std_string value/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHSet_RpcCall , table , key , value, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleHGet(const char * pSessionName , std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleHGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleZSet(const char * pSessionName , std_string table/* = std::string()*/ , std_string key/* = std::string()*/ , INT64 score/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZSet_RpcCall , table , key , score, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleZGet(const char * pSessionName , std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZGet_RpcCall , table , key, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleCreateUser(const char * pSessionName , std_string name/* = std::string()*/ , std_string pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleCreateUser_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleZTop(const char * pSessionName , std_string table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleZRTop(const char * pSessionName , std_string table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_4((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleZRTop_RpcCall , table , start , end , limit, vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_HandleDump(const char * pSessionName , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_0((&(Client::DBClient::GetInstance())) , pSessionName , Msg::g_szHandleDump_RpcCall , vecTargets , objSrc , usPriority , Client::DBClient::GetInstance().GetServerName() , objSyncType , 10);
	}

}

#endif
