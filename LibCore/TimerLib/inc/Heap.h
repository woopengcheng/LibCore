#ifndef __timer_heap_h__
#define __timer_heap_h__
#include "Node.h" 
#include "ThreadLock.h"
#include "IStrategy.h"

namespace Timer
{
	template <typename ValueType>
	class Heap : public IStrategy<ValueType>
	{
	public:
		typedef tbb::concurrent_hash_map<INT32 , Node<ValueType> *> MapNodesT;      //5 ��֤�̰߳�ȫ.

	public:
		Heap(void)/*: m_pNodes(NULL)*/{}
		virtual ~Heap(void){ m_mapNodes.clear(); }

	public:
		virtual  INT32    Init(void);
		virtual  INT32    Cleanup(void); 

	public:
		virtual  INT32    InsertNode(UINT32 unNodeID , Node<ValueType> * pNode) { return FALSE; }
		virtual  INT32    RemoveNode(UINT32 unNodeID) { return FALSE; } 
		virtual  Node<ValueType> * GetNode(UINT32 unNodeID);

	protected:
		virtual  INT32    HeapRebuildDown(Node<ValueType> * pRebuildNode) { return FALSE; }
		virtual  INT32    HeapRebuildUp(Node<ValueType>  * pRebuildNode) { return FALSE; }

	public:
		INT32             GetHeapParentPos(UINT32 unPos);
		INT32             GetHeapLeftPos(UINT32 unPos);
		INT32             GetHeapRightPos(UINT32 unPos);
		UINT32            GetHeapSize(void);
		INT32             SwitchNode(Node<ValueType>  * pMoveNode , UINT32 unMoveNodePos);
		void              SetNode(UINT32 unNodePos , Node<ValueType> * pNode);

	protected:
		MapNodesT                       m_mapNodes;              //5 ��Ҫ����������Node������λ��,Ȼ�����ɾ��.
		Node<ValueType>  *              m_pNodes[MAX_NODE_SIZE]; //5 ��������ķ�ʽ��ʵ�ֶ�. 
		ThreadPool::ThreadSpinRWMutex   m_objLock;               //5 ��������������.
	};  

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