#ifndef __timer_global_timer_h
#define __timer_global_timer_h
#include "TimerInterface.h"
#include "ThreadTask.h"

namespace Timer
{   

	/**
	 * @class : GlobalTimer
	 * @author: woo
	 * @date  : 2014��8��2��
	 * @file  : GlobalTimer.h
	 * @brief : �����̳���ThreadSustainTask.Ҳ������һ���̵߳����������ʱ��.Ȼ�󽫼�ʱ�������������������߳�.
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