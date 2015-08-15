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
		virtual INT32  Init(void);
		virtual INT32  Cleanup(void);
		virtual Node<ValueType> *    Update(void);

	public:
		virtual INT32  InsertNode(UINT32 unNodeID , Node<ValueType> * pNode);
		virtual INT32  RemoveNode(UINT32 unNodeID);  

	protected:
		virtual INT32  HeapRebuildDown(Node<ValueType> * pRebuildNode);
		virtual INT32  HeapRebuildUp(UINT32 unCurPos , Node<ValueType>  * pRebuildNode);
	}; 

	template <typename ValueType>
	Node<ValueType> *   MinHeap<ValueType>::Update(void)
	{
		return GetNode(0);
	}

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
			return ERR_FAILURE;
		}

		while (unCurPos > 0)
		{
			if (pParentNode && pRebuildNode->GetValue() < pParentNode->GetValue())
			{  
				SwitchNode(pParentNode , unCurPos);        //5 往上移的时候,交换父类的指针.最后交换自己的.
				unCurPos = unParentPos;
				unParentPos = GetHeapParentPos(unCurPos);
				pParentNode = GetNode(unParentPos);
			}
			else
				break;
		}

		SwitchNode(pRebuildNode , unCurPos);

		return ERR_SUCCESS;
	}

	template <typename ValueType>
	INT32 MinHeap<ValueType>::HeapRebuildDown(Node<ValueType> * pRebuildNode )
	{
		if (!pRebuildNode)
		{
			return ERR_FAILURE;
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

				if (objRightValue < objLeftValue)            //5  选择两个子节点中小的一个
				{
					++ unLeftPos;
				} 
			}
			{
				Node<ValueType> * pCurNode = GetNode(unCurPos);
				Node<ValueType> * pNextNode = GetNode(unLeftPos);
				if(!pNextNode || !pCurNode)
				{
					return ERR_FAILURE;
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
		return ERR_SUCCESS;
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
				return ERR_FAILURE;
			}

			unCurPos = pCurNode->GetNodePos();
			unHeapSize = GetHeapSize();
			if (unCurPos < unHeapSize)
			{ 
				Node<ValueType> * pLastNode = GetNode(unHeapSize - 1);
				Node<ValueType> * pParentNode = GetNode(GetHeapParentPos(unCurPos));
				if(!pLastNode || ! pParentNode)
				{
					return ERR_FAILURE; 
				} 
				 
				m_mapNodes.erase(result);

				UINT32 unLastPos = pLastNode->GetNodePos();
				SwitchNode(pLastNode , unCurPos);             //5 将最后一个node交换到需要删除的节点上. 
				{
					ThreadPool::AutoSpinRWLock objLock(m_objLock);
					if (m_pNodes)
					{
						m_pNodes[unLastPos] = NULL;
					} 
				}

				if (pLastNode->GetValue() >= pParentNode->GetValue())  //5 从末尾移上去的比当前的父节点还要大.那么向下建立.否则向上建立.
				{
					HeapRebuildDown(pLastNode);
				}
				else
					HeapRebuildUp(unCurPos , pLastNode);
			}
		}

		return ERR_SUCCESS;
	}

	template <typename ValueType>
	INT32 MinHeap<ValueType>::InsertNode( UINT32 unNodeID , Node<ValueType> * pNode )
	{
		if (pNode)
		{
			MapNodesT::accessor result; 
			if (!m_mapNodes.find(result , unNodeID))
			{
				UINT32  unCurPos = GetHeapSize();           //5 将当前的node设置为堆的最后一个.
				pNode->SetNodePos(unCurPos); 

				m_mapNodes.insert(std::make_pair(unNodeID , pNode));
				SetNode(unCurPos , pNode);

				HeapRebuildUp(unCurPos , pNode);                       //5 开始向上重建.
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
