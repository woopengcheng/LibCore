#include "GameDB/inc/DBMasterInterface.h"  
#include "NetLib/inc/NetReactorSelect.h"
#include "NetLib/inc/NetReactorZMQ.h"
#include "GameDB/inc/DBServerManager.h"
#include "GameDB/inc/DBClientManager.h"
#include "LogLib/inc/Log.h" 

namespace GameDB
{  
	DBMasterInterface::DBMasterInterface()   
	{  		
	}

	DBMasterInterface::~DBMasterInterface(void)
	{  
	}

	INT32 DBMasterInterface::Init(Json::Value & conf)
	{    
		InitNet(conf);

		return ERR_SUCCESS; 
	}
	 
	INT32 DBMasterInterface::InitNet(const Json::Value & conf)
	{
		if (!m_pNetReactor)
		{
#ifdef USE_ZMQ
			m_pNetReactor = new Net::NetReactorZMQ; 
#else
			m_pNetReactor = new Net::NetReactorSelect; 
#endif
			if(ERR_SUCCESS != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF1(0, "init net fail."); 
			}
		}

		if (!m_pRpcServerManager)
		{
			m_pRpcServerManager = new DBServerManager(this , m_pNetReactor); 
		} 
		if (!m_pRpcClientManager)
		{
			m_pRpcClientManager = new DBClientManager(this , m_pNetReactor); 
		} 
		 
		std::string strType = conf.get("listen_type" , "tcp").asCString();
		std::string strAddress = conf.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = conf.get("listen_port" , "8003").asCString();

		StartupRPCServer(strType,  strAddress , strPort); 

		Json::Value clients = conf.get("clients" , Json::Value());
		StartupRPCClient(clients);

		RegisterRpc(); 

		return ERR_SUCCESS;
	}

	INT32 DBMasterInterface::Cleanup(void)
	{ 
		if (m_pNetReactor)
		{
			m_pNetReactor->Cleanup();
		}
		SAFE_DELETE(m_pNetReactor);   

		if (m_pRpcServerManager)
		{
			m_pRpcServerManager->Cleanup();
		}
		SAFE_DELETE(m_pRpcServerManager); 
		  

		return ERR_SUCCESS;
	}

	INT32 DBMasterInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

}