#ifndef __gamedb_user_auth_h__
#define __gamedb_user_auth_h__ 
#include "GameDB/inc/User.h"

namespace GameDB
{ 

	class DLL_EXPORT UserAuth 
	{ 
	public:
		UserAuth(const User & objUserInfos);
		virtual ~UserAuth(); 

	public:
		bool CheckSysPermission(); 

	protected:
		User m_objUserInfo; 
	};

}


#endif
