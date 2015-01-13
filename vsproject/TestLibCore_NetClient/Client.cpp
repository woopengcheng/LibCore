#include "Client.h"

INT32 Client::Init()
{
	if (!m_pNetReactor)
	{
		m_pNetReactor = new Net::NetReactorSelect;
	}
	m_pNetReactor->Init();

	if (!m_pMsgProcess)
	{
		m_pMsgProcess = new TestMsgProcess();
	}

	if (!m_pNetHandlerClient)
	{
		m_pNetHandlerClient = Net::NetHandlerClientPtr(new Net::NetHandlerClient(m_pNetReactor , new Net::ISession("127.0.0.1" , 5555 , "") , m_pMsgProcess));
	}

	m_pNetHandlerClient->Init("127.0.0.1" , 5555);
	m_pNetReactor->AddNetHandler(m_pNetHandlerClient);

	return ERR_SUCCESS;
}

INT32 Client::Cleanup()
{
	SAFE_DELETE(m_pMsgProcess);
	SAFE_DELETE(m_pNetReactor);

	return ERR_SUCCESS;
}

INT32 Client::Update()
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
	return TRUE;
}


INT32 TestMsgProcess::Process( Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
{
	printf("%s\n" , pBuffer);

	return TRUE;
}
