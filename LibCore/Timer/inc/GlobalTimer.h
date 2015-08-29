#ifndef __timer_global_timer_h
#define __timer_global_timer_h
#include "Timer/inc/TimerNode.h"
#include "Timer/inc/TimerInterface.h"
#include "ThreadPool/inc/ThreadTask.h"

namespace Timer
{   
	class DLL_EXPORT FooTimeInterface :  public TimerInterface 
	{
	public:
		virtual TimerNode * Update_Timer(void)
		{
			return Update();
		}
	};

	class DLL_EXPORT BarThreadSustainTask : public ThreadPool::ThreadSustainTask  
	{
	public:
		BarThreadSustainTask(UINT32 unPriority , char * a = "UnknownName", BOOL bInStack = TRUE)
			: ThreadPool::ThreadSustainTask(unPriority , a , bInStack) 
		{

		}
		virtual CErrno Update_Thread(void)
		{
			return CErrno::Success();
		} 
		virtual CErrno Update(void)
		{
			return Update_Thread();
		} 
	};

	/**
	 * @class : GlobalTimer
	 * @author: woo
	 * @date  : 2014��8��2��
	 * @file  : GlobalTimer.h
	 * @brief : �����̳���ThreadSustainTask.Ҳ������һ���̵߳����������ʱ��.Ȼ�󽫼�ʱ�������������������߳�.
	 */ 
	class DLL_EXPORT GlobalTimer : public FooTimeInterface , public BarThreadSustainTask   
	{
	public:
		GlobalTimer(void)
			: BarThreadSustainTask(DEFAULT_TIMER_THREAD_ID , "GlobalTimer" , TRUE) 
		{}
		virtual ~GlobalTimer(void){}
		 
	public:
		static GlobalTimer & GetInstance( void ){ static GlobalTimer m_sInstance; return m_sInstance;}

	public: 
		virtual CErrno    Init(UINT32 unTimerThreadPriorityCount = 1 , UINT32 unTimerHandlerthreadPriorityCount = 1, UINT32 unTimerThreadPriority = DEFAULT_TIMER_THREAD_ID ,UINT32 unTimerHandlerthreadPriority = DEFAULT_TIMER_HANDLE_THREAD_ID );
		virtual CErrno    Cleanup(void);

	public:  
		virtual CErrno    Update_Thread(void); 
	};  
} 
#endif