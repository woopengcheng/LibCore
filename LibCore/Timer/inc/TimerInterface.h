#ifndef __timer_timer_interface_h__
#define __timer_timer_interface_h__ 
/*#include "Timer/inc/MinHeapTimer.h"*/
#include "Timer/inc/IStrategy.h"

namespace Timer
{
	enum ETimerStrategyType
	{
		TIMER_STRATEGY_MIN_HEAP = 0 , 
		TIMER_STRATEGY_TIMINGWHEEL = 1 , 

		TIMER_STRATEGY_DEFAULT  = TIMER_STRATEGY_MIN_HEAP,
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
		TimerInterface(void);
		virtual ~TimerInterface(void){} 

	public:
		virtual CErrno		Init(ETimerStrategyType objTimerStrategyType = TIMER_STRATEGY_DEFAULT);
		virtual CErrno		Cleanup(void);

	public:
		virtual INT32		SetTimer(UINT32 unTimeInterval , UINT32 unTimes = 0, UINT32 unStartTime = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL , UINT32 unTimerID = 0);
		virtual CErrno		RemoveTimer(UINT32 unTimeID);
		virtual CErrno		Update(void);

	public:
		//************************************
		// Method:    GetNode
		// FullName:  Timer::TimerInterface::GetNode
		// Access:    virtual public 
		// Returns:   Node<TimerType> *
		// Qualifier: 如果这里是最小堆实现的.则输入最小堆的位置.一般输入栈顶为0
		// Parameter: UINT32 unTimerID
		//************************************
		TimerNode 		*	GetNode(UINT32 unTimerID = 0);
		CErrno				HandleNode( TimerNode * pNode );
		CErrno				UpdateNode(TimerNode * pNode);  

	public:
		UINT32				GetTimerIDCount();
		UINT32				TimerIDAutoAddOne();
	protected:
		UINT32				m_unTimerIDCount;
		IStrategy		*	m_pTimerStrategy;
		UINT32				m_unTimerCount;   //5 用来计时1秒1心跳
		UINT64				m_unLastTimerCount;
		ETimerStrategyType	m_objStrategyType;
		ThreadPool::ThreadSpinRWMutex  m_objLock;
	};
} 

#endif