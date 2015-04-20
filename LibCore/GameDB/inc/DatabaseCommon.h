#ifndef __database_common_h__ 
#define __database_common_h__
#include "Common/Common.h" 
#include "leveldb/db.h"
#include "leveldb/iterator.h"
#include "leveldb/comparator.h"
#include "Common/LibCore.h"
#include "Common/Chunk.h"

const size_t MAX_DB_TEMP_BUFFER_LENGTH = (64*1024*1024);

namespace GameDB
{	

	static const char * g_szSystemDatabase = "SystemDatabase";

	typedef leveldb::Status		 Status;
	typedef leveldb::Slice		 Slice;
	typedef leveldb::WriteBatch  WriteBatch;

	typedef LibCore::Chunk  Chunk; 

	typedef std::vector<leveldb::Slice> CollectionSlicesT;
	typedef std::vector<std::string>	CollectionBuffersT;

	//5 ***************************�벻Ҫ���׸Ķ�,�������ݿ���Ч************************************
	const UINT32   MAX_KEY_LENGTH = 1024;    //5 key����󳤶�Ϊ1024

	const char     SEPARATOR_FIRST = '!';    //5 ��һ���ָ������ڷָ�����
	const char     SEPARATOR_FIRST_R = '@';  //5 zsetʱ������Ƿ��򱣴�ı��.
	const char     SEPARATOR_SECOND = '#';   //5 ��2���ָ������ڷָ����
	const char     SEPARATOR_THRID = '$';    //5 ��3���ָ������ڷָ�key

	const char     PREFIX_HASHTABLE = 'h';   //5 hashtable���ݽṹ����ǰ׺
	const char     PREFIX_ZSET = 'z';		 //5 zset���ݽṹ����ǰ׺
	const char     PREFIX_ZSET_SCORE = 's';  //5 zset��¼score�����ݽṹ����ǰ׺
	const char     PREFIX_KEY_VALUE = 'k';   //5 ������¼key,value�����ݽṹ����ǰ׺
	 
	extern const char  *  g_szGlobalHashtableSizeName;  //5 ����hash�ڲ��洢ÿ����������õ�.
	//5 ***************************************************************

	//5 ***************************�궨����ֵ************************************
#define  DEFAULT_STACKCHUNK LibCore::StackChunk<MAX_KEY_LENGTH>


	//5 ***************************************************************


	static void fnCustomCacheDeleter(const Slice& objKey,void* pValue) 
	{
		std::string * p = (std::string*)pValue;
		delete p;
	}
}


#endif