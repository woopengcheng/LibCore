#include "TimerLib/inc/TimerInterface.h" 
#include "TimerLib/inc/TimerNode.h" 
#include "TimerLib/inc/IStrategy.h"
#include "TimerLib/inc/TimingWheel.h"

namespace Timer
{ 

	INT32 TimerInterface::Init( ETimerStrategyType objTimerStrategyType )
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

	INT32 TimerInterface::Cleanup( void )
	{
		INT32 nResult = -1;
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

	INT32 TimerInterface::RemoveTimer( UINT32 unTimeID )
	{
		INT32 nResult = -1;
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