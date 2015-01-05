#ifndef __msg_internal_msg_task_h__
#define __msg_internal_msg_task_h__ 
#include "MsgCommon.h"
#include "ThreadTask.h"

namespace Msg
{ 
	class ObjectMsgCall;
	class InnerMsg;
	
	class DLL_EXPORT  InternalMsgTask : public ThreadPool::ThreadTask
	{   
	public:
		InternalMsgTask(InnerMsg * pInnerMsg , ObjectMsgCall * pMsg);
		virtual ~InternalMsgTask();

	public:
		virtual INT32 Update( void );

	protected: 
		ObjectMsgCall * m_pMsg;
		InnerMsg      * m_pInnerMsg;
	};
	 
}
#endif