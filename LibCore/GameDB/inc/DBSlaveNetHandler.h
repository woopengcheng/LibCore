#ifndef __gamedb_db_slave_net_handler_h__
#define __gamedb_db_slave_net_handler_h__   
#include "MsgLib/inc/RemoteRpcClient.h"

namespace GameDB
{   
	class DBClientManager;

	class DLL_EXPORT  DBSlaveNetHandler : public Msg::RemoteRpcClient 
	{ 
	public:
		DBSlaveNetHandler( Msg::RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor , Net::ISession * pSession)
			: RemoteRpcClient(pRpcManager , pNetReactor , pSession)
		{
		}
		virtual ~DBSlaveNetHandler(){}

// 	public: 
// 		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength); 

	public:
	};    

	DECLARE_BOOST_POINTERS(DBSlaveNetHandler); 
}

#endif