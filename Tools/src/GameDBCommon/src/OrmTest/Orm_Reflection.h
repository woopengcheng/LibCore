/************************************
FileName	:	Orm_Reflection.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.104
Version		:	0.0.1
Date		:	2015-08-23 22:17:08
Description	:	���slave�����������.
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
