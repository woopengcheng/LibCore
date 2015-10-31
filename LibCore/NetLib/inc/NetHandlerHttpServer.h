#ifndef __net_i_net_handler_http_server_h__
#define __net_i_net_handler_http_server_h__ 
#include "NetLib/inc/NetHandlerListener.h"
#include "NetLib/inc/NetHandlerServer.h"
#include "NetLib/inc/ServerSession.h"

namespace Net 
{   
	class HttpProtocol;
	class HttpServer;

	class DLL_EXPORT HttpSession : public ServerSession
	{
	public:
		HttpSession(const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID = -1 , INT32 nNetState = 0 , NetSocket socket = -1 ,INT64 llTimeout = 0)
			: ServerSession(pAddress , usSocktPort , pRemoteName , nSessionID , nNetState , socket , llTimeout)
		{

		}
		~HttpSession()
		{

		}
	protected:

	};

	class DLL_EXPORT NetHandlerHttpServer : public NetHandlerServer
	{
	public: 
		NetHandlerHttpServer(HttpServer	* pServer , INetReactor * pNetReactor , ISession * pSession)
			: NetHandlerServer(pNetReactor , pSession) 
			, m_pServer(pServer)
		{ 
		}
		virtual ~NetHandlerHttpServer(){}

	public:
		virtual CErrno  OnMsgRecving( const char * pBuf , UINT32 unSize );  
		virtual	INT32	Send( HttpProtocol& response );

	protected:
		HttpServer	*	m_pServer;
	};
	DECLARE_BOOST_POINTERS(NetHandlerHttpServer);
	
	class DLL_EXPORT HttpServerListener : public NetHandlerListener
	{
	public:
		HttpServerListener(HttpServer * pServer , INetReactor * pNetReactor , ISession * pSession)
			: NetHandlerListener(pNetReactor , pSession)
			, m_pHttpServer(pServer)
		{

		}
		virtual ~HttpServerListener( void )
		{

		}

	public:
		virtual void			OnAccept(NetSocket socket , sockaddr_in * addr);

	protected:
		HttpServer			*	m_pHttpServer;
	}; 
	DECLARE_BOOST_POINTERS(HttpServerListener);

	class DLL_EXPORT HttpServer
	{
	public:
		explicit HttpServer( INetReactor * pNetReactor);
		virtual ~HttpServer( void );  

	public:
		virtual CErrno			Init(const char * pAddress , INT32 nPort , BOOL bResueAddr = TRUE , INT32  nListenerCount = DEFAULT_LISTENER_COUNT);
		virtual CErrno			Cleanup(); 
		virtual void			OnAccept(NetSocket socket , sockaddr_in * addr);
		virtual	CErrno			HttpHandler(HttpSession * pSession , HttpProtocol& request,HttpProtocol& response){ return CErrno::Success();}

	protected:
		HttpServerListenerPtr	m_pListener;
		INetReactor			*	m_pNetReactor;
	}; 
	DECLARE_BOOST_POINTERS(HttpServer);

}

#endif
