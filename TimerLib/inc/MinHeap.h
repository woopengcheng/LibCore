#ifndef __timer_min_heap_h__
#define __timer_min_heap_h__
#include "Heap.h"

namespace Timer
{ 
	template <typename ValueType>
	class MinHeap :	public Heap<ValueType>
	{
	public:
		MinHeap(void){}
		virtual ~MinHeap(void){} 

	public:
		virtual INT32  Init(void);
		virtual INT32  Cleanup(void);

	public:
		virtual INT32  InsertNode(UINT32 unNodeID , Node<ValueType> * pNode);
		virtual INT32  RemoveNode(UINT32 unNodeID);  

	protected:
		virtual INT32  HeapRebuildDown(Node<ValueType> * pRebuildNode);
		virtual INT32  HeapRebuildUp(UINT32 unCurPos , Node<ValueType>  * pRebuildNode);
	}; 

	template <typename ValueType>
	INT32 MinHeap<ValueType>::Init( void )
	{ 
		return Heap::Init();
	}

	template <typename ValueType>
	INT32 MinHeap<ValueType>::Cleanup( void )
	{ 
		return Heap::Cleanup();
	} 

	template <typename ValueType>
	INT32 MinHeap<ValueType>::HeapRebuildUp(UINT32 unCurPos , Node<ValueType> * pRebuildNode )
	{
		UINT32 unParentPos = GetHeapParentPos(unCurPos);
		Node<ValueType> * pParentNode = GetNode(unParentPos);

		if (!pRebuildNode || !pParentNode || pParentNode == pRebuildNode)
		{
			return FALSE;
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

		return TRUE;
	}

	template <typename ValueType>
	INT32 MinHeap<ValueType>::HeapRebuildDown(Node<ValueType> * pRebuildNode )
	{
		if (!pRebuildNode)
		{
			return FALSE;
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
					return FALSE;
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
					return FALSE;
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
		return TRUE;
	} 

	template <typename ValueType>
	INT32 MinHeap<ValueType>::RemoveNode( UINT32 unNodeID )
	{
		MapNodesT::accessor result; 
		if (m_mapNodes.find(result , unNodeID))
		{
			UINT32   unCurPos = 0 , unHeapSize = 0;
			Node<ValueType> * pCurNode = result->second;
			if (!pCurNode)
			{
				return FALSE;
			}

			unCurPos = pCurNode->GetNodePos();
			unHeapSize = GetHeapSize();
			if (unCurPos < unHeapSize)
			{ 
				Node<ValueType> * pLastNode = GetNode(unHeapSize - 1);
				Node<ValueType> * pParentNode = GetNode(GetHeapParentPos(unCurPos));
				if(!pLastNode || ! pParentNode)
				{
					return FALSE; 
				} 

				SAFE_DELETE(pCurNode);                        //5 ɾ����ǰ�ڵ�.
				m_mapNodes.erase(unNodeID);
				SwitchNode(pLastNode , unCurPos);             //5 �����һ��node��������Ҫɾ���Ľڵ���.

				if (pLastNode->GetValue() >= pParentNode->GetValue())  //5 ��ĩβ����ȥ�ıȵ�ǰ�ĸ��ڵ㻹Ҫ��.��ô���½���.�������Ͻ���.
				{
					HeapRebuildDown(pLastNode);
				}
				else
					HeapRebuildUp(unCurPos , pLastNode);
			}
		}

		return TRUE;
	}

	template <typename ValueType>
	INT32 MinHeap<ValueType>::InsertNode( UINT32 unNodeID , Node<ValueType> * pNode )
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
				return FALSE;
			} 
		}

		return TRUE;
	} 
}  
#endif
