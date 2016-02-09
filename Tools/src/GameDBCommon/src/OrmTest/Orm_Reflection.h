/************************************
FileName	:	Orm_Reflection.h
Author		:	generate by tools
HostName	:	devuser-PC
IP			:	10.236.41.54
Version		:	0.0.1
Date		:	2016-02-03 17:05:36
Description	:	针对slave的类产生反射.
************************************/
#ifndef __Orm_Orm__feflection_h__
#define __Orm_Orm__feflection_h__
#include "GameDB/inc/Orm.h"

namespace Orm
{
	extern const char * cst_slaves_of_TestSlave[];
	extern INT64 cst_slaves_hash_of_TestSlave[];

	extern GameDB::Orm * CreateObject(bson::bo & obj);
	extern GameDB::Orm * CreateObject(const char * data,size_t size);
	
}//Orm

#endif
