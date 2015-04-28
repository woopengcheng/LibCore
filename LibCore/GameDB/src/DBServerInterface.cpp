#include "GameDB/inc/DBServerInterface.h"  
#include "NetLib/inc/NetReactorSelect.h"
#include "GameDB/inc/DBServerManager.h"
#include "LogLib/inc/Log.h" 

namespace GameDB
{  
	DBServerInterface::DBServerInterface()  
	{  
	}

	DBServerInterface::~DBServerInterface(void)
	{  
	}

	INT32 DBServerInterface::Init(Json::Value & conf)
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

		m_pRpcServerManager = new DBServerManager(this , m_pNetReactor); 

		Json::Value rpc_server = conf.get("rpc_server" , Json::Value()); 
		std::string strType = rpc_server.get("listen_type" , "tcp").asCString();
		std::string strAddress = rpc_server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = rpc_server.get("listen_port" , "8003").asCString();

		StartupRPCServer(strType,  strAddress , strType); 
		  
		RegisterRpc();

		return ERR_SUCCESS; 
	}

	INT32 DBServerInterface::Cleanup(void)
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

	INT32 DBServerInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

}