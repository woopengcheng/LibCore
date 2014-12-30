#ifndef __msg_inner_msg_h__
#define __msg_inner_msg_h__
#include "ThreadTask.h"
#include "InternalMsgTask.h"
#include "ObjectMsgCall.h"
#include "MsgQueue.h" 
#include "ThreadPoolInterface.h"
#include "TimerHelp.h"
#include "MsgDispatcher.h"

namespace Msg
{ 
	
	class DLL_EXPORT InnerMsg : public ThreadPool::ThreadSustainTask , public MsgDispatcher
	{
	public:
		InnerMsg(): ThreadPool::ThreadSustainTask(DEFAULT_MSG_THREAD_ID , "ThreadSustainTask" , TRUE){}
		virtual ~InnerMsg(){}

	public:
		static InnerMsg & GetInstance()
		{
			static InnerMsg m_sInnerMsg;
			return m_sInnerMsg;
		}

	public:
		virtual  INT32  Init( UINT32 unMsgThreadPriorityCount = 1 , UINT32 unMsgHandlerthreadPriorityCount = 1, UINT32 unMsgThreadPriority = DEFAULT_MSG_THREAD_ID ,UINT32 unMsgHandlerthreadPriority = DEFAULT_MSG_HANDLE_THREAD_ID );
		virtual  INT32  Cleanup( void );
		virtual  INT32  Update( void ); 

	public:
		INT32  SendMsg(ObjectMsgCall * pMsg); 

	private:
		MsgQueue  m_objMsgQueue;
	}; 
	 
}
#endif