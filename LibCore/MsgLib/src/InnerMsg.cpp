#include "MsgLib/inc/InnerMsg.h"
#include "MsgLib/inc/InternalMsgTask.h"
#include "MsgLib/inc/InnerMsg.h"
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"

namespace Msg
{ 
	INT32 InnerMsg::Init( void )
	{ 
		RegisterMsg();

		return ERR_SUCCESS;
	}


	INT32 InnerMsg::Cleanup( void )
	{

		return ERR_SUCCESS;
	}


	INT32 InnerMsg::SendMsg( ObjectMsgCall * pMsg  , UINT32 unTimeout/* = 0*/)
	{   
		return m_objMsgQueue.AddMsg(pMsg , unTimeout);  
	} 

	INT32 InnerMsg::Update( void )
	{     
		m_objMsgQueue.Update();  //5 这里更新后,会将到时间的消息加入到队列中

		ObjectMsgCall * pMsg = m_objMsgQueue.FetchMsg();
		while (pMsg)
		{ 
			RunMsg(pMsg);

			pMsg = m_objMsgQueue.FetchMsg();
		}

		return ERR_SUCCESS;
	} 

	INT32 InnerMsg::RunMsg( ObjectMsgCall * pMsg )
	{
		if (pMsg)
		{ 
			MethodImpl * pMethodImpl = GetMethodImpl(pMsg->m_szMsgMethod);
			Assert_Re0(pMethodImpl);

			ParaseMsgCall objParaseMsgCall;
			objParaseMsgCall.m_pMehtodImpl = pMethodImpl;
			objParaseMsgCall.m_pMsgCall = pMsg; 

			if (pMsg->GetTargetsCount() == 0)
			{
				pMethodImpl->m_pMethodImpl(&objParaseMsgCall);
			}
			else
			{
				for (UINT32 i = 0;i < pMsg->GetTargetsCount();++i)
				{
					ICallableObject * pICallableObject = GetCallableObject(pMsg->m_aTargets[i]);
					if (pICallableObject)
					{
						objParaseMsgCall.m_pObj = pICallableObject;
						pMethodImpl->m_pMethodImpl(&objParaseMsgCall);
					} 
				}  
			} 
				
			SAFE_DELETE(pMsg); 
			
			return ERR_SUCCESS;
		}

		return ERR_FAILURE;
	}
// 
// 	INT32 InnerMsg::Update( void )
// 	{   
// 		m_objMsgQueue.Update();  //5 这里更新后,会将到时间的消息加入到队列中
// 
// 		ObjectMsgCall * pMsg = m_objMsgQueue.FetchMsg();
// 		while (pMsg)
// 		{ 
// 			if (m_pThreadPoolInterface)
// 			{
// 				return m_pThreadPoolInterface->AddTask(new InternalMsgTask(this , pMsg)); 
// 			}
// 			else
// 			{
// 				InternalMsgTask objInnerMsg(this , pMsg);
// 				objInnerMsg.Update();
// 			} 
// 
// 			pMsg = m_objMsgQueue.FetchMsg();
// 		}
// 
// 		return ERR_SUCCESS;
// 	}

	void InnerMsg::RegisterMsg( void )
	{ 
		OnRegisterMsgs();
	}


}