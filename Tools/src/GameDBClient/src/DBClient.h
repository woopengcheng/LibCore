#ifndef __client_db_client_h__
#define __client_db_client_h__

#include "GameDB/inc/DBClientInterface.h"


namespace  Client
{
	class DBClient : public GameDB::DBClientInterface
	{
	public:
		DBClient( ):GameDB::DBClientInterface(){}
		virtual ~DBClient(void){}
	public:
		static DBClient & GetInstance()
		{
			static DBClient m_sRpcInterface;
			return m_sRpcInterface;
		} 
	private:
	};
}

#endif
