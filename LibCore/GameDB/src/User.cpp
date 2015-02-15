#include "User.h"

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
	std::string User::rawkey()
	{
		std::string result;
		result.reserve(64);

		result.append(name.c_str());
		return result;
	}

	std::string User::getkey()
	{
		return this->rawkey();
	}

	std::string User::getmeta()
	{
		return User::meta();
	}

	void User::set_autoincr(int64 key)
	{
		assert(false);
	}

	User* User::Clone()
	{
		bson::bo obj;
		ToBson(obj);
		User* pNew = new User();
		pNew->FromBson(obj);
		return pNew;
	}

	void User::ToCompress(std::string & __buf)
	{
		bson::bo __obj;
		ToBson(__obj);
		snappy::Compress(__obj.objdata(),__obj.objsize(),&__buf);
	}

	void User::ToBson(std::string& __buf)
	{
		bson::bo __obj;
		ToBson(__obj);
		__buf = std::string(__obj.objdata(),__obj.objsize());
	}

	void User::ToBson(bson::bo& __obj)
	{
		mongo::BSONObjBuilder __builder;
		__builder.append("_T",meta());
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
		snappy::Uncompress(__inbuf.c_str(),__inbuf.length(),&tmpbuf);
		bson::bo __obj(tmpbuf.c_str());
		assert(__obj.objsize() == tmpbuf.length());
		FromBson(__obj);
	}

	void User::FromCompress(const char* __data,size_t __size)
	{
		std::string tmpbuf;
		snappy::Uncompress(__data,__size,&tmpbuf);
		bson::bo __obj(tmpbuf.c_str());
		assert(__obj.objsize() == tmpbuf.length());
		FromBson(__obj);
	}

	void User::FromBson(const char* __data,size_t __size)
	{
		bson::bo __obj(__data);
		assert(__obj.objsize() == __size);
		FromBson(__obj);
	}

	void User::FromBson(const bson::bo& __obj)
	{
		mongo::BSONObjIterator iter(__obj);
		while(iter.more())
		{
			mongo::BSONElement __be = iter.next();
			const char* fieldName = __be.fieldName();
			int64 hash = pwutils::bkdr_hash_and_sum(fieldName);
			switch(hash)
			{
			case 768799158513: // _T
				{
					assert(pwutils::strcmp(__be.valuestr(),meta()) == 0);
				}
				break;
			case 1791250331439: // name type: string
				{
					pwutils::bsonToCppVariable(name,__be);
				}
				break;
			case 1915809189412: // pswd type: string
				{
					pwutils::bsonToCppVariable(pswd,__be);
				}
				break;
			case 3427387595580: // sysuser type: bool
				{
					pwutils::bsonToCppVariable(sysuser,__be);
				}
				break;
			}
		}
		__hash = hash_make(0);
	}


	int64 User::hash_make(int64 seed)
	{
		int64 _result = seed;
		_result = LibCore::city_hash(&name,sizeof(name),_result);

		_result = pwutils::city_hash(&pswd,sizeof(pswd),_result);

		_result = pwutils::city_hash(&sysuser,sizeof(sysuser),_result);

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

}