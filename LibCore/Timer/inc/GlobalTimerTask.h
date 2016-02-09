#ifndef __timer_global_timer_task_h
#define __timer_global_timer_task_h
#include "Timer/inc/TimerTask.h" 


namespace Timer
{ 
	/**
	 * @class : TimerTask
	 * @author: woo
	 * @date  : 2014��8��2��
	 * @file  : TimerTask.h
	 * @brief : �������Ҫ����Ҫʹ�õ���ʱ������̳�,Ȼ������OnTimer����.�ȴ���ʱ������.
	 */
	class DLL_EXPORT GlobalTimerTask : public TimerTask
	{
	public:
		GlobalTimerTask( void );
		virtual ~GlobalTimerTask( void );

	public:		 
		virtual void		OnTimer(UINT32 unTimerID , UINT32 unTimers) override;
		virtual INT32		SetTimer( UINT32 unInterval , UINT32 unTimes = 0, UINT32 unStartTimer = 0) override;

	};
}

#endif