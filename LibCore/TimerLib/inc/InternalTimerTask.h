#ifndef __timer_internal_timer_task_h__
#define __timer_internal_timer_task_h__
#include "ThreadPoolLib/inc/ThreadTask.h"

namespace Timer
{
	class TimerNode;
	class TimerInterface;

	class InternalTimerTask : public ThreadPool::ThreadNormalTask
	{
	public:
		InternalTimerTask(TimerInterface * pTimerInterface , TimerNode * pNode);
		virtual ~InternalTimerTask( void );

	public:
		virtual INT32  Update();

	private:
		TimerNode		* m_pNode;
		TimerInterface	* m_pTimerInterface;
	};
}
#endif