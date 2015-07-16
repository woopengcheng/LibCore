#ifndef __gamedb_master_handler_h__
#define __gamedb_master_handler_h__

#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "GameDB/inc/User.h"
#include "RpcDefines.h" 
#include "MsgNameDefine.h"  
#include "DBMaster.h" 
#include "SlaveRecord.h"

namespace Server
{  
	class MasterHandler : public Msg::IRpcMsgCallableObject
	{ 
 		RPC_DEFINE_MasterHandler;
	public:
		typedef std::map<Msg::Object , SlaveRecord *> CollectionSlaveRecordsT;

	public:
		MasterHandler(Msg::Object objID , DBMaster * pDBMaster)
			: Msg::IRpcMsgCallableObject(objID , pDBMaster->GetRpcServerManager())
			, m_pDBMaster(pDBMaster)
			, m_nSessionID(0)
		{}
		~MasterHandler();
	public:
		virtual INT32	Update(){ return 0; } 

	public:
		bool			SendFile(const std::string & strFilePath , std::string & strFileName);
		DBMaster 	 *  GetDBMaster(){ return m_pDBMaster; }
		void			StartSyncToSlave(std::string strDBDir);
		void			CreateSlaveRecord(INT32 nSessionID , Msg::Object id);
		BOOL			SetSlaveRecordInfo(Msg::Object id , GameDB::User & objUser);
		BOOL			DelSlaveRecord(Msg::Object id);
		SlaveRecord  *  GetSlaveRecord(Msg::Object id);
		SlaveRecord  *  GetSlaveRecord(std::string strName);
	private:
		INT32			m_nSessionID;
		DBMaster	 *  m_pDBMaster;
		CollectionSlaveRecordsT m_mapSlaveRecords;
	}; 
}

#endif