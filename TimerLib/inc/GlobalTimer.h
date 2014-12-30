#ifndef __timer_global_timer_h
#define __timer_global_timer_h
#include "TimerInterface.h"
#include "ThreadTask.h"

namespace Timer
{   

	/**
	 * @class : GlobalTimer
	 * @author: woo
	 * @date  : 2014年8月2日
	 * @file  : GlobalTimer.h
	 * @brief : 这个类继承自ThreadSustainTask.也就是有一个线程单独跑这个计时器.然后将计时器的任务分配给其他的线程.
	 */ 
	class DLL_EXPORT GlobalTimer : public TimerInterface , public ThreadPool::ThreadSustainTask   
	{
	public:
		GlobalTimer(void)
			: ThreadPool::ThreadSustainTask(DEFAULT_TIMER_THREAD_ID , "GlobalTimer" , TRUE) 
		{}
		virtual ~GlobalTimer(void){}
		 
	public:
		static GlobalTimer & GetInstance( void ){ static GlobalTimer m_sInstance; return m_sInstance;}

	public: 
		virtual INT32    Init(UINT32 unTimerThreadPriorityCount = 1 , UINT32 unTimerHandlerthreadPriorityCount = 1, UINT32 unTimerThreadPriority = DEFAULT_TIMER_THREAD_ID ,UINT32 unTimerHandlerthreadPriority = DEFAULT_TIMER_HANDLE_THREAD_ID );
		virtual INT32    Cleanup(void);

	public: 
		virtual INT32    Update(void); 
	};  
} 
#endif