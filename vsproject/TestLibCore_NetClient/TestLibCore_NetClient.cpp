// TestNetLib.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"  
#include "Common/inc/CUtil.h"
#include "MsgLib/inc/InnerMsg.h"
#include "ThreadPoolLib/inc/ThreadTask.h"  
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"  
#include "client.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	CUtil::Init("Client");

	int nCount = ThreadPool::ThreadPoolInterface::GetInstance().GetThreadsCount(); 	
	Client client;
	client.Init();

	client.Update();


	CUtil::Cleanup(); 

	return 0;
}

