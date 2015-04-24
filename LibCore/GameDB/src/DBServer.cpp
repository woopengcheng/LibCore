#include "GameDB/inc/DBServer.h"
#include "GameDB/inc/DBServerListener.h"
#include "GameDB/inc/DBServerNetHandler.h"
#include "NetLib/inc/ServerSession.h"
#include "LogLib/inc/Log.h"

namespace GameDB
{ 

	DBServer::DBServer(Json::Value & conf)
		: ThreadPool::ThreadSustainTask(DEFAULT_RPC_MSG_THREAD_ID , "DBServer")
		, m_pNetReactor(NULL)
		, m_pEnvironment(NULL)
	{
		int nMode				 = conf.get("auth_mode","0").asInt();
		std::string strDir		 = conf.get("dir","./db/").asCString();
		std::string strBackupDir = conf.get("backup_dir","./db_backups/").asCString();
		Json::Value dbConfig	 = conf.get("dbconf",Json::Value());

		if(strDir[strDir.length() - 1] != '/')
			strDir = strDir + "/";
		if(strBackupDir[strBackupDir.length() - 1] != '/')
			strBackupDir = strBackupDir + "/";

		m_nMode = nMode;
//		m_pEnvironment = new Environment(strDir , dbConfig);
		m_strBackupDir = strBackupDir;

		leveldb::Env::Default()->CreateDir(m_strBackupDir);

		m_pNetReactor = new Net::NetReactorSelect;
		if(ERR_SUCCESS != m_pNetReactor->Init())
		{
			SAFE_DELETE(m_pNetReactor);
			MsgAssert(0, "rpc init net reactor fail."); 
		}
	}

	DBServer::~DBServer(void)
	{
		SAFE_DELETE(m_pEnvironment);
		SAFE_DELETE(m_pNetReactor);
	}

	INT32 DBServer::Init(Json::Value & conf)
	{
		int port				 = conf.get("port","8600").asInt(); 
		std::string strAddress	 = conf.get("address","").asCString(); 

		Net::ISession * pSeesion = new Net::ISession(strAddress.c_str() , port , "");
		DBServerListenerPtr pDBServerListener(new DBServerListener(this , m_pNetReactor , pSeesion));
		if(ERR_SUCCESS == pDBServerListener->Init(strAddress.c_str() , port))
		{
			pSeesion->SetClosed(FALSE);
			pSeesion->SetNetState(Net::NET_STATE_CONNECTED);
			m_pNetReactor->AddNetHandler(pDBServerListener);
		}
		else
		{
			pDBServerListener->Cleanup();   //5 这里会释放pSeesion 
		}

		return ERR_SUCCESS;
	}

	INT32 DBServer::Cleanup(void)
	{
		m_mapHandlers.clear();
		return ERR_SUCCESS;
	}

	INT32 DBServer::Update(void)
	{
		m_pNetReactor->Update();

		return ERR_SUCCESS;
	}

	Net::NetHandlerTransitPtr DBServer::CreateNetHandler(SOCKET socket , sockaddr_in * addr)
	{
		char szAddress[MAX_NAME_LENGTH];
		UINT16 usPort;
		Net::NetHelper::GetAddressAndPortByAddrIn(addr , szAddress , usPort);
		
		Net::ISession * pSession = new Net::ServerSession(szAddress , usPort , "");
		DBServerNetHandlerPtr pHandler(new DBServerNetHandler(this , m_pNetReactor , pSession));

		pSession->SetNetState(Net::NET_STATE_CONNECTED);
		pSession->SetClosed(FALSE);
		
		m_pNetReactor->AddNetHandler(pHandler);
		AddNetHandler(pSession->GetSessionID() , pHandler);

		gDebugStream("accept: ID: " << pSession->GetSessionID());

		return pHandler;
	}

	void DBServer::AddNetHandler(INT32 nSessionID , Net::NetHandlerTransitPtr pHandler)
	{ 
		MapSessionToHandlersT::iterator iterSessions = m_mapHandlers.find(nSessionID);
		if (iterSessions == m_mapHandlers.end())
		{
			m_mapHandlers.insert(std::make_pair(nSessionID , pHandler)); 
		}
		else
		{
			iterSessions->second = pHandler;
		}
	}

	void DBServer::DelNetHandler(INT32 nSessionID)
	{ 
		MapSessionToHandlersT::iterator iter = m_mapHandlers.find(nSessionID);
		if (iter != m_mapHandlers.end())
		{
			m_mapHandlers.erase(iter); 
		}
	}

	INT32 DBServer::UpdateHandlers(void)
	{
		MapSessionToHandlersT::iterator iter = m_mapHandlers.begin();
		for (;iter != m_mapHandlers.end();)
		{
			{
				Net::NetHandlerTransitPtr pHandler = iter->second; 
				++iter; 

				pHandler->Update();   //5 maybe has closed. 
			}
		}

		return ERR_SUCCESS; 
	} 

}