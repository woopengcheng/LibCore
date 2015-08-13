// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "TimerLib/inc/TimerHelp.h"  
#include "MsgNameDefine.h"  
#include "TestObject.h" 
#include "RpcInstance.h"
#include "Common/CUtil.h"   

int _tmain(int argc, _TCHAR* argv[])
{
	CUtil::Init("RPCProxy"); 
	Proxy::RpcInstance::GetInstance().Init("RPCProxyConfigs.xml"); 

// 	TestObject<MSG_ID>  ObjTestObject;  
// 	RPC_DEFINE(TestObject1)

	while (1)
	{
		Proxy::RpcInstance::GetInstance().Update(); 
	}

	Proxy::RpcInstance::GetInstance().Cleanup();  
	CUtil::Cleanup();
	return 0;
}

