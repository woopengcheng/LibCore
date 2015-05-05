#include "NetLib/inc/NetHandlerListener.h" 
#include "NetLib/inc/NetHandlerServer.h"
#include "NetLib/inc/ServerSession.h"
#include "NetLib/inc/INetReactor.h"
#include "NetLib/inc/NetHelper.h"
#ifdef WIN32
#include <WinSock.h>
#endif

namespace Net
{ 
	NetHandlerListener::NetHandlerListener( INetReactor * pNetReactor , ISession * pSession)
		: INetHandler(pNetReactor , pSession)
	{ 
		Assert(m_pSession); 
		NetSocket socket = NetHelper::CreateSocket(AF_INET , SOCK_STREAM , IPPROTO_TCP);

		int nValueTrue = 1;
		NetHelper::SetIOCtrl(socket , FIOASYNC , &nValueTrue);
		m_pSession->SetSocket(socket); 
	}

	INT32 NetHandlerListener::Init( const char * pAddress , INT32 nPort , BOOL bResueAddr /*= TRUE */, INT32 nListenerCount /*= DEFAULT_LISTENER_COUNT*/ )
	{ 
		Assert_ReF1(!Bind(pAddress , nPort));

		return Listen(nListenerCount);
	}

	INT32 NetHandlerListener::Cleanup()
	{ 
		SAFE_DELETE(m_pSession);
		return FALSE;
	}

	INT32 NetHandlerListener::OnMsgRecving( void )
	{
		sockaddr_in addr = {0};
#ifdef __linux
		socklen_t nAddrLen = sizeof(sockaddr_in);
#else
		INT32 nAddrLen = sizeof(sockaddr_in);
#endif
		NetSocket socket = ::accept(m_pSession->GetSocket(),(sockaddr*)&addr , &nAddrLen);
		if( socket != -1)
		{ 
			NetHelper::SetSocket(socket);	  
			this->OnAccept(socket , &addr);
		}
		return ERR_SUCCESS;
	}

	INT32 NetHandlerListener::Listen( INT32 nListenerCount /*= DEFAULT_LISTENER_COUNT*/)
	{
		return ::listen(m_pSession->GetSocket() , nListenerCount);
	}

	INT32 NetHandlerListener::Bind( const char * pAddress , INT32 nPort , BOOL bResueAddr)
	{
		Assert_ReF1(pAddress);
		 
		int nValueTrue = 1;
		if (bResueAddr)
		{
			setsockopt(m_pSession->GetSocket(), SOL_SOCKET , SO_REUSEADDR , (char *)&nValueTrue , sizeof(nValueTrue)); 
		}

		sockaddr_in addr = {0};
		addr.sin_family = AF_INET;
		addr.sin_port = htons(nPort);
		addr.sin_addr.S_un.S_addr = INADDR_ANY;
		if (pAddress != 0 && strlen(pAddress) > 0)
		{
			addr.sin_addr.S_un.S_addr = ::inet_addr(pAddress);
		}

		return ::bind(m_pSession->GetSocket() , (sockaddr*)&addr , sizeof(sockaddr_in));
	}

	void NetHandlerListener::OnAccept( NetSocket socket , sockaddr_in * addr )
	{
		if (m_pNetReactor)
		{
			char szAddress[MAX_NAME_LENGTH];
			UINT16 usPort = 0;
			Net::NetHelper::GetAddressAndPortByAddrIn(addr , szAddress , usPort);
			std::string strName = Net::NetHelper::GenerateRemoteName(NET_TYPE_TCP , szAddress , usPort);

			ServerSession * pServerSession = new ServerSession(szAddress , usPort , strName.c_str() , 0 , -1 , socket);
			NetHandlerServerPtr pServer( new NetHandlerServer(m_pNetReactor , pServerSession) ); 
			m_pNetReactor->AddNetHandler(pServer); 
		} 
	}


}