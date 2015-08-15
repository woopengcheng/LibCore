#ifndef __cutil_heap_h__
#define __cutil_heap_h__
#include "CUtil/inc/Common.h"
#include "CUtil/inc/Node.h"   

namespace CUtil
{
#define MAX_NODE_SIZE 10000                   //5 定义100000个计时器.

	template <typename ValueType>
	class Heap
	{
	public:
		typedef tbb::concurrent_hash_map<INT32 , Node<ValueType> *> MapNodesT;      //5 保证线程安全.

	public:
		Heap(void)/*: m_pNodes(NULL)*/{}
		virtual ~Heap(void){ m_mapNodes.clear(); }

	public:
		virtual  INT32    Init(void);
		virtual  INT32    Cleanup(void); 
		virtual  Node<ValueType> *  Update(void);

	public:
		virtual  INT32    InsertNode(UINT32 unNodeID , Node<ValueType> * pNode){ return ERR_SUCCESS; }
		virtual  INT32    RemoveNode(UINT32 unNodeID) { return ERR_SUCCESS; }
		virtual  Node<ValueType> * GetNode(UINT32 unNodeID);

	protected:
		virtual  INT32    HeapRebuildDown(Node<ValueType> * pRebuildNode){ return ERR_SUCCESS; }
		virtual  INT32    HeapRebuildUp(Node<ValueType>  * pRebuildNode) { return ERR_SUCCESS; }

	public:
		INT32             GetHeapParentPos(UINT32 unPos);
		INT32             GetHeapLeftPos(UINT32 unPos);
		INT32             GetHeapRightPos(UINT32 unPos);
		UINT32            GetHeapSize(void);
		INT32             SwitchNode(Node<ValueType>  * pMoveNode , UINT32 unMoveNodePos);
		void              SetNode(UINT32 unNodePos , Node<ValueType> * pNode);

	protected:
		MapNodesT                       m_mapNodes;              //5 主要是用来查找Node所处的位置,然后进行删除.
		Node<ValueType>  *              m_pNodes[MAX_NODE_SIZE]; //5 采用数组的方式来实现堆. 
		ThreadPool::ThreadSpinRWMutex   m_objLock;               //5 用来锁堆这个类的.
	};  

	template <typename ValueType>
	Node<ValueType> *  Heap<ValueType>::Update(void)
	{
		return NULL;
	}

	template <typename ValueType>
	INT32 Heap<ValueType>::Cleanup( void )
	{
		MapNodesT::iterator iter = m_mapNodes.begin();
		for (;iter != m_mapNodes.end();++iter)
		{
			SAFE_DELETE(iter->second);
		}
		m_mapNodes.clear();

//		SAFE_DELETE_ARRAY(m_pNodes);

		return TRUE;
	}

	template <typename ValueType>
	INT32 Heap<ValueType>::Init( void )
	{ 
//		m_pNodes = new Node<ValueType>*[MAX_NODE_SIZE];
		return TRUE;
	}

	template <typename ValueType>
	Node<ValueType> * Heap<ValueType>::GetNode( UINT32 unNodeID )
	{
		if (unNodeID < GetHeapSize())
		{
			ThreadPool::AutoSpinRWLock objLock(m_objLock , false);
			if (m_pNodes)
			{
				return m_pNodes[unNodeID];
			}
		}

		return NULL;
	}

	template <typename ValueType>
	void Heap<ValueType>::SetNode( UINT32 unNodePos , Node<ValueType> * pNode )
	{
		if (pNode && unNodePos < GetHeapSize())
		{
			ThreadPool::AutoSpinRWLock objLock(m_objLock);
			if (m_pNodes)
			{
				m_pNodes[unNodePos] = pNode;
				pNode->SetNodePos(unNodePos);
			}
		} 
	}

	template <typename ValueType>
	INT32 Heap<ValueType>::SwitchNode( Node<ValueType> * pMoveNode , UINT32 unMoveNodePos )
	{
		if (pMoveNode)
		{
			SetNode(unMoveNodePos , pMoveNode);
			return TRUE;
		}

		return FALSE; 
	}

	template <typename ValueType>
	UINT32 Heap<ValueType>::GetHeapSize( void )
	{
		return (UINT32)(m_mapNodes.size());
	}

	template <typename ValueType>
	INT32 Heap<ValueType>::GetHeapRightPos( UINT32 unPos )
	{
		return unPos * 2 + 2;
	}

	template <typename ValueType>
	INT32 Heap<ValueType>::GetHeapLeftPos( UINT32 unPos )
	{
		return unPos * 2 + 1;
	}

	template <typename ValueType>
	INT32 Heap<ValueType>::GetHeapParentPos( UINT32 unPos )
	{
		return unPos == 0 ? 0 : ((unPos - 1) / 2);
	}  
} 
#endif