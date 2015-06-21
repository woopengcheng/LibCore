#ifndef __test_server_object_h__
#define __test_server_object_h__

#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "RpcDefines.h" 
#include "MsgNameDefine.h"  
#include "DBServer.h" 
#include "GameDB/inc/UserAuth.h"

namespace Server
{  
	class ServerHandler : public Msg::IRpcMsgCallableObject
	{ 
		RPC_DEFINE_ServerHandler;
	public:
		ServerHandler(DBServer * pDBServer)
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , pDBServer->GetRpcServerManager())
			, m_pDBServer(pDBServer)
			, m_pAuthInfo(NULL)
			, m_strDatabaseName("")
		{}
	public:
		virtual INT32 Update(){ return 0; } 
		 
	public:
		DBServer * GetDBServer(){ return m_pDBServer; }
		GameDB::UserAuth * GetAuthInfo() const { return m_pAuthInfo; }
		void SetAuthInfo(GameDB::UserAuth * val) { m_pAuthInfo = val; }

	private:
		DBServer * m_pDBServer;
		GameDB::UserAuth * m_pAuthInfo;
		std::string m_strDatabaseName;

	}; 
}

#endif