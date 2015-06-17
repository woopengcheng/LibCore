#ifndef __msg_msg_timer_node_h__
#define __msg_msg_timer_node_h__ 
#include "TimerLib/inc/TimerNode.h"
#include "TimerLib/inc/TimeCount.h" 
#include "TimerLib/inc/TimerNode.h"
#include "MsgLib/inc/ObjectMsgCall.h"

namespace Msg
{   
	
	class DLL_EXPORT  MsgTimerNode : public Timer::TimerNode
	{ 
	public:
		CLASS_TYPE_ID(MsgTimerNode , TimerNode , CTID_MsgTimerNode)

	public: 
		MsgTimerNode(ObjectMsgCall * pMsg , UINT32 unTimerID , UINT32 unTimeInterval , UINT32 unStartTime = 0, UINT32 unTimes = 0, void * pObj = NULL , TimerCallBackFunc pFunc = NULL)
			: Timer::TimerNode(unTimerID , unTimeInterval , unStartTime , unTimes , pObj , pFunc)
			, m_pMsg(pMsg)
		{
		}
		virtual   ~MsgTimerNode(){}

	public: 
		ObjectMsgCall * GetMsgCall(){ return m_pMsg; }

	private:
		ObjectMsgCall * m_pMsg ;
	};


}

#endif