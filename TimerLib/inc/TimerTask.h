#ifndef __timer_timer_task_h
#define __timer_timer_task_h
#include "TimerCommon.h"  
#include "ThreadTask.h"

namespace Timer
{ 	 
	/**
	 * @class : TimerTask
	 * @author: woo
	 * @date  : 2014��8��2��
	 * @file  : TimerTask.h
	 * @brief : �������Ҫ����Ҫʹ�õ���ʱ������̳�,Ȼ������OnTimer����.�ȴ���ʱ������.
	 */
	class DLL_EXPORT TimerTask 
	{   
	public:
		TimerTask( void ){}
		virtual ~TimerTask( void ){}

	public:		
		//************************************
		// Method:    OnTimer
		// FullName:  TimerTask::OnTimer
		// Access:    virtual public 
		// Returns:   void
		// Qualifier: ��ʱ����������õĺ���.��Ҫ����.
		// Parameter: UINT32 unTimerID  ��ʱ����ID
		// Parameter: UINT32 unTimers   ��ʱ���Ĵ���
		//************************************
		virtual void  OnTimer(UINT32 unTimerID , UINT32 unTimers) = 0;
		 
		//************************************
		// Method:    RunTimer
		// FullName:  TimerTask::RunTimer
		// Access:    static public 
		// Returns:   void
		// Qualifier: ��ʱ�����ü�ʱ������ĺ���.
		// Parameter: UINT32 unTimerID
		// Parameter: UINT32 unTimers
		//************************************
		static void  RunTimer(void * pObj , UINT32 unTimerID , UINT32 unTimers);

		//************************************
		// Method:    SetTimer
		// FullName:  TimerTask::SetTimer
		// Access:    virtual public  
		// Returns:   INT32   ����Timer��ID.-1�������.
		// Qualifier: ��Ӽ�ʱ������ʱ��������.
		// Parameter: UINT32 unInterval    ʱ����
		// Parameter: UINT32 unTimes       0�������.1����һ��.
		// Parameter: UINT32 unStartTimer  0�����ɿ�ʼ
		//************************************
		virtual INT32  SetTimer( UINT32 unInterval , UINT32 unTimes = 0, UINT32 unStartTimer = 0);
	};
}

#endif