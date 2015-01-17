// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "TimerLib/inc/TimerHelp.h"  
#include "MsgNameDefine.h"  
#include "TestObject.h" 
#include "RpcInstance.h"
#include "Common/LibCore.h"   

int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("RPCProxy"); 
	Proxy::RpcInstance::GetInstance().Init("RPCProxyConfigs.xml"); 

// 	TestObject<MSG_ID>  ObjTestObject;  
// 	RPC_DEFINE(TestObject1)

	while (1)
	{
		Proxy::RpcInstance::GetInstance().Update(); 
	}

	Proxy::RpcInstance::GetInstance().Cleanup();  
	LibCore::Cleanup();
	return 0;
}

