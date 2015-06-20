#ifndef __msg_inner_msg_h__
#define __msg_inner_msg_h__ 
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/MsgQueue.h"   
#include "MsgLib/inc/MsgDispatcher.h"

namespace ThreadPool
{
	class ThreadPoolInterface;
}

namespace Msg
{ 
	
	class DLL_EXPORT InnerMsg : public MsgDispatcher
	{
	public:
		InnerMsg(ThreadPool::ThreadPoolInterface * pThreadPoolInterface = NULL)
			: m_pThreadPoolInterface(pThreadPoolInterface)
		{

		}
		virtual ~InnerMsg(){}
		
	public:
		virtual  INT32  Init( void );
		virtual  INT32  Cleanup( void );
		virtual  INT32  Update( void ); 
		virtual  void   OnRegisterMsgs(void){}

	public:
		void   RegisterMsg(void);
		INT32  SendMsg(ObjectMsgCall * pMsg , UINT32 unTimeout = 0); 
		ThreadPool::ThreadPoolInterface * GetThreadPool(void){ return m_pThreadPoolInterface; }
		void   SetThreadPool(ThreadPool::ThreadPoolInterface * pThreadPoolInterface){ m_pThreadPoolInterface = pThreadPoolInterface; }

	protected: 
		INT32  RunMsg( ObjectMsgCall * pMsg );

	protected:
		MsgQueue						  m_objMsgQueue;
		ThreadPool::ThreadPoolInterface * m_pThreadPoolInterface;
	}; 
	 
}
#endif