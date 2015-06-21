#include "GameDB/inc/HashTable.h"
#include "MsgLib/inc/GenMsgHelper.h" 

namespace GameDB
{
	const char  *  g_szGlobalHashtableSizeName = "__hsize__";

	void HashTable::EncodeKey(const Slice& table,const Slice& key,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk)
	{  
		sChunk.Pushback((void*)&PREFIX_HASHTABLE,1);
		sChunk.Pushback((void*)&SEPARATOR_FIRST,1);
		sChunk.Pushback((void*)(table.data()),(UINT32)table.size());
		sChunk.Pushback((void*)&SEPARATOR_SECOND,1);
		sChunk.Pushback((void*)(key.data()),(UINT32)key.size());

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

	void HashTable::HCount_Initial(Database &db,const Slice & countKey,INT64 & llOldCount)
	{
		std::string strOldCount;
		Status status = db.QuickGet(countKey,strOldCount);
		if(status.ok())
			llOldCount = *reinterpret_cast<const INT64*>(strOldCount.c_str());
		else
			llOldCount = 0;
	}

	bool HashTable::HCount_IncrIfNonExists(Database &db,const Slice& dbKey,INT64& size)
	{
		std::string oldVal;
		Status status = db.QuickGet(dbKey,oldVal);
		if(status.IsNotFound())
		{
			++size;
			return true;
		}
		return false;

	}

	bool HashTable::HCount_DecrIfExists(Database &db,const Slice& dbKey,INT64& size)
	{
		std::string oldVal;
		Status status = db.QuickGet(dbKey,oldVal);
		if(status.ok())
		{
			--size;
			return true;
		}
		return false;

	}

	void HashTable::HCount_SaveToDB(const Slice & countKey,INT64 countVal,WriteBatch& batch,Operate & or)
	{
		batch.Put(countKey , Slice((const char *)&countVal , sizeof(countVal)));
		or.GetOperateRecord()->Insert(countKey , Slice((const char *)&countVal , sizeof(countVal)));
	}

	HashTable::CHECK_RESULT HashTable::CheckExists(Database &db,const Slice& dbKey,const Slice& newValue)
	{
		std::string strOldValue;
		leveldb::Status status = db.QuickGet(dbKey,strOldValue);
		if(status.IsNotFound())
			return CHECK_RESULT_NOTEXISTS;
		if(!status.ok())
			return CHECK_RESULT_ERROR;

		if(newValue.size() == strOldValue.length() && memcmp(newValue.data(),strOldValue.c_str(),strOldValue.length()) == 0)
			return CHECK_RESULT_SAME;

		return CHECK_RESULT_EXISTS; 
	}

	void HashTable::HSet(Database &db,Operate & oper,const Slice& table,const Slice& key,const Slice& val)
	{
		DEFAULT_STACKCHUNK sc;
		Slice encodedKey; 
		leveldb::Status status;
		 
		EncodeKey(table,key,encodedKey , sc);

		INT64 sizeVal = -1;
		Slice sizeKey;
		{
			HCount_EncodeKey(table,sizeKey);
			HCount_Initial(db,sizeKey,sizeVal);
		}

		switch(CheckExists(db,encodedKey,val))
		{
		case CHECK_RESULT_EXISTS:
			break;
		case CHECK_RESULT_NOTEXISTS:
			++sizeVal;
			break;
		case CHECK_RESULT_SAME:
			{
				oper.SetErrorCode(ERR_SUCCESS);
				return ;
			}
			break;
		}

		WriteBatch batch;
		batch.Put(encodedKey,val);
		HCount_SaveToDB(sizeKey,sizeVal,batch,oper);

		status = db.QuickWrite(&batch);

		oper.GetOperateRecord()->Insert(encodedKey,val);
		oper.SetErrorCode(status); 
	}

	void HashTable::HSetNX(Database &db,Operate & oper,const Slice& table,const Slice& key,const Slice& val)
	{
		DEFAULT_STACKCHUNK sc;
		Slice	encodedKey; 
		leveldb::Status status;

		EncodeKey(table,key,encodedKey , sc);

		INT64 sizeVal = -1;
		Slice sizeKey;
		{
			HCount_EncodeKey(table,sizeKey);
			HCount_Initial(db,sizeKey,sizeVal);
			if(!HCount_IncrIfNonExists(db,encodedKey,sizeVal))
			{
				oper.SetErrorCode(ERR_HAS_EXISTS);
				return ;
			}
		}

		leveldb::WriteBatch batch;
		batch.Put(encodedKey,val);
		HCount_SaveToDB(sizeKey,sizeVal,batch,oper);

		status = db.QuickWrite(&batch);

		//result.MutableOplog()->Put(encodedKey,val);  //5 这里可能会有问题.
		oper.SetErrorCode(status);

	}

	void HashTable::HSetOW(Database &db,Operate& oper,const Slice& table,const Slice& key,const Slice& val)
	{
		DEFAULT_STACKCHUNK sc;
		Slice	encodedKey; 
		leveldb::Status status;

		EncodeKey(table,key,encodedKey , sc);

		switch(CheckExists(db,encodedKey,val))
		{
		case CHECK_RESULT_SAME:
			{
				oper.SetErrorCode(ERR_SUCCESS);
				return ;
			};
		case CHECK_RESULT_NOTEXISTS:
			{
				oper.SetErrorCode(ERR_NOTFOUND); 
				return ;
			}
		} 

		status = db.QuickWrite(encodedKey,val);

		oper.GetOperateRecord()->Insert(encodedKey,val);  
		oper.SetErrorCode(status); 
	}

	void HashTable::HGet(Database &db,Operate& oper,const Slice& table,const Slice& key)
	{
		DEFAULT_STACKCHUNK sc;
		Slice	encodedKey;
		leveldb::Status status;

		EncodeKey(table , key , encodedKey , sc);

		std::string strValue; 
		status = db.QuickGet(encodedKey,strValue); 
		oper.GetStream() << strValue;
		Msg::GenMsgHelper::GenMsgParams(oper.GetParamters() , strValue);

		oper.SetErrorCode(status); 
	}

}