#include "GameDB/inc/User.h" 
#include "Common/BsonToCpp.h"

namespace GameDB
{ 
	User::User()
		: name("")
		, pswd("")
		, sysuser(false)
		, __hash(0)
	{
	}

	User::~User()
	{
	}
	std::string User::GetRawKey()
	{
		std::string result;
		result.reserve(64);

		result.append(name.c_str());
		return result;
	}

	std::string User::GetKey()
	{
		return this->GetRawKey();
	}

	std::string User::GetTableName()
	{
		return User::TableName();
	}

	void User::AutoIncrease(INT64 llKey)
	{
		assert(false);
	}

	User* User::Clone()
	{ 
		_bson::bsonobj obj;
		ToBson(obj);
		User* pNew = new User();
		pNew->FromBson(obj);
		return pNew;
	}

	void User::ToCompress(std::string & __buf)
	{
		_bson::bsonobj __obj;
		ToBson(__obj);
		LibCore::Compress(__obj.objdata(),__obj.objsize(),__buf);
	}
	  
	void User::ToBson(std::string& __buf)
	{
		_bson::bsonobj __obj;
		ToBson(__obj);
		__buf = std::string(__obj.objdata(),__obj.objsize());
	}

	void User::ToBson(_bson::bsonobj & __obj)
	{
		_bson::bsonobjbuilder __builder;
		__builder.append("_T",TableName());
		if(name != "")
			__builder.append("name",name);
		if(pswd != "")
			__builder.append("pswd",pswd);
		if(sysuser != false)
			__builder.append("sysuser",sysuser);
		__obj = __builder.obj();
	}

	void User::FromCompress(const std::string& __inbuf)
	{
		std::string tmpbuf;
		LibCore::UnCompress(__inbuf.c_str(),__inbuf.length(),tmpbuf);
		_bson::bsonobj __obj(tmpbuf.c_str());
		assert(__obj.objsize() == tmpbuf.length());
		FromBson(__obj);
	}

	void User::FromCompress(const char* __data,INT32 __size)
	{
		std::string tmpbuf;
		LibCore::UnCompress(__data,__size,tmpbuf);
		_bson::bsonobj __obj(tmpbuf.c_str());
		assert(__obj.objsize() == tmpbuf.length());
		FromBson(__obj);
	}

	void User::FromBson(const char* __data,INT32 __size)
	{
		_bson::bsonobj __obj(__data);
		assert(__obj.objsize() == __size);
		FromBson(__obj);
	}

	void User::FromBson(const _bson::bsonobj & __obj)
	{
		_bson::bsonobjiterator iter(__obj); 
		while(iter.more())
		{
			_bson::bsonelement __be = iter.next(); 
			const char* fieldName = __be.fieldName();
			INT64 hash = LibCore::BKDRHashSum(fieldName);
			switch(hash)
			{
			case 768799158513: // _T
				{
					assert(LibCore::strcmp(__be.valuestr(),TableName()) == 0);
				}
				break;
			case 1791250331439: // name type: string
				{
					LibCore::BsonToCpp(name,__be);
				}
				break;
			case 1915809189412: // pswd type: string
				{
					LibCore::BsonToCpp(pswd,__be);
				}
				break;
			case 3427387595580: // sysuser type: bool
				{
					LibCore::BsonToCpp(sysuser,__be);
				}
				break;
			}
		}
		__hash = HashMake(0);
	}


	INT64 User::HashMake(INT64 seed)
	{
		INT64 _result = seed;
		_result = LibCore::CityHash(&name,sizeof(name),_result);

		_result = LibCore::CityHash(&pswd,sizeof(pswd),_result);

		_result = LibCore::CityHash(&sysuser,sizeof(sysuser),_result);

		return _result;
	}

	const char* User::get_name() const
	{
		return name.c_str();
	}

	void User::set_name(const char* value)
	{
		name = value;
	}

	const char* User::get_pswd() const
	{
		return pswd.c_str();
	}

	void User::set_pswd(const char* value)
	{
		pswd = value;
	}

	bool User::get_sysuser() const
	{
		return sysuser;
	}

	void User::set_sysuser(bool value)
	{
		sysuser = value;
	}


	bool User::IsDefaultValue()
	{
		if(name.length() != 0)
			return false;

		if(pswd.length() != 0)
			return false;

		if(sysuser != false)
			return false;

		return true;
	}

	void User::HashUpdate(INT64 llHash)
	{ 
		__hash = llHash; 
	}

	void User::SetMasterID(INT64 llID)
	{

	}

	void User::SetMasterID(const char* pID)
	{

	}

	INT64 User::GetMasterID()
	{
		return 0;
	}

	const char* User::GetMasterStrID()
	{
		return "";
	}

}