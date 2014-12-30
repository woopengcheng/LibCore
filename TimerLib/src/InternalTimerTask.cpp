#include "InternalTimerTask.h"
#include "TimerNode.h"
#include "TimerTask.h"
#include "GlobalTimer.h"

namespace Timer
{ 
	InternalTimerTask::InternalTimerTask( TimerNode * pNode )
		: ThreadNormalTask(DEFAULT_TIMER_HANDLE_THREAD_ID , "InternalTimerTask")
		, m_pNode(pNode)
	{

	}

	InternalTimerTask::~InternalTimerTask( void )
	{

	}

	INT32 InternalTimerTask::Update()
	{
		if (m_pNode)
		{
			TimerTask * pTask = (TimerTask *)(m_pNode->GetObject());
			if (pTask)
			{
				UINT32 unTimers = m_pNode->GetTimes();
				pTask->RunTimer(pTask , m_pNode->GetTimerID() , unTimers); 

				if (unTimers == 0)
				{
					pTask->SetTimer(m_pNode->GetTimeInterval() , unTimers , 0);
				}
				else if(unTimers == 1)
				{
					GlobalTimer::GetInstance().RemoveTimer(m_pNode->GetTimerID());
				}
				else
					m_pNode->SetTimes(--unTimers);

			}
			return TRUE;
		}

		return FALSE;
	}

}