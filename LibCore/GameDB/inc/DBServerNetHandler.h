#ifndef __gamedb_db_server_net_handler_h__
#define __gamedb_db_server_net_handler_h__  
#include "NetLib/inc/NetHandlerServer.h"

namespace GameDB
{     
	class DLL_EXPORT DBServerNetHandler : public Net::NetHandlerServer
	{
	public:
		DECLARE_BOOST_TEMPLATE_POINTERS(DBServerNetHandler , RemoteRpcServer); 

	public:
		DBServerNetHandler(RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~DBServerNetHandler();

	public: 
		virtual INT32  OnClose( void );    
		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);  

	public:
		INT32   Update( void );   
		INT32   UpdatePing( void );   
		void    SetLastRecvPingTime( INT64 ullLstRecfPing = 0);

	protected:
		INT64        m_ullLastRecvPing; 
		RpcManager * m_pRpcManager; 
	};
}

#endif
