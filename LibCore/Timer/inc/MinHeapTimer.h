#ifndef __timer_min_heap_timer_h
#define __timer_min_heap_timer_h
#include "CUtil/inc/MinHeap.h"
#include "Timer/inc/TimerNode.h"
#include "Timer/inc/IStrategy.h"

namespace Timer
{ 
	class MinHeapTimer : public CUtil::MinHeap<TimerType> , public IStrategy
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
			CUtil::Node<TimerType> * pNode = CUtil::MinHeap<TimerType>::Update();
			if (pNode)
			{
				pTimerNode = pNode->GetClass<TimerNode>();
				RemoveNode(pTimerNode->GetTimerID());
			} 

			return pTimerNode;
		}
 		virtual INT32		SetTimer(UINT32 unTimeInterval , UINT32 unStartTime , UINT32 unTimes , void * pObj = NULL , TimerCallBackFunc pFunc = NULL){ return ERR_SUCCESS; }

	public:
		virtual INT32		InsertNode(UINT32 unNodeID ,TimerNode * pNode)
		{
			return CUtil::MinHeap<TimerType>::InsertNode(unNodeID , pNode);
		}
		virtual INT32		RemoveNode(UINT32 unNodeID)
		{
			return CUtil::MinHeap<TimerType>::RemoveNode(unNodeID); 
		}
		virtual TimerNode * GetNode(UINT32 unNodeID)
		{ 
			TimerNode * pTimerNode = NULL;
			CUtil::Node<TimerType> * pNode = CUtil::MinHeap<TimerType>::GetNode(unNodeID);
			if (pNode)
			{
				pTimerNode = pNode->GetClass<TimerNode>();
			}
			return pTimerNode;
		}

	};
 } 
#endif