#ifndef __gamedb_db_client_net_handler_h__
#define __gamedb_db_client_net_handler_h__  
#include "MsgLib/inc/RemoteRpcClient.h" 

namespace GameDB
{   
	class DBClientManager;

	class DLL_EXPORT  DBClientNetHandler : public Msg::RemoteRpcClient 
	{ 
	public:
		DBClientNetHandler( Msg::RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~DBClientNetHandler();

	public: 
		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength); 
		  
	};    
	 
	DECLARE_BOOST_POINTERS(DBClientNetHandler); 
}

#endif
