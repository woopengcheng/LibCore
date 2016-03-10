#ifndef __timer_min_heap_timer_h
#define __timer_min_heap_timer_h
#include "CUtil/inc/MinHeap.h"
#include "Timer/inc/TimerNode.h"
#include "Timer/inc/IStrategy.h"

namespace Timer
{ 
	class DLL_EXPORT MinHeapTimer : public CUtil::MinHeap<TimerType> , public IStrategy
	{
	public:
		MinHeapTimer( void ){}
		virtual ~MinHeapTimer( void ){} 

	public:
		virtual CErrno		Init( void )override { return CErrno::Success(); }
		virtual CErrno		Cleanup( void ) override { return CErrno::Success(); }
		virtual TimerNode * Update(void) override
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
 		virtual CErrno		SetTimer(UINT32 unTimeInterval , UINT32 unStartTime , UINT32 unTimes , void * pObj = NULL , TimerCallBackFunc pFunc = NULL){ return CErrno::Success(); }

	public:
		virtual CErrno		InsertNode(UINT32 unNodeID ,TimerNode * pNode) override
		{
			return CUtil::MinHeap<TimerType>::InsertNode(unNodeID , pNode);
		}
		virtual CErrno		RemoveNode(UINT32 unNodeID) override
		{
			return CUtil::MinHeap<TimerType>::RemoveNode(unNodeID); 
		}
		virtual TimerNode * GetNode(UINT32 unNodeID) override
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