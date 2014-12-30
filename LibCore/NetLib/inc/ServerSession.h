#ifndef __net_server_session_h__
#define __net_server_session_h__ 
#include "ISession.h"

namespace Net 
{  
	class DLL_EXPORT ServerSession : public ISession
	{
	public:
		ServerSession( const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID = -1 , INT32 nNetState = 0 , SOCKET socket = 0 ,INT64 llTimeout = 0)
			: ISession(pAddress , usSocktPort , pRemoteName , nSessionID , nNetState , socket , llTimeout)
		{}
		virtual ~ServerSession(){}

	public:
		virtual    INT32    Cleanup() { return ISession::Cleanup();	} 
	};  

}

#endif
