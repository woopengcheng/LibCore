#include "NetLib/inc/NetThread.h"
#include "NetLib/inc/NetLib.h"
#include "ThreadPool/inc/ThreadPoolInterface.h"

namespace Net
{ 

	NetThread::NetThread(void)
		: ThreadPool::ThreadSustainTask(DEFAULT_THREAD_PRIORITY , "NetThread" , TRUE)
		, m_usServerPort(0)
		, m_pNetReactor(NULL)
	{
		memset(m_szServerName , 0 , sizeof(m_szServerName));
		memset(m_szNetNodeName , 0 , sizeof(m_szNetNodeName));
		memset(m_szRpcType , 0 , sizeof(m_szRpcType));

	} 

	NetThread::~NetThread(void)
	{
	}

	NetThread & NetThread::GetInstance()
	{
		static NetThread instance;
		return instance;
	}

	CErrno NetThread::Init(Json::Value & conf)
	{   
		if (!m_pNetReactor)
		{
			m_pNetReactor = new Net::NetReactorDefault();
			m_pNetReactor->SetMutilThread(TRUE);

			if(CErrno::Success() != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF(0, "NetReactor fail."); 
			}
		}
		
		Json::Value server = conf.get("server" , Json::Value()); 
		std::string strType = server.get("listen_type" , "tcp").asCString();
		std::string strAddress = server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = server.get("listen_port" , "8003").asCString();
		std::string strNodeName = server.get("net_node_name" , "").asCString();
		  
		StartupServer(strNodeName , strType,  strAddress , strPort);

		Json::Value clients = conf.get("clients" , Json::Value()); 
		StartupClient(clients); 

		ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(DEFAULT_THREAD_PRIORITY);
		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);

		return CErrno::Success(); 
	}

	CErrno NetThread::Cleanup( void )
	{
		if (m_pNetReactor || m_pNetReactor->Cleanup().IsFailure())
		{
			return CErrno::Failure();
		}
		SAFE_DELETE(m_pNetReactor);  

		return CErrno::Success();
	} 

	CErrno NetThread::Update( void )
	{
		CErrno err = DeliverMsg();

		if(m_pNetReactor)
		{
			if (m_pNetReactor->Update().IsSuccess() && err.IsSuccess())
			{
				err = CErrno::Failure();
			}
		}

		return err;
	}

	CErrno NetThread::DeliverMsg()
	{
		CErrno err;
		const INetReactor::CollectNetHandlersT mapHandlers = m_pNetReactor->GetNetHandlers();
		INetReactor::CollectNetHandlersT::const_iterator iter = mapHandlers.begin();
		for (; iter != mapHandlers.end(); ++iter)
		{
			const INetHandlerPtr pHandler = iter->second;
			if (pHandler)
			{
				if (pHandler->DeliverMsg().IsFailure() && err.IsSuccess())
				{
					err = CErrno::Failure();
				}
			}
		}
		return err;
	}

	CErrno NetThread::FetchMsgs(INT32 nSessionID , CollectMsgChunksT & queMsgs)
	{
		INetHandlerPtr pHandler = m_pNetReactor->GetNetHandlerByID(nSessionID);
		if (pHandler)
		{
			return pHandler->FetchMsgs(queMsgs);
		}

		return CErrno::Failure();
	}

	CErrno NetThread::StartupServer(const std::string & strNetNodeName , const std::string & strType , const std::string & strAddress , const std::string & strPort)
	{
		std::string str = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

		m_usServerPort = atoi(strPort.c_str());
		memcpy(m_szServerName , str.c_str() , str.length());
		memcpy(m_szNetNodeName , strNetNodeName.c_str() , strNetNodeName.length());
		memcpy(m_szRpcType , strType.c_str() , strType.length()); 

		Net::ISession * pSeesion = new Net::ServerSession(strAddress.c_str() , m_usServerPort , str.c_str());
		NetHandlerListenerPtr pListener(new NetHandlerListener(m_pNetReactor , pSeesion));
		if (CErrno::Failure() == pListener->Init(strAddress.c_str(), m_usServerPort))
		{
			gErrorStream("NetHandlerListener init failure:" << str << ":address=" << strAddress << ":port=" << m_usServerPort);
			return CErrno::Failure();
		}

		if (!(m_pNetReactor->AddNetHandler(pListener, Net::NET_FUNC_ACCEPT_DEFAULT)).IsSuccess())
		{
			gDebugStream("StartupRPCServer AddNetHandler failure:" << str);
			return CErrno::Failure();
		}

		gDebugStream("StartupRPCServer success:" << str);
		return CErrno::Success();
	}
	
	CErrno NetThread::StartupClient(const Json::Value & clients)
	{
		INT32 nCount = clients.size(); 
		for (INT32 i = 0 ;i < nCount; ++ i)
		{     
			Json::Value client = clients[i];

			std::string strType = client.get("type" , "tcp").asCString();
			std::string strAddress = client.get("address", "127.0.0.1").asCString();
			std::string strPort = client.get("port", "8001").asCString();

			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

			Net::INetHandlerPtr pNetHandler = CreateClientHandler(strRemoteRPCName.c_str(), strAddress.c_str(), atoi(strPort.c_str()));
			if (!pNetHandler)
			{
				return CErrno::Failure();
			} 
		}
		return CErrno::Success();
	} 

	INetHandlerPtr NetThread::CreateClientHandler(const char * pName, const char * pAddress, UINT16 usPort, Net::NetSocket socket /*= 0*/, void * context/* = NULL*/)
	{
		if (!pName || !pAddress)
		{
			return NULL;
		}

		Net::ClientSession * pSession = new Net::ClientSession(pAddress, usPort, pName);
		NetHandlerClientPtr pNetHandler(new NetHandlerClient(m_pNetReactor, pSession));

		CErrno nResult = pNetHandler->Init();
		if (nResult.IsSuccess())
		{
			m_pNetReactor->AddNetHandler(pNetHandler);
		}
		else
		{
			pSession->SetClosed(TRUE);
			pSession->SetNetState(Net::NET_STATE_LOSTED);
		}

		return pNetHandler;
	}

	INT32 NetThread::SendMsg(INT32 nSessionID , const char * pBuffer, UINT32 unLength)
	{
		INetHandlerPtr pHandler = m_pNetReactor->GetNetHandlerByID(nSessionID);
		if (pHandler)
		{
			 return pHandler->SendMsg(pBuffer, unLength);
		}

		return -1;
	}

	void NetThread::AcceptSession(INT32 nSessionID)
	{
		m_queAceeptSessions.push(nSessionID);
	}

	CErrno NetThread::FetchSession(std::vector<INT32> & vecSessions)
	{
		INT32 nSessionID = 0;
		while (m_queAceeptSessions.try_pop(nSessionID))
		{
			vecSessions.push_back(nSessionID);
		}

		return CErrno::Success();

	}

}