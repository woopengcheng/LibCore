#include "GameDB/inc/DBClient.h" 
#include "NetLib/inc/ClientSession.h"
#include "LogLib/inc/Log.h"
#include "json/json.h"

namespace GameDB
{ 

	DBClient::DBClient()
		: ThreadPool::ThreadSustainTask(DEFAULT_RPC_MSG_THREAD_ID , "DBClient")
		, m_pNetReactor(NULL) 
	{ 
		m_pNetReactor = new Net::NetReactorSelect;
		if(ERR_SUCCESS != m_pNetReactor->Init())
		{
			SAFE_DELETE(m_pNetReactor);
			MsgAssert(0, "rpc init net reactor fail."); 
		}
	}

	DBClient::~DBClient(void)
	{ 
		SAFE_DELETE(m_pNetReactor);
	}

	INT32 DBClient::Init(Json::Value & conf)
	{ 
		int port				 = conf.get("port","8600").asInt(); 
		std::string strAddress	 = conf.get("address","").asCString(); 

		if(!CreateNetHandler(strAddress.c_str() , port))
		{
			return ERR_FAILURE;
		}

		return ERR_SUCCESS;
	}

	INT32 DBClient::Cleanup(void)
	{ 
		return ERR_SUCCESS;
	}

	INT32 DBClient::Update(void)
	{
		if (m_pNetReactor)
		{
			m_pNetReactor->Update();
		}

		if (m_pHandlers)
		{
			m_pHandlers->Update();
		}

		return ERR_SUCCESS;
	}

	ErrCode DBClient::CreateNetHandler(const char * pAddress , UINT16 usPort)
	{
		Assert_Re(pAddress , ERR_FAILURE); 

		Net::ClientSession * pClientSession =  new Net::ClientSession(pAddress , usPort , "");
		m_pHandlers = DBClientNetHandlerPtr(new DBClientNetHandler(this , m_pNetReactor , pClientSession)); 

		if(ERR_SUCCESS == m_pHandlers->Init(pAddress, usPort)) 
		{  
			m_pNetReactor->AddNetHandler(m_pHandlers);  
			pClientSession->SetClosed(FALSE);
			pClientSession->SetNetState(Net::NET_STATE_CONNECTED);
			 
			return ERR_SUCCESS; 
		}
		else
		{ 
			pClientSession->SetClosed(TRUE);
			pClientSession->SetNetState(Net::NET_STATE_LOSTED); 
		}

		return ERR_FAILURE;
	} 
}