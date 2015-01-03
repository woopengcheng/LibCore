#ifndef __net_net_handler_server_h__
#define __net_net_handler_server_h__  
#include "NetHandlerZMQServer.h"
#include "NetHandlerCommonServer.h"

namespace Net
{ 
#ifndef USE_ZMQ
	class NetHandlerServer : public NetHandlerCommonServer
	{ 
	public:
		NetHandlerServer(INetReactor * pNetReactor , ISession * pSession)
			: NetHandlerCommonServer(pNetReactor , pSession) 
		{
		}
	};

#else
	class NetHandlerServer : public NetHandlerZMQServer 
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