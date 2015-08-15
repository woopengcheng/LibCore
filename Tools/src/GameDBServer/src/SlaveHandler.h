#ifndef __server_slave_handler_h__
#define __server_slave_handler_h__
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "GameDB/inc/SlaveSession.h"
#include "GameDB/inc/Database.h"
#include "Common/inc/Chunk.h"
#include "MsgNameDefine.h"  
#include "RpcDefines.h" 
#include "DBSlave.h" 

namespace Server
{   
	class SlaveHandler : public Msg::IRpcMsgCallableObject
	{ 
		RPC_DEFINE_SlaveHandler;

	public:
		CollectionObjectFuncsT m_stest;
	public:
		SlaveHandler(Msg::Object objID , DBSlave * pDBSlave)
			: Msg::IRpcMsgCallableObject(objID , pDBSlave->GetRpcServerManager())
			, m_pDBSlave(pDBSlave)
			, m_pDatabase(NULL)
		{
		}

		~SlaveHandler()
		{

			SAFE_DELETE(m_pDatabase);
		}
	public:
		virtual INT32 Update(){ return 0; } 

	public:
		void		StartAuth();
		void		SelectDB();
		void		RequestSyncData();
		DBSlave *	GetDBSlave(){ return m_pDBSlave; }
		bool		RecvFile(std::string strDir , std::string strFileName , std::string strDBName , INT32 nFileSize , INT32 nSendType , const CUtil::Chunk & objChunk);
		bool		RecvFileEnd(std::string strDir , std::string strDBName );
		void		SetSlaveInfo(const GameDB::SDBSlaveInfo & info);
		GameDB::SDBSlaveInfo  GetSlaveInfo(){ return m_objSlaveInfo;}
	private:
		DBSlave				*	m_pDBSlave;
		GameDB::Database	*	m_pDatabase; 
		GameDB::SDBSlaveInfo	m_objSlaveInfo;

	}; 
}

#endif