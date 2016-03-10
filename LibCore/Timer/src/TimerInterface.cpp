#include "Timer/inc/TimerInterface.h" 
#include "Timer/inc/TimerNode.h" 
#include "Timer/inc/IStrategy.h"
#include "Timer/inc/TimingWheel.h"
#include "Timer/inc/TimerTask.h"
#include "Timer/inc/TimerHelp.h"

namespace Timer
{ 
#define TIMER_PEROID 1000

	TimerInterface::TimerInterface(void)
		: m_unTimerIDCount(0)
		, m_pTimerStrategy(NULL)
		, m_unTimerCount(0)
		, m_unLastTimerCount(Timer::GetTickMicroSecond())
	{}

	CErrno TimerInterface::Init(ETimerStrategyType objTimerStrategyType)
	{
		if (m_pTimerStrategy)
		{
			return CErrno::Failure();
		}

		switch(objTimerStrategyType)
		{
		default: 
		case TIMER_STRATEGY_MIN_HEAP:
			{
/*				m_pTimerStrategy = new MinHeapTimer;*/
			}break; 
		case TIMER_STRATEGY_TIMINGWHEEL:
			{
				m_pTimerStrategy = new TimingWheel;
			}break; 
		}

		m_objStrategyType = objTimerStrategyType;
		return m_pTimerStrategy->Init();
	}

	CErrno TimerInterface::Cleanup( void )
	{
		CErrno nResult(CErrno::ERR_FAILURE);
		if (m_pTimerStrategy)
		{
			nResult = m_pTimerStrategy->Cleanup();
			SAFE_DELETE(m_pTimerStrategy);
		}

		return nResult;
	}

	INT32 TimerInterface::SetTimer( UINT32 unTimeInterval ,UINT32 unTimes /*= 0*/,  UINT32 unStartTime /*= 0*/, void * pObj /*= NULL */, TimerCallBackFunc pFunc /*= NULL*/ , UINT32 unTimerID/* = 0*/)
	{
		UINT32 unID = 0;
		if (m_pTimerStrategy)
		{
			if (unTimerID > 0)
			{
				unID = unTimerID;
			}
			else
			{
				++m_unTimerIDCount;
				unID = m_unTimerIDCount;
			}
			TimerNode * pNode = new TimerNode(unID , unTimeInterval , unStartTime , unTimes , pObj , pFunc);
			m_pTimerStrategy->InsertNode(unID , pNode);
		}

		return unID;
	}

	CErrno TimerInterface::RemoveTimer( UINT32 unTimeID )
	{
		CErrno nResult(CErrno::ERR_FAILURE);
		if (m_pTimerStrategy)
		{
			nResult = m_pTimerStrategy->RemoveNode(unTimeID);
		}

		return nResult;
	}

	CErrno TimerInterface::HandleNode( TimerNode * pNode )
	{
		if (!pNode)
		{
			return CErrno::Failure();
		} 

		TimerNode * pOldNode = NULL;
		do
		{
			if (pNode)
			{
				if (!pNode->IsDelete())
				{
					UpdateNode(pNode);
				}
				pOldNode = pNode;
				pNode = pNode->GetNext();
				SAFE_DELETE(pOldNode);
			} 
			else
			{
				break;
			}
		}while(pNode);

		return CErrno::Success();
	}

	CErrno TimerInterface::Update( void )
	{ 
		if (m_pTimerStrategy)
		{
			if (m_objStrategyType == TIMER_STRATEGY_TIMINGWHEEL)
			{
				m_unTimerCount += Timer::GetTickMicroSecond() - m_unLastTimerCount;
				m_unLastTimerCount = Timer::GetTickMicroSecond();
				int nRepeat = (m_unTimerCount) / TIMER_PEROID;
				m_unTimerCount = (m_unTimerCount % TIMER_PEROID);
				if (nRepeat)
				{	
					while(nRepeat--)
					{
						TimerNode * pNode = m_pTimerStrategy->Update();
						HandleNode(pNode);
					}

					return CErrno::Success();
				}
			}
			else
			{
// 				TimerNode * pNode = m_pTimerStrategy->Update();
// 				if (pNode && pNode->GetTimeCount().IncCounter(g_pGame->GetRealTickTime()))
// 				{
// 					HandleNode(pNode);
// 					return CErrno::Success();
// 				}				
			}
		}

		return CErrno::Failure();
	} 

	TimerNode * TimerInterface::GetNode( UINT32 unNodeID )
	{
		if (m_pTimerStrategy)
		{
			return m_pTimerStrategy->GetNode(unNodeID);
		}
		return NULL;
	}

	CErrno TimerInterface::UpdateNode( TimerNode * pNode )
	{
		if (pNode)
		{
			TimerTask * pTask = (TimerTask *)(pNode->GetObject());
			if (pTask)
			{
				UINT32 unTimers = pNode->GetTimes();
				if (pNode->GetCallBackFunc())
				{
					pNode->GetCallBackFunc()(pTask , pNode->GetTimerID() , unTimers);
				}
				else
				{
					pTask->OnTimer(pNode->GetTimerID() , unTimers);  
				}

				if (unTimers == 0)
				{
					if (!pNode->IsDelete())
					{
						pTask->SetTimer(pNode->GetTimeInterval() , unTimers , 0 , pNode->GetTimerID());
					}
				}
				else
				{
					pNode->SetTimes(--unTimers);
					if (unTimers > 0)
					{
						if (!pNode->IsDelete())
						{
							pTask->SetTimer(pNode->GetTimeInterval() , unTimers , 0 , pNode->GetTimerID());
						}
					}
					else
					{
						RemoveTimer(pNode->GetTimerID());
					}
				}

			}
			else
			{
				UINT32 unTimers = pNode->GetTimes();
				if (pNode->GetCallBackFunc())
				{
					pNode->GetCallBackFunc()(NULL , pNode->GetTimerID() , unTimers);
				}

				if (unTimers == 0)
				{
					if (!pNode->IsDelete())
					{
						SetTimer(pNode->GetTimeInterval() , unTimers, 0 , NULL , pNode->GetCallBackFunc() , pNode->GetTimerID());
					}
				}
				else
				{
					pNode->SetTimes(--unTimers); 
					if (unTimers > 0)
					{
						if (!pNode->IsDelete())
						{
							SetTimer(pNode->GetTimeInterval() , unTimers, 0 ,NULL , pNode->GetCallBackFunc() , pNode->GetTimerID());
						}
					}
					else
					{
						RemoveTimer(pNode->GetTimerID());
					}
				}

			}

			return CErrno::Success();
		}

		return CErrno::Failure();
	}

	UINT32 TimerInterface::GetTimerIDCount()
	{
		ThreadPool::AutoSpinRWLock(m_objLock, false);
		return m_unTimerIDCount;
	}

	UINT32 TimerInterface::TimerIDAutoAddOne()
	{
		ThreadPool::AutoSpinRWLock(m_objLock);
		return ++m_unTimerIDCount;
	}

}
