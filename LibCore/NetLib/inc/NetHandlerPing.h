#ifndef __net_net_handler_ping_h__
#define __net_net_handler_ping_h__
#include "CUtil/inc/Chunk.h"
#include "NetLib/inc/NetCommon.h"  
#include "NetLib/inc/NetMsgQueue.h"  
#include "NetLib/inc/Ping.h"  

namespace Net
{
	class DLL_EXPORT NetHandlerPing : public NetMsgQueue
	{
	public:
		NetHandlerPing(INetReactor * pNetReactor, ISession * pSession)
			: NetMsgQueue(pNetReactor, pSession)
			, m_llLastSendPing(0)
		{}
		~NetHandlerPing() {}

	public:
		virtual CErrno		Update(void);
		virtual CErrno		HandlePing(ISession * pSession, SPing * pPing);
		virtual	CErrno		HandleMsg(const char* pBuffer, UINT32 unLength) final;
		virtual CErrno		HandleMsg(ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength);
		virtual CErrno		UpdatePing(void);

	public:
		CErrno				Ping(void);

	private:
		INT64				m_llLastSendPing;
	};
};

#endif