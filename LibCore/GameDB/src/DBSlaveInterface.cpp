#include "GameDB/inc/DBSlaveInterface.h"  
#include "NetLib/inc/NetReactorSelect.h"
#include "NetLib/inc/NetReactorZMQ.h"
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

	INT32 DBSlaveInterface::Init(Json::Value & conf)
	{   
		InitNet(conf);
		InitDB(conf);

		return ERR_SUCCESS; 
	}

	INT32 DBSlaveInterface::InitDB(const Json::Value & conf)
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
			return 1;
		}

		if(databases.size() == 0)
		{
			std::cerr << "invalid conf: databases not contain name" << std::endl;
			return 2;
		}

		for(size_t i = 0; i < databases.size(); ++i)
		{     
			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(strType.c_str() , strAddress.c_str() , strPort.c_str());

			std::string strDBName = databases[(INT32)i].asString();
			SDBSlaveInfo * pInfo = GetDBSlaveInfo(strRemoteRPCName);
			if (pInfo)
			{
				pInfo->strDBName = strDBName; 
				pInfo->strDir = strDirectory;
				pInfo->strUser = conf.get("login_user" , "test").asString();
				pInfo->strPswd = conf.get("login_pswd" , "test").asString();
			}
			else
			{
				objInfo.strDBName = strDBName; 
				m_mapDatabases.insert(std::make_pair(strRemoteRPCName , objInfo)); 
				pInfo = &objInfo;
			}

			Net::NetHandlerTransitPtr pNetHandler(NULL);
			pNetHandler = m_pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
			if (!pNetHandler)
			{
				m_pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , strAddress.c_str() , strPort.c_str() , 0 , pInfo); 
			}   
		} 
		return ERR_SUCCESS;
	}
	 

	INT32 DBSlaveInterface::InitNet(const Json::Value & conf)
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
				MsgAssert_ReF1(0, "init net fail."); 
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

		StartupRPCServer(strType,  strAddress , strPort); 
		 
		RegisterRpc(); 

		return ERR_SUCCESS;
	}

	INT32 DBSlaveInterface::Cleanup(void)
	{ 
 
		return RpcInterface::Cleanup();
	}

	INT32 DBSlaveInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

	SDBSlaveInfo * DBSlaveInterface::GetDBSlaveInfo(std::string strRemoteName)
	{
		CollectionDatabasesT::iterator iter = m_mapDatabases.find(strRemoteName);
		if (iter != m_mapDatabases.end())
		{
			return & iter->second;
		}

		return NULL;
	}

}