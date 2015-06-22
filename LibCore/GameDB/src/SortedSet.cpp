#include "GameDB/inc/SortedSet.h"
#include "MsgLib/inc/GenMsgHelper.h" 

namespace GameDB
{
	const char  *  g_szGlobalSortedSetSizeName = "__hsize__";

	void SortedSet::EncodeKey(const Slice& table,const Slice& key,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk)
	{  
		sChunk.Pushback((void*)&PREFIX_ZSET,1);
		sChunk.Pushback((void*)&SEPARATOR_FIRST,1);
		sChunk.Pushback((void*)(table.data()),(UINT32)table.size());
		sChunk.Pushback((void*)&SEPARATOR_SECOND,1);
		sChunk.Pushback((void*)(key.data()),(UINT32)key.size());

		outEncodedKey = Slice((const char *)(sChunk.Begin()) , sChunk.GetDataLen());
	}

	bool SortedSet::DecodeKey(const Slice& encodedName,const Slice& name,Slice& key)
	{
		const char* pFullName = encodedName.data();
		size_t unFullNameSize = encodedName.size();

		size_t separatorSecondPos = name.size() + 1 + 1; //5 传递进来的表名+2个分隔符就是Key开始的位置.

		if(pFullName[0] == PREFIX_ZSET 
			&& pFullName[1] == SEPARATOR_FIRST 
			&& pFullName[separatorSecondPos] == SEPARATOR_SECOND
			&& memcmp(&pFullName[2],name.data(),name.size()) == 0)
		{
			key = Slice(&pFullName[separatorSecondPos+1],unFullNameSize - separatorSecondPos - 1);

			return true;
		}
		return false; 
	}

	void SortedSet::EncodeScoreKey(const Slice& table,const Slice& key , INT64 score,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk)
	{
		sChunk.Pushback((void*)&PREFIX_ZSET_SCORE,1);
		sChunk.Pushback((void*)&SEPARATOR_FIRST,1);
		sChunk.Pushback((void*)(table.data()),(UINT32)table.size());
		sChunk.Pushback((void*)&SEPARATOR_SECOND,1);
		sChunk.Pushback((void*)&(score),sizeof(score));
		sChunk.Pushback((void*)&SEPARATOR_THRID,1);
		sChunk.Pushback((void*)(key.data()),(UINT32)key.size());

		outEncodedKey = Slice((const char *)(sChunk.Begin()) , sChunk.GetDataLen());
	}

	bool SortedSet::DecodeScoreKey(const Slice& dbKeyData,const Slice& table,Slice& outkey,INT64& outscore)
	{
		const char* pFullName = dbKeyData.data();
		size_t unFullNameSize = dbKeyData.size();

		size_t separator2_pos = 1 + table.size() + 1; // HM_PREFIX + name + SEPARATOR1
		size_t score_pos = 1 + 1 + table.size() + 1; // HM_PREFIX + SEPARATOR1 + name + SEPARATOR2
		size_t separator3_pos = 1 + 1 + table.size() + 1 + sizeof(INT64); // HM_PREFIX + SEPARATOR1 + name + SEPARATOR2 + int64

		if(pFullName[0] == PREFIX_ZSET_SCORE
			&& unFullNameSize > separator2_pos
			&& unFullNameSize > score_pos
			&& unFullNameSize > separator3_pos
			&& pFullName[1] == SEPARATOR_FIRST
			&& pFullName[separator2_pos] == SEPARATOR_SECOND
			&& pFullName[separator3_pos] == SEPARATOR_THRID
			&& memcmp(&pFullName[2],table.data(),table.size()) == 0
			)
		{
			outscore = *reinterpret_cast<const INT64*>(&pFullName[score_pos]);
			outkey = Slice(&pFullName[separator3_pos+1],unFullNameSize - separator3_pos - 1);
			return true;
		}

		return false; 
	}

	void SortedSet::EncodeRScoreKey(const Slice& table,const Slice& key , INT64 score,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk)
	{
		sChunk.Pushback((void*)&PREFIX_ZSET_SCORE,1);
		sChunk.Pushback((void*)&SEPARATOR_FIRST_R,1);
		sChunk.Pushback((void*)(table.data()),(UINT32)table.size());
		sChunk.Pushback((void*)&SEPARATOR_SECOND,1);
		sChunk.Pushback((void*)&(score),sizeof(score));
		sChunk.Pushback((void*)&SEPARATOR_THRID,1);
		sChunk.Pushback((void*)(key.data()),(UINT32)key.size());

		outEncodedKey = Slice((const char *)(sChunk.Begin()) , sChunk.GetDataLen());
	}

	bool SortedSet::DecodeRScoreKey(const Slice& dbKeyData,const Slice& table,Slice& outkey,INT64& outscore)
	{
		const char* pFullName = dbKeyData.data();
		size_t unFullNameSize = dbKeyData.size();

		size_t separator2_pos = 1 + table.size() + 1; // HM_PREFIX + name + SEPARATOR1
		size_t score_pos = 1 + 1 + table.size() + 1; // HM_PREFIX + SEPARATOR1 + name + SEPARATOR2
		size_t separator3_pos = 1 + 1 + table.size() + 1 + sizeof(INT64); // HM_PREFIX + SEPARATOR1 + name + SEPARATOR2 + int64

		if(pFullName[0] == PREFIX_ZSET_SCORE
			&& unFullNameSize > separator2_pos
			&& unFullNameSize > score_pos
			&& unFullNameSize > separator3_pos
			&& pFullName[1] == SEPARATOR_FIRST_R
			&& pFullName[separator2_pos] == SEPARATOR_SECOND
			&& pFullName[separator3_pos] == SEPARATOR_THRID
			&& memcmp(&pFullName[2],table.data(),table.size()) == 0
			)
		{
			outscore = *reinterpret_cast<const INT64*>(&pFullName[score_pos]);
			outkey = Slice(&pFullName[separator3_pos+1],unFullNameSize - separator3_pos - 1);
			return true;
		}

		return false; 

	}

	void SortedSet::ZCount_EncodeKey(const Slice& key, Slice & outKey)
	{
		Slice	encodedKey;
		DEFAULT_STACKCHUNK stackChunk;

		EncodeKey(g_szGlobalSortedSetSizeName , key , encodedKey , stackChunk);

		outKey = encodedKey; 
	}

	bool SortedSet::ZCount_DecodeKey(const Slice& dbKeyData,Slice& outKey)
	{
		return DecodeKey(dbKeyData,g_szGlobalSortedSetSizeName,outKey); 
	}

	void SortedSet::ZCount_Initial(Database &db,const Slice & countKey,INT64 & llOldCount)
	{
		std::string strOldCount;
		Status status = db.QuickGet(countKey,strOldCount);
		if(status.ok())
			llOldCount = *reinterpret_cast<const INT64*>(strOldCount.c_str());
		else
			llOldCount = 0;
	}

	bool SortedSet::ZCount_IncrIfNonExists(Database &db,const Slice& dbKey,INT64& size)
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

	bool SortedSet::ZCount_DecrIfExists(Database &db,const Slice& dbKey,INT64& size)
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

	void SortedSet::ZCount_SaveToDB(const Slice & countKey,INT64 countVal,WriteBatch& batch,Operate & or)
	{
		batch.Put(countKey , Slice((const char *)&countVal , sizeof(countVal)));
		or.GetOperateRecord()->Insert(countKey , Slice((const char *)&countVal , sizeof(countVal)));
	}

	void SortedSet::ZSet(Database &db,Operate& oper,const Slice& table,const Slice& key , INT64 llScore)
	{
		DEFAULT_STACKCHUNK sc;
		Slice encodedKey;  

		EncodeKey(table,key,encodedKey , sc);

		INT64 sizeVal = -1;
		Slice sizeKey;
		{
			ZCount_EncodeKey(table,sizeKey);
			ZCount_Initial(db,sizeKey,sizeVal);
		}

		leveldb::Status objStatus;
		leveldb::WriteBatch batch;
		{
			std::string val;
			objStatus = db.QuickGet(encodedKey,val);
			if (objStatus.ok())
			{
				if (val.length() != sizeof(INT64))
				{
					oper.SetErrorCode(ERR_INVALID_DATA);
					return ;
				}

				DEFAULT_STACKCHUNK sc_core;
				DEFAULT_STACKCHUNK sc_coreR;
				Slice scoreKey,scoreKeyR;
				INT64 oldScore = *reinterpret_cast<const INT64*>(val.c_str());
				EncodeScoreKey(table , key , oldScore , scoreKey , sc_core);
				EncodeRScoreKey(table , key , oldScore , scoreKeyR , sc_coreR);

				batch.Delete(scoreKey);
				batch.Delete(scoreKeyR);

				oper.GetOperateRecord()->Delete(scoreKey);
				oper.GetOperateRecord()->Delete(scoreKeyR);
			}
			else if (objStatus.IsNotFound())
			{
				++sizeVal;
			}
			else
			{
				oper.SetErrorCode(objStatus);
				return ;
			}
		}

		DEFAULT_STACKCHUNK sc_core , sc_coreR; 
		Slice scoreKey,scoreKeyR;
		Slice scoreval((const char*)&llScore,sizeof(INT64)); 

		EncodeScoreKey(table , key , llScore , scoreKey ,sc_core);
		EncodeRScoreKey(table , key , llScore , scoreKeyR , sc_coreR);
		batch.Put(encodedKey , scoreval);
		batch.Put(scoreKey , scoreval);
		batch.Put(scoreKeyR , scoreval);

		oper.GetOperateRecord()->Insert(encodedKey , scoreval);
		oper.GetOperateRecord()->Insert(scoreKey , scoreval);
		oper.GetOperateRecord()->Insert(scoreKeyR , scoreval);

		ZCount_SaveToDB(sizeKey , sizeVal , batch , oper);

		objStatus = db.QuickWrite(&batch);

		oper.SetErrorCode(objStatus);
	} 

	void SortedSet::ZGet(Database &db,Operate & oper,const Slice& table,const Slice& key , INT64 & llScore)
	{ 
		DEFAULT_STACKCHUNK sc;
		Slice encodedKey , scoreKey,scoreKeyR;
		leveldb::Status status;

		EncodeKey(table,key,encodedKey , sc);

		std::string strValue;
		status = db.QuickGet(encodedKey , strValue);
		if (status.ok())
		{
			if (strValue.length() != sizeof(INT64))
			{
				oper.SetErrorCode(ERR_INVALID_DATA);
				return ;
			}

			llScore = *reinterpret_cast<const INT64*>(strValue.c_str());
			oper.GetStream() << llScore;
			oper.SetErrorCode(ERR_SUCCESS);
		}
		else
		{
			oper.SetErrorCode(ERR_FAILURE);
		}
	}

	void SortedSet::ZRTop(Database &db,Operate & oper,const Slice& table,INT64 llStart , INT64 llEnd , INT64 llLimit)
	{
		DEFAULT_STACKCHUNK sc;
		Slice scoreKey;  
		leveldb::Status status;

		EncodeRScoreKey(table,"",std::numeric_limits<INT64>::max(),scoreKey , sc);

		if (llEnd - llStart <= 0 && llLimit == 0)
		{
			oper.SetErrorCode(ERR_FAILURE);
			return ;
		}

		//5 优先使用排序
		if (llEnd != 0)
		{
			llLimit = llEnd - llStart; 
		}

		LibCore::CStream cs;
		INT64 llCount = 0 , llCSCount = 0;
		leveldb::Iterator* iter = db.GetLevelDB()->NewIterator(leveldb::ReadOptions());
		iter->Seek(scoreKey);
		while(iter->Valid() && llLimit > 0)
		{
			++ llCount;//5 默认是从第一名开始,不是第0名开始.
			if (llCount <= llStart)
			{
				continue;
			}
			Slice dbData = iter->key();
			Slice val = iter->value();
			Slice key;
			INT64 llScore = 0;

			if(!DecodeRScoreKey(dbData,table,key,llScore))
				break;

			++llCSCount;
			--llLimit;
			cs << std::string(key.data(),key.size()) << llScore; 

			iter->Next();
		}

		oper.GetOperateReturns().GetStream() << llCSCount ; 
		oper.GetOperateReturns().GetStream().Pushback(cs.Begin() , cs.GetDataLen()) ;

		delete iter;

		oper.SetErrorCode(ERR_SUCCESS);
	}

	void SortedSet::ZTop(Database &db,Operate & oper,const Slice& table,INT64 llStart , INT64 llEnd , INT64 llLimit)
	{
		DEFAULT_STACKCHUNK sc;
		Slice scoreKey;  
		leveldb::Status status;

		EncodeScoreKey(table,"",std::numeric_limits<INT64>::min(),scoreKey , sc);

		if (llEnd - llStart <= 0 && llLimit == 0)
		{
			oper.SetErrorCode(ERR_FAILURE);
			return ;
		}

		//5 优先使用排序
		if (llEnd != 0)
		{
			llLimit = llEnd - llStart; 
		}

		LibCore::CStream cs;
		INT64 llCount = 0 , llCSCount = 0;
		leveldb::Iterator* iter = db.GetLevelDB()->NewIterator(leveldb::ReadOptions());
		iter->Seek(scoreKey);
		while(iter->Valid() && llLimit > 0)
		{
			++ llCount;//5 默认是从第一名开始,不是第0名开始.
			if (llCount <= llStart)
			{
				continue;
			}
			Slice dbData = iter->key();
			Slice val = iter->value();
			Slice key;
			INT64 llScore = 0;

			if(!DecodeScoreKey(dbData,table,key,llScore))
				break;

			++llCSCount;
			--llLimit;
			cs << std::string(key.data(),key.size()) << llScore; 

			iter->Next();
		}

		oper.GetOperateReturns().GetStream() << llCSCount ; 
		oper.GetOperateReturns().GetStream().Pushback(cs.Begin() , cs.GetDataLen()) ;

		delete iter;

		oper.SetErrorCode(ERR_SUCCESS);

	}


}