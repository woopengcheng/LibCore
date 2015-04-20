#ifndef __gamedb_hashtable_h__
#define __gamedb_hashtable_h__ 
#include "GameDB/inc/DatabaseCommon.h"

namespace GameDB
{  
	class HashTable
	{
	public:
		static void EncodeKey(const Slice& table,const Slice& key,Slice& outEncodedKey , DEFAULT_STACKCHUNK & sChunk);
		static bool DecodeKey(const Slice& encodedName,const Slice& name,Slice& key);
		  
		static void HCount_EncodeKey(const Slice& key, Slice & outKey);
		static bool HCount_DecodeKey(const Slice& dbFullKey,Slice& hKey);
		static void HCount_Initial(Database &db,const Slice & countkey,INT64 & llOldCount);
//		static bool HCount_IncrIfNonExists(OperateEnv& env,const Slice& dbkey,int64& size);
//		static bool HCount_DecrIfExists(OperateEnv& env,const Slice& dbkey,int64& size);
		static void HCount_SaveToDB(const Slice & countKey,INT64 countVal,WriteBatch& batch,OperateRecord & or);
		

		enum CHECK_RESULT
		{
			CHECK_RESULT_NOTEXISTS,
			CHECK_RESULT_SAME,
			CHECK_RESULT_EXISTS,
			CHECK_RESULT_ERROR,
		};
		static CHECK_RESULT CheckExists(Database &db,const Slice& dbkey,const Slice& newvalue);

		static void Set(Database &db,OperateRecord & or,const Slice& name,const Slice& key,const Slice& val);
		static void SetNX(Database &db,OperateRecord & or,const Slice& name,const Slice& key,const Slice& val);
		static void SetOW(Database &db,OperationResult1Val& result,const Slice& name,const Slice& key,const Slice& val);
// 		static void Get(Database &db,OperationResult1Val& result,const Slice& name,const Slice& key);
// 		static void Del(Database &db,OperationResult1Val& result,const Slice& name,const Slice& key);
// 
// 		static void MultiSet(Database &db,OperateRecord & or,const Slice& name,const CollectionSlicesT& keys,const CollectionSlicesT& vals);
// 		static void MultiGet(Database &db,OperationResultMval& result,const Slice& name,const CollectionSlicesT& keys);
// 		static void MultiDel(Database &db,OperationResultAffected& result,const Slice& name,const CollectionSlicesT& keys);
// 
// 		static void Incr(Database &db,OperationResultIncr& result,const Slice& name,const Slice& key,int64 v);
// 		static void IncrFloat(Database &db,OperationResultIncrFloat& result,const Slice& name,const Slice& key,double v);
// 
// 		static void All(Database &db,OperationResultMrefkeyval& result,const Slice& name);
// 		static void All(Database &db,OperationResultCallback& result,const Slice& name);		
// 
// 		static void Scan(Database &db,OperationResultMrefkeyval& result,const Slice& name,const Slice& start,const Slice& pattern,int64 limit);
// 		static void Scan(Database &db,OperationResultCallback& result,const Slice& name,const Slice& start,const Slice& pattern,int64 limit);
// 
// 		static void Clear(Database &db,OperationResultAffected& result,const Slice& name);
// 		static void Count(Database &db,OperationResultInteger& result,const Slice& name);
// 
// 		static void CrossAll(Database &db,OperationResultMrefkeyval& result,const Slice& name);
// 		static void CrossAll(Database &db,OperationResultCallback& result,const Slice& name);
// 
// 		static void List(Database &db,OperationResultMrefval& result);
	protected:
	private:
	};
	  
}

#endif
