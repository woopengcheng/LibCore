/************************************
FileName	:	Orm_Test_PrimaryKey.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.104
Version		:	0.0.1
Date		:	2015-08-16 13:48:48
Description	:	orm²Ù×÷¼¯ºÏ.
************************************/
#ifndef __Orm_Orm_Test_PrimaryKey_h__
#define __Orm_Orm_Test_PrimaryKey_h__
#include "GameDB/inc/Orm.h"

namespace Orm
{
	class DLL_EXPORT Test_PrimaryKey : public GameDB::Orm
	{ 
		public:
			Test_PrimaryKey();
			virtual ~Test_PrimaryKey();
		
		public:
			Test_PrimaryKey* Clone();

		public:
			static const char* TableName() { return "Test_PrimaryKey"; }
			static const INT64 meta_hash = 6649511737446;
		
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
			virtual void		ToCompress(std::string & __buf); 
			virtual void		FromCompress(const char* data,INT32 size);
			virtual void		FromCompress(const std::string & strBuf);
		
		public:
			virtual INT64		HashMake(INT64 llSeed = DEFAULT_HASH_SEED);
			virtual INT64		CurHash(){ return __hash; }
			virtual void		HashUpdate(INT64 llHash);
		
		public:
			virtual void		AutoIncrease(INT64 llKey); 
			virtual void		SetMasterID(INT64 llID);
			virtual void		SetMasterID(const char* pID);
			virtual INT64		GetMasterID();
			virtual const char*	GetMasterStrID(); 
		
		public:
			int Getid() const;
			void Setid(int& value);

			std::string Getp1() const;
			void Setp1(std::string& value);

		
		public:
			int	id;
			std::string	p1;
		
		private:
			INT64			__hash;
		
	}; 
 
}//Orm

#endif
