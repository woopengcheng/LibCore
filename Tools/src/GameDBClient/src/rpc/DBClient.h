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

	public: 
		virtual void OnRegisterRpcs(void); 
	};  
	 
} 

#endif