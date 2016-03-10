#ifndef __timer_timing_wheel_h__
#define __timer_timing_wheel_h__
#include "Timer/inc/TimerCommon.h"
#include "Timer/inc/TimerNode.h"  
#include "Timer/inc/IStrategy.h"
#include "Timer/inc/TimerHelp.h" 
#include "LogLib/inc/Log.h"

#define TIMER_ROOT_SIZE_MASK_NUM 8
#define TIMER_OTHER_SIZE_MASK_NUM 6
#define TIMER_ROOT_SIZE  256
#define TIMER_OTHER_SIZE 64
#define TIMER_OTHER_WHEEL_SIZE  4 
#define TIMER_OTHER_SIZE_MASK 0X3F
#define TIMER_ROOT_SIZE_MASK 0XFF


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
			: m_nCurTime(0)
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
		virtual CErrno  RemoveNode(UINT32 unNodeID)
		{
			MapNodesT::iterator iter = m_mapNodes.find(unNodeID);
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
		virtual TimerNode * GetNode(UINT32 unNodeID)
		{
			MapNodesT::iterator iter = m_mapNodes.find(unNodeID);
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
			INT32 nTemp = m_nCurTime;
			INT32 nLastTemp = m_nCurTime - 1;
			if ((m_nCurTime & TIMER_ROOT_SIZE_MASK) != 0)
			{
				return CErrno::Failure();
			}
			else
			{

				nTemp >>= TIMER_ROOT_SIZE_MASK_NUM;
				nLastTemp >>= TIMER_ROOT_SIZE_MASK_NUM;
				INT32 nSize = 0;
				while (1)
				{
					if ((nLastTemp >> TIMER_OTHER_SIZE_MASK_NUM) == (nTemp >> TIMER_OTHER_SIZE_MASK_NUM))
					{
						break;
					}
					nLastTemp >>= TIMER_OTHER_SIZE_MASK_NUM;
					nTemp >>= TIMER_OTHER_SIZE_MASK_NUM;
					++nSize;
				}

				pCurList = &m_aTimer[nSize][nTemp & TIMER_OTHER_SIZE_MASK];

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
						pHead->SetValue(pHead->GetStartTime() + pHead->GetTimeInterval() + pHead->GetStartAddTime() - m_nCurTime);
						InsertNode(pHead->GetTimerID(), pHead, false);
						pHead = pNext;
						++nCount;
					}
				}
				//				glb_LogOutput(true , "dispatcher:nSize=%d:nPos=%d:nCurPos=%d:nCount=%d:" , nSize , nTemp & TIMER_OTHER_SIZE_MASK , m_nCurTime , nCount);
				m_aTimer[nSize][nTemp & TIMER_OTHER_SIZE_MASK].SetTimerHead(NULL);
			}
			return CErrno::Success();
		}

		virtual CErrno  InsertNode(UINT32 unNodeID, TimerNode * pNode, bool bRemoveSame = true)
		{
			UINT32 nFutureTime = m_nCurTime + pNode->GetValue() + 1;   //5 +1是因为执行时肯定会是下一帧执行
			UINT32 nOldTime = nFutureTime;
			pNode->SetStartAddTime(m_nCurTime);
			UINT32 nTemp = m_nCurTime;

			MapNodesT::iterator iter = m_mapNodes.find(unNodeID);
			if (bRemoveSame && iter != m_mapNodes.end())
			{
				TimerNode * pOldNode = iter->second;
				pOldNode->SetDelete(TRUE);
				RemoveNode(unNodeID);
			}

			if ((nFutureTime >> TIMER_ROOT_SIZE_MASK_NUM) == ((m_nCurTime) >> TIMER_ROOT_SIZE_MASK_NUM))
			{
				pNode->SetNodePos(nOldTime);
				m_mapNodes[unNodeID] = pNode;
				m_objRoot[nFutureTime & TIMER_ROOT_SIZE_MASK].AddTimerNode(pNode);
				//				glb_LogOutput(true , "insert_root:nPos=%d:unNodeID=%d:nCurPos=%d:internal=%d:bDelete=%d" , nFutureTime & TIMER_ROOT_SIZE_MASK , unNodeID , m_nCurTime , nOldTime - m_nCurTime , pNode->IsDelete());
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

			pNode->SetNodePos(nOldTime);
			m_aTimer[nSize][nFutureTime & TIMER_OTHER_SIZE_MASK].AddTimerNode(pNode);
			m_mapNodes[unNodeID] = pNode;
			//			glb_LogOutput(true , "insert_other:nSize=%d:nPos=%d:unNodeID=%d:nCurPos=%d:internal=%d:bDelete=%d" , nSize , nFutureTime & TIMER_OTHER_SIZE_MASK , unNodeID , m_nCurTime , nOldTime - m_nCurTime , pNode->IsDelete());

			return CErrno::Success();
		}

		virtual TimerNode * Update(void)
		{
			TimerList * pCurList = NULL;

			++m_nCurTime;
			INT32 nTemp = m_nCurTime & TIMER_ROOT_SIZE_MASK;
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
				// 					glb_LogOutput(true , "update:total=%d:unNodeID=%d:nCurPos=%d:internal=%d:bDelete=%d" , pNode->GetStartTime() + pNode->GetStartAddTime() + pNode->GetTimeInterval() , pNode->GetTimerID() , m_nCurTime , pNode->GetTimeInterval() + pNode->GetStartTime() , pNode->IsDelete());
				// 				}
				return pNode;
			}
			else
				return NULL;
		}

	private:
		TimerList   m_objRoot[TIMER_ROOT_SIZE];
		TimerList   m_aTimer[TIMER_OTHER_WHEEL_SIZE][TIMER_OTHER_SIZE];
		UINT32      m_nCurTime;
		MapNodesT   m_mapNodes;
	};
}


#endif