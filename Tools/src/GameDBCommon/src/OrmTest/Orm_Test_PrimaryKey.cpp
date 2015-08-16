#include "Orm_Test_PrimaryKey.h"

namespace Orm
{
	Test_PrimaryKey::Test_PrimaryKey()
		: id(0)
		, p1(std::string())
	{
	}

	Test_PrimaryKey::~Test_PrimaryKey()
	{
	}

	std::string Test_PrimaryKey::GetRawKey()
	{
		std::string result;
		result.reserve(64);

		{
			result.append(CUtil::itoa((INT64)id));
		}
		return result;
	}

	std::string Test_PrimaryKey::GetKey()
	{
		return this->GetRawKey();

	}

	std::string Test_PrimaryKey::GetTableName()
	{
		return Test_PrimaryKey::TableName();
	}

	void Test_PrimaryKey::AutoIncrease(INT64 llKey)
	{
		id = llKey;
	}

	Test_PrimaryKey * Test_PrimaryKey::Clone()
	{
		mongo::BSONObj  obj;
		ToBson(obj);
		Test_PrimaryKey * pNew = new Test_PrimaryKey();
		pNew->FromBson(obj);
		return pNew;
	}

	void Test_PrimaryKey::ToCompress(std::string & __buf)
	{
		mongo::BSONObj  __obj;
		ToBson(__obj);
		CUtil::Compress(__obj.objdata(),__obj.objsize(),__buf);
	}

	void Test_PrimaryKey::ToBson(std::string & __buf)
	{
		mongo::BSONObj  __obj;
		ToBson(__obj);
		__buf = std::string(__obj.objdata(),__obj.objsize());
	}

	void Test_PrimaryKey::ToBson(mongo::BSONObj  & __obj)
	{
		mongo::BSONObjBuilder __builder;
		__builder.append("_T",TableName());
		if(id != 0)
			__builder.append("id",id);
		if(p1 != std::string())
			__builder.append("p1",p1);
		__obj = __builder.obj();
	}

	void Test_PrimaryKey::FromCompress(const std::string& __inbuf)
	{
		std::string tmpbuf;
		CUtil::UnCompress(__inbuf.c_str(),(UINT32)__inbuf.length(),tmpbuf);
		mongo::BSONObj  __obj(tmpbuf.c_str());
		MsgAssert(__obj.objsize() == tmpbuf.length() , "");
		FromBson(__obj);
	}

	void Test_PrimaryKey::FromCompress(const char* __data,INT32 __size)
	{
		std::string tmpbuf;
		CUtil::UnCompress(__data,__size,tmpbuf);
		mongo::BSONObj  __obj(tmpbuf.c_str());
		MsgAssert(__obj.objsize() == tmpbuf.length() , "");
		FromBson(__obj);
	}

	void Test_PrimaryKey::FromBson(const char* __data,INT32 __size)
	{
		mongo::BSONObj  __obj(__data);
		MsgAssert(__obj.objsize() == __size , "FromBson error.");
		FromBson(__obj);
	}

	void Test_PrimaryKey::FromBson(const mongo::BSONObj  & __obj)
	{
		mongo::BSONObjIterator  iter(__obj); 
		while(iter.more())		{			mongo::BSONElement __be = iter.next();
			const char* fieldName = __be.fieldName();
			INT64 hash = CUtil::BKDRHashSum(fieldName);
			switch(hash)
			{
			case 880468309535: // id
				{
					MsgAssert(CUtil::strcmp(__be.valuestr(), TableName()) == 0 , "FromBson error.");
				}break;
			case 691489749377: // p1
				{
				}break;
			}
		}
		__hash = HashMake(0);
	}

	INT64 Test_PrimaryKey::HashMake(INT64 seed)
	{
		INT64 _result = seed;
		_result = CUtil::CityHash(&id,sizeof(id),_result);
		return _result;
		return _result;
	}

	int Test_PrimaryKey::Getid() const
	{
		return id;
	}

	void Test_PrimaryKey::Setid(int & value)
	{
		id = value;
	}

	std::string Test_PrimaryKey::Getp1() const
	{
		return p1;
	}

	void Test_PrimaryKey::Setp1(std::string & value)
	{
		p1 = value;
	}

}//Orm

