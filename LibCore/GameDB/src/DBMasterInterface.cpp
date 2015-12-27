#include "GameDB/inc/DBMasterInterface.h"  
#include "NetLib/inc/NetLib.h"
#include "GameDB/inc/DBMasterManager.h"
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

	CErrno DBMasterInterface::Init(Json::Value & conf)
	{    
		InitNet(conf);

		return CErrno::Success(); 
	}
	 
	CErrno DBMasterInterface::InitNet(const Json::Value & conf)
	{
		if (!m_pNetReactor)
		{
#ifdef USE_ZMQ
			m_pNetReactor = new Net::NetReactorZMQ; 
#else
			m_pNetReactor = new Net::NetReactorDefault;
#endif
			if(CErrno::Success() != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
				MsgAssert_ReF(0, "init net fail."); 
			}
		}

		if (!m_pRpcServerManager)
		{
			m_pRpcServerManager = new DBMasterManager(this , m_pNetReactor); 
		} 
		if (!m_pRpcClientManager)
		{
			m_pRpcClientManager = new DBClientManager(this , m_pNetReactor); 
		} 
		 
		std::string strType = conf.get("listen_type" , "tcp").asCString();
		std::string strAddress = conf.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = conf.get("listen_port" , "8003").asCString();
		std::string strNodeName = conf.get("net_node_name" , "").asCString();

		StartupRPCServer(strNodeName , strType,  strAddress , strPort); 

		Json::Value clients = conf.get("clients" , Json::Value());
		StartupRPCClient(clients);

		RegisterRpc(); 

		return CErrno::Success();
	}

	CErrno DBMasterInterface::Cleanup(void)
	{  
		return RpcInterface::Cleanup();
	}

	CErrno DBMasterInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

}