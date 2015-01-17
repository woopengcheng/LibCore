// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "TestObject.h" 
#include "RpcInstance.h" 
#include "Common/LibCore.h" 
  
int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("RpcServer"); 
	Server::RpcInstance::GetInstance().Init("RPCServerConfigs.xml"); 
	 
	Server::TestObject  ObjTestObject;   
	while (1)
	{
 		Server::RpcInstance::GetInstance().Update();
	}

 	Server::RpcInstance::GetInstance().Cleanup();  
	LibCore::Cleanup();
	return 0;
}

