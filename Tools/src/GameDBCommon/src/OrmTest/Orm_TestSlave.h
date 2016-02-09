/************************************
FileName	:	Orm_TestSlave.h
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.31.196
Version		:	0.0.1
Date		:	2016-02-09 11:26:27
Description	:	orm��������.
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
			virtual std::string GetKey() override;
			virtual std::string GetRawKey() override;
			virtual std::string GetTableName() override;
		
		public:
			bool IsEqual(const TestSlave & val);
			bool operator == (const TestSlave & val);
			bool operator != (const TestSlave & val);
		
		public:
			virtual void		ToBson(std::string & strBuf) override;
			virtual void		ToBson(mongo::BSONObj  & objBson) override;
			virtual void		FromBson(const char * pData , INT32 nSize) override;
			virtual void		FromBson(const mongo::BSONObj  & objBson) override;
			virtual void		ToCompress(std::string & strBuf); 
			virtual void		FromCompress(const char* data,INT32 size) override;
			virtual void		FromCompress(const std::string & strBuf) override;
		
		public:
			virtual INT64		HashMake(INT64 llSeed = DEFAULT_HASH_SEED) override;
			virtual INT64		CurHash() override { return __hash; }
			virtual void		HashUpdate(INT64 llHash) override { __hash = llHash; }
		
		public:
			virtual void		AutoIncrease(INT64 llKey) override ; 
			virtual void		SetMasterID(INT64 llID) override {id = llID; }
			virtual void		SetMasterID(const char* pID) override { }
			virtual INT64		GetMasterID() override { return id;}
			virtual const char*	GetMasterStrID() override { return "";}
		
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
