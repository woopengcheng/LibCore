#ifndef __timer_internal_timer_task_h__
#define __timer_internal_timer_task_h__
#include "ThreadTask.h"

namespace Timer
{
	class TimerNode;

	class InternalTimerTask : public ThreadPool::ThreadNormalTask
	{
	public:
		InternalTimerTask( TimerNode * pNode);
		virtual ~InternalTimerTask( void );

	public:
		virtual INT32  Update();

	private:
		TimerNode * m_pNode;
	};
}
#endif