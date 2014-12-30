#ifndef __net_msg_process_h__
#define __net_msg_process_h__ 
#include "NetCommon.h"
#include "ISession.h"

namespace Net
{     
	class MsgProcess
	{
	public:
		MsgProcess(){}
		virtual ~MsgProcess(){} 

	public:
		virtual BOOL IsAccept(UINT32 unMsgID) { return TRUE; }

	public:
		virtual INT32 Process(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength) = 0;  
	};
	  
} //Net

#endif