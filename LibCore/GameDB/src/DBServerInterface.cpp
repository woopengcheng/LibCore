#include "GameDB/inc/DBServerInterface.h"  
#include "NetLib/inc/NetLib.h"
#include "MsgLib/inc/RpcManager.h"
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
		InitDB(conf);

		return RpcInterface::Init(conf); 
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