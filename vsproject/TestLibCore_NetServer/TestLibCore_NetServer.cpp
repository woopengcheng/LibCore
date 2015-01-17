// TestNetLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "MsgLib/inc/InnerMsg.h"
#include "ThreadPoolLib/inc/ThreadTask.h"  
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"  
#include "Server.h"
#include "Common/LibCore.h"

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

