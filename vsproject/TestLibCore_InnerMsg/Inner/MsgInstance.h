#ifndef __msg_inner_instance_h__
#define __msg_inner_instance_h__  
#include "MsgLib/inc/InnerMsg.h"
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"
 

namespace Client
{  
	class  MsgInstance : public Msg::InnerMsg
	{ 
	public:
		MsgInstance(ThreadPool::ThreadPoolInterface * pThreadPoolInterface = NULL)  
			: Msg::InnerMsg(pThreadPoolInterface)
		{ 
		}
		virtual ~MsgInstance(void){} 

	public:
		static MsgInstance & GetInstance()
		{
			static MsgInstance m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public:  
		virtual INT32  Init( UINT32 unMsgHandlerthreadPriorityCount = 1 , UINT32 unMsgHandlerthreadPriority = DEFAULT_MSG_HANDLE_THREAD_ID )
		{ 
			ThreadPool::ThreadPoolInterface::GetInstance().Init(std::map<UINT32 , UINT32>() , TRUE);
			ThreadPool::ThreadPoolInterface::GetInstance().Startup();
			ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(unMsgHandlerthreadPriority , unMsgHandlerthreadPriorityCount);  //5 ���������ʱ��������߳�.
			
			m_pThreadPoolInterface = &ThreadPool::ThreadPoolInterface::GetInstance();

			return InnerMsg::Init();
		}

		virtual INT32  Cleanup( void )
		{
			return ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();
		}

		virtual void   OnRegisterMsgs(void);
	};  

} 

#endif
