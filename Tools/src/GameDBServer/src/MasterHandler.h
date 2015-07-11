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
		MasterHandler(Msg::Object objID , DBMaster * pDBMaster)
			: Msg::IRpcMsgCallableObject(objID , pDBMaster->GetRpcServerManager())
			, m_pDBMaster(pDBMaster)
			, m_nSessionID(0)
		{}
	public:
		virtual INT32	Update(){ return 0; } 

	public:
		bool			SendFile(const std::string & strFilePath , std::string & strFileName);
		void			SetDBName(std::string strName){ m_strDatabaseName = strName; }
		std::string		GetDBName( ){ return m_strDatabaseName; }
		DBMaster	*	GetDBMaster(){ return m_pDBMaster; }
		void			StartSyncToSlave(std::string strDBDir);

	private:
		INT32			m_nSessionID;
		DBMaster	 *  m_pDBMaster;
		std::string		m_strDatabaseName;
		GameDB::UserAuth m_objAuthInfo;
	}; 
}

#endif