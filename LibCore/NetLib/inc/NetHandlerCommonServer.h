#ifndef __net_net_handler_common_server_h__
#define __net_net_handler_common_server_h__ 
#include "NetLib/inc/NetHandlerTransit.h"

namespace Net 
{  
	class DLL_EXPORT NetHandlerCommonServer :public NetHandlerTransit
	{
	public:
		NetHandlerCommonServer(INetReactor * pNetReactor , ISession * pSession)
			: NetHandlerTransit(pNetReactor , pSession) 
		{ 
		}
		virtual ~NetHandlerCommonServer();

	public:
		virtual INT32  OnClose( void )     ;

	public:
		virtual INT32 HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);

	}; 

	DECLARE_BOOST_POINTERS(NetHandlerCommonServer);
	 
}

#endif 