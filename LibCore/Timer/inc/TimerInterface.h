#ifndef __timer_timer_interface_h__
#define __timer_timer_interface_h__ 
#include "Timer/inc/MinHeapTimer.h"

namespace Timer
{
	enum ETimerStrategyType
	{
		TIMER_STRATEGY_MIN_HEAP = 0 , 
		TIMER_STRATEGY_TIMINGWHEEL = 1 , 

		TIMER_STRATEGY_DEFAULT  = TIMER_STRATEGY_MIN_HEAP , 
	};

	/**
	 * @class : Timer
	 * @author: woo
	 * @date  : 2014年8月3日
	 * @file  : Timer.h
	 * @brief : 过渡类.用来屏蔽底层和上层.也可以进行转换底层的实现机制.
	 * @bug   : 这里有一个Bug.当这个类为Timer 的时候.那么在模板实现中.就不能写作用域Timer.否则编译器不能识别.
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
		virtual INT32		Init(ETimerStrategyType objTimerStrategyType = TIMER_STRATEGY_DEFAULT);
		virtual INT32		Cleanup(void);

	public:
		virtual INT32		SetTimer(UINT32 unTimeInterval , UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL);
		virtual INT32		RemoveTimer(UINT32 unTimeID);
		virtual TimerNode * Update(void);

	public:
		//************************************
		// Method:    GetNode
		// FullName:  Timer::TimerInterface::GetNode
		// Access:    virtual public 
		// Returns:   Node<TimerType> *
		// Qualifier: 如果这里是最小堆实现的.则输入最小堆的位置.一般输入栈顶为0
		// Parameter: UINT32 unNodeID
		//************************************
		TimerNode *			GetNode(UINT32 unNodeID = 0);

	public:
		UINT32				GetTimerIDCount()
		{
			ThreadPool::AutoSpinRWLock(m_objLock , false);
			return m_unTimerIDCount;
		} 
		UINT32				TimerIDAutoAddOne()
		{
			ThreadPool::AutoSpinRWLock(m_objLock);
			return ++m_unTimerIDCount; 
		} 

	protected:
		UINT32                 m_unTimerIDCount;
		IStrategy			 * m_pTimerStrategy;
		ThreadPool::ThreadSpinRWMutex  m_objLock;
	};
} 

#endif