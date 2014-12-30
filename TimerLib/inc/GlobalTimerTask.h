#ifndef __timer_global_timer_task_h
#define __timer_global_timer_task_h
#include "TimerTask.h" 


namespace Timer
{ 
	/**
	 * @class : TimerTask
	 * @author: woo
	 * @date  : 2014年8月2日
	 * @file  : TimerTask.h
	 * @brief : 这个类主要是需要使用到计时器的类继承,然后重载OnTimer函数.等待计时器触发.
	 */
	class DLL_EXPORT GlobalTimerTask : public TimerTask
	{
	public:
		GlobalTimerTask( void );
		virtual ~GlobalTimerTask( void );

	public:		
		//************************************
		// Method:    OnTimer
		// FullName:  GlobalTimerTask::OnTimer
		// Access:    virtual public 
		// Returns:   void
		// Qualifier: 计时器触发后调用的函数.需要重载.
		// Parameter: UINT32 unTimerID  计时器的ID
		// Parameter: UINT32 unTimers   计时器的次数
		//************************************
		virtual void  OnTimer(UINT32 unTimerID , UINT32 unTimers);
		  
		//************************************
		// Method:    SetTimer
		// FullName:  GlobalTimerTask::SetTimer
		// Access:    virtual public 
		// Returns:   INT32   返回Timer的ID.-1代表错误.
		// Qualifier: 
		// Parameter: UINT32 unInterval    时间间隔
		// Parameter: UINT32 unTimes       0代表持续.1代表一次.
		// Parameter: UINT32 unStartTimer  0代表即可开始
		//************************************
		virtual INT32  SetTimer( UINT32 unInterval , UINT32 unTimes = 0, UINT32 unStartTimer = 0);

	};
}

#endif