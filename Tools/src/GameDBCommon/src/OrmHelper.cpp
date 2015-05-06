#include "OrmHelper.h"
#include "RpcCallFuncs.h"
#include "bson/bson.h"

namespace GameDB
{ 
	INT32 OrmHelper::OrmInsert(GameDB::Orm * obj , EORM_MASK objMask /*= ORM_NONE*/)
	{
		MsgAssert_ReF1(obj , "error obj.");

		return Commit(obj,OPERATION_INSERT); 
	}

	INT32 OrmHelper::OrmUpdate(GameDB::Orm * obj , EORM_MASK objMask /*= ORM_NONE*/)
	{
		MsgAssert_ReF1(obj , "error obj.");

		INT64 llOldHash = obj->CurHash();
		INT64 llNewHash = obj->HashMake(DEFAULT_HASH_SEED);

		if (llOldHash == llNewHash)
		{
			gDebugStream("OrmUpdate table: " << obj->GetTableName() << " key:" << obj->GetKey() << "is same hash.");
			
			return ERR_FAILURE;
		}

		obj->HashUpdate(llNewHash);
		return Commit(obj,OPERATION_UPDATE); 
	}

	INT32 OrmHelper::OrmDelete(GameDB::Orm * obj , EORM_MASK objMask /*= ORM_NONE*/)
	{
		MsgAssert_ReF1(obj , "error obj.");

		return Commit(obj,OPERATION_DELETE); 
	}

	INT32 OrmHelper::Commit(GameDB::Orm * obj , EORM_OPERATION objOper)
	{
		MsgAssert_ReF1(obj , "error obj.");

		switch (objOper)
		{
		case OPERATION_INSERT:
			{
				std::string strTable , strKey , strValue;
				strTable = obj->GetTableName();
				strKey   = obj->GetKey();
				obj->ToBson(strValue);

	//			_bson::bsonobj objValue;
	//			obj->ToBson(objValue);
	//			
	//			LibCore::Chunk objChunk(objValue.objdata(),objValue.objsize()).;

				//5 这里调试直接往服务器写.但是真实情况这么写就会出问题.因为这里会卡住.
				std::vector<Msg::Object> targets;
				targets.push_back(Msg::Object(1));   
				Client::local_call_HandleHSet("tcp://127.0.0.1:8001" , strTable , strKey , strValue , targets , Msg::Object(0) , 1);
			}
			break;
		case OPERATION_UPDATE:
			{ 
				std::string strTable , strKey ;
				strTable = obj->GetTableName();
				strKey   = obj->GetKey(); 

				//5 这里调试直接往服务器写.但是真实情况这么写就会出问题.因为这里会卡住.同时value为string应该不好.
				std::vector<Msg::Object> targets;
				targets.push_back(Msg::Object(1));   
				Client::local_call_HandleHGet("tcp://127.0.0.1:8001" , strTable , strKey , targets , Msg::Object(0) , 1);

			}
			break;
		case OPERATION_DELETE:
			break;
		default:
			break;
		}
		
		return ERR_SUCCESS;
	}

}