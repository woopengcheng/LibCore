#ifndef __net_net_helper_h__
#define __net_net_helper_h__ 
#include "NetCommon.h" 

struct in_addr;
struct sockaddr_in;

namespace Net 
{   
	class ISession;

	class DLL_EXPORT NetHelper
	{
	public:  
		static std::string GenerateRemoteName(const char * pNetType , const char * pAddress , UINT16 usPort); 
		static std::string GenerateRemoteName(const char * pNetType , const char * pAddress , const char * pPort);
		static std::string GenerateRemoteName(const char * pNetType , const char * pAddress , UINT16 usPort ,UINT16 usRemotePort); 
		static std::string GenerateRemoteName(const char * pNetType , const char * pAddress , const char * pPort , const char * pRemotePort);
		static void   SetSocket(SOCKET & socket);
		static INT32  SetDefaultSocket(SOCKET & socket , INT32 nSendBufSize = DEFAULT_SOCKET_BUFFER_SIZE , INT32 nRecvBufSize = DEFAULT_SOCKET_BUFFER_SIZE );
		static INT32  SetIOCtrl(int s,long cmd,int *argp);
		static void   CloseSocket(SOCKET socket);
		static void   CloseSocket(ISession * pSession);
		static SOCKET CreateSocket(INT32 af, INT32 type, INT32 protocol);
		static INT32  RecvMsg(SOCKET socket , char * pBuf , UINT32 unSize);
		static BOOL   IsSocketEagain();
		static INT32  NetToN( const char *ip, struct in_addr *addr );
		static BOOL   GetIPByHost( char* ip , const char* host = NULL);
		static BOOL   GetAddressAndPortByAddrIn(sockaddr_in * pAddrIn , char * pAddress , UINT16 & usPort);
	};
}

#endif