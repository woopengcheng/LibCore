#include "TimerNode.h"


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
		ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
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

}