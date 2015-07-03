#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "DBServer.h"
#include "DBMaster.h"
#include "DBSlave.h"

namespace Server
{
	static INT32  rpc_SyncDataToSlave(const char * pSessionName , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBServer::GetInstance())) , pSessionName , Msg::g_szSyncDataToSlave_RpcCall , dbname , value, vecTargets , objSrc , usPriority , Server::DBServer::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SyncDataToSlave(const char * pSessionName , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SyncDataToSlave( pSessionName ,dbname , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_testRefers(const char * pSessionName , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBServer::GetInstance())) , pSessionName , Msg::g_sztestRefers_RpcCall , dbname , value, vecTargets , objSrc , usPriority , Server::DBServer::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_testRefers(const char * pSessionName , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_testRefers( pSessionName ,dbname , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_MasterStartSync(const char * pSessionName , std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_4((&(Server::DBMaster::GetInstance())) , pSessionName , Msg::g_szMasterStartSync_RpcCall , filename , filesize , sendtype , value, vecTargets , objSrc , usPriority , Server::DBMaster::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_MasterStartSync(const char * pSessionName , std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_MasterStartSync( pSessionName ,filename , filesize , sendtype , value, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_SlaveStartAuth(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveStartAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SlaveStartAuth(const char * pSessionName , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveStartAuth( pSessionName ,name , pwd, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_SlaveSelectDB(const char * pSessionName , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_1((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveSelectDB_RpcCall , dbname, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SlaveSelectDB(const char * pSessionName , std_string & dbname/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveSelectDB( pSessionName ,dbname, vecTargets , objSrc , usPriority , objSyncType);
	}

	static INT32  rpc_SlaveRequestSync(const char * pSessionName , std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveRequestSync_RpcCall , dbbackdir , dbname, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 3600);
	}

	static INT32  rpc_SlaveRequestSync(const char * pSessionName , std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/, Msg::Object objTarget, Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveRequestSync( pSessionName ,dbbackdir , dbname, vecTargets , objSrc , usPriority , objSyncType);
	}

}

#endif
