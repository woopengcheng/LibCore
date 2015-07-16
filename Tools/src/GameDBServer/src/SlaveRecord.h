#ifndef __server_slave_record_h__
#define __server_slave_record_h__ 
#include "GameDB/inc/UserAuth.h"

namespace Server
{  
	class SlaveRecord
	{ 
	public:
		SlaveRecord(MasterHandler * pHandler)
			: m_pMaster(pHandler)
		{
		}

		~SlaveRecord()
		{
			 
		}

	public:
		void			SetDBName(std::string strName){ m_strDBName = strName; }
		std::string		GetDBName( ){ return m_strDBName; }
		void			SetUserAuth(GameDB::UserAuth & objUserInfo){ m_objAuthInfo = objUserInfo; }
		GameDB::UserAuth	GetUserAuth( ){ return m_objAuthInfo; }

	private:
		MasterHandler *  m_pMaster;
		std::string		 m_strDBName;
		GameDB::UserAuth m_objAuthInfo;		
	}; 
}

#endif