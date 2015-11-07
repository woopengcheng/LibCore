#ifndef __gamedb_db_client_http_server_h__
#define __gamedb_db_client_http_server_h__  
#include "GameDB/inc/DBClientInterface.h"
#include "NetLib/inc/NetHandlerHttpServer.h"
#include "ThreadPool/inc/ThreadTask.h"

namespace Client
{  
	class  DBClientHttpServer : public Net::HttpServer , ThreadPool::ThreadSustainTask
	{ 
	public:
		DBClientHttpServer(Net::INetReactor * pNetReactor = NULL);
		virtual ~DBClientHttpServer(void){} 

	public:
		static DBClientHttpServer & GetInstance()
		{
			static DBClientHttpServer m_sInterface;
			return m_sInterface;
		} 
	public:    
		CErrno				Init(Json::Value & conf);	
		virtual CErrno		Init(const char * pAddress , INT32 nPort , BOOL bResueAddr = TRUE , INT32  nListenerCount = DEFAULT_LISTENER_COUNT);
		virtual CErrno		Cleanup(); 
		virtual CErrno		Update(void);
		virtual	CErrno		HttpHandler(Net::HttpSession * pSession , Net::HttpProtocol& request,Net::HttpProtocol& response);
	};  

} 

#endif