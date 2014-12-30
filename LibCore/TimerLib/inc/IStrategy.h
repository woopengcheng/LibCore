#ifndef __timer_i_strategy_h__
#define __timer_i_strategy_h__ 
#include "Node.h"  


namespace Timer
{
	template <typename ValueType>
	class IStrategy
	{ 
	public:
		IStrategy(void){}
		virtual ~IStrategy(void){ }

	public:
		virtual INT32  Init(void) = 0;
		virtual INT32  Cleanup(void) = 0;

	public:
		virtual INT32  InsertNode(UINT32 unNodeID , Node<ValueType> * pNode) = 0 { return FALSE; }
		virtual INT32  RemoveNode(UINT32 unNodeID) = 0 { return FALSE; }
		virtual Node<ValueType> * GetNode(UINT32 unNodeID) = 0;
	};   
} 
#endif