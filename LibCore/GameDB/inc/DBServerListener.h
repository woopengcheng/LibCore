#ifndef __gamedb_db_server_listener_h__
#define __gamedb_db_server_listener_h__  
#include "GameDB/inc/DatabaseCommon.h"
#include "NetLib/inc/INetReactor.h"
#include "NetLib/inc/ServerSession.h"
#include "NetLib/inc/NetHandlerListener.h" 
 
namespace GameDB 
{  
	class DBServer;
	class INetReactor;

	class DLL_EXPORT DBServerListener : public Net::NetHandlerListener
	{
	public:
		DBServerListener( DBServer * pDBServer , Net::INetReactor * pNetReactor , Net::ISession * pSession)
			: Net::NetHandlerListener(pNetReactor , pSession)
			, m_pDBServer(pDBServer)
		{

		}
		virtual ~DBServerListener( void ){}  

	public: 
		virtual void   OnAccept(SOCKET socket , sockaddr_in * addr); 

	private:
		DBServer * m_pDBServer;
	}; 
	DECLARE_BOOST_POINTERS( DBServerListener ); 
}

#endif
