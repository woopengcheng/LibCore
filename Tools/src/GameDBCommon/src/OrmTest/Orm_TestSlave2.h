/************************************
FileName	:	Orm_TestSlave2.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-17 00:08:59
Description	:	orm²Ù×÷¼¯ºÏ.
************************************/
#ifndef __Orm_Orm_TestSlave2_h__
#define __Orm_Orm_TestSlave2_h__
#include "GameDB/inc/Orm.h"

namespace Orm
{
	class TestSlave2 : public GameDB::Orm
	{ 
		public:
			TestSlave2();
			virtual ~TestSlave2();
		
		private:
			TestSlave2( const TestSlave2 &);
			const TestSlave2& operator=( const TestSlave2 &);
		
		public:
			TestSlave2* Clone();

		public:
			static const char* TableName() { return "TestSlave2"; }
			static const INT64 meta_hash = 4180792914557;
		
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

			INT64 Getid2() const;
			void Setid2(INT64& value);

			void Plusid2(INT64 & value);
			void Minusid2(INT64 & value);
			void id2Include(INT64 & value);
			BOOL Isid2Include(INT64 & value);
			void id2Exclude(INT64 & value);
		
		public:
			INT64	id;
			INT64	id2;
		
		private:
			INT64			__hash;
		
	}; 
 
}//Orm

#endif
