/************************************
FileName	:	Orm_TestSlave.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-09-16 00:05:43
Description	:	orm²Ù×÷¼¯ºÏ.
************************************/
#ifndef __Orm_Orm_TestSlave_h__
#define __Orm_Orm_TestSlave_h__
#include "Orm_OrmStructs.h"
#include "GameDB/inc/Orm.h"

namespace Orm
{
	class TestSlave : public GameDB::Orm
	{ 
		public:
			TestSlave();
			virtual ~TestSlave();
		
		private:
			TestSlave( const TestSlave &);
			const TestSlave& operator=( const TestSlave &);
		
		public:
			TestSlave* Clone();

		public:
			static const char* TableName() { return "TestSlave"; }
			static const INT64 meta_hash = 3965202877593;
		
		public:
			virtual std::string GetKey();
			virtual std::string GetRawKey();
			virtual std::string GetTableName();
		
		public:
			bool IsEqual(const TestSlave & val);
			bool operator == (const TestSlave & val);
			bool operator != (const TestSlave & val);
		
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
			virtual void		SetMasterID(INT64 llID){id = llID; }
			virtual void		SetMasterID(const char* pID){ }
			virtual INT64		GetMasterID(){ return id;}
			virtual const char*	GetMasterStrID(){ return "";}
		
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
