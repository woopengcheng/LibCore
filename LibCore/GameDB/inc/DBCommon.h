#ifndef __database_common_h__ 
#define __database_common_h__
#include "Common/inc/Parameters.h" 
#include "leveldb/db.h"
#include "leveldb/iterator.h"
#include "leveldb/comparator.h"
#include "Common/CUtil.h"
#include "Common/Chunk.h"
#include "Common/StringEx.h"

const size_t MAX_DB_TEMP_BUFFER_LENGTH = (64*1024*1024);
#pragma warning(disable:4275)

#define g_szSystemDatabase (".sys")
#define g_szSystemUserTable ("user")

namespace GameDB
{	
//	extern DLL_IMPORT const char *  g_szSystemDatabase;
//	extern DLL_IMPORT const char *  g_szSystemUserTable;

	typedef leveldb::Slice			 Slice;
	typedef leveldb::Status			 Status;
	typedef leveldb::WriteBatch		 WriteBatch;  
	typedef CUtil::Parameters			 Parameters; 
	class DLL_EXPORT Options : public leveldb::Options{};
	 
	extern DLL_EXPORT CUtil::CStream & operator << (CUtil::CStream& cs,const leveldb::Slice& c); 

	typedef CUtil::Chunk  Chunk; 

	typedef std::vector<leveldb::Slice> CollectionSlicesT;
	typedef std::map<std::string , leveldb::Slice> CollectionKeyValsT;
	typedef std::vector<std::string>	CollectionBuffersT;

	//5 ***************************请不要轻易改动,否则数据库无效************************************
	const UINT32   MAX_KEY_LENGTH = 1024;    //5 key的最大长度为1024

	const char     SEPARATOR_FIRST = '!';    //5 第一个分隔符用于分割类型
	const char     SEPARATOR_FIRST_R = '@';  //5 zset时代表的是反向保存的标记.
	const char     SEPARATOR_SECOND = '#';   //5 第2个分隔符用于分割表名
	const char     SEPARATOR_THRID = '$';    //5 第3个分隔符用于分割key

	const char     PREFIX_HASHTABLE = 'h';   //5 hashtable数据结构类型前缀
	const char     PREFIX_ZSET = 'z';		 //5 zset数据结构类型前缀
	const char     PREFIX_ZSET_SCORE = 's';  //5 zset记录score的数据结构类型前缀
	const char     PREFIX_KEY_VALUE = 'k';   //5 单纯记录key,value的数据结构类型前缀
	 
	extern const char  *  g_szGlobalHashtableSizeName;  //5 用于hash内部存储每个表的数量用的.
	//5 ***************************************************************

	//5 ***************************宏定义数值************************************
#define  DEFAULT_STACKCHUNK CUtil::StackChunk<MAX_KEY_LENGTH>


	//5 ***************************************************************


	static void fnCustomCacheDeleter(const Slice& objKey,void* pValue) 
	{
		std::string * p = (std::string*)pValue;
		delete p;
	}
}


#endif