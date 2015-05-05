#ifndef __gamedb_db_server_net_handler_h__
#define __gamedb_db_server_net_handler_h__   
#include "MsgLib/inc/RemoteRpcServer.h"

namespace GameDB
{   
	class DBServerManager ;

	class DLL_EXPORT DBServerNetHandler : public Msg::RemoteRpcServer
	{  
	public:
		DBServerNetHandler(Msg::RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~DBServerNetHandler();
	
	public:
		virtual INT32  UpdatePing( void ); 
// 	public:   
// 		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);   
	};

	DECLARE_BOOST_POINTERS(DBServerNetHandler); 
}

#endif
