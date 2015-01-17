#include "MsgLib/inc/MsgQueue.h"
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/MsgTimerNode.h"
#include "MsgLib/inc/InternalMsgTask.h"
#include "MsgLib/inc/InnerMsg.h"

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
			return ERR_FAILURE;
		}
		MsgTimerNode * pNode = pNodeInt64->GetClass<MsgTimerNode >();    //5 获取堆顶的元素.然后进行比较.

		if (pNode && pNode->GetTimeCount().IsExpired())
		{
			AddMsg(pNode->GetMsgCall());
// 			InternalMsgTask * pTask = new InternalMsgTask()); 
// 			ThreadPool::ThreadPoolInterface::GetInstance().AddTask(pTask);
			RemoveTimer(pNode->GetTimerID());
		}

		return ERR_SUCCESS;
	}


	INT32 MsgQueue::AddMsg(ObjectMsgCall * pMsg )
	{
		Assert_ReF1(pMsg);

		m_queueMsgs.push(pMsg);

		return ERR_SUCCESS; 
	} 


	INT32 MsgQueue::AddMsg( ObjectMsgCall * pMsg , UINT32 unTimeout )
	{
		Assert_ReF1(pMsg);
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

		return ERR_FAILURE;
	}


}