#include "GameDB/inc/DBServerInterface.h"  
#include "NetLib/inc/NetReactorSelect.h"
#include "GameDB/inc/DBServerManager.h"
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

	INT32 DBServerInterface::Init(Json::Value & conf)
	{   
		InitDB(conf);
		InitNet(conf);

		return ERR_SUCCESS; 
	}

	INT32 DBServerInterface::InitDB(const Json::Value & conf)
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

		return ERR_SUCCESS;
	}

	INT32 DBServerInterface::InitNet(const Json::Value & conf)
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

		Json::Value rpc_server = conf.get("rpc_server" , Json::Value()); 
		std::string strType = rpc_server.get("listen_type" , "tcp").asCString();
		std::string strAddress = rpc_server.get("listen_address" , "127.0.0.1").asCString();
		std::string strPort = rpc_server.get("listen_port" , "8003").asCString();

		StartupRPCServer(strType,  strAddress , strPort); 

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

		if (m_pEnvironment)
		{
//			m_pEnvironment->Cleanup();
		}
		SAFE_DELETE(m_pEnvironment); 

		return ERR_SUCCESS;
	}

	INT32 DBServerInterface::Update(void)
	{ 
		return RpcInterface::Update();
	}  

}