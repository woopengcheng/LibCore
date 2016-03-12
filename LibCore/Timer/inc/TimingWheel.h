#ifndef __timer_timing_wheel_h__
#define __timer_timing_wheel_h__
#include "Timer/inc/TimerCommon.h"
#include "Timer/inc/TimerNode.h"  
#include "Timer/inc/IStrategy.h"
#include "Timer/inc/TimerHelp.h" 
#include "LogLib/inc/Log.h"

#define TIMER_ROOT_SIZE_MASK_NUM	((UINT32)8)
#define TIMER_OTHER_SIZE_MASK_NUM	((UINT32)6)
#define TIMER_ROOT_SIZE				((UINT32)256)
#define TIMER_OTHER_SIZE			((UINT32)64)
#define TIMER_OTHER_WHEEL_SIZE		((UINT32)4) 
#define TIMER_OTHER_SIZE_MASK		0X3F
#define TIMER_ROOT_SIZE_MASK		0XFF

namespace Timer
{
	class DLL_EXPORT TimerList
	{
	public:
		TimerList()
			: m_pHead(NULL)
		{

		}
	public:
		TimerNode * GetTimerHead() { return m_pHead; }
		void SetTimerHead(TimerNode * pNode) { m_pHead = pNode; }

		void  AddTimerNode(TimerNode * pNode)
		{
			pNode->m_pNext = m_pHead;
			m_pHead = pNode;
		}

	protected:
		TimerNode * m_pHead;
	};

	class DLL_EXPORT TimingWheel : public IStrategy
	{
	public:
		typedef std_unordered_map<UINT32, TimerNode *> MapNodesT;

	public:
		TimingWheel()
			: m_ullCurTime(TIMING_WHEEL_PRECISE_FUNC)
		{
			memset(m_objRoot, 0, sizeof(TimerList) * TIMER_ROOT_SIZE);
			memset(m_aTimer, 0, sizeof(TimerList) * TIMER_OTHER_WHEEL_SIZE * TIMER_OTHER_SIZE);
		}
	public:
		virtual CErrno  Init(void) override { return CErrno::Success(); }
		virtual CErrno  Cleanup(void)
		{
			m_mapNodes.clear();

			for (INT32 i = 0; i < TIMER_ROOT_SIZE; ++i)
			{
				TimerList & pList = m_objRoot[i];

				TimerNode * pNode = pList.GetTimerHead();
				TimerNode * pNext = NULL;
				while (pNode)
				{
					pNext = pNode->GetNext();
					SAFE_DELETE(pNode);
					pNode = pNext;
				}
			}

			for (INT32 i = 0; i < TIMER_OTHER_WHEEL_SIZE; ++i)
			{
				for (INT32 j = 0; j < TIMER_OTHER_SIZE; ++j)
				{
					TimerList & pList = m_aTimer[i][j];
					{
						TimerNode * pNode = pList.GetTimerHead();
						TimerNode * pNext = NULL;
						while (pNode)
						{
							pNext = pNode->GetNext();
							SAFE_DELETE(pNode);
							pNode = pNext;
						}
					}
				}
			}

			memset(m_objRoot, 0, sizeof(TimerList) * TIMER_ROOT_SIZE);
			memset(m_aTimer, 0, sizeof(TimerList) * TIMER_OTHER_WHEEL_SIZE * TIMER_OTHER_SIZE);

			return CErrno::Success();
		}

	public:
		virtual CErrno  RemoveNode(UINT32 unTimerID)
		{
			MapNodesT::iterator iter = m_mapNodes.find(unTimerID);
			if (iter != m_mapNodes.end())
			{
				TimerNode * pNode = iter->second;
				if (pNode)
				{
					pNode->SetDelete(TRUE);
					m_mapNodes.erase(iter);
				}
			}

			return CErrno::Success();
		}
		virtual TimerNode * GetNode(UINT32 unTimerID)
		{
			MapNodesT::iterator iter = m_mapNodes.find(unTimerID);
			if (iter != m_mapNodes.end())
			{
				return iter->second;
			}

			return NULL;
		}

	public:
		virtual CErrno  DispathNode()
		{
			TimerList * pCurList = NULL;
			UINT64 ullTemp = m_ullCurTime;
			UINT64 ullLastTemp = m_ullCurTime - 1;
			if ((m_ullCurTime & TIMER_ROOT_SIZE_MASK) != 0)
			{
				return CErrno::Failure();
			}
			else
			{

				ullTemp >>= TIMER_ROOT_SIZE_MASK_NUM;
				ullLastTemp >>= TIMER_ROOT_SIZE_MASK_NUM;
				INT32 nSize = 0;
				while (1)
				{
					if ((ullLastTemp >> TIMER_OTHER_SIZE_MASK_NUM) == (ullTemp >> TIMER_OTHER_SIZE_MASK_NUM))
					{
						break;
					}
					ullLastTemp >>= TIMER_OTHER_SIZE_MASK_NUM;
					ullTemp >>= TIMER_OTHER_SIZE_MASK_NUM;
					++nSize;
				}

				pCurList = &m_aTimer[nSize][ullTemp & TIMER_OTHER_SIZE_MASK];

				int nCount = -1;
				if (pCurList)
				{
					nCount = 0;
					memset(m_objRoot, 0, sizeof(TimerList) * TIMER_ROOT_SIZE);	//5 客户端不会跳帧.所以不用释放.
					TimerNode * pHead = pCurList->GetTimerHead();
					TimerNode * pNext = pHead;
					while (pHead)
					{
						pNext = pHead->GetNext();
						InsertNode(pHead->GetTimerID(), pHead, false);
						pHead = pNext;
						++nCount;
					}
				}
				m_aTimer[nSize][ullTemp & TIMER_OTHER_SIZE_MASK].SetTimerHead(NULL);
			}
			return CErrno::Success();
		}

		virtual CErrno  InsertNode(UINT32 unTimerID, TimerNode * pNode, bool bRemoveSame = true)
		{
			UINT64 ullEndTime = pNode->GetEndTime();
			if (ullEndTime < m_ullCurTime )
			{
				return CErrno::Failure();
			}
			UINT64 nFutureTime = (ullEndTime);   //5 +1是因为执行时肯定会是下一帧执行,不然insert了,但是没有update
			UINT64 nTemp = m_ullCurTime;

			MapNodesT::iterator iter = m_mapNodes.find(unTimerID);
			if (bRemoveSame && iter != m_mapNodes.end())
			{
				TimerNode * pOldNode = iter->second;
				pOldNode->SetDelete(TRUE);
				RemoveNode(unTimerID);
			}

			if ((nFutureTime >> TIMER_ROOT_SIZE_MASK_NUM) == ((m_ullCurTime) >> TIMER_ROOT_SIZE_MASK_NUM))
			{
				m_mapNodes[unTimerID] = pNode;
				m_objRoot[nFutureTime & TIMER_ROOT_SIZE_MASK].AddTimerNode(pNode);
//				gDebugStream("insert_root:total=" << pNode->GetEndTime() << ":unTimerID=" << pNode->GetTimerID() << "internal=" << pNode->GetTimeInterval() << ":bDelete=%d" << pNode->IsDelete() << ":curTime=" << m_ullCurTime);
				
				return CErrno::Success();
			}

			nTemp >>= TIMER_ROOT_SIZE_MASK_NUM;
			nFutureTime >>= TIMER_ROOT_SIZE_MASK_NUM;  //5 这里代表处于哪个时刻上.
			INT32 nSize = 0;
			while (1)
			{
				if ((nFutureTime >> TIMER_OTHER_SIZE_MASK_NUM) == (nTemp >> TIMER_OTHER_SIZE_MASK_NUM))
				{
					break;
				}
				nFutureTime >>= TIMER_OTHER_SIZE_MASK_NUM;
				nTemp >>= TIMER_OTHER_SIZE_MASK_NUM;
				++nSize;
			}

			m_aTimer[nSize][nFutureTime & TIMER_OTHER_SIZE_MASK].AddTimerNode(pNode);
			m_mapNodes[unTimerID] = pNode;
//			gDebugStream("insert_other:total=" << pNode->GetEndTime() << ":nTimerPos=" << nSize << ":unTimerID=" << pNode->GetTimerID() << "internal=" << pNode->GetTimeInterval() << ":bDelete=%d" << pNode->IsDelete() << ":curTime=" << m_ullCurTime);

			return CErrno::Success();
		}

		virtual TimerNode * Update(void)
		{
			TimerList * pCurList = NULL;

			++m_ullCurTime;
			INT32 nTemp = m_ullCurTime & TIMER_ROOT_SIZE_MASK;
			if (nTemp == 0)
			{
				DispathNode();
			}

			pCurList = &m_objRoot[nTemp];

			if (pCurList)
			{
				TimerNode * pNode = pCurList->GetTimerHead();
				m_objRoot[nTemp].SetTimerHead(NULL);
// 				if (pNode)
// 				{
// 					gDebugStream("update:total=" << pNode->GetEndTime() << ":unTimerID=" << pNode->GetTimerID() << "internal=" << pNode->GetTimeInterval() << ":bDelete=%d" << pNode->IsDelete() << ":curTime=" << m_ullCurTime);
// 				}
				return pNode;
			}
			else
				return NULL;
		}

	private:
		TimerList   m_objRoot[TIMER_ROOT_SIZE];
		TimerList   m_aTimer[TIMER_OTHER_WHEEL_SIZE][TIMER_OTHER_SIZE];
		UINT64      m_ullCurTime;
		MapNodesT   m_mapNodes;
	};
}


#endif