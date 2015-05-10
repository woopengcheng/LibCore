#include "GameDB/inc/DBClientInterface.h"  
#include "LogLib/inc/Log.h"
#include "json/json.h"
#include "NetLib/inc/NetReactorSelect.h"
#include "GameDB/inc/DBClientManager.h"
#include "GameDB/inc/DBServerManager.h"

namespace GameDB
{ 

	DBClientInterface::DBClientInterface()  
	{  
	}

	DBClientInterface::~DBClientInterface(void)
	{  
	}

	INT32 DBClientInterface::Init(Json::Value & conf)
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
		if(!m_pRpcClientManager)
			m_pRpcClientManager = new DBClientManager(this , m_pNetReactor);  
		if(!m_pRpcServerManager)
			m_pRpcServerManager = new DBServerManager(this , m_pNetReactor);  

		Json::Value server = conf.get("server" , Json::Value()); 
		std::string strType = server.get("listen_type" , "tcp").asCString();
		std::string strAddress = server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = server.get("listen_port" , "8003").asCString();

		StartupRPCServer(strType,  strAddress , strPort);
		
		Json::Value client = conf.get("client" , Json::Value()); 
		StartupRPCClient(client); 

		RegisterRpc();

		return ERR_SUCCESS; 
	}

	INT32 DBClientInterface::Cleanup(void)
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

		return ERR_SUCCESS;
	}

	INT32 DBClientInterface::Update(void)
	{ 
		return RpcInterface::Update();
	} 

	void DBClientInterface::StartupRPCClient(const Json::Value & client)
	{ 
		std::string strType = client.get("type" , "tcp").asCString();
		std::string strAddress = client.get("address" , "127.0.0.1").asCString();
		std::string strPort = client.get("port" , "8001").asCString(); 

		std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

		Net::NetHandlerTransitPtr pNetHandler(NULL);
		pNetHandler = m_pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
		if (!pNetHandler)
		{
			m_pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , strAddress.c_str() , strPort.c_str());
		}  
	}

}