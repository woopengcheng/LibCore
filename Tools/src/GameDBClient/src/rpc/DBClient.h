#ifndef __client_dbclient_h__
#define __client_dbclient_h__   
#include "GameDB/inc/DBClientInterface.h"

namespace Client
{  
	class  DBClient : public GameDB::DBClientInterface
	{ 
	public:
		DBClient(void)
		{ 
		}
		virtual ~DBClient(void){} 

	public:
		static DBClient & GetInstance()
		{
			static DBClient m_sRpcInterface;
			return m_sRpcInterface;
		} 
		virtual CErrno  Init(Json::Value & conf)
		{ 
			return DBClientInterface::Init(conf);
		}
		virtual CErrno  Cleanup(void)
		{
			return DBClientInterface::Cleanup();
		}

	public: 
		virtual void OnRegisterRpcs(void); 
	};  
	 
} 

#endif