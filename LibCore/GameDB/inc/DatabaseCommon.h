#ifndef __database_common_h__ 
#define __database_common_h__
#include "Common/Common.h" 
#include "leveldb/db.h"
#include "leveldb/iterator.h"
#include "leveldb/comparator.h"

const size_t MAX_DB_TEMP_BUFFER_LENGTH = (64*1024*1024);

namespace GameDB
{
	static const char * g_szSystemDatabase = "SystemDatabase";

typedef leveldb::Status Status;
typedef leveldb::Slice  Slice;

static void fnCustomCacheDeleter(const Slice& objKey,void* pValue)
{
	std::string * p = (std::string*)pValue;
	delete p;
}

}


#endif