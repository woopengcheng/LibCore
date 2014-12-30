// TestNetLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "ThreadPoolInterface.h"
#include "ThreadTask.h"  
#include "Server.h"
#include "LibCore.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	LibCore::Init("server"); 
	int nCount = ThreadPool::ThreadPoolInterface::GetInstance().GetThreadsCount(); 
	Server server;
	server.Init();

	server.Update();

	LibCore::Cleanup(); 
	return 0;
}

