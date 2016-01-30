#ifndef __game_db_slave_session_h__
#define __game_db_slave_session_h__ 
#include "NetLib/inc/ClientSession.h"

namespace GameDB 
{   
	class Database;

	struct SDBMasterInfo
	{
		std::string  strDBName;  

		SDBMasterInfo()
			: strDBName("") 
		{

		}
	};
/*
	class DLL_EXPORT MasterSession : public Net::ClientSession
	{
	public:
		MasterSession(SDBMasterInfo * pInfo , const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID = -1 , INT32 nNetState = 0 , Net::NetSocket socket = -1 , INT64 llTimeout = 0 , BOOL bReconnect = TRUE ) 
			: ClientSession(pAddress , usSocktPort , pRemoteName , nSessionID , nNetState , socket , llTimeout , bReconnect) 
		{
			if (pInfo)
			{
				m_objMasterInfo = *pInfo;
			}
		}
		virtual ~MasterSession(){}

	public:
		virtual    CErrno    Cleanup() 
		{  
			return ClientSession::Cleanup();	
		} 

	public:
		void     SetMasterInfo(const SDBMasterInfo & val) { m_objMasterInfo = val; }
		SDBMasterInfo	GetMasterInfo( void ) const { return m_objMasterInfo; }

	private:
		SDBMasterInfo m_objMasterInfo;
	}; */

}

#endif
