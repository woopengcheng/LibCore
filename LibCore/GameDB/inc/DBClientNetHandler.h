#ifndef __gamedb_db_client_net_handler_h__
#define __gamedb_db_client_net_handler_h__  
#include "NetLib/inc/NetHandlerCommonClient.h"
#include "NetLib/inc/INetReactor.h"
#include "NetLib/inc/ISession.h"

namespace GameDB
{     
	class DLL_EXPORT  DBClientNetHandler : public Net::NetHandlerCommonClient 
	{ 
	public:
		DBClientNetHandler( Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~DBClientNetHandler();

	public: 
		virtual INT32  Init( const char* ip,int port );
		virtual INT32  Cleanup( void );
		virtual INT32  Update(void);
		virtual INT32  OnClose( void );   
		virtual INT32  OnReconnect( void );
		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength); 
		 
	};    
	 
	DECLARE_BOOST_POINTERS(DBClientNetHandler); 
}

#endif
