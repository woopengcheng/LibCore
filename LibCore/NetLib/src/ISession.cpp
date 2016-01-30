#include "NetLib/inc/ISession.h"
#include "NetLib/inc/NetHelper.h"

namespace Net
{ 
	static   INT32   g_nSessionCount = 0; 

	ISession::ISession(const std::string & strAddress, INT16 usSocktPort, const std::string & strCurNodeName , const std::string & strRemoteName /*= ""*/, INT32 nSessionID/* = -1*/, INT32 nNetState/* = 0*/, NetSocket socket /*= -1*/, INT64 llTimeout /*= 0*/)
		: m_strAddress(strAddress)
		, m_usSocktPort(usSocktPort)
		, m_strCurNodeName(strCurNodeName)
		, m_strRemoteName(strRemoteName)
		, m_nNetState(nNetState)
		, m_bCanWrite(TRUE)
		, m_pContext(NULL)
		, m_objReactorType(REACTOR_TYPE_VAILID)
		, m_bClosed(TRUE)
		, m_nSessionID(nSessionID)
		, m_socket(socket)
		, m_nSendBufSize(DEFAULT_SOCKET_BUFFER_SIZE)
		, m_nRecvBufSize(DEFAULT_SOCKET_BUFFER_SIZE)
	{
		m_objTimeout.Start(llTimeout);

		if (nSessionID == -1)
		{
			AutoSetSessionID();
		}
	}  

	ISession::~ISession(void)
	{
		Cleanup();

		if (m_pContext)
		{
			SAFE_DELETE(m_pContext);
		}
	}

	CErrno ISession::OnRecvMsg(void)
	{
		m_objTimeout.ResetTime();
		return CErrno::Success();
	}

	CErrno ISession::OnSendMsg( void )
	{ 
		m_objTimeout.ResetTime();

		return CErrno::Success();
	}

	CErrno ISession::OnClose( void )
	{
		Cleanup();

		return CErrno::Success();
	}

	CErrno ISession::Init()
	{  
		return CErrno::Success();
	}

	CErrno ISession::Cleanup(void)
	{  
		m_bClosed = TRUE;
		m_nNetState = NET_STATE_LOSTED; 
		m_objTimeout.Clean();

		if (m_socket != -1)
		{
			NetHelper::CloseSocket(this);
			m_socket = -1; 
		}

		return CErrno::Success();
	}
	 
	void ISession::AutoSetSessionID( void )
	{
		 m_nSessionID = ++Net::g_nSessionCount;
	}

	void ISession::SetContext(void * val)
	{
		if (m_pContext)
		{
			SAFE_DELETE(m_pContext);
		}

		m_pContext = val;
	}

}