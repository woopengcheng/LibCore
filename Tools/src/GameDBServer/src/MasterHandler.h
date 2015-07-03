#ifndef __gamedb_master_handler_h__
#define __gamedb_master_handler_h__

#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "RpcDefines.h" 
#include "MsgNameDefine.h"  
#include "DBMaster.h" 
#include "GameDB/inc/UserAuth.h"

namespace Server
{  
	class MasterHandler : public Msg::IRpcMsgCallableObject
	{ 
 		RPC_DEFINE_MasterHandler;
	public:
		MasterHandler(DBMaster * pDBMaster)
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , pDBMaster->GetRpcServerManager())
			, m_pDBMaster(pDBMaster)
		{}
	public:
		virtual INT32 Update(){ return 0; } 

	public:
		DBMaster * GetDBMaster(){ return m_pDBMaster; }
		void  StartSyncToSlave(std::string strDBDir);
		bool  SendFile(const std::string & strFilePath , std::string & strFileName);

	private:
		DBMaster * m_pDBMaster;
		GameDB::UserAuth * m_pAuthInfo;
		std::string m_strDatabaseName;
	}; 
}

#endif