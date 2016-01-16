#ifndef __net_net_msg_queue_h__
#define __net_net_msg_queue_h__
#include "CUtil/inc/Chunk.h"
#include "NetLib/inc/NetCommon.h"  
#include "NetLib/inc/NetHandlerTransit.h"  

namespace Net
{
	class NetMsgQueue : public NetHandlerTransit
	{
	public:
		NetMsgQueue(INetReactor * pNetReactor, ISession * pSession)
			: NetHandlerTransit(pNetReactor , pSession)
		{}
		~NetMsgQueue() {}

	public:
		virtual CErrno		HandleMsg(const char* pBuffer, UINT32 unLength);
		virtual INT32		SendMsg(const char * pBuf, UINT32 unSize);

	public:
		virtual CErrno		FetchMsgs(CollectMsgChunksT & queMsgs);
		virtual CErrno		DeliverMsg();

	private:
		CollectMsgChunksT	m_queSendMsgQueues;
		CollectMsgChunksT	m_queRecvMsgQueues;
	};
};

#endif