#ifndef __msg_msg_queue_h__
#define __msg_msg_queue_h__
#include "MsgLib/inc/MsgCommon.h"
#include "Timer/inc/TimerNode.h"
#include "Timer/inc/TimerInterface.h"

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
		virtual CErrno				Init(Timer::ETimerStrategyType objType = Timer::TIMER_STRATEGY_DEFAULT) override;
		virtual CErrno				Cleanup(void) override;
		virtual Timer::TimerNode*	Update(void) override;
		virtual INT32				SetTimer(ObjectMsgCall * pMsg , UINT32 unTimeInterval , UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL) ;

	public: 
		virtual  CErrno				AddMsg(ObjectMsgCall * pMsg , UINT32  unTimeout = 0);
		virtual  ObjectMsgCall	*	FetchMsg(); 

	public:
		QueueMsgsT					m_queueMsgs; 
	}; 
	
}
#endif