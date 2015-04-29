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

		Json::Value rpc_server = conf.get("rpc_server" , Json::Value()); 
		std::string strType = rpc_server.get("listen_type" , "tcp").asCString();
		std::string strAddress = rpc_server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = rpc_server.get("listen_port" , "8003").asCString();

		StartupRPCServer(strType,  strAddress , strPort);
		
		Json::Value rpc_clients = conf.get("rpc_client" , Json::Value()); 
		StartupRPCClient(rpc_clients); 

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

	void DBClientInterface::StartupRPCClient(const Json::Value & rpc_client)
	{ 
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