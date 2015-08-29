#include "Timer/inc/GlobalTimer.h" 
#include "MsgLib/inc/InnerMsg.h"
#include "Timer/inc/InternalTimerTask.h" 
#include "Timer/inc/TimerNode.h" 
#include "ThreadPool/inc/ThreadPool.h"
#include "ThreadPool/inc/ThreadPoolInterface.h"

namespace Timer
{  
	CErrno GlobalTimer::Init(UINT32 unTimerThreadPriorityCount , UINT32 unTimerHandlerthreadPriorityCount , UINT32 unTimerThreadPriority /* = DEFAULT_TIMER_THREAD_ID*/ ,UINT32 unTimerHandlerthreadPriority /*= DEFAULT_TIMER_HANDLE_THREAD_ID */)
	{
 		ThreadPool::ThreadPoolInterface::GetInstance().Init(std::map<UINT32 , UINT32>() , TRUE);
 		ThreadPool::ThreadPoolInterface::GetInstance().Startup();
		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unTimerThreadPriority , unTimerThreadPriorityCount);  //5 创建一个全局的计时器线程.
 		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unTimerHandlerthreadPriority , unTimerHandlerthreadPriorityCount);  //5 创建处理计时器任务的线程.

		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);

		return TimerInterface::Init();              //5 这里必须调用
	}

	CErrno GlobalTimer::Cleanup( void )
	{
		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();

		return TimerInterface::Cleanup();            //5 这里必须调用
	} 

	CErrno  GlobalTimer::Update_Thread( void )
	{  
		TimerNode * pNode = TimerInterface::Update();
		if (!pNode)
		{
			return CErrno::Failure();
		} 

		while(pNode)
		{
			if (pNode && pNode->GetTimeCount().IsExpired())
			{
				InternalTimerTask * pTask = new InternalTimerTask(this , pNode); 
				ThreadPool::ThreadPoolInterface::GetInstance().AddTask(pTask);

				pNode = pNode->GetNext();
			}  
		}
		return CErrno::Success();
	} 
}