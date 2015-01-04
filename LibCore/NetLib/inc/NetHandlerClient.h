#ifndef __net_net_handler_client_h__
#define __net_net_handler_client_h__  
#include "NetHandlerCommonClient.h"
#include "NetHandlerZMQClient.h"

namespace Net 
{   
#ifndef USE_ZMQ
	class DLL_EXPORT NetHandlerClient : public NetHandlerCommonClient 
	{ 
	public:
		NetHandlerClient(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL)
			: NetHandlerCommonClient(pNetReactor , pSession , pMsgProcess) 
		{
		}
	};
	 
#else
	class DLL_EXPORT NetHandlerClient : public NetHandlerZMQClient 
	{ 
	public:
		NetHandlerClient(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL)
			: NetHandlerZMQClient(pNetReactor , pSession , pMsgProcess) 
		{
		}
	};
#endif
	DECLARE_BOOST_POINTERS(NetHandlerClient); 

}

#endif


