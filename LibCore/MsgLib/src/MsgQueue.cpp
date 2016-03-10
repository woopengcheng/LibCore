#include "MsgLib/inc/MsgQueue.h"
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/MsgTimerNode.h"
#include "MsgLib/inc/InternalMsgTask.h"
#include "MsgLib/inc/InnerMsg.h"

namespace Msg
{ 
	CErrno MsgQueue::Init(Timer::ETimerStrategyType objType/* = Timer::TIMER_STRATEGY_DEFAULT*/)
	{ 
		return TimerInterface::Init(objType);
	}


	CErrno MsgQueue::Cleanup( void )
	{
		return TimerInterface::Cleanup();
	}


	CErrno MsgQueue::Update( void )
	{  
		Timer::TimerNode * pNodeInt64 = GetNode(0);
		if (!pNodeInt64)
		{
			return CErrno::Failure();
		}
		MsgTimerNode * pNode = dynamic_cast<MsgTimerNode*>(pNodeInt64);    //5 ��ȡ�Ѷ���Ԫ��.Ȼ����бȽ�.

		if (pNode && pNode->GetTimeCount().IsExpired())
		{
			AddMsg(pNode->GetMsgCall());
// 			InternalMsgTask * pTask = new InternalMsgTask()); 
// 			ThreadPool::ThreadPoolInterface::GetInstance().AddTask(pTask);
			RemoveTimer(pNode->GetTimerID());
		}

		return CErrno::Success();
	}  

	CErrno MsgQueue::AddMsg( ObjectMsgCall * pMsg , UINT32 unTimeout/* = 0*/)
	{
		Assert_ReF(pMsg);
		if (unTimeout == 0)
		{
			m_queueMsgs.push(pMsg);
		}
		else
		{
			SetTimer(pMsg , unTimeout); 
		}

		return CErrno::Success(); 
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

	INT32 MsgQueue::SetTimer( ObjectMsgCall * pMsg , UINT32 unTimeInterval , UINT32 unTimes /*= 0*/, UINT32 unStartTime /*= 0*/, void * pObj /*= NULL */, TimerCallBackFunc pFunc /*= NULL*/ )
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