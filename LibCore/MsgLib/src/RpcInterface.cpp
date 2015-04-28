#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcClientManager.h"
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
		memset(m_szRpcType , 0 , sizeof(m_szRpcType));

	} 

	RpcInterface::~RpcInterface(void)
	{
	}

	void RpcInterface::RegisterRpc( void )
	{
		OnRegisterRpcs();
	}

	INT32 RpcInterface::Init( std::string strFilePath )
	{ 
		if (!m_pNetReactor)
		{
#ifdef USE_ZMQ
			m_pNetReactor = new Net::NetReacgtorZMQ; 
#else
			m_pNetReactor = new Net::NetReactorSelect; 
#endif
			if(ERR_SUCCESS != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF1(0, "rpc init net reactor fail."); 
			}
		}

		m_pRpcClientManager = new RpcClientManager(this , m_pNetReactor);
		m_pRpcServerManager = new RpcServerManager(this , m_pNetReactor);

		XML::XML xml;  
		MsgAssert_ReF1(!xml.LoadFromFile(strFilePath) , "xml load fail : " << strFilePath );  
		  
		std::string strType = xml.GetXMLValue("/RemoteRPC/RPCServer/ListenType"); 
		std::string strAddress = xml.GetXMLValue("/RemoteRPC/RPCServer/ListenAddress");
		std::string strPort = xml.GetXMLValue("/RemoteRPC/RPCServer/ListenPort");
		StartupRPCServer(strType , strAddress , strPort); 
		 
		StartupRPCClient(&xml); 

		RegisterRpc();

		return ERR_SUCCESS;
	}

	INT32 RpcInterface::Init(Json::Value & conf)
	{   
		if (!m_pNetReactor)
		{
#ifdef USE_ZMQ
			m_pNetReactor = new Net::NetReacgtorZMQ; 
#else
			m_pNetReactor = new Net::NetReactorSelect; 
#endif
			if(ERR_SUCCESS != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF1(0, "rpc init net reactor fail."); 
			}
		}

		m_pRpcClientManager = new RpcClientManager(this , m_pNetReactor);
		m_pRpcServerManager = new RpcServerManager(this , m_pNetReactor);

		Json::Value rpc_server = conf.get("rpc_server" , Json::Value()); 
		std::string strType = rpc_server.get("listen_type" , "tcp").asCString();
		std::string strAddress = rpc_server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = rpc_server.get("listen_port" , "8003").asCString();
		  
		StartupRPCServer(strType,  strAddress , strType);

		Json::Value rpc_clients = conf.get("rpc_clients" , Json::Value()); 
		StartupRPCClient(rpc_clients); 

		RegisterRpc();

		return ERR_SUCCESS; 
	}


	INT32 RpcInterface::Cleanup( void )
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

		return ERR_SUCCESS;
	} 


	INT32 RpcInterface::Update( void )
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
		return ERR_SUCCESS;
	}

// 	void RpcInterface::StartupRPCServer( XML::XML * pXML )
// 	{ 
// 		if (pXML)
// 		{   
// 			std::string str = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());
// 
// 			m_usServerPort = atoi(strPort.c_str());
// 			memcpy(m_szServerName , str.c_str() , str.length());
// 			memcpy(m_szRpcType , strType.c_str() , strType.length()); 
// 
// #ifdef USE_ZMQ
// 			m_pRpcServerManager->CreateNetHandler(m_szServerName , strAddress.c_str() , m_usServerPort , 0);
// #else
// 			Net::ISession * pSeesion = new Net::ISession(strAddress.c_str() , m_usServerPort , str.c_str());
// 			NetHandlerRpcListenerPtr pNetHandlerListener(new NetHandlerRpcListener(m_pRpcServerManager , m_pNetReactor , pSeesion));
// 			pNetHandlerListener->Init(strAddress.c_str() , m_usServerPort);
// 			pSeesion->SetClosed(FALSE);
// 			pSeesion->SetNetState(Net::NET_STATE_CONNECTED);
// 			m_pNetReactor->AddNetHandler(pNetHandlerListener);
// #endif 
// 		}
// 	}

	void RpcInterface::StartupRPCServer(const std::string & strType , const std::string & strAddress , const std::string & strPort)
	{
		std::string str = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

		m_usServerPort = atoi(strPort.c_str());
		memcpy(m_szServerName , str.c_str() , str.length());
		memcpy(m_szRpcType , strType.c_str() , strType.length()); 

#ifdef USE_ZMQ
		m_pRpcServerManager->CreateNetHandler(m_szServerName , strAddress.c_str() , m_usServerPort , 0);
#else
		Net::ISession * pSeesion = new Net::ISession(strAddress.c_str() , m_usServerPort , str.c_str());
		NetHandlerRpcListenerPtr pNetHandlerListener(new NetHandlerRpcListener(m_pRpcServerManager , m_pNetReactor , pSeesion));
		pNetHandlerListener->Init(strAddress.c_str() , m_usServerPort);
		pSeesion->SetClosed(FALSE);
		pSeesion->SetNetState(Net::NET_STATE_CONNECTED);
		m_pNetReactor->AddNetHandler(pNetHandlerListener);
#endif 
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

	void RpcInterface::StartupRPCClient(const Json::Value & rpc_clients)
	{
		INT32 nRpcCount = rpc_clients.size(); 
		for (INT32 i = 0 ;i < nRpcCount; ++ i)
		{     
			Json::Value rpc_client = rpc_clients[i];

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
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(pRpcServerName , pMsg , bForce , bAddRpc) != ERR_FAILURE && bAddRpc)
		{   
			m_pRpcServerManager->InsertSendRpc(pMsg); 

			TakeOverSync(pMsg);
			return ERR_SUCCESS;
		}

		return ERR_FAILURE;
	}


	INT32 RpcInterface::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{   
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(nSessionID , pMsg , bForce , bAddRpc) != ERR_FAILURE && bAddRpc)
		{  
			m_pRpcServerManager->InsertSendRpc(pMsg); 

			TakeOverSync(pMsg);
			return ERR_SUCCESS;
		}

		return ERR_FAILURE;
	}


	INT32 RpcInterface::SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(pRemoteRpc , unMsgID , pBuffer , unLength , bForce , bAddRpc) != ERR_FAILURE  && bAddRpc)
		{   
			return ERR_SUCCESS;
		}

		return ERR_FAILURE;
	}  


	INT32 RpcInterface::SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pMsg , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(pRemoteRpc , pMsg , bForce , bAddRpc) != ERR_FAILURE && bAddRpc)
		{  
			m_pRpcServerManager->InsertSendRpc(pMsg);
			TakeOverSync(pMsg);

			return ERR_SUCCESS;
		} 
		return ERR_FAILURE;
	}  

	void RpcInterface::TakeOverSync(RPCMsgCall * pMsg)
	{
		if (pMsg->GetSyncType() == SYNC_TYPE_SYNC)
		{ 
			while (pMsg->GetSyncResult() > SYNC_RESULT_START_RETURN)
			{
				if(m_pNetReactor)
				{
					m_pNetReactor->Update();  //5 这里其实是接管网络的消息部分用于同步处理.也相当于这个线程阻塞了.
				}
			}
			SAFE_DELETE(pMsg);
		}
	}

	INT32 RpcInterface::CloseNet(const char * pName)
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

		return ERR_SUCCESS;
	}  

}