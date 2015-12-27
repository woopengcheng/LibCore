#include "GameDB/inc/DBSlaveInterface.h"  
#include "NetLib/inc/NetLib.h"
#include "GameDB/inc/DBServerManager.h"
#include "GameDB/inc/DBSlaveManager.h"
#include "LogLib/inc/Log.h" 
#include "json/json.h"
#include <algorithm>

namespace GameDB
{  
	DBSlaveInterface::DBSlaveInterface()   
	{  		
	}

	DBSlaveInterface::~DBSlaveInterface(void)
	{  
	}

	CErrno DBSlaveInterface::Init(Json::Value & conf)
	{   
		InitNet(conf);
		InitDB(conf);

		return CErrno::Success(); 
	}

	CErrno DBSlaveInterface::InitDB(const Json::Value & conf)
	{  
		std::string timestamp = Timer::TimerHelper::GetDate();
		for(size_t i = 0; i < timestamp.length(); ++i)
		{
			if(timestamp[i] == '-' || timestamp[i] == ' ' || timestamp[i] == ':')
				timestamp[i] = '_';
		}
		 
		// strDirectory = directory + timestamp + "/" ; 
		std::string strDirectory = conf.get("slave_dir" , "./slave_db/").asString();
		if(strDirectory[strDirectory.length() - 1] != '/')
			strDirectory = strDirectory + "/";

		SDBSlaveInfo objInfo; 
		objInfo.strDir = strDirectory;
		objInfo.strUser = conf.get("login_user" , "test").asString();
		objInfo.strPswd = conf.get("login_pswd" , "test").asString();

		std::string strType = conf.get("type" , "tcp").asCString();
		std::string strAddress = conf.get("master_addr" , "127.0.0.1").asCString();
		std::string strPort = conf.get("master_port" , "8001").asCString(); 

		Json::Value databases = conf.get("databases","[]");
		if(!databases.isArray())
		{
			std::cerr << "invalid conf: databases not array" << std::endl;
			return CErrno::Failure();
		}

		if(databases.size() == 0)
		{
			std::cerr << "invalid conf: databases not contain name" << std::endl;
			return CErrno::Failure();
		}

		for(size_t i = 0; i < databases.size(); ++i)
		{     
			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

			std::string strDBName = databases[(INT32)i].asString(); 
			objInfo.strDBName = strDBName;  
			OnCreateDatabase(objInfo);

			Net::NetHandlerTransitPtr pNetHandler(NULL);
			pNetHandler = m_pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
			if (!pNetHandler)
			{
				m_pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , strAddress.c_str() , strPort.c_str() , 0 , &objInfo); 
			}   
		} 
		return CErrno::Success();
	}
	 

	CErrno DBSlaveInterface::InitNet(const Json::Value & conf)
	{
		if (!m_pNetReactor)
		{
#ifdef USE_ZMQ
			m_pNetReactor = new Net::NetReacgtorZMQ; 
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
			m_pRpcServerManager = new DBServerManager(this , m_pNetReactor); 
		} 
		if (!m_pRpcClientManager)
		{
			m_pRpcClientManager = new DBSlaveManager(this , m_pNetReactor); 
		} 

		std::string strType = conf.get("listen_type" , "tcp").asCString();
		std::string strAddress = conf.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = conf.get("listen_port" , "8003").asCString();
		std::string strNodeName = conf.get("net_node_name" , "").asCString();

		StartupRPCServer(strNodeName , strType,  strAddress , strPort); 
		 
		RegisterRpc(); 

		return CErrno::Success();
	}

	CErrno DBSlaveInterface::Cleanup(void)
	{ 
 
		return RpcInterface::Cleanup();
	}

	CErrno DBSlaveInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

}