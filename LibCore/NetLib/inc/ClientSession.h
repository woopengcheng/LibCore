#ifndef __net_client_session_h__
#define __net_client_session_h__ 
#include "NetLib/inc/ISession.h"

namespace Net 
{   
	class DLL_EXPORT ClientSession : public ISession
	{
	public:
		ClientSession( const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID = -1 , INT32 nNetState = 0 , NetSocket socket = -1 , INT64 llTimeout = 0 , BOOL bReconnect = TRUE ) 
			: ISession(pAddress , usSocktPort , pRemoteName , nSessionID , nNetState , socket , llTimeout)
			, m_bReconnect(bReconnect)
		{}
		virtual ~ClientSession(){}

	public:
		virtual    INT32    Cleanup() 
		{  
			return ISession::Cleanup();	
		} 

	public:
		BOOL     IsReconnect( void ) const { return m_bReconnect; }
		void     SetReconnect(BOOL val) { m_bReconnect = val; }

	private:
		BOOL     m_bReconnect;
	}; 
	  
}

#endif
