#include "Server.h"
#include "NetLib/inc/NetThread.h"

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

	Net::NetHandlerServerPtr pNetHandlerListener(new Net::NetHandlerServer(m_pNetReactor , new Net::ServerSession("0.0.0.0" , 5555 , "")));
	m_pNetReactor->AddNetHandler(pNetHandlerListener , Net::NET_FUNC_ACCEPT_DEFAULT);

	return TRUE;
}

INT32 Server::InitZMQ()
{
	if (!m_pNetReactor)
	{
		m_pNetReactor = new Net::NetReactorZMQ;
	}
	m_pNetReactor->Init();

	Net::ServerSession * pServerSession = new Net::ServerSession("127.0.0.1", 5555, "", -1, 0);
	pServerSession->SetNetState(Net::NET_STATE_CONNECTED);

	Net::NetHandlerServerPtr pNetHandlerListener(new Net::NetHandlerServer(m_pNetReactor, pServerSession));
	m_pNetReactor->AddNetHandler(pNetHandlerListener, Net::NET_FUNC_ACCEPT_DEFAULT);

	return TRUE;
}

INT32 Server::InitRakNet()
{
	if (!m_pNetReactor)
	{
		m_pNetReactor = new Net::NetReactorRakNet;
	}
	m_pNetReactor->Init();

	Net::ServerSession * pServerSession = new Net::ServerSession("127.0.0.1", 5555, "", -1, 0);
	Net::NetHandlerServerPtr pNetHandlerListener(new Net::NetHandlerServer(m_pNetReactor, pServerSession));
	m_pNetReactor->AddNetHandler(pNetHandlerListener, Net::NET_FUNC_ACCEPT_DEFAULT);

	return TRUE;
}

INT32 Server::InitNetThread()
{
	std::string defaultConf = "./netServer.conf";

	Json::Value root;
	Json::JsonParase(defaultConf.c_str(), root);
	Net::NetThread::GetInstance().Init(root);

	return TRUE;
}

INT32 Server::Cleanup()
{
	if (m_pNetReactor)
	{
		m_pNetReactor->Cleanup();
		SAFE_DELETE(m_pNetReactor);
	}
	Net::NetThread::GetInstance().Cleanup();
	return TRUE;
}

INT32 Server::Update()
{
	char pBuf[1024];
	const char * kSendMsg = "send from server.\n";
	std::vector<INT32> vecSessions;
	std::vector<INT32> vecSessionsTmp;
	while(1)
	{
		if (m_pNetReactor)
		{
			m_pNetReactor->Update();
		}
		Net::NetThread::GetInstance().FetchSession(vecSessionsTmp);
		if (vecSessionsTmp.size())
		{
			vecSessions.insert(vecSessions.end(), vecSessionsTmp.begin(), vecSessionsTmp.end());
			vecSessionsTmp.clear();
		}
		std::vector<INT32>::iterator iter = vecSessions.begin();
		for (;iter != vecSessions.end();++iter)
		{
			Net::CollectMsgChunksT  queMsgs;
			Net::NetThread::GetInstance().FetchMsgs(*iter, queMsgs);

			CUtil::Chunk objChunk;
			while (queMsgs.try_pop(objChunk))
			{
				char * pRecvBuf = (char *)(objChunk.Begin());

				gDebugStream("msg:" << pRecvBuf + sizeof(Net::MsgHeader));
			}

			UINT32 unLen = strlen(kSendMsg) + 1;
			((Net::MsgHeader*)pBuf)->unMsgID = 0;
			((Net::MsgHeader*)pBuf)->unMsgLength = unLen + sizeof(Net::MsgHeader);
			memcpy(pBuf + sizeof(Net::MsgHeader), kSendMsg, unLen);
			INT32 nLength = sizeof(Net::MsgHeader) + unLen;

			Net::NetThread::GetInstance().SendMsg(*iter, pBuf, nLength);
		}
		Timer::sleep(1); 
	}
	return TRUE;
}
