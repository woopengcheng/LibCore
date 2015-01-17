#ifndef __timer_i_strategy_h__
#define __timer_i_strategy_h__ 
#include "TimerLib/inc/Node.h"  


namespace Timer
{
	template <typename ValueType>
	class IStrategy
	{ 
	public:
		IStrategy(void){}
		virtual ~IStrategy(void){ }

	public:
		virtual INT32  Init(void) = 0 { return ERR_SUCCESS; }
		virtual INT32  Cleanup(void) = 0{ return ERR_SUCCESS; }

	public:
		virtual INT32  InsertNode(UINT32 unNodeID , Node<ValueType> * pNode) = 0 { return ERR_SUCCESS; }
		virtual INT32  RemoveNode(UINT32 unNodeID) = 0 { return ERR_SUCCESS; }
		virtual Node<ValueType> * GetNode(UINT32 unNodeID) = 0{ return ERR_SUCCESS; }
	};   
} 
#endif