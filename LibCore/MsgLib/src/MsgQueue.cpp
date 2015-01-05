#include "MsgQueue.h"
#include "ObjectMsgCall.h"
#include "MsgTimerNode.h"
#include "InternalMsgTask.h"
#include "ThreadPoolInterface.h"

namespace Msg
{ 
	INT32 MsgQueue::Init( void )
	{ 
		return TimerInterface::Init();
	}


	INT32 MsgQueue::Cleanup( void )
	{
		return TimerInterface::Cleanup();
	}


	INT32 MsgQueue::Update( void )
	{  
		Timer::Node<INT64> * pNodeInt64 = GetNode(0);
		if (!pNodeInt64)
		{
			return FALSE;
		}
		MsgTimerNode * pNode = pNodeInt64->GetClass<MsgTimerNode >();    //5 获取堆顶的元素.然后进行比较.

		if (pNode && pNode->GetTimeCount().IsExpired())
		{
			AddMsg(pNode->GetMsgCall());
// 			InternalMsgTask * pTask = new InternalMsgTask()); 
// 			ThreadPool::ThreadPoolInterface::GetInstance().AddTask(pTask);
			RemoveTimer(pNode->GetTimerID());
		}

		return TRUE;
	}


	INT32 MsgQueue::AddMsg(ObjectMsgCall * pMsg )
	{
		Assert_Re0(pMsg);

		m_queueMsgs.push(pMsg);

		return TRUE; 
	} 


	INT32 MsgQueue::AddMsg( ObjectMsgCall * pMsg , UINT32 unTimeout )
	{
		Assert_Re0(pMsg);
		return SetTimer(pMsg , unTimeout);
	}


	ObjectMsgCall * MsgQueue::FetchMsg()
	{ 
		ObjectMsgCall * pMsg = NULL;
		if(!m_queueMsgs.try_pop(pMsg))
		{
			return NULL;
		}
		return pMsg;
	}

	INT32 MsgQueue::SetTimer( ObjectMsgCall * pMsg , UINT32 unTimeInterval , UINT32 unStartTime /*= 0*/, UINT32 unTimes /*= 0*/, void * pObj /*= NULL */, TimerCallBackFunc pFunc /*= NULL*/ )
	{
		if (m_pTimerStrategy)
		{
			MsgTimerNode * pNode = new MsgTimerNode(pMsg , TimerIDAutoAddOne() , unTimeInterval , unStartTime , unTimes , pObj , pFunc);
			m_pTimerStrategy->InsertNode( GetTimerIDCount() , pNode);

			return GetTimerIDCount(); 
		}

		return -1;
	}


}