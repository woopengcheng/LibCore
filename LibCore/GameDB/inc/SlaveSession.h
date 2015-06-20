#ifndef __game_db_slave_session_h__
#define __game_db_slave_session_h__ 
#include "NetLib/inc/ClientSession.h"

namespace GameDB 
{   
	class Database;

	struct SDBSlaveInfo
	{
		std::string  strDBName;
		std::string  strDir;
		std::string  strUser;
		std::string  strPswd;
		Database   * pDB;

		SDBSlaveInfo()
			: strDBName("")
			, strDir("")
			, strUser("")
			, strPswd("")
			, pDB(NULL)
		{

		}
	};

	class DLL_EXPORT SlaveSession : public Net::ClientSession
	{
	public:
		SlaveSession(SDBSlaveInfo * pInfo , const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID = -1 , INT32 nNetState = 0 , Net::NetSocket socket = -1 , INT64 llTimeout = 0 , BOOL bReconnect = TRUE ) 
			: ClientSession(pAddress , usSocktPort , pRemoteName , nSessionID , nNetState , socket , llTimeout , bReconnect) 
		{
			if (pInfo)
			{
				m_objSlaveInfo = *pInfo;
			}
		}
		virtual ~SlaveSession(){}

	public:
		virtual    INT32    Cleanup() 
		{  
			return ClientSession::Cleanup();	
		} 
		
	public:
		void     SetSlaveInfo(const SDBSlaveInfo & val) { m_objSlaveInfo = val; }
		SDBSlaveInfo	GetSlaveInfo( void ) const { return m_objSlaveInfo; }

	private:
		SDBSlaveInfo m_objSlaveInfo;
	}; 

}

#endif
