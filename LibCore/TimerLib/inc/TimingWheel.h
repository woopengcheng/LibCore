#ifndef __timer_timing_wheel_h__
#define __timer_timing_wheel_h__
#include "TimerLib/inc/TimerCommon.h"
#include "TimerLib/inc/TimerNode.h"  
#include "TimerLib/inc/IStrategy.h"
#include "TimerLib/inc/TimerHelp.h" 
#include "LogLib/inc/Log.h"

#define TIMER_ROOT_SIZE_MASK 8
#define TIMER_OTHER_SIZE_MASK 6
#define TIMER_ROOT_SIZE  256
#define TIMER_OTHER_SIZE 64
#define TIMER_OTHER_WHEEL_SIZE  4 
 

namespace Timer
{  
	class TimerList
	{
	public:
		TimerList()
			: m_pHead(NULL) 
		{
		
		}
	public:
		TimerNode * GetTimerHead(){ return m_pHead; }
		void SetTimerHead(TimerNode * pNode){ m_pHead = pNode; }

		void  AddTimerNode(TimerNode * pNode)
		{ 
			pNode->m_pNext = m_pHead;
			m_pHead = pNode;
		} 

	protected:   
		TimerNode * m_pHead;
	};
	   
	class TimingWheel : public IStrategy
	{
	public:
		typedef tbb::concurrent_hash_map<UINT32 , TimerNode *> MapNodesT;      //5 保证线程安全.

	public:
		TimingWheel()
			: m_nCurTime(0)
		{
		
		} 
	public:
		virtual INT32  Init(void){ return ERR_SUCCESS; }
		virtual INT32  Cleanup(void){ return ERR_SUCCESS; }

	public: 
		virtual INT32  RemoveNode(UINT32 unNodeID) 
		{
			MapNodesT::accessor result; 
			if (m_mapNodes.find(result , unNodeID))
			{
				TimerNode * pNode = result->second;
				if (pNode)
				{
					TimerNode * pPrev = pNode->GetPrev();
					TimerNode * pNext = pNode->GetNext();
					if (pPrev)
					{
						pPrev->m_pNext = pNext;
					}
					else
					{
						UINT32 unNodePos = pNode->GetNodePos();
						INT32 nTimerList = 0 , nTimerPos = 0;
						TimerHelper::GetCurTimingwheelPos(unNodePos , nTimerList , nTimerPos);
						if (nTimerList == 0)
						{
							m_objRoot.SetTimerHead(pNext);
						}
						else if (nTimerList > 0) 
						{
							m_aTimer[nTimerList][nTimerPos].SetTimerHead(pNext);
						}
						else
							gErrorStream("wrong timelist id:" << nTimerList << ",timeID:" << pNode->GetTimerID());
					}
				}
			}
			

			return ERR_SUCCESS; 
		}
		virtual TimerNode * GetNode(UINT32 unNodeID) 
		{
			MapNodesT::accessor result; 
			if (m_mapNodes.find(result , unNodeID))
			{
				return result->second;
			}

			return NULL; 
		}

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
			
			pNode->SetNodePos((UINT32)nFutureTime);
			m_aTimer[nSize][nFutureTime].AddTimerNode(pNode); 
			m_mapNodes.insert(std::make_pair(unNodeID , pNode));
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
		MapNodesT   m_mapNodes;
	};
}


#endif