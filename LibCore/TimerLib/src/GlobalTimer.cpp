#include "TimerLib/inc/GlobalTimer.h" 
#include "MsgLib/inc/InnerMsg.h"
#include "TimerLib/inc/InternalTimerTask.h" 
#include "TimerLib/inc/TimerNode.h" 
#include "ThreadPoolLib/inc/ThreadPool.h"
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"

namespace Timer
{  
	INT32 GlobalTimer::Init(UINT32 unTimerThreadPriorityCount , UINT32 unTimerHandlerthreadPriorityCount , UINT32 unTimerThreadPriority /* = DEFAULT_TIMER_THREAD_ID*/ ,UINT32 unTimerHandlerthreadPriority /*= DEFAULT_TIMER_HANDLE_THREAD_ID */)
	{
 		ThreadPool::ThreadPoolInterface::GetInstance().Init(std::map<UINT32 , UINT32>() , TRUE);
 		ThreadPool::ThreadPoolInterface::GetInstance().Startup();
		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unTimerThreadPriority , unTimerThreadPriorityCount);  //5 创建一个全局的计时器线程.
 		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unTimerHandlerthreadPriority , unTimerHandlerthreadPriorityCount);  //5 创建处理计时器任务的线程.

		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);

		return TimerInterface::Init();              //5 这里必须调用
	}

	INT32 GlobalTimer::Cleanup( void )
	{
		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();

		return TimerInterface::Cleanup();            //5 这里必须调用
	} 

	INT32  GlobalTimer::Update_Thread( void )
	{  
		TimerNode * pNode = TimerInterface::Update();
		if (!pNode)
		{
			return NULL;
		} 

		if (pNode && pNode->GetTimeCount().IsExpired())
		{
			InternalTimerTask * pTask = new InternalTimerTask(pNode); 
			ThreadPool::ThreadPoolInterface::GetInstance().AddTask(pTask);

			pNode = pNode->GetNext();
			return ERR_SUCCESS;
		} 
		return ERR_FAILURE;
	} 
}