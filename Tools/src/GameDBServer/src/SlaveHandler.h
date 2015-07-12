#ifndef __test_slave_object_h__
#define __test_slave_object_h__

#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "RpcDefines.h" 
#include "MsgNameDefine.h"  
#include "DBSlave.h" 
#include "Common/Chunk.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/SlaveSession.h"

namespace Server
{  
	class SlaveHandler : public Msg::IRpcMsgCallableObject
	{ 
		RPC_DEFINE_SlaveHandler;
	public:
		SlaveHandler(DBSlave * pDBSlave)
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , pDBSlave->GetRpcServerManager())
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
		DBSlave *	GetDBSlave(){ return m_pDBSlave; }
		bool		RecvFile(std::string strDir , std::string strFileName , std::string strDBName , INT32 nFileSize , INT32 nSendType , const LibCore::Chunk & objChunk);
		bool		RecvFileEnd(std::string strDir , std::string strDBName );

	private:
		DBSlave * m_pDBSlave;
		GameDB::SDBSlaveInfo m_objSlaveInfo;
		GameDB::Database* m_pDatabase; 

	}; 
}

#endif