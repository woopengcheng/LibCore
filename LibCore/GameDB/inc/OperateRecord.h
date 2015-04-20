#ifndef __gamedb_operate_recode_h__
#define __gamedb_operate_recode_h__ 
#include "GameDB/inc/DatabaseCommon.h"

namespace GameDB
{ 
	class OperateRecord
	{
	public:
		static const INT32 OPERATE_RECODE_INSERT = 0;
		static const INT32 OPERATE_RECODE_DELETE = 1;
	public:
		void    Insert(const Slice& dbKey,const Slice& dbValue);
		void	Delete(const Slice& dbKey);
	private:
	};
}

#endif
