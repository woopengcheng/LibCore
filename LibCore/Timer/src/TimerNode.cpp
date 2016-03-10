#include "Timer/inc/TimerNode.h"
#include "ThreadPool/inc/ThreadLock.h"

namespace Timer
{ 
	void TimerNode::SetStartTime( UINT32 unStartTime )
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_unStartTime = unStartTime;
	}

	UINT32 TimerNode::GetStartTime()
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
		return m_unStartTime;
	}

	void TimerNode::SetTimeInterval( UINT32 unTimeInterval )
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_unTimeInterval = unTimeInterval;

	}

	UINT32 TimerNode::GetTimeInterval()
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
		return m_unTimeInterval;
	}

	void TimerNode::SetTimes( UINT32 unTimes )
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_unTimes = unTimes;

	}

	UINT32 TimerNode::GetTimes()
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
		return m_unTimes;
	}

	void TimerNode::SetTimeCount( TimeCount_Safe objTimerCount )
	{ 
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_objTimerCount = objTimerCount;
	}

	TimeCount_Safe TimerNode::GetTimeCount()
	{ 
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
		return m_objTimerCount;
	}

	void TimerNode::SetObject( void * pObj )
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_pObj = pObj;
	}

	void   * TimerNode::GetObject()
	{
		return m_pObj;
	}

	void TimerNode::SetTimerID( UINT32 unTimerID )
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_unTimerID = unTimerID;
	}

	UINT32 TimerNode::GetTimerID()
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
		return m_unTimerID;
	}

	void TimerNode::SetDelete(BOOL bDelete)
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_bDelete = bDelete; 
	}

	BOOL TimerNode::IsDelete()
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
		return m_bDelete;

	}

	void TimerNode::SetNodePos(UINT32 unNodePos)
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_unNodePos = unNodePos;
	}

	INT32 TimerNode::GetNodePos(void)
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock, false);
		return m_unNodePos;
	}

	INT64 TimerNode::GetValue(void)
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock, false);
		return m_objValue;
	}

	void TimerNode::SetValue(INT64 objValue)
	{
		ThreadPool::AutoSpinRWLock objLock(m_objLock);
		m_objValue = objValue;
	}

	ThreadPool::ThreadSpinRWMutex & TimerNode::GetLock()
	{
		return m_objLock;
	}

}