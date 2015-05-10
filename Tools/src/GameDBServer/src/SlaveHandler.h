#ifndef __test_slave_object_h__
#define __test_slave_object_h__

#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/Object.h"
#include "RpcDefines.h" 
#include "MsgNameDefine.h"  
#include "DBSlave.h" 

namespace Server
{  
	class SlaveHandler : public Msg::IRpcMsgCallableObject
	{ 
//		RPC_DEFINE_SlaveHandler;
	public:
		SlaveHandler(DBSlave * pDBSlave)
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , pDBSlave->GetRpcServerManager())
			, m_pDBSlave(pDBSlave)
		{}
	public:
		virtual INT32 Update(){ return 0; } 

	public:
		DBSlave * GetDBSlave(){ return m_pDBSlave; }

	private:
		DBSlave * m_pDBSlave;
	}; 
}

#endif