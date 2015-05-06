#ifndef __gamedb_db_server_interface_h__
#define __gamedb_db_server_interface_h__   
#include "GameDB/inc/DBCommon.h" 
#include "MsgLib/inc/RpcInterface.h" 
#include "json/json.h"
#include "GameDB/inc/Environment.h"

namespace GameDB
{     
	class DLL_EXPORT DBServerInterface : public Msg::RpcInterface
	{   
	public:
		DBServerInterface( );
		virtual ~DBServerInterface(void);

	public: 
		virtual INT32  Init(Json::Value & conf); 
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void);  

	public:
		INT32          GetMode(){ return m_nMode; }
		std::string    GetBackupDir(){ return m_strBackupDir; }
		Environment  * GetEnvironment(){ return m_pEnvironment; }

	private:
		INT32    InitDB(const Json::Value & conf);
		INT32    InitNet(const Json::Value & conf);

	protected:
		INT32						  m_nMode;				 //5 DB服务器的运行模式,主要为宽松还是需要密码验证
		Environment					* m_pEnvironment;
		std::string					  m_strBackupDir;
	};

	DECLARE_BOOST_POINTERS(DBServerInterface); 
}

#endif




// #ifndef __gamedb_db_client_h__
// #define __gamedb_db_client_h__   
// #include "GameDB/inc/DatabaseCommon.h"
// #include "ThreadPoolLib/inc/ThreadTask.h"
// #include "NetLib/inc/INetReactor.h"
// #include "NetLib/inc/ISession.h"
// #include "NetLib/inc/NetReactorSelect.h"  
// #include "NetLib/inc/NetHandlerTransit.h"  
// #include "NetLib/inc/NetHelper.h"  
// #include "MsgLib/inc/MsgDispatcher.h" 
// #include "GameDB/inc/DBClientNetHandler.h"
// 
// 
// namespace GameDB
// {     
// 	class DLL_EXPORT DBClient : public Msg::MsgDispatcher , public ThreadPool::ThreadSustainTask
// 	{   
// 	public:
// 		DBClient( );
// 		virtual ~DBClient(void);
// 
// 	public:
// 		virtual INT32  Init(Json::Value & conf); 
// 		virtual INT32  Cleanup(void);
// 		virtual INT32  Update(void);  
// 
// 	public: 
// 		Net::INetReactor *			GetNetReactor() { return m_pNetReactor; }
// 		DBClientNetHandlerPtr	    GetNetHandler() { return m_pHandlers;}
// 		ErrCode					 	CreateNetHandler(const char * pAddress , UINT16 usPort);
// 
// 	protected:   
// 		Net::INetReactor		  * m_pNetReactor;          
// 		DBClientNetHandlerPtr	    m_pHandlers;  
// 	};
// 
// 	DECLARE_BOOST_POINTERS(DBClient); 
// }
// 
// #endif
