#include "Orm_TestSlave1.h"

namespace Orm
{
	TestSlave1::TestSlave1()
		: id(0)
	{
	}

	TestSlave1::~TestSlave1()
	{
	}

	std::string TestSlave1::GetRawKey()
	{
		std::string result;
		result.reserve(64);

		return result;
	}

	std::string TestSlave1::GetKey()
	{
		std::string result;
		result.reserve(64);

			{
			result.append(CUtil::itoa((INT64)id));
		}
		return result;
	}

	std::string TestSlave1::GetTableName()
	{
		return TestSlave1::TableName();
	}

	void TestSlave1::AutoIncrease(INT64 llKey)
	{
		MsgAssert(false , "AutoIncrease key:" << llKey);
	}

	TestSlave1 * TestSlave1::Clone()
	{
		mongo::BSONObj  obj;
		ToBson(obj);
		TestSlave1 * pNew = new TestSlave1();
		pNew->FromBson(obj);
		return pNew;
	}

	void TestSlave1::ToCompress(std::string & strBuf)
	{
		mongo::BSONObj  obj;
		ToBson(obj);
		CUtil::Compress(obj.objdata(),obj.objsize(),strBuf);
	}

	void TestSlave1::ToBson(std::string & strBuf)
	{
		mongo::BSONObj  obj;
		ToBson(obj);
		strBuf = std::string(obj.objdata(),obj.objsize());
	}

	void TestSlave1::ToBson(mongo::BSONObj  & obj)
	{
		mongo::BSONObjBuilder builder;
		builder.append("_T",TableName());
		if(id != 0)
			builder.append("id",id);
		obj = builder.obj();
	}

	void TestSlave1::FromCompress(const std::string& inbuf)
	{
		std::string tmpbuf;
		CUtil::Uncompress(inbuf.c_str(),(UINT32)inbuf.length(),tmpbuf);
		mongo::BSONObj  obj(tmpbuf.c_str());
		MsgAssert(obj.objsize() == tmpbuf.length() , "");
		FromBson(obj);
	}

	void TestSlave1::FromCompress(const char* pData,INT32 size)
	{
		std::string tmpbuf;
		CUtil::Uncompress(pData,size,tmpbuf);
		mongo::BSONObj  obj(tmpbuf.c_str());
		MsgAssert(obj.objsize() == tmpbuf.length() , "");
		FromBson(obj);
	}

	void TestSlave1::FromBson(const char* pData,INT32 size)
	{
		mongo::BSONObj  obj(pData);
		MsgAssert(obj.objsize() == size , "FromBson error.");
		FromBson(obj);
	}

	void TestSlave1::FromBson(const mongo::BSONObj  & obj)
	{
		mongo::BSONObjIterator  iter(obj); 
		while(iter.more())		{			mongo::BSONElement be = iter.next();
			const char* fieldName = be.fieldName();
			INT64 hash = CUtil::BKDRHashSum(fieldName);
			switch(hash)
			{
			case 880468309535: // id
				{
					CUtil::BsonToCpp( id , be);
				}break;
			}
		}
		__hash = HashMake(0);
	}

	INT64 TestSlave1::HashMake(INT64 seed)
	{
		INT64 _result = seed;
		_result = CUtil::CityHash(&id,sizeof(id),_result);
		return _result;
	}

	INT64 TestSlave1::Getid() const
	{
		return id;
	}

	void TestSlave1::Setid(INT64 & value)
	{
		id = value;
	}

}//Orm

