#ifndef __gamedb_orm_h__
#define __gamedb_orm_h__
#include "GameDB/inc/DatabaseCommon.h"
#include "bson/bson.h"

namespace GameDB
{
	class Orm
	{
	public:
		Orm(){}
		virtual ~Orm(){}

	public: 
		virtual std::string GetKey() = 0;
		virtual std::string GetRawKey() = 0;
		virtual std::string GetTableName() = 0;
		virtual bool        IsDefaultValue() = 0;

	public:
		virtual void		ToBson(std::string & strBuf) = 0;
		virtual void		ToBson(_bson::bsonobj & objBson) = 0;
		virtual void		FromBson(const char * pData , INT32 nSize) = 0;
		virtual void		FromBson(const _bson::bsonobj & objBson) = 0;
		virtual void		ToCompress(std::string & __buf) = 0; 
		virtual void		FromCompress(const char* data,INT32 size) = 0;
		virtual void		FromCompress(const std::string & strBuf) = 0;

	public:
		virtual INT64		HashMake(INT64 llSeed) = 0;
		virtual INT64		CurHash() = 0;
		virtual void		HashUpdate(INT64 llHash) = 0;

	public:
		virtual void		AutoIncrease(INT64 llKey) = 0; 
		virtual void		SetMasterID(INT64 llID) = 0;
		virtual void		SetMasterID(const char* pID) = 0;
		virtual INT64		GetMasterID() = 0;
		virtual const char*	GetMasterStrID() = 0;  
	};
}

#endif