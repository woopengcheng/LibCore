#ifndef __gamedb_user_auth_h__
#define __gamedb_user_auth_h__ 
#include "GameDB/inc/User.h"

namespace GameDB
{ 

	class DLL_EXPORT UserAuth 
	{ 
	public:
		UserAuth(){}
		UserAuth(const User & objUserInfos);
		virtual ~UserAuth(); 

	public:
		bool CheckSysPermission(); 
		void SetUserInfo(const User & user){m_objUserInfo = user;}
		User GetUserInfo(){ return m_objUserInfo;}

	protected:
		User m_objUserInfo; 
	};

}


#endif
