#include "GameDB/inc/DBServerListener.h"
#include "GameDB/inc/DBServer.h"

namespace GameDB
{
	void DBServerListener::OnAccept(SOCKET socket , sockaddr_in * addr)
	{
		if (m_pDBServer)
		{
			m_pDBServer->CreateNetHandler(socket , addr);
		}
	}


}

