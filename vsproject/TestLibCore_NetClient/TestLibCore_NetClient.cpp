// TestNetLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "Common/LibCore.h"
#include "MsgLib/inc/InnerMsg.h"
#include "ThreadPoolLib/inc/ThreadTask.h"  
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"  
#include "client.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	LibCore::Init("Client");

	int nCount = ThreadPool::ThreadPoolInterface::GetInstance().GetThreadsCount(); 	
	Client client;
	client.Init();

	client.Update();


	LibCore::Cleanup(); 

	return 0;
}

