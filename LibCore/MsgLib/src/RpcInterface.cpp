#include "RpcInterface.h"
#include "RpcServerManager.h"
#include "RpcClientManager.h"
#include "xml.h"
#include "ClientSession.h"
#include "ServerSession.h"
//#include "RpcRegister.h"
#include "IRpcListener.h"
#include "NetHelper.h"
#include "NetReactorZMQ.h"

namespace Msg
{ 
	void RpcInterface::RegisterRpc( void )
	{
		OnRegisterRpcs();
	}


	INT32 RpcInterface::Init( std::string strFilePath )
	{ 
		XML::XML xml;  
		Assert_Re0(-1 != xml.LoadFromFile(strFilePath) && "xml load fail.");  

		if (!m_pNetReactor)
		{
#ifdef USE_ZMQ
			m_pNetReactor = new Net::NetReactorZMQ; 
#else
			m_pNetReactor = new Net::NetReactorSelect; 
#endif
			if(-1 == m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				Assert_Re0(0 && "rpc init net reactor fail."); 
			}
		}

		m_pRpcClientManager = new RpcClientManager(this , m_pNetReactor);
		m_pRpcServerManager = new RpcServerManager(this , m_pNetReactor);

		StartupRPCServer(&xml);
		StartupRPCClient(&xml); 

		RegisterRpc();

		return TRUE;
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
		return FALSE;
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
		return -1;
	}


	void RpcInterface::StartupRPCServer( XML::XML * pXML )
	{ 
		if (pXML)
		{   
			std::string strType = pXML->GetXMLValue("/RemoteRPC/RPCServer/ListenType"); 
			std::string strAddress = pXML->GetXMLValue("/RemoteRPC/RPCServer/ListenAddress");
			std::string strPort = pXML->GetXMLValue("/RemoteRPC/RPCServer/ListenPort");
			std::string str = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

			m_usServerPort = atoi(strPort.c_str());
			memcpy(m_szServerName , str.c_str() , str.length());
			memcpy(m_szRpcType , strType.c_str() , strType.length()); 

#ifdef USE_ZMQ
			m_pRpcServerManager->CreateNetHandler(m_szServerName , strAddress.c_str() , m_usServerPort , 0);
#else
			NetHandlerRpcListener::NetHandlerRpcListenerPtr pNetHandlerListener(new NetHandlerRpcListener(m_pRpcServerManager , m_pNetReactor , new Net::ISession(strAddress.c_str() , m_usServerPort , str.c_str())));
			pNetHandlerListener->Init(strAddress.c_str() , m_usServerPort);
			m_pNetReactor->AddNetHandler(pNetHandlerListener);
#endif 
		}
	}


	void RpcInterface::StartupRPCClient( XML::XML * pXML )
	{
		std::string strCurNetName , strType , strAddress , strPort , strPath = "/RemoteRPC/RPCClients/Client";
		INT32 nRpcCount = atoi(pXML->GetXMLValue("/RemoteRPC/RPCClients/Count").c_str());
		strCurNetName = pXML->GetXMLValue("/RemoteRPC/RPCClient/RemoteRPCName");
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


	INT32 RpcInterface::SendMsg( const char * pRpcServerName , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(pRpcServerName , pMsg , bForce , bAddRpc) && bAddRpc)
		{   
			m_pRpcServerManager->InsertSendRpc(pMsg); 

			return 1;
		}

		return -1;
	}


	INT32 RpcInterface::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{   
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(nSessionID , pMsg , bForce , bAddRpc) && bAddRpc)
		{  
			m_pRpcServerManager->InsertSendRpc(pMsg); 

			return 1;
		}

		return -1;
	}


	INT32 RpcInterface::SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(pRemoteRpc , unMsgID , pBuffer , unLength , bForce , bAddRpc) && bAddRpc)
		{   
			return 1;
		}

		return -1;
	}  


	INT32 RpcInterface::SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pMsg , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (m_pRpcClientManager && m_pRpcServerManager && m_pRpcClientManager->SendMsg(pRemoteRpc , pMsg , bForce , bAddRpc) && bAddRpc)
		{  
			m_pRpcServerManager->InsertSendRpc(pMsg); 

			return 1;
		} 
		return -1;
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

		return TRUE;
	}  
}