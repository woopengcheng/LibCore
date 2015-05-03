#ifndef __test_server_object_h__
#define __test_server_object_h__

#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "RpcDefines.h" 
#include "MsgNameDefine.h"  
#include "DBServer.h" 

namespace Server
{  
	class ServerHandler : public Msg::IRpcMsgCallableObject
	{ 
		RPC_DEFINE_ServerHandler;
	public:
		ServerHandler()
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , DBServer::GetInstance().GetRpcServerManager()){}
	public:
		virtual INT32 Update(){ return 0; } 

		
	protected:
	private:
	}; 
}

#endif