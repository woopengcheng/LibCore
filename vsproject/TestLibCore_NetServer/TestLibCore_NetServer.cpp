// TestNetLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "MsgLib/inc/InnerMsg.h"
#include "ThreadPoolLib/inc/ThreadTask.h"  
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"  
#include "Server.h"
#include "Common/CUtil.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	CUtil::Init("server"); 
	int nCount = ThreadPool::ThreadPoolInterface::GetInstance().GetThreadsCount(); 
	Server server;
	server.Init();

	server.Update();

	CUtil::Cleanup(); 
	return 0;
}

