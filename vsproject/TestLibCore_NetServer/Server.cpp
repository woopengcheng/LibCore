#include "Server.h"

INT32 Server::Init()
{
	if (!m_pNetReactor)
	{
		m_pNetReactor = new Net::NetReactorDefault;
	}
	m_pNetReactor->Init();

	Net::NetHandlerListenerPtr pNetHandlerListener(new Net::NetHandlerListener(m_pNetReactor , new Net::ServerSession("127.0.0.1" , 5555 , "")));
	pNetHandlerListener->Init("127.0.0.1" , 5555);
	m_pNetReactor->AddNetHandler(pNetHandlerListener , Net::NET_FUNC_ACCEPT_DEFAULT);

	return TRUE;
}

INT32 Server::InitUDP()
{
	if (!m_pNetReactor)
	{
		m_pNetReactor = new Net::NetReactorUDP;
	}
	m_pNetReactor->Init();

	Net::NetHandlerServerPtr pNetHandlerListener(new Net::NetHandlerServer(m_pNetReactor , new Net::ServerSession("127.0.0.1" , 5555 , "")));
	m_pNetReactor->AddNetHandler(pNetHandlerListener , Net::NET_FUNC_ACCEPT_DEFAULT);

	return TRUE;
}

INT32 Server::Cleanup()
{
	if (m_pNetReactor)
	{
		m_pNetReactor->Cleanup();
	}
	SAFE_DELETE(m_pNetReactor);
	return TRUE;
}

INT32 Server::Update()
{
	while(1)
	{
		m_pNetReactor->Update();
		Timer::TimerHelper::sleep(1); 
	}
	return TRUE;
}
