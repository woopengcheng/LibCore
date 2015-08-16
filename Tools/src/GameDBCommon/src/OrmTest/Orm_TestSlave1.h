/************************************
FileName	:	Orm_TestSlave1.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-17 00:08:59
Description	:	orm²Ù×÷¼¯ºÏ.
************************************/
#ifndef __Orm_Orm_TestSlave1_h__
#define __Orm_Orm_TestSlave1_h__
#include "GameDB/inc/Orm.h"

namespace Orm
{
	class TestSlave1 : public GameDB::Orm
	{ 
		public:
			TestSlave1();
			virtual ~TestSlave1();
		
		private:
			TestSlave1( const TestSlave1 &);
			const TestSlave1& operator=( const TestSlave1 &);
		
		public:
			TestSlave1* Clone();

		public:
			static const char* TableName() { return "TestSlave1"; }
			static const INT64 meta_hash = 4176497947260;
		
		public:
			virtual std::string GetKey();
			virtual std::string GetRawKey();
			virtual std::string GetTableName();
			virtual bool        IsDefaultValue();
		
		public:
			virtual void		ToBson(std::string & strBuf);
			virtual void		ToBson(mongo::BSONObj  & objBson);
			virtual void		FromBson(const char * pData , INT32 nSize);
			virtual void		FromBson(const mongo::BSONObj  & objBson);
			virtual void		ToCompress(std::string & strBuf); 
			virtual void		FromCompress(const char* data,INT32 size);
			virtual void		FromCompress(const std::string & strBuf);
		
		public:
			virtual INT64		HashMake(INT64 llSeed = DEFAULT_HASH_SEED);
			virtual INT64		CurHash(){ return __hash; }
			virtual void		HashUpdate(INT64 llHash){ __hash = llHash; }
		
		public:
			virtual void		AutoIncrease(INT64 llKey); 
			virtual void		SetMasterID(INT64 llID);
			virtual void		SetMasterID(const char* pID);
			virtual INT64		GetMasterID();
			virtual const char*	GetMasterStrID(); 
		
		public:
			INT64 Getid() const;
			void Setid(INT64& value);

		
		public:
			INT64	id;
		
		private:
			INT64			__hash;
		
	}; 
 
}//Orm

#endif
