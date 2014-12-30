#ifndef __msg_internal_msg_task_h__
#define __msg_internal_msg_task_h__ 
#include "MsgCommon.h"
#include "ThreadTask.h"

namespace Msg
{ 
	class ObjectMsgCall;
	
	class DLL_EXPORT  InternalMsgTask : public ThreadPool::ThreadTask
	{   
	public:
		InternalMsgTask(ObjectMsgCall * pMsg);
		virtual ~InternalMsgTask();

	public:
		virtual INT32 Update( void );

	public: 
		ObjectMsgCall * m_pMsg;

	};
	 
}
#endif