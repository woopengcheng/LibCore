// TestNetLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "ThreadPoolInterface.h"
#include "ThreadTask.h"  
#include "Server.h"

int _tmain(int argc, _TCHAR* argv[])
{   

	Net::InitNet();
	int nCount = ThreadPool::ThreadPoolInterface::GetInstance().GetThreadsCount(); 
	Server server;
	server.Init();

	server.Update();

	Net::CleanNet();

	return 0;
}

