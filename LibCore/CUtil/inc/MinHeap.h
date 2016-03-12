#ifndef __cutil_min_heap_h__
#define __cutil_min_heap_h__
#include "CUtil/inc/Heap.h"  

namespace CUtil
{ 
	template <typename NodeType>
	class MinHeap :	public Heap<NodeType>
	{
	public:
		MinHeap(void){}
		virtual ~MinHeap(void){} 

	public:
		virtual CErrno		Init(void) override
		{
			return Heap::Init();
		}

		virtual CErrno		Cleanup(void) override
		{
			return Heap::Cleanup();
		}

		virtual NodeType *	Update(void) override
		{
			return GetNode(0);
		}

	public:
		virtual CErrno		InsertNode(UINT32 unNodeID, NodeType * pNode) override
		{
			if (pNode)
			{
				MapNodesT::accessor result;
				if (!m_mapNodes.find(result, unNodeID))
				{
					UINT32  unCurPos = GetHeapSize();			//5 ����ǰ��node����Ϊ�ѵ����һ��.
					pNode->SetNodePos(unCurPos);

					m_mapNodes.insert(std::make_pair(unNodeID, pNode));
					SetNode(unCurPos, pNode);

					HeapRebuildUp(unCurPos, pNode);				//5 ���һ����ʼ�����ؽ�.
				}
				else
				{
					return CErrno::Failure();
				}
			}

			return CErrno::Success();
		}
		virtual CErrno		RemoveNode(UINT32 unNodeID) override
		{
			MapNodesT::accessor result;
			if (m_mapNodes.find(result, unNodeID))
			{
				UINT32   unCurPos = 0, unHeapSize = 0;
				NodeType * pCurNode = result->second;
				if (!pCurNode)
				{
					return CErrno::Failure();
				}

				unCurPos = pCurNode->GetNodePos();
				unHeapSize = GetHeapSize();
				if (unCurPos < unHeapSize)
				{
					NodeType * pLastNode = GetNode(unHeapSize - 1);
					NodeType * pParentNode = GetNode(GetHeapParentPos(unCurPos));
					if (!pLastNode || !pParentNode)
					{
						return CErrno::Failure();
					}

					m_mapNodes.erase(result);

					UINT32 unLastPos = pLastNode->GetNodePos();
					SwitchNode(pLastNode, unCurPos);             //5 �����һ��node��������Ҫɾ���Ľڵ���. 
					{
						ThreadPool::AutoSpinRWLock objLock(m_objLock);
						if (m_pNodes)
						{
							m_pNodes[unLastPos] = NULL;
						}
					}

					if (pLastNode->GetValue() >= pParentNode->GetValue())  //5 ��ĩβ����ȥ�ıȵ�ǰ�ĸ��ڵ㻹Ҫ��.��ô���½���.�������Ͻ���.
					{
						HeapRebuildDown(pLastNode);
					}
					else
					{
						HeapRebuildUp(unCurPos, pLastNode);
					}
				}
			}

			return CErrno::Success();
		}


	protected:
		virtual CErrno		HeapRebuildDown(NodeType * pRebuildNode)
		{
			if (!pRebuildNode)
			{
				return CErrno::Failure();
			}
			UINT32 unCurPos = pRebuildNode->GetNodePos();
			UINT32 unLeftPos = GetHeapLeftPos(unCurPos);
			UINT32 unHeapSize = GetHeapSize();
			NodeType * pNextNode = NULL;

			while (unLeftPos < unHeapSize)
			{
				INT64 objLeftValue, objRightValue;
				if (unLeftPos + 1 < unHeapSize)
				{
					NodeType * pLeftNode = GetNode(unLeftPos);
					NodeType * pRightNode = GetNode(unLeftPos + 1);
					if (!pLeftNode || !pRightNode)
					{
						return CErrno::Failure();
					}
					objLeftValue = pLeftNode->GetValue();
					objRightValue = pRightNode->GetValue();

					if (objRightValue < objLeftValue)            //5  ѡ�������ӽڵ���С��һ��
					{
						++unLeftPos;
					}
				}
				{
					NodeType * pCurNode = GetNode(unCurPos);
					NodeType * pNextNode = GetNode(unLeftPos);
					if (!pNextNode || !pCurNode)
					{
						return CErrno::Failure();
					}
					objLeftValue = pCurNode->GetValue();
					objRightValue = pNextNode->GetValue();
				}

				if (objLeftValue >= objRightValue)
				{
					SwitchNode(pNextNode, unCurPos);
					unCurPos = unLeftPos;
					unLeftPos = GetHeapLeftPos(unCurPos);
				}
				else
					break;
			}

			SwitchNode(pRebuildNode, unCurPos);
			return CErrno::Success();
		}
		virtual CErrno		HeapRebuildUp(UINT32 unCurPos, NodeType  * pRebuildNode)
		{
			UINT32 unParentPos = GetHeapParentPos(unCurPos);
			NodeType * pParentNode = GetNode(unParentPos);

			if (!pRebuildNode || !pParentNode || pParentNode == pRebuildNode)
			{
				return CErrno::Failure();
			}

			while (unCurPos > 0)
			{
				if (pParentNode && pRebuildNode->GetValue() < pParentNode->GetValue())
				{
					SwitchNode(pParentNode, unCurPos);        //5 �����Ƶ�ʱ��,���������ָ��.��󽻻��Լ���.
					unCurPos = unParentPos;
					unParentPos = GetHeapParentPos(unCurPos);
					pParentNode = GetNode(unParentPos);
				}
				else
				{
					break;
				}
			}

			SwitchNode(pRebuildNode, unCurPos);

			return CErrno::Success();
		}

	};  
}  
#endif
