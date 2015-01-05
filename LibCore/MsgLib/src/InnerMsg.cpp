#include "InnerMsg.h"
#include "InternalMsgTask.h"
#include "ThreadPoolInterface.h"

namespace Msg
{ 
	INT32 InnerMsg::Init( void )
	{ 
		RegisterMsg();
		return TRUE;
	}


	INT32 InnerMsg::Cleanup( void )
	{

		return FALSE;
	}


	INT32 InnerMsg::SendMsg( ObjectMsgCall * pMsg )
	{ 
		return m_objMsgQueue.AddMsg(pMsg);
	} 


	INT32 InnerMsg::Update( void )
	{   
		m_objMsgQueue.Update();  //5 这里更新后,会将到时间的消息加入到队列中

		ObjectMsgCall * pMsg = m_objMsgQueue.FetchMsg();
		while (pMsg)
		{
			if (pMsg)
			{ 
				if (m_pThreadPoolInterface)
				{
					return m_pThreadPoolInterface->AddTask(new InternalMsgTask(this , pMsg)); 
				}
				else
				{
					InternalMsgTask objInnerMsg(this , pMsg);
					objInnerMsg.Update();
				}
			}  

			pMsg = m_objMsgQueue.FetchMsg();
		}

		return FALSE;
	}

	void InnerMsg::RegisterMsg( void )
	{ 
		OnRegisterMsgs();
	}

}