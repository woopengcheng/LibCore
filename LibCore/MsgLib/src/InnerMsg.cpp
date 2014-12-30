#include "InnerMsg.h"

namespace Msg
{ 
	INT32 InnerMsg::Init(UINT32 unMsgThreadPriorityCount /*= 1*/ , UINT32 unMsgHandlerthreadPriorityCount /*= 1*/, UINT32 unMsgThreadPriority /*= DEFAULT_MSG_THREAD_ID*/ ,UINT32 unMsgHandlerthreadPriority /*= DEFAULT_MSG_HANDLE_THREAD_ID*/)
	{ 
		ThreadPool::ThreadPoolInterface::GetInstance().Init(std::map<UINT32 , UINT32>() , TRUE);
		ThreadPool::ThreadPoolInterface::GetInstance().Startup();
		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unMsgThreadPriority , unMsgThreadPriorityCount);  //5 创建一个全局的计时器线程.
		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unMsgHandlerthreadPriority , unMsgHandlerthreadPriorityCount);  //5 创建处理计时器任务的线程.

		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);

		return TRUE;
	}


	INT32 InnerMsg::Cleanup( void )
	{
		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();

		return FALSE;
	}


	INT32 InnerMsg::SendMsg( ObjectMsgCall * pMsg )
	{ 
		return m_objMsgQueue.AddMsg(pMsg);
	} 


	INT32 InnerMsg::Update( void )
	{   
		ObjectMsgCall * pMsg = m_objMsgQueue.FetchMsg();
		if (pMsg)
		{ 
			return ThreadPool::ThreadPoolInterface::GetInstance().AddTask(new InternalMsgTask(pMsg)); 
		} 
		else
		{
			Timer::TimerHelper::sleep(1);
		} 
		return FALSE;
	}
}