#ifndef __timer_timing_wheel_h__
#define __timer_timing_wheel_h__
#include "TimerLib/inc/TimerCommon.h"
#include "TimerLib/inc/TimerNode.h"  
#include "TimerLib/inc/IStrategy.h"

#define TIMER_ROOT_SIZE_MASK 8
#define TIMER_OTHER_SIZE_MASK 6
#define TIMER_ROOT_SIZE  256
#define TIMER_OTHER_SIZE 64
#define TIMER_OTHER_WHEEL_SIZE  4 

namespace Timer
{ 
// 	class TimingWheelTimerNode : public TimerNode
// 	{
// 	public:
// 		CLASS_TYPE_ID(TimingWheelTimerNode , TimerNode , CTID_TimingWheelTimerNode)
// 	public:
// 		TimingWheelTimerNode()
// 			: m_pNext(NULL)
// 		{
// 		
// 		}
// 
// 	public:
// 		virtual  void OnTimeout(){}
// 
// 	public:
// 		TimingWheelTimerNode * m_pNext;  //5 ��������.��ʱ������������.
// 	};

	class TimerList
	{
	public:
		TimerList()
			: m_pHead(NULL)
			, m_nInternal(0) 
		{
		
		}
	public:
		TimerNode * GetTimerHead(){ return m_pHead; }

		void  AddTimerNode(TimerNode * pNode)
		{ 
			pNode->m_pNext = m_pHead;
			m_pHead = pNode;
		} 

	protected: 
		INT32	    m_nInternal; 
		TimerNode * m_pHead;
	};
	   
	class TimingWheel : public IStrategy
	{
	public:
		TimingWheel()
			: m_nCurTime(0)
		{
		
		} 
	public:
		virtual INT32  Init(void){ return ERR_SUCCESS; }
		virtual INT32  Cleanup(void){ return ERR_SUCCESS; }

	public: 
		virtual INT32  RemoveNode(UINT32 unNodeID) { return ERR_SUCCESS; }
		virtual TimerNode * GetNode(UINT32 unNodeID) { return NULL; }

	public:
		virtual INT32  InsertNode(UINT32 unNodeID , TimerNode * pNode)
		{
			INT32 nFutureTime = m_nCurTime + pNode->GetTimeInterval();
					
			nFutureTime = nFutureTime << TIMER_ROOT_SIZE_MASK;
			if ( nFutureTime < (1 << TIMER_ROOT_SIZE_MASK))
			{
				m_objRoot.AddTimerNode(pNode);
				return ERR_SUCCESS;
			}

			INT32 nSize = 0;
			while(1)
			{
				nFutureTime = nFutureTime << TIMER_OTHER_SIZE_MASK;
				if (nFutureTime < (1 << TIMER_OTHER_SIZE_MASK))
				{
					break;
				} 
				++nSize;
			}

			m_aTimer[nSize][nFutureTime].AddTimerNode(pNode); 
			return ERR_SUCCESS;
		}

		virtual TimerNode * Update(void)
		{
			TimerList * pCurList = NULL;
			m_nCurTime += 1;
			INT32 nTemp = m_nCurTime;
			if (nTemp << TIMER_ROOT_SIZE_MASK < (1 << TIMER_ROOT_SIZE_MASK))
			{
				pCurList = &m_objRoot;
			}
			else
			{
				INT32 nSize = 0;
				while(1)
				{
					nTemp = nTemp << TIMER_OTHER_SIZE_MASK;
					if (nTemp < (1 << TIMER_OTHER_SIZE_MASK))
					{
						break;
					} 
					++nSize;
				}
				pCurList = &m_aTimer[nSize][nTemp];
			}

			if (pCurList)
			{
				return pCurList->GetTimerHead();
			}
			else
				return NULL;
		}


	private:
		TimerList   m_objRoot;
		TimerList   m_aTimer[TIMER_OTHER_WHEEL_SIZE][TIMER_OTHER_SIZE];
		INT32       m_nCurTime;
	};
}


#endif