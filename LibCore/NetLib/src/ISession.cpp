#include "NetLib/inc/ISession.h"
#include "NetLib/inc/NetHelper.h"

namespace Net
{ 
	static   INT32   g_nSessionCount = 0; 

	ISession::ISession( const char * pAddress  , INT16 usSocktPort ,  const char * pRemoteName/* = NULL*/ , INT32 nSessionID/* = -1*/ , INT32 nNetState/* = 0*/ , SOCKET socket /*= -1*/ , INT64 llTimeout /*= 0*/)
		: m_nNetState(nNetState)
		, m_bCanWrite(TRUE) 
	{ 
		Init(pAddress , usSocktPort , pRemoteName , nSessionID , socket , llTimeout);

		if (nSessionID == -1)
		{
			AutoSetSessionID();
		}
	}  

	INT32 ISession::OnRecvMsg( void )
	{
		m_objTimeout.ResetTime();
		return ERR_SUCCESS;
	}

	INT32 ISession::OnSendMsg( void )
	{ 
		m_objTimeout.ResetTime();

		return ERR_SUCCESS;
	}

	INT32 ISession::OnClose( void )
	{ 
		return ERR_SUCCESS;
	}

	INT32 ISession::Init( const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID , SOCKET socket , INT64 llTimeout)
	{  
		m_bClosed = TRUE;
		memcpy(m_szAddress , pAddress , strlen(pAddress) + 1);
		m_usSocktPort = usSocktPort;  
		memcpy(m_szRemoteName , pRemoteName , strlen(pRemoteName) + 1);
		m_nSessionID = nSessionID;
		m_socket = socket;

		m_objTimeout.Start(llTimeout);

		return ERR_SUCCESS;
	}

	INT32 ISession::Cleanup(void)
	{  
		m_bClosed = TRUE;
		m_nNetState = NET_STATE_LOSTED; 
		m_objTimeout.Clean();

		if (m_socket != -1)
		{
			NetHelper::CloseSocket(this);
			m_socket = -1; 
		}
		return ERR_SUCCESS;
	}
	 
	void ISession::AutoSetSessionID( void )
	{
		 m_nSessionID = ++Net::g_nSessionCount;
	}

}