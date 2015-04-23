#ifndef __gamedb_db_server_h__
#define __gamedb_db_server_h__   
#include "GameDB/inc/DatabaseCommon.h"
#include "ThreadPoolLib/inc/ThreadTask.h"
#include "NetLib/inc/INetReactor.h"
#include "NetLib/inc/ISession.h"
#include "NetLib/inc/NetReactorSelect.h"  
#include "NetLib/inc/NetHandlerTransit.h"  
#include "NetLib/inc/NetHelper.h"  
#include "MsgLib/inc/MsgDispatcher.h"
#include "GameDB/inc/Environment.h"


namespace GameDB
{     
	class DLL_EXPORT DBServer : public Msg::MsgDispatcher , public ThreadPool::ThreadSustainTask
	{  
	public: 
		typedef std_unordered_map<INT32 , Net::NetHandlerTransitPtr> MapSessionToHandlersT;

	public:
		DBServer( Json::Value & conf );
		virtual ~DBServer(void);

	public:
		virtual INT32  Init(Json::Value & conf); 
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void); 

	public:
		virtual void   AddNetHandler(INT32 nSessionID , Net::NetHandlerTransitPtr pHandler);
		virtual void   DelNetHandler(INT32 nSessionID); 
		virtual INT32  UpdateHandlers(void);   

	public: 
		Net::INetReactor *			GetNetReactor() { return m_pNetReactor; }
		Net::NetHandlerTransitPtr   GetNetHandlerBySessionID(INT32 nSessionID);
		Net::NetHandlerTransitPtr	CreateNetHandler(SOCKET socket , sockaddr_in * addr);

	protected:   
		Net::INetReactor			* m_pNetReactor;         //5 没有访问机会.不会加锁 
		MapSessionToHandlersT		  m_mapHandlers; 
		INT32						  m_nMode;				 //5 DB服务器的运行模式,主要为宽松还是需要密码验证
		Environment					* m_pEnvironment;
		std::string					  m_strBackupDir;
	};

	DECLARE_BOOST_POINTERS(DBServer); 
}

#endif
