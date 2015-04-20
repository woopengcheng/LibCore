#include "GameDB/inc/HashTable.h"


namespace GameDB
{ 
	void HashTable::EncodeKey(const Slice& table,const Slice& key,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk)
	{  
		sChunk.Pushback((void*)&PREFIX_HASHTABLE,1);
		sChunk.Pushback((void*)&SEPARATOR_FIRST,1);
		sChunk.Pushback((void*)(table.data()),table.size());
		sChunk.Pushback((void*)&SEPARATOR_SECOND,1);
		sChunk.Pushback((void*)(key.data()),key.size());

		outEncodedKey = Slice((const char *)(sChunk.Begin()) , sChunk.GetDataLen());
	}

	bool HashTable::DecodeKey(const Slice& encodedName,const Slice& name,Slice& key)
	{
		const char* pFullName = encodedName.data();
		size_t unFullNameSize = encodedName.size();

		size_t separatorSecondPos = name.size() + 1 + 1; //5 传递进来的表名+2个分隔符就是Key开始的位置.

		if(pFullName[0] == PREFIX_HASHTABLE 
			&& pFullName[1] == SEPARATOR_FIRST
			&& unFullNameSize > separatorSecondPos
			&& pFullName[separatorSecondPos] == SEPARATOR_SECOND
			&& memcmp(&pFullName[2],name.data(),name.size()) == 0)
		{
			key = Slice(&pFullName[separatorSecondPos+1],unFullNameSize - separatorSecondPos - 1);

			return true;
		}
		return false; 
	}

	void HashTable::HCount_EncodeKey(const Slice& key,Slice & outKey)
	{
		Slice	encodedKey;
		DEFAULT_STACKCHUNK stackChunk;

		EncodeKey(g_szGlobalHashtableSizeName , key , encodedKey , stackChunk);
		
		outKey = encodedKey;
	}

	bool HashTable::HCount_DecodeKey(const Slice& dbFullKey,Slice& hKey)
	{
		return DecodeKey(dbFullKey,g_szGlobalHashtableSizeName,hKey); 

	}

	void HashTable::HCount_Initial(Database &db,const Slice & countkey,INT64 & llOldCount)
	{
		std::string strOldCount;
		leveldb::Status status = db->QuickGet(countkey,&strOldCount);
		if(status.ok())
			llOldCount = *reinterpret_cast<const int64*>(strOldCount.c_str());
		else
			llOldCount = 0;
	}

	void HashTable::HCount_SaveToDB(const Slice & countKey,INT64 countVal,WriteBatch& batch,Operate & or)
	{
		batch.Put(countKey , countVal);
		or.GetOperateRecord()->Insert(countKey , Slice((const char *)&countVal , sizeof(countVal));
	}

}