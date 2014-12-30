#ifndef __test_object_h__
#define __test_object_h__

#include "stdafx.h"
#include "InnerMsg.h"
#include "ObjectMsgCall.h"
#include "TimerHelp.h"
#include "ICallableObject.h" 
#include "MsgNameDefine.h" 
#include "Chunk.h"
#include "Rpc.h" 
#include "RpcServerManager.h"
  
 
class TestObject : public Msg::IRpcMsgCallableObject<MSG_ID>
{ 
public:
	TestObject()
		: IRpcMsgCallableObject(1){}
public:
	virtual INT32 Update(){ return 0; } 
protected:
private:
};


#endif