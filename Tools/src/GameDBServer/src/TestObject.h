#ifndef __test_server_object_h__
#define __test_server_object_h__

#include "stdafx.h"  
#include "MsgNameDefine.h"  
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "RpcDefines.h" 
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcInterface.h"
#include "DBServer.h"
#include "RpcInstance.h"

namespace Server
{  
	class TestObject : public Msg::IRpcMsgCallableObject
	{ 
		RPC_DEFINE_TestObject;
	public:
		TestObject()
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , RpcInstance::GetInstance().GetRpcServerManager()){}
	public:
		virtual INT32 Update(){ return 0; } 

		
	protected:
	private:
	}; 
}

#endif