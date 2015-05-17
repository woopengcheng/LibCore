#ifndef __timer_timer_node_h__
#define __timer_timer_node_h__
#include "Common/Node.h" 
#include "TimerLib/inc/TimeCount.h"

namespace Timer
{   
	class DLL_EXPORT  TimerNode : public LibCore::Node<TimerType>
	{ 
	public:
		CLASS_TYPE_ID(TimerNode , LibCore::Node<TimerType> , CTID_TimerNode)
	public:
		TimerNode()
			: m_unTimerID(0)
			, m_pObj(NULL)
			, m_unTimeInterval(0)
			, m_unStartTime(0)
			, m_unTimes(0)
			, m_pCallBackFunc(NULL)
			, LibCore::Node<TimerType>(0)
			, m_pNext(NULL)
		{}
		TimerNode(UINT32 unTimerID , UINT32 unTimeInterval , UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL)
			: m_unTimerID(unTimerID)
			, m_pObj(pObj)
			, m_unTimeInterval(unTimeInterval)
			, m_unStartTime(unStartTime)
			, m_unTimes(unTimes)
			, m_pCallBackFunc(pFunc)
			, LibCore::Node<TimerType>(unStartTime + unTimeInterval)
			, m_pNext(NULL)
		{
			m_objTimerCount.Start(GetValue());
		}
		virtual   ~TimerNode(){}
		 
	public:
		void               SetStartTime(UINT32 unStartTime);
		UINT32             GetStartTime();
		void               SetTimeInterval(UINT32 unTimeInterval);
		UINT32             GetTimeInterval();
		void               SetTimes(UINT32 unTimes);
		UINT32             GetTimes();
		void               SetTimeCount(TimeCount_Safe objTimerCount);
		TimeCount_Safe     GetTimeCount();
        void   *           GetObject();
		void               SetObject(void * pObj);
		void               SetTimerID(UINT32 unTimerID);
		UINT32             GetTimerID();
		TimerNode     *    GetNext(){ return m_pNext; } 

	public:
		TimerNode		*  m_pNext;  

	protected:
		UINT32             m_unTimerID;
		void *             m_pObj; 
		UINT32             m_unTimes;
		UINT32             m_unStartTime;
		UINT32             m_unTimeInterval;
		TimeCount_Safe     m_objTimerCount;
		TimerCallBackFunc  m_pCallBackFunc;
	}; 

}

#endif