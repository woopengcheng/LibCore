#ifndef __gamedb_orm_helper_h__
#define __gamedb_orm_helper_h__
#include "GameDB/inc/DBCommon.h"
#include "GameDB/inc/Orm.h"

namespace GameDB
{
	//5 特殊用途,还不知道做什么.
	enum EORM_MASK
	{
		ORM_NONE = 0,
	};

	enum EORM_OPERATION
	{
		OPERATION_INSERT,
		OPERATION_UPDATE,
		OPERATION_DELETE,

		OPERATION_MAX,
	};
	class OrmHelper
	{
	public:
		static INT32 OrmInsert(GameDB::Orm * obj , EORM_MASK objMask = ORM_NONE);
		static INT32 OrmUpdate(GameDB::Orm * obj , EORM_MASK objMask = ORM_NONE);
		static INT32 OrmDelete(GameDB::Orm * obj , EORM_MASK objMask = ORM_NONE);
	
	protected:
		static INT32 Commit(GameDB::Orm * obj , EORM_OPERATION objOper);
	};
}


#endif