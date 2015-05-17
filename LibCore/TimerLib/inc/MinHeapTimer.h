#ifndef __timer_min_heap_timer_h
#define __timer_min_heap_timer_h
#include "Common/MinHeap.h"
#include "TimerLib/inc/TimerNode.h"
#include "TimerLib/inc/IStrategy.h"

namespace Timer
{ 
	class MinHeapTimer : public LibCore::MinHeap<TimerType> , public IStrategy
	{
	public:
		MinHeapTimer( void ){}
		virtual ~MinHeapTimer( void ){} 

	public:
		virtual INT32		Init( void ){ return ERR_SUCCESS; }
		virtual INT32		Cleanup( void ){ return ERR_SUCCESS; } 
		virtual TimerNode * Update(void)
		{ 
			TimerNode * pTimerNode = NULL;
			LibCore::Node<TimerType> * pNode = LibCore::MinHeap<TimerType>::Update();
			if (pNode)
			{
				pTimerNode = pNode->GetClass<TimerNode>();
			}

			return pTimerNode;
		}
 		virtual INT32		SetTimer(UINT32 unTimeInterval , UINT32 unStartTime , UINT32 unTimes , void * pObj = NULL , TimerCallBackFunc pFunc = NULL){ return ERR_SUCCESS; }

	public:
		virtual INT32		InsertNode(UINT32 unNodeID ,TimerNode * pNode)
		{
			return LibCore::MinHeap<TimerType>::InsertNode(unNodeID , pNode);
		}
		virtual INT32		RemoveNode(UINT32 unNodeID)
		{
			return LibCore::MinHeap<TimerType>::RemoveNode(unNodeID); 
		}
		virtual TimerNode * GetNode(UINT32 unNodeID)
		{ 
			TimerNode * pTimerNode = NULL;
			LibCore::Node<TimerType> * pNode = LibCore::MinHeap<TimerType>::GetNode(unNodeID);
			if (pNode)
			{
				pTimerNode = pNode->GetClass<TimerNode>();
			}
			return pTimerNode;
		}

	};
 } 
#endif