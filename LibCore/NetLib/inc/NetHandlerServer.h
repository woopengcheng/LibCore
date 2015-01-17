#ifndef __net_net_handler_server_h__
#define __net_net_handler_server_h__  
#include "NetLib/inc/NetHandlerZMQServer.h"
#include "NetLib/inc/NetHandlerCommonServer.h"

namespace Net
{ 
#ifndef USE_ZMQ
	class DLL_EXPORT NetHandlerServer : public NetHandlerCommonServer
	{ 
	public:
		NetHandlerServer(INetReactor * pNetReactor , ISession * pSession)
			: NetHandlerCommonServer(pNetReactor , pSession) 
		{
		}
	};

#else
	class DLL_EXPORT NetHandlerServer : public NetHandlerZMQServer 
	{ 
	public:
		NetHandlerServer(INetReactor * pNetReactor , ISession * pSession)
			: NetHandlerZMQServer(pNetReactor , pSession) 
		{
		}
	};

#endif
	DECLARE_BOOST_POINTERS(NetHandlerServer); 
}

#endif 