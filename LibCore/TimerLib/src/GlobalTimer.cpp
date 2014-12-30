#include "GlobalTimer.h" 
#include "ThreadPoolInterface.h"
#include "InternalTimerTask.h" 
#include "TimerNode.h" 

namespace Timer
{  
	INT32 GlobalTimer::Init(UINT32 unTimerThreadPriorityCount , UINT32 unTimerHandlerthreadPriorityCount , UINT32 unTimerThreadPriority /* = DEFAULT_TIMER_THREAD_ID*/ ,UINT32 unTimerHandlerthreadPriority /*= DEFAULT_TIMER_HANDLE_THREAD_ID */)
	{
 		ThreadPool::ThreadPoolInterface::GetInstance().Init(std::map<UINT32 , UINT32>() , TRUE);
 		ThreadPool::ThreadPoolInterface::GetInstance().Startup();
		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unTimerThreadPriority , unTimerThreadPriorityCount);  //5 ����һ��ȫ�ֵļ�ʱ���߳�.
 		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unTimerHandlerthreadPriority , unTimerHandlerthreadPriorityCount);  //5 ���������ʱ��������߳�.

		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);

		return TimerInterface::Init();              //5 ����������
	}

	INT32 GlobalTimer::Cleanup( void )
	{
		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();

		return TimerInterface::Cleanup();            //5 ����������
	} 

	INT32 GlobalTimer::Update( void )
	{ 
		Node<TimerType> * pNodeInt64 = GetNode();
		if (!pNodeInt64)
		{
			return FALSE;
		}
		TimerNode * pNode = pNodeInt64->GetClass<TimerNode>();    //5 ��ȡ�Ѷ���Ԫ��.Ȼ����бȽ�.

		if (pNode && pNode->GetTimeCount().IsExpired())
		{
			InternalTimerTask * pTask = new InternalTimerTask(pNode); 
 			ThreadPool::ThreadPoolInterface::GetInstance().AddTask(pTask);

			return RemoveTimer(pNode->GetTimerID());
		}

		return TRUE;
	} 
}