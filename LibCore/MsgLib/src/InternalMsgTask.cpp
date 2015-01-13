#include "InternalMsgTask.h"
#include "ObjectMsgCall.h"
#include "MethodImpl.h"
#include "InnerMsg.h"

namespace Msg
{

	InternalMsgTask::InternalMsgTask(InnerMsg * pInnerMsg , ObjectMsgCall * pMsg )
		: ThreadPool::ThreadTask(DEFAULT_MSG_HANDLE_THREAD_ID , "InternalMsgTask") 
		, m_pMsg(pMsg)
		, m_pInnerMsg(pInnerMsg)
	{  
	}


	InternalMsgTask::~InternalMsgTask()
	{
	}


	INT32 InternalMsgTask::Update( void )
	{
		if (m_pMsg && m_pInnerMsg)
		{ 
			MethodImpl * pMethodImpl = m_pInnerMsg->GetMethodImpl(m_pMsg->m_szMsgMethod);
			Assert_Re0(pMethodImpl);

			ParaseMsgCall objParaseMsgCall;
			objParaseMsgCall.m_pMehtodImpl = pMethodImpl;
			objParaseMsgCall.m_pMsgCall = m_pMsg; 

			if (m_pMsg->GetTargetsCount() == 0)
			{
				pMethodImpl->m_pMethodImpl(&objParaseMsgCall);
			}
			else
			{
				for (UINT32 i = 0;i < m_pMsg->GetTargetsCount();++i)
				{
					ICallableObject * pICallableObject = m_pInnerMsg->GetCallableObject(m_pMsg->m_aTargets[i]);
					if (pICallableObject)
					{
						objParaseMsgCall.m_pObj = pICallableObject;
						pMethodImpl->m_pMethodImpl(&objParaseMsgCall);
					} 
				}  
			}

//			if (m_pInnerMsg->GetThreadPool())
			{
				SAFE_DELETE(m_pMsg);    //5 这里释放的是每个函数调用的时候那个指针.如果是线程池在这里释放.
			}

			return ERR_SUCCESS;
		}

		return ERR_FAILURE;
	}

}