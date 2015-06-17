#ifndef __gamedb_sorted_set_h__
#define __gamedb_sorted_set_h__ 
#include "GameDB/inc/DBCommon.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"
#include "GameDB/inc/OperateReturns.h"

namespace GameDB
{  
	class DLL_EXPORT SortedSet
	{
	public:
// 		static void EncodeKey(const Slice& table,const Slice& key,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk);
// 		static bool DecodeKey(const Slice& encodedName,const Slice& name,Slice& key);
// 		static void EncodeScoreKey(const Slice& table,const Slice& key , int64 score,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk);
// 		static bool DecodeScoreKey(const Slice& dbKeyData,const Slice& table,Slice& outkey,int64& outscore);
// 
// 		static void ZCount_EncodeKey(const Slice& key, Slice & outKey);
// 		static bool ZCount_DecodeKey(const Slice& dbKeyData,Slice& outKey);
// 		static void ZCount_Initial(Database &db,const Slice & countKey,INT64 & llOldCount);
// 		static bool ZCount_IncrIfNonExists(Database &db,const Slice& dbKey,INT64& size);
// 		static bool ZCount_DecrIfExists(Database &db,const Slice& dbKey,INT64& size);
// 		static void ZCount_SaveToDB(const Slice & countKey,INT64 countVal,WriteBatch& batch,Operate & or);
// 		 
// 		static void ZSet(Database &db,Operate & oper,const Slice& table,const Slice& key,const Slice& val);
// 		static void ZGet(Database &db,Operate& oper,const Slice& table,const Slice& key);
// 	 
	protected:
	private:
	};

}

#endif