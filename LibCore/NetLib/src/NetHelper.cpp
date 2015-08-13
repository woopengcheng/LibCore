#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/ISession.h"
#include "Common/CUtil.h"

#ifdef WIN32
#include <Windows.h>  
#endif 

namespace Net
{ 
	std::string NetHelper::GenerateRemoteName( const char * pNetType , const char * pAddress , const char * pPort )
	{
		std::string str = pNetType;
		str += "://";
		str += pAddress;
		str += ":";
		str += pPort;

		return str;
	}

	std::string NetHelper::GenerateRemoteName( const char * pNetType , const char * pAddress , UINT16 usPort )
	{ 
		char szPort[MAX_NAME_LENGTH]; 
		CUtil::itoa(szPort , (INT64)usPort); 

		return GenerateRemoteName(pNetType , pAddress , szPort); 
	}

	std::string NetHelper::GenerateRemoteName( const char * pNetType , const char * pAddress , UINT16 usPort ,UINT16 usRemotePort )
	{
		char szPort[MAX_NAME_LENGTH] , szRemotePort[MAX_NAME_LENGTH];
		CUtil::itoa(szPort , (INT64)usPort);  
		CUtil::itoa(szRemotePort , (INT64)usRemotePort);  

		return GenerateRemoteName(pNetType , pAddress , szPort , szRemotePort); 
	}

	std::string NetHelper::GenerateRemoteName( const char * pNetType , const char * pAddress , const char * pPort , const char * pRemotePort )
	{ 
		std::string str = pNetType;
		str += "-";
		str += pAddress;
		str += "-";
		str += pPort;
		str += "-";
		str += pRemotePort;

		return str;
	}

	void NetHelper::SetSocket( NetSocket & socket )
	{
		linger s = {0};
		s.l_onoff = 1;
		setsockopt(socket,SOL_SOCKET,SO_LINGER,(char*)&s,sizeof(linger));

		int valuetrue = 1;
		setsockopt(socket,SOL_SOCKET,SO_KEEPALIVE,(char*)&valuetrue,sizeof(int));

		SetIOCtrl(socket,FIOASYNC,&valuetrue);
	}

	INT32 NetHelper::RecvMsg(NetSocket socket , char * pBuf , UINT32 unSize )
	{
#ifdef __linux
		return ::recv(socket , pBuf , unSize , MSG_DONTWAIT);
#else
		return ::recv(socket , pBuf , unSize , 0);
#endif
	}

	BOOL NetHelper::IsSocketEagain()
	{ 
#ifdef __linux
		int e = errno;
		return (e == EAGAIN || e == EINTR);
#else
		int e = WSAGetLastError();
		return e == WSAEWOULDBLOCK;
#endif 

	}

	INT32 NetHelper::SetIOCtrl( int s,long cmd,int *argp )
	{
#ifdef __linux
		return ::ioctl(s,cmd,argp);
#else
		return ioctlsocket(s,cmd,(u_long*)argp);
#endif

	}

	INT32 NetHelper::NetToN( const char *ip, struct in_addr *addr )
	{
#ifdef __linux
		return ::inet_aton(ip,addr);
#else
		addr->S_un.S_addr = ::inet_addr(ip);
		return 0;
#endif
	}

#ifdef __linux
	BOOL NetHelper::GetIPByHost( char* ip , char* host = NULL)
	{ 
		char hostname[256]; 
		if (host == NULL)
		{
			int ret = gethostname(hostname,sizeof(hostname));
			if (ret==SOCKET_ERROR)
			{
				return false;
			}

			host = hostname;
		}

		struct hostent *answer;
		char ipstr[16];

		answer = gethostbyname(host);
		if (answer == NULL)
			return false;
		inet_ntop(AF_INET, (answer->h_addr_list)[0], ip, 16);
		return true;
	}
#else
	BOOL NetHelper::GetIPByHost( char* ip ,const char * host )
	{
		char hostname[256]; 
		if (host == NULL)
		{
			int ret=gethostname(hostname,sizeof(hostname));
			if (ret==SOCKET_ERROR)
			{
				return false;
			}

			host = hostname;
		}

		struct hostent *answer;

		answer = gethostbyname(host);
		if (answer == NULL)
			return false;
		char* ipstr = inet_ntoa(*(in_addr*)(answer->h_addr_list)[0]);
		if(ipstr == NULL)
			return false;
		CUtil::strncpy(ip, strlen(ipstr) + 1 , ipstr);
		return true;
	}

	BOOL NetHelper::GetAddressAndPortByAddrIn( sockaddr_in * pAddrIn , char * pAddress , UINT16 & usPort )
	{
		Assert_Re0(pAddrIn);
		sprintf(pAddress, inet_ntoa(pAddrIn->sin_addr));
		usPort = pAddrIn->sin_port;

		return TRUE;
	}

	INT32 NetHelper::SetDefaultSocket( NetSocket & socket , INT32 nSendBufSize/* = DEFAULT_SOCKET_BUFFER_SIZE */ , INT32 nRecvBufSize/* = DEFAULT_SOCKET_BUFFER_SIZE */)
	{ 
		INT32 nRes = 0;
		if (socket > 0)
		{
			INT32 valtrue = 1;

			nRes += setsockopt(socket,IPPROTO_TCP,TCP_NODELAY,(char*)&valtrue,sizeof(valtrue));
			nRes += setsockopt(socket,SOL_SOCKET,SO_KEEPALIVE,(char*)&valtrue,sizeof(valtrue));
			 
			nRes += setsockopt(socket,SOL_SOCKET,SO_SNDBUF,(char*)&nSendBufSize,sizeof(nSendBufSize));
			nRes += setsockopt(socket,SOL_SOCKET,SO_RCVBUF,(char*)&nSendBufSize,sizeof(nSendBufSize)); 
		} 
		return nRes;
	}

	void NetHelper::CloseSocket( NetSocket  socket )
	{
		::closesocket(socket); 
	}

	void NetHelper::CloseSocket( ISession * pSession )
	{
		if (pSession)
		{
			CloseSocket(pSession->GetSocket());
			pSession->SetSocket(-1);
		}

	}

	NetSocket NetHelper::CreateSocket( INT32 af, INT32 type, INT32 protocol )
	{
		return ::socket(af , type , protocol);
	}

#endif
}