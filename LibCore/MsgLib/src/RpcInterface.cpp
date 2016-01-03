#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/NetNode.h"
#include "XMLLib/inc/xml.h"
#include "NetLib/inc/ClientSession.h"
#include "NetLib/inc/ServerSession.h" 
#include "MsgLib/inc/IRpcListener.h"
#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/NetReactorZMQ.h"

namespace Msg
{ 

	RpcInterface::RpcInterface(void)
		: m_usServerPort(0)
		, m_pNetReactor(NULL)
		, m_pRpcServerManager(NULL)
		, m_pRpcClientManager(NULL)
		, m_pRpcListener(NULL) 
	{
		memset(m_szServerName , 0 , sizeof(m_szServerName));
		memset(m_szNetNodeName , 0 , sizeof(m_szNetNodeName));
		memset(m_szRpcType , 0 , sizeof(m_szRpcType));

	} 

	RpcInterface::~RpcInterface(void)
	{
	}

	void RpcInterface::RegisterRpc( void )
	{
		OnRegisterRpcs();
	}

	CErrno RpcInterface::Init( std::string strFilePath )
	{ 
		if (!m_pNetReactor)
		{
			m_pNetReactor = new Net::NetReactorDefault;

			if(CErrno::Success() != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF(0, "rpc init net reactor fail."); 
			}
		}

		m_pRpcClientManager = new RpcClientManager(this , m_pNetReactor);
		m_pRpcServerManager = new RpcServerManager(this , m_pNetReactor);

		XML::XML xml;  
		MsgAssert_ReF(xml.LoadFromFile(strFilePath).IsSuccess() , "xml load fail : " << strFilePath );  
		  
		std::string strType = xml.GetXMLValue("/RemoteRPC/RPCServer/ListenType"); 
		std::string strAddress = xml.GetXMLValue("/RemoteRPC/RPCServer/ListenAddress");
		std::string strPort = xml.GetXMLValue("/RemoteRPC/RPCServer/ListenPort");
		std::string strNodeName = xml.GetXMLValue("/RemoteRPC/RPCServer/NetNodeName");
		StartupRPCServer(strNodeName , strType , strAddress , strPort); 
		 
		StartupRPCClient(&xml); 

		RegisterRpc();

		return CErrno::Success();
	}

	CErrno RpcInterface::Init(Json::Value & conf)
	{   
		if (!m_pNetReactor)
		{
			m_pNetReactor = new Net::NetReactorDefault;

			if(CErrno::Success() != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF(0, "rpc init net reactor fail."); 
			}
		}

		if (m_pRpcServerManager)
		{
			m_pRpcServerManager = new RpcServerManager(this , m_pNetReactor);
		}
		if (m_pRpcClientManager)
		{
			m_pRpcClientManager = new RpcClientManager(this , m_pNetReactor);
		}

		Json::Value server = conf.get("server" , Json::Value()); 
		std::string strType = server.get("listen_type" , "tcp").asCString();
		std::string strAddress = server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = server.get("listen_port" , "8003").asCString();
		std::string strNodeName = server.get("net_node_name" , "").asCString();
		  
		StartupRPCServer(strNodeName , strType,  strAddress , strPort);

		Json::Value clients = conf.get("clients" , Json::Value()); 
		StartupRPCClient(clients); 

		RegisterRpc();

		return CErrno::Success(); 
	}


	CErrno RpcInterface::Cleanup( void )
	{
		if (m_pNetReactor)
		{
			m_pNetReactor->Cleanup();
		}
		SAFE_DELETE(m_pNetReactor);  

		if (m_pRpcClientManager)
		{
			m_pRpcClientManager->Cleanup();
		}
		SAFE_DELETE(m_pRpcClientManager); 

		if (m_pRpcServerManager)
		{
			m_pRpcServerManager->Cleanup();
		}
		SAFE_DELETE(m_pRpcServerManager); 

		return CErrno::Success();
	} 


	CErrno RpcInterface::Update( void )
	{ 
		if(m_pNetReactor)
		{
			m_pNetReactor->Update();
		}

		if (m_pRpcClientManager)
		{
			m_pRpcClientManager->Update();
		}

		if (m_pRpcServerManager)
		{
			m_pRpcServerManager->Update();
		}

		Timer::TimerHelper::sleep(1);
		return CErrno::Success();
	}
	
	void RpcInterface::StartupRPCServer(const std::string & strNetNodeName , const std::string & strType , const std::string & strAddress , const std::string & strPort)
	{
		std::string str = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

		m_usServerPort = atoi(strPort.c_str());
		memcpy(m_szServerName , str.c_str() , str.length());
		memcpy(m_szNetNodeName , strNetNodeName.c_str() , strNetNodeName.length());
		memcpy(m_szRpcType , strType.c_str() , strType.length()); 

		Net::ISession * pSeesion = new Net::ServerSession(strAddress.c_str() , m_usServerPort , str.c_str());
		NetHandlerRpcListenerPtr pNetHandlerListener(new NetHandlerRpcListener(m_pRpcServerManager , m_pNetReactor , pSeesion));
		if(CErrno::Failure() == pNetHandlerListener->Init(strAddress.c_str() , m_usServerPort))
			gErrorStream("listen failure:" << str);

		pSeesion->SetNetState(Net::NET_STATE_CONNECTED);
		m_pNetReactor->AddNetHandler(pNetHandlerListener , Net::NET_FUNC_ACCEPT_DEFAULT);

		NetNode::GetInstance().InsertMyselfNodes(m_szNetNodeName , this);
		gDebugStream("StartupRPCServer success:" << str);
	}
	
	void RpcInterface::StartupRPCClient( XML::XML * pXML )
	{
		std::string strType , strAddress , strPort , strPath = "/RemoteRPC/RPCClients/Client";
		INT32 nRpcCount = atoi(pXML->GetXMLValue("/RemoteRPC/RPCClients/Count").c_str());
		while(nRpcCount > 0)
		{   
			char bufType[200] = "";
			char bufAddr[200] = "";
			char bufPort[200] = "";

			sprintf(bufType,"/RemoteRPC/RPCClients/Client%d/Type",nRpcCount);
			sprintf(bufAddr,"/RemoteRPC/RPCClients/Client%d/Address",nRpcCount); 
			sprintf(bufPort,"/RemoteRPC/RPCClients/Client%d/Port",nRpcCount); 

			strType = pXML->GetXMLValue(bufType);
			strAddress = pXML->GetXMLValue(bufAddr);
			strPort = pXML->GetXMLValue(bufPort); 

			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

			Net::NetHandlerTransitPtr pNetHandler(NULL);
			pNetHandler = m_pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
			if (!pNetHandler)
			{
				m_pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , strAddress.c_str() , strPort.c_str());
			}

			--nRpcCount;
		}
	}

	void RpcInterface::StartupRPCClient(const Json::Value & clients)
	{
		INT32 nRpcCount = clients.size(); 
		for (INT32 i = 0 ;i < nRpcCount; ++ i)
		{     
			Json::Value rpc_client = clients[i];

			std::string strType = rpc_client.get("type" , "tcp").asCString();
			std::string strAddress = rpc_client.get("address" , "127.0.0.1").asCString();
			std::string strPort = rpc_client.get("port" , "8001").asCString(); 

			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

			Net::NetHandlerTransitPtr pNetHandler(NULL);
			pNetHandler = m_pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
			if (!pNetHandler)
			{
				m_pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , strAddress.c_str() , strPort.c_str());
			} 
		} 
	} 

	INT32 RpcInterface::SendMsg( const char * pRpcServerName , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{
		if (m_pRpcClientManager && m_pRpcServerManager)
		{   
			INT32 nResult = m_pRpcClientManager->SendMsg(pRpcServerName , pMsg , bForce , bAddRpc);
			if (nResult >= 0 && bAddRpc)
			{
				m_pRpcServerManager->InsertSendRpc(pMsg); 

				TakeOverSync(pMsg);
			}
			return nResult;
		}

		return -1;
	} 

	INT32 RpcInterface::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{   
		if (m_pRpcClientManager && m_pRpcServerManager)
		{  
			INT32 nResult =  m_pRpcClientManager->SendMsg(nSessionID , pMsg , bForce , bAddRpc);
			if (nResult >= 0 && bAddRpc)
			{
				m_pRpcServerManager->InsertSendRpc(pMsg); 

				TakeOverSync(pMsg);
			}
			return nResult;
		}

		return -1;
	} 

	INT32 RpcInterface::SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (m_pRpcClientManager && m_pRpcServerManager)
		{   
			INT32 nResult =  m_pRpcClientManager->SendMsg(pRemoteRpc , unMsgID , pBuffer , unLength , bForce , bAddRpc); 
			return nResult;
		}

		return -1;
	}   

	INT32 RpcInterface::SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pMsg , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (m_pRpcClientManager && m_pRpcServerManager)
		{  
			INT32 nResult = m_pRpcClientManager->SendMsg(pRemoteRpc , pMsg , bForce , bAddRpc);
			if (nResult >= 0 && bAddRpc)
			{
				m_pRpcServerManager->InsertSendRpc(pMsg);
				TakeOverSync(pMsg);
			}
			return nResult;
		} 
		return -1;
	}  

	INT32 RpcInterface::SendMsg(const std::string & strNetNodeName , RPCMsgCall * pMsg , BOOL bForce /*= FALSE */, BOOL bAddRpc /*= TRUE*/)
	{
		if (NetNode::GetInstance().IsInMyselfNodes(strNetNodeName))
		{
			RpcInterface * pInterface = NetNode::GetInstance().GetMyselfNode(strNetNodeName);
			if (pInterface != NULL)
			{
				m_pRpcServerManager->InsertSendRpc(pMsg);
				pInterface->GetRpcServerManager()->PostMsg(GetServerName() , pMsg);
			}
			return 0;
		}
		else
		{
			//5 有问题,多个相同的就不行了.
			Net::ISession * pSession = NetNode::GetInstance().GetRemoteNode(strNetNodeName);
			if (pSession)
			{
				m_pRpcClientManager->SendMsg(pSession->GetSessionID() , pMsg , bForce , bAddRpc);
			}
			return 0;
		}
		return -1;
	}

	void RpcInterface::TakeOverSync(RPCMsgCall * pMsg)
	{
		if (pMsg->GetSyncType() == SYNC_TYPE_SYNC)
		{ 
			while (pMsg->GetSyncResult() == SYNC_RESULT_START_RETURN)
			{
				Update();
// 				if(m_pNetReactor)
// 				{
// 					m_pNetReactor->Update();  //5 这里其实是接管网络的消息部分用于同步处理.也相当于这个线程阻塞了.
// 				}
			}
			SAFE_DELETE_NEW(pMsg);
		}
	}

	CErrno RpcInterface::CloseNet(const char * pName)
	{ 
		//5 对于RPC的客户端需要清空因为下次要重新连接.
		if (m_pRpcClientManager)
		{
			Net::NetHandlerTransitPtr pHandler = m_pRpcClientManager->GetHandlerByName(pName);
			if (pHandler.get())
			{
				m_pRpcClientManager->CleanupRemoteRpc(pHandler->GetSession()->GetSessionID()); 
			}
		}

		//5 对于RPC的服务端需要彻底的删除.
		if ( m_pRpcServerManager)
		{
			Net::NetHandlerTransitPtr pHandler = m_pRpcServerManager->GetHandlerBySimilarName(pName); 
			if (pHandler.get())
			{
				pHandler->GetSession()->SetClosed(TRUE);
				pHandler->GetSession()->SetNetState(FALSE);
				m_pRpcServerManager->DelRemoteRpc(pHandler->GetSession()->GetSessionID()); 
			}
		}

		return CErrno::Success();
	}  

}