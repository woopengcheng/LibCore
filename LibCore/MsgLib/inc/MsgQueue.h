#ifndef __msg_msg_queue_h__
#define __msg_msg_queue_h__
#include "MsgCommon.h"
#include "TimerInterface.h"

namespace Msg
{ 
	class ObjectMsgCall;
	
	class DLL_EXPORT  MsgQueue : public Timer::TimerInterface
	{
	public:
		typedef tbb_priority_queue<ObjectMsgCall*> QueueMsgsT; 

	public:
		MsgQueue(){}
		virtual ~MsgQueue(){}

	public:
		virtual INT32    Init(void);
		virtual INT32    Cleanup(void);
		virtual INT32    Update(void); 
		virtual INT32    SetTimer(ObjectMsgCall * pMsg , UINT32 unTimeInterval , UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL);

	public:
		virtual  INT32            AddMsg(ObjectMsgCall * pMsg);
		virtual  INT32            AddMsg(ObjectMsgCall * pMsg , UINT32  unTimeout);
		virtual  ObjectMsgCall  * FetchMsg(); 

	public:
		QueueMsgsT m_queueMsgs; 
	}; 
	
}
#endif