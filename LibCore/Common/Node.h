#ifndef __libcore_node_h__
#define __libcore_node_h__
#include "Common/Common.h"
#include "Common/ClassTypeInterface.h" 
#include "ThreadPoolLib/inc/ThreadLock.h"

namespace LibCore
{ 
	template<typename ValueType>
	class  Node : public LibCore::ClassTypeInterface
	{
		CLASS_TYPE_ID(Node<ValueType> , LibCore::ClassTypeInterface , CTID_Node)
	public:
		Node()
			: m_unNodePos(-1)
			, m_objValue(0)
		{

		}
		explicit Node(ValueType objValue)
			: m_unNodePos(-1)
			, m_objValue(objValue)
		{

		}
		virtual ~Node(void)
		{

		}

	public:
		void SetNodePos(UINT32 unNodePos)
		{
			ThreadPool::AutoSpinRWLock objLock(m_objLock); 
			m_unNodePos = unNodePos;   
		}

		INT32 GetNodePos( void )
		{
			ThreadPool::AutoSpinRWLock objLock(m_objLock , false); 
			return m_unNodePos; 
		}

		ValueType   GetValue( void )
		{
			ThreadPool::AutoSpinRWLock objLock(m_objLock , false); 
			return m_objValue;
		} 

	protected:
		INT32                m_unNodePos;
		ValueType            m_objValue;
		ThreadPool::ThreadSpinRWMutex   m_objLock; 
	}; 
} 
 
 
#endif