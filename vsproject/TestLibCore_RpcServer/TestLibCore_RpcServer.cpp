// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "TestObject.h" 
#include "RpcInstance.h" 
#include "Common/CUtil.h" 
  
int _tmain(int argc, _TCHAR* argv[])
{
	CUtil::Init("RpcServer"); 
	Server::RpcInstance::GetInstance().Init("RPCServerConfigs.xml"); 
	 
	Server::TestObject  ObjTestObject;   
	while (1)
	{
 		Server::RpcInstance::GetInstance().Update();
	}

 	Server::RpcInstance::GetInstance().Cleanup();  
	CUtil::Cleanup();
	return 0;
}

