#include "Timer/inc/TimerInterface.h" 
#include "Timer/inc/TimerNode.h" 
#include "Timer/inc/IStrategy.h"
#include "Timer/inc/TimingWheel.h"

namespace Timer
{ 

	CErrno TimerInterface::Init( ETimerStrategyType objTimerStrategyType )
	{
		switch(objTimerStrategyType)
		{
		default: 
		case TIMER_STRATEGY_MIN_HEAP:
			{
				m_pTimerStrategy = new MinHeapTimer;
			}break; 
		case TIMER_STRATEGY_TIMINGWHEEL:
			{
				m_pTimerStrategy = new TimingWheel;
			}break; 
		}

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

	INT32 TimerInterface::SetTimer( UINT32 unTimeInterval , UINT32 unStartTime /*= 0*/, UINT32 unTimes /*= 0*/, void * pObj /*= NULL */, TimerCallBackFunc pFunc /*= NULL*/ )
	{
		if (m_pTimerStrategy)
		{
			TimerNode * pNode = new TimerNode(++m_unTimerIDCount , unTimeInterval , unStartTime , unTimes , pObj , pFunc);
			m_pTimerStrategy->InsertNode(m_unTimerIDCount , pNode);
		}

		return m_unTimerIDCount;
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

	TimerNode * TimerInterface::Update( void )
	{ 
		if (m_pTimerStrategy)
		{
			return m_pTimerStrategy->Update();
		}

		return NULL;
	} 

	TimerNode * TimerInterface::GetNode( UINT32 unNodeID )
	{
		if (m_pTimerStrategy)
		{
			return m_pTimerStrategy->GetNode(unNodeID);
		}
		return NULL;
	}

}