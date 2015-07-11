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
	static INT32  rpc_SyncDataToSlave(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBServer::GetInstance())) , pSessionName , Msg::g_szSyncDataToSlave_RpcCall , dbname , value, vecTargets , objSrc , usPriority , Server::DBServer::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SyncDataToSlave(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SyncDataToSlave( pSessionName ,vecTargets , objSrc , dbname , value, usPriority , objSyncType);
	}

	static INT32  rpc_SyncDataToSlave(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBServer::GetInstance())) , nSessionID , Msg::g_szSyncDataToSlave_RpcCall , dbname , value, vecTargets , objSrc , usPriority , Server::DBServer::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SyncDataToSlave(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SyncDataToSlave( nSessionID ,vecTargets , objSrc , dbname , value, usPriority , objSyncType);
	}

	static INT32  rpc_testRefers(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBServer::GetInstance())) , pSessionName , Msg::g_sztestRefers_RpcCall , dbname , value, vecTargets , objSrc , usPriority , Server::DBServer::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_testRefers(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_testRefers( pSessionName ,vecTargets , objSrc , dbname , value, usPriority , objSyncType);
	}

	static INT32  rpc_testRefers(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBServer::GetInstance())) , nSessionID , Msg::g_sztestRefers_RpcCall , dbname , value, vecTargets , objSrc , usPriority , Server::DBServer::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_testRefers(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_testRefers( nSessionID ,vecTargets , objSrc , dbname , value, usPriority , objSyncType);
	}

	static INT32  rpc_SyncMasterHandler(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 id/* = 0*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_1((&(Server::DBMaster::GetInstance())) , pSessionName , Msg::g_szSyncMasterHandler_RpcCall , id, vecTargets , objSrc , usPriority , Server::DBMaster::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SyncMasterHandler(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , INT32 id/* = 0*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SyncMasterHandler( pSessionName ,vecTargets , objSrc , id, usPriority , objSyncType);
	}

	static INT32  rpc_SyncMasterHandler(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 id/* = 0*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_1((&(Server::DBMaster::GetInstance())) , nSessionID , Msg::g_szSyncMasterHandler_RpcCall , id, vecTargets , objSrc , usPriority , Server::DBMaster::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SyncMasterHandler(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , INT32 id/* = 0*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SyncMasterHandler( nSessionID ,vecTargets , objSrc , id, usPriority , objSyncType);
	}

	static INT32  rpc_MasterStartSync(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_4((&(Server::DBMaster::GetInstance())) , pSessionName , Msg::g_szMasterStartSync_RpcCall , filename , filesize , sendtype , value, vecTargets , objSrc , usPriority , Server::DBMaster::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_MasterStartSync(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_MasterStartSync( pSessionName ,vecTargets , objSrc , filename , filesize , sendtype , value, usPriority , objSyncType);
	}

	static INT32  rpc_MasterStartSync(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_4((&(Server::DBMaster::GetInstance())) , nSessionID , Msg::g_szMasterStartSync_RpcCall , filename , filesize , sendtype , value, vecTargets , objSrc , usPriority , Server::DBMaster::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_MasterStartSync(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_MasterStartSync( nSessionID ,vecTargets , objSrc , filename , filesize , sendtype , value, usPriority , objSyncType);
	}

	static INT32  rpc_SlaveStartAuth(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveStartAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SlaveStartAuth(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveStartAuth( pSessionName ,vecTargets , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_SlaveStartAuth(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBSlave::GetInstance())) , nSessionID , Msg::g_szSlaveStartAuth_RpcCall , name , pwd, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SlaveStartAuth(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveStartAuth( nSessionID ,vecTargets , objSrc , name , pwd, usPriority , objSyncType);
	}

	static INT32  rpc_SlaveSelectDB(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_1((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveSelectDB_RpcCall , dbname, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SlaveSelectDB(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveSelectDB( pSessionName ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_SlaveSelectDB(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_1((&(Server::DBSlave::GetInstance())) , nSessionID , Msg::g_szSlaveSelectDB_RpcCall , dbname, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  rpc_SlaveSelectDB(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveSelectDB( nSessionID ,vecTargets , objSrc , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_SlaveRequestSync(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveRequestSync_RpcCall , dbbackdir , dbname, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 3600);
	}

	static INT32  rpc_SlaveRequestSync(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc , std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveRequestSync( pSessionName ,vecTargets , objSrc , dbbackdir , dbname, usPriority , objSyncType);
	}

	static INT32  rpc_SlaveRequestSync(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_2((&(Server::DBSlave::GetInstance())) , nSessionID , Msg::g_szSlaveRequestSync_RpcCall , dbbackdir , dbname, vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 3600);
	}

	static INT32  rpc_SlaveRequestSync(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc , std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/ , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(objTarget);
		return rpc_SlaveRequestSync( nSessionID ,vecTargets , objSrc , dbbackdir , dbname, usPriority , objSyncType);
	}

}

#endif
