#ifndef __timer_i_strategy_h__
#define __timer_i_strategy_h__ 
#include "Timer/inc/TimerNode.h"  


namespace Timer
{ 
	class IStrategy
	{ 
	public:
		IStrategy(void){}
		virtual ~IStrategy(void){ }

	public:
		virtual CErrno		Init(void) = 0 { return CErrno::Success(); }
		virtual CErrno		Cleanup(void) = 0{ return CErrno::Success(); }
		virtual TimerNode * Update(void) = 0{ return NULL; }

	public:
		virtual CErrno		InsertNode(UINT32 unNodeID ,TimerNode * pNode) = 0 { return CErrno::Success(); }
		virtual CErrno		RemoveNode(UINT32 unNodeID) = 0 { return CErrno::Success(); }
		virtual TimerNode * GetNode(UINT32 unNodeID) = 0{ return NULL; }
	};   
} 
#endif