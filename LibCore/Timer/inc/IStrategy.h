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
		virtual INT32		Init(void) = 0 { return ERR_SUCCESS; }
		virtual INT32		Cleanup(void) = 0{ return ERR_SUCCESS; }
		virtual TimerNode * Update(void) = 0{ return NULL; }

	public:
		virtual INT32		InsertNode(UINT32 unNodeID ,TimerNode * pNode) = 0 { return ERR_SUCCESS; }
		virtual INT32		RemoveNode(UINT32 unNodeID) = 0 { return ERR_SUCCESS; }
		virtual TimerNode * GetNode(UINT32 unNodeID) = 0{ return NULL; }
	};   
} 
#endif