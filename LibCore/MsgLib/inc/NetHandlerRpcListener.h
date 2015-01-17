#ifndef __msg_net_handler_rpc_listener_h__
#define __msg_net_handler_rpc_listener_h__  
#include "NetLib/inc/NetHandlerListener.h" 
 
namespace Msg
{    
	class RpcManager;

	class DLL_EXPORT  NetHandlerRpcListener 
		: public Net::NetHandlerListener
	{
	public:
		DECLARE_BOOST_TEMPLATE_POINTERS(NetHandlerRpcListener , NetHandlerRpcListener); 

	public:
		NetHandlerRpcListener(RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession)
			: Net::NetHandlerListener(pNetReactor , pSession) 
			, m_pRpcManager(pRpcManager)
		{

		}
		virtual ~NetHandlerRpcListener( void )
		{
			Cleanup();
			SAFE_DELETE(m_pSession);
		}   

	public:
		virtual INT32  Init(const char * pAddress , INT32 nPort , BOOL bResueAddr = TRUE , INT32  nListenerCount = DEFAULT_LISTENER_COUNT);
		virtual INT32  Cleanup();  

	public:   
		virtual void   OnAccept(Net::SOCKET socket , sockaddr_in * addr); 

	private:
		RpcManager * m_pRpcManager; 
	}; 
}

#endif
