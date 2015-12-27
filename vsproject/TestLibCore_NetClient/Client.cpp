#include "Client.h"

CErrno Client::Init()
{
	if (!m_pNetReactor)
	{
		m_pNetReactor = new Net::NetReactorDefault;
	}
	m_pNetReactor->Init();

	if (!m_pMsgProcess)
	{
		m_pMsgProcess = new TestMsgProcess();
	}

	if (!m_pNetHandlerClient)
	{
		m_pNetHandlerClient = Net::NetHandlerClientPtr(new Net::NetHandlerClient(m_pNetReactor , new Net::ClientSession("127.0.0.1" , 5555 , "") , m_pMsgProcess));
	}

	m_pNetHandlerClient->Init("127.0.0.1" , 5555);
	m_pNetReactor->AddNetHandler(m_pNetHandlerClient);

	return CErrno::Success();
}

CErrno Client::Cleanup()
{
	SAFE_DELETE(m_pMsgProcess);
	SAFE_DELETE(m_pNetReactor);

	return CErrno::Success();
}

CErrno Client::Update()
{
	while(1)
	{
		m_pNetReactor->Update();

		char pBuf[1024]; 
		((Net::MsgHeader*)pBuf)->unMsgID = 0;
		((Net::MsgHeader*)pBuf)->unMsgLength = 6+ sizeof(Net::MsgHeader);
		memcpy(pBuf + sizeof(Net::MsgHeader) , "asdfa" , 6);

		if (m_pNetHandlerClient)
		{
			m_pNetHandlerClient->SendMsg(pBuf , 6 + sizeof(Net::MsgHeader));
		}
		Timer::TimerHelper::sleep(1); 
	}
	return CErrno::Success();
}


CErrno TestMsgProcess::Process(Net::ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength)
{
	printf("%s\n" , pBuffer);

	return Net::MsgProcess::Process(pSession , unMsgID , pBuffer , unLength);
}
