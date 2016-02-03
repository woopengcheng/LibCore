#ifndef __cutil_min_heap_h__
#define __cutil_min_heap_h__
#include "CUtil/inc/Heap.h"  

namespace CUtil
{ 
	template <typename ValueType>
	class MinHeap :	public Heap<ValueType>
	{
	public:
		MinHeap(void){}
		virtual ~MinHeap(void){} 

	public:
		virtual CErrno		Init(void);
		virtual CErrno		Cleanup(void);
		virtual Node<ValueType> *    Update(void);

	public:
		virtual CErrno		InsertNode(UINT32 unNodeID , Node<ValueType> * pNode);
		virtual CErrno		RemoveNode(UINT32 unNodeID);  

	protected:
		virtual CErrno		HeapRebuildDown(Node<ValueType> * pRebuildNode);
		virtual CErrno		HeapRebuildUp(UINT32 unCurPos , Node<ValueType>  * pRebuildNode);
	}; 

	template <typename ValueType>
	Node<ValueType> *   MinHeap<ValueType>::Update(void)
	{
		return GetNode(0);
	}

	template <typename ValueType>
	CErrno MinHeap<ValueType>::Init( void )
	{ 
		return Heap::Init();
	}

	template <typename ValueType>
	CErrno MinHeap<ValueType>::Cleanup( void )
	{ 
		return Heap::Cleanup();
	} 

	template <typename ValueType>
	CErrno MinHeap<ValueType>::HeapRebuildUp(UINT32 unCurPos , Node<ValueType> * pRebuildNode )
	{
		UINT32 unParentPos = GetHeapParentPos(unCurPos);
		Node<ValueType> * pParentNode = GetNode(unParentPos);

		if (!pRebuildNode || !pParentNode || pParentNode == pRebuildNode)
		{
			return CErrno::Failure();
		}

		while (unCurPos > 0)
		{
			if (pParentNode && pRebuildNode->GetValue() < pParentNode->GetValue())
			{  
				SwitchNode(pParentNode , unCurPos);        //5 �����Ƶ�ʱ��,���������ָ��.��󽻻��Լ���.
				unCurPos = unParentPos;
				unParentPos = GetHeapParentPos(unCurPos);
				pParentNode = GetNode(unParentPos);
			}
			else
				break;
		}

		SwitchNode(pRebuildNode , unCurPos);

		return CErrno::Success();
	}

	template <typename ValueType>
	CErrno MinHeap<ValueType>::HeapRebuildDown(Node<ValueType> * pRebuildNode )
	{
		if (!pRebuildNode)
		{
			return CErrno::Failure();
		}
		UINT32 unCurPos   = pRebuildNode->GetNodePos();
		UINT32 unLeftPos  = GetHeapLeftPos(unCurPos);
		UINT32 unHeapSize = GetHeapSize();
		Node<ValueType> * pNextNode = NULL;

		while (unLeftPos < unHeapSize)
		{
			ValueType objLeftValue , objRightValue;
			if (unLeftPos + 1 < unHeapSize )
			{
				Node<ValueType> * pLeftNode = GetNode(unLeftPos);
				Node<ValueType> * pRightNode = GetNode(unLeftPos + 1);
				if(!pLeftNode || !pRightNode)
				{
					return CErrno::Failure();
				} 
				objLeftValue = pLeftNode->GetValue();
				objRightValue =  pRightNode->GetValue();

				if (objRightValue < objLeftValue)            //5  ѡ�������ӽڵ���С��һ��
				{
					++ unLeftPos;
				} 
			}
			{
				Node<ValueType> * pCurNode = GetNode(unCurPos);
				Node<ValueType> * pNextNode = GetNode(unLeftPos);
				if(!pNextNode || !pCurNode)
				{
					return CErrno::Failure();
				}  
				objLeftValue = pCurNode->GetValue();
				objRightValue =  pNextNode->GetValue();
			}

			if (objLeftValue >= objRightValue)
			{ 
				SwitchNode(pNextNode , unCurPos);
				unCurPos = unLeftPos;
				unLeftPos = GetHeapLeftPos(unCurPos);
			}
			else
				break;
		}

		SwitchNode(pRebuildNode , unCurPos);
		return CErrno::Success();
	} 

	template <typename ValueType>
	CErrno MinHeap<ValueType>::RemoveNode( UINT32 unNodeID )
	{
		MapNodesT::accessor result; 
		if (m_mapNodes.find(result , unNodeID))
		{
			UINT32   unCurPos = 0 , unHeapSize = 0;
			Node<ValueType> * pCurNode = result->second;
			if (!pCurNode)
			{
				return CErrno::Failure();
			}

			unCurPos = pCurNode->GetNodePos();
			unHeapSize = GetHeapSize();
			if (unCurPos < unHeapSize)
			{ 
				Node<ValueType> * pLastNode = GetNode(unHeapSize - 1);
				Node<ValueType> * pParentNode = GetNode(GetHeapParentPos(unCurPos));
				if(!pLastNode || ! pParentNode)
				{
					return CErrno::Failure(); 
				} 
				 
				m_mapNodes.erase(result);

				UINT32 unLastPos = pLastNode->GetNodePos();
				SwitchNode(pLastNode , unCurPos);             //5 �����һ��node��������Ҫɾ���Ľڵ���. 
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
					HeapRebuildUp(unCurPos , pLastNode);
			}
		}

		return CErrno::Success();
	}

	template <typename ValueType>
	CErrno MinHeap<ValueType>::InsertNode( UINT32 unNodeID , Node<ValueType> * pNode )
	{
		if (pNode)
		{
			MapNodesT::accessor result; 
			if (!m_mapNodes.find(result , unNodeID))
			{
				UINT32  unCurPos = GetHeapSize();           //5 ����ǰ��node����Ϊ�ѵ����һ��.
				pNode->SetNodePos(unCurPos); 

				m_mapNodes.insert(std::make_pair(unNodeID , pNode));
				SetNode(unCurPos , pNode);

				HeapRebuildUp(unCurPos , pNode);                       //5 ��ʼ�����ؽ�.
			}
			else
			{
				return CErrno::Failure();
			} 
		}

		return CErrno::Success();
	} 
}  
#endif
