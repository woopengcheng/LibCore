#ifndef __database_common_h__ 
#define __database_common_h__
#include "Common/Common.h" 
#include "leveldb/db.h"
#include "leveldb/iterator.h"
#include "leveldb/comparator.h"


namespace GameDB
{
typedef leveldb::Status Status;
typedef leveldb::Slice  Slice;

static void fnCustomCacheDeleter(const Slice& objKey,void* pValue)
{
	std::string * p = (std::string*)pValue;
	delete p;
}

}


#endif