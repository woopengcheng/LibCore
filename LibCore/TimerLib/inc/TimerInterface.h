#ifndef __timer_timer_interface_h__
#define __timer_timer_interface_h__ 
#include "MinHeapTimer.h"

namespace Timer
{
	enum ETimerStrategyType
	{
		TIMER_STRATEGY_MIN_HEAP = 0 , 

		TIMER_STRATEGY_DEFAULT  = TIMER_STRATEGY_MIN_HEAP , 
	};

	/**
	 * @class : Timer
	 * @author: woo
	 * @date  : 2014��8��3��
	 * @file  : Timer.h
	 * @brief : ������.�������εײ���ϲ�.Ҳ���Խ���ת���ײ��ʵ�ֻ���.
	 * @bug   : ������һ��Bug.�������ΪTimer ��ʱ��.��ô��ģ��ʵ����.�Ͳ���д������Timer.�������������ʶ��.
	 */ 
	class DLL_EXPORT TimerInterface
	{ 
	public:
		TimerInterface(void)
			: m_unTimerIDCount(0)
			, m_pTimerStrategy(NULL)
		{}
		virtual ~TimerInterface(void){} 

	public:
		virtual INT32    Init(ETimerStrategyType objTimerStrategyType = TIMER_STRATEGY_DEFAULT);
		virtual INT32    Cleanup(void);

	public:
		virtual INT32    SetTimer(UINT32 unTimeInterval , UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL);
		virtual INT32    RemoveTimer(UINT32 unTimeID);
		virtual INT32    Update(void);

	public:
		//************************************
		// Method:    GetNode
		// FullName:  Timer::TimerInterface::GetNode
		// Access:    virtual public 
		// Returns:   Node<TimerType> *
		// Qualifier: �����������С��ʵ�ֵ�.��������С�ѵ�λ��.һ������ջ��Ϊ0
		// Parameter: UINT32 unNodeID
		//************************************
		Node<TimerType>* GetNode(UINT32 unNodeID = 0);

	public:
		UINT32           GetTimerIDCount()
		{
			ThreadPool::AutoSpinRWLock(m_objLock , false);
			return m_unTimerIDCount;
		} 
		UINT32           TimerIDAutoAddOne()
		{
			ThreadPool::AutoSpinRWLock(m_objLock);
			return ++m_unTimerIDCount; 
		} 

	protected:
		UINT32                 m_unTimerIDCount;
		IStrategy<TimerType> * m_pTimerStrategy;
		ThreadPool::ThreadSpinRWMutex  m_objLock;
	};
} 

#endif