#ifndef __timer_timer_node_h__
#define __timer_timer_node_h__
#include "Timer/inc/TimeCount.h" 

namespace Timer
{
#define SECOND_MILL_TIME 1000

	class DLL_EXPORT  TimerNode
	{
	public:
		TimerNode()
			: m_bDelete(FALSE)
			, m_unTimerID(0)
			, m_pObj(NULL)
			, m_unTimeInterval(0)
			, m_unStartTime(0)
			, m_unTimes(0)
			, m_pCallBackFunc(NULL)
			, m_pNext(NULL)
			, m_pPrev(NULL)
			, m_unStartAddTime(0)
			, m_unNodePos(-1)
			, m_objValue(0)
		{}
		TimerNode(UINT32 unTimerID, UINT32 unTimeInterval, UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL, TimerCallBackFunc pFunc = NULL)
			: m_bDelete(FALSE)
			, m_unTimerID(unTimerID)
			, m_pObj(pObj)
			, m_unTimeInterval(unTimeInterval)
			, m_unStartTime(unStartTime)
			, m_unTimes(unTimes)
			, m_pCallBackFunc(pFunc)
			, m_unNodePos(-1)
			, m_objValue((unStartTime + unTimeInterval))
			, m_pNext(NULL)
			, m_pPrev(NULL)
			, m_unStartAddTime(0)
		{
		}
		virtual   ~TimerNode() {}

	public:
		void				SetStartTime(UINT32 unStartTime);
		UINT32				GetStartTime();
		void				SetTimeInterval(UINT32 unTimeInterval);
		UINT32				GetTimeInterval();
		void				SetTimes(UINT32 unTimes);
		UINT32				GetTimes();
		void				SetTimeCount(TimeCount_Safe objTimerCount);
		TimeCount_Safe		GetTimeCount();
		void			*	GetObject();
		void				SetObject(void * pObj);
		void				SetTimerID(UINT32 unTimerID);
		UINT32				GetTimerID();
		void				SetDelete(BOOL bDelete);
		int					IsDelete();
		TimerNode		*	GetNext() { return m_pNext; }
		TimerNode		*	GetPrev() { return m_pPrev; }
		TimerCallBackFunc	GetCallBackFunc() { return m_pCallBackFunc; }
		UINT32				GetStartAddTime() const { return m_unStartAddTime; }
		void				SetStartAddTime(UINT32 val) { m_unStartAddTime = val; }
		void				SetNodePos(UINT32 unNodePos);
		INT32				GetNodePos(void);
		INT64				GetValue(void);
		void				SetValue(INT64 objValue);
		ThreadPool::ThreadSpinRWMutex & GetLock();

	public:
		TimerNode		*	m_pNext;
		TimerNode		*	m_pPrev;

	protected:
		BOOL				m_bDelete;
		UINT32				m_unTimerID;
		void			*	m_pObj;
		UINT32				m_unTimes;
		UINT32				m_unStartTime;
		UINT32				m_unTimeInterval;
		TimeCount_Safe		m_objTimerCount;
		UINT32				m_unStartAddTime;  //5 记录开始加入时间轮的时间.
		INT32				m_unNodePos;
		INT64	            m_objValue;

		TimerCallBackFunc	m_pCallBackFunc;
		ThreadPool::ThreadSpinRWMutex   m_objLock;
	};

}

#endif