#include "GameDB/inc/DBServerInterface.h"  
#include "NetLib/inc/NetLib.h"
#include "GameDB/inc/DBServerManager.h"
#include "GameDB/inc/DBClientManager.h"
#include "LogLib/inc/Log.h" 

namespace GameDB
{  
	DBServerInterface::DBServerInterface()  
		: m_pEnvironment(NULL)
		, m_nMode(0)
		, m_strBackupDir("./db_backups/")
	{  		
	}

	DBServerInterface::~DBServerInterface(void)
	{  
	}

	CErrno DBServerInterface::Init(Json::Value & conf)
	{   
		InitNet(conf);
		InitDB(conf);

		return CErrno::Success(); 
	}

	CErrno DBServerInterface::InitDB(const Json::Value & conf)
	{ 
		m_nMode					 = conf.get("auth_mode","0").asInt();
		m_strBackupDir			 = conf.get("backup_dir","./db_backups/").asCString();
		std::string strDir		 = conf.get("dir","./db/").asCString();
		Json::Value dbConfig	 = conf.get("dbconf",Json::Value());

		if(strDir[strDir.length() - 1] != '/')
			strDir = strDir + "/";
		if(m_strBackupDir[m_strBackupDir.length() - 1] != '/')
			m_strBackupDir = m_strBackupDir + "/";

		if (!m_pEnvironment)
		{
			m_pEnvironment = new Environment(strDir , dbConfig); 
		}
		leveldb::Env::Default()->CreateDir(m_strBackupDir);

		return CErrno::Success();
	}

	CErrno DBServerInterface::InitNet(const Json::Value & conf)
	{
		if (!m_pNetReactor)
		{
			m_pNetReactor = new Net::NetReactorDefault;

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

	CErrno DBServerInterface::Cleanup(void)
	{  
		if (m_pEnvironment)
		{
//			m_pEnvironment->Cleanup();
		}
		SAFE_DELETE(m_pEnvironment); 

		return RpcInterface::Cleanup();
	}

	CErrno DBServerInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

}