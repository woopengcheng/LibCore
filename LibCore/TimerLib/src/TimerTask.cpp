#include "TimerTask.h" 

namespace Timer
{
	void TimerTask::OnTimer( UINT32 unTimerID , UINT32 unTimers )
	{

	}

	void TimerTask::RunTimer(void * pObj , UINT32 unTimerID , UINT32 unTimers )
	{
		if (pObj)
		{
			TimerTask * pTask = (TimerTask*)pObj;
			pTask->OnTimer(unTimerID , unTimers);
		}
	}

	INT32 TimerTask::SetTimer( UINT32 unInterval , UINT32 unTimes , UINT32 unStartTimer /*= 0*/ )
	{   
		return ERR_FAILURE;
	} 
}