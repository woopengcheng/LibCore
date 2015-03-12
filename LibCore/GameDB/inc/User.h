#ifndef __gamedb_user_h__
#define __gamedb_user_h__
#include "Common/StringEx.h"
#include "GameDB/inc/Orm.h"

namespace GameDB
{ 
	class User : public Orm
	{ 
	public:
		User();
		virtual ~User();
	public:
		User* Clone();

	public:
		static const char* TableName() { return "user"; }
		static const INT64 meta_hash = 1920115394819; 

	public: 
		virtual std::string GetKey();
		virtual std::string GetRawKey();
		virtual std::string GetTableName();
		virtual bool        IsDefaultValue();

	public:
		virtual void		ToBson(std::string & strBuf);
		virtual void		ToBson(_bson::bsonobj & objBson);
		virtual void		FromBson(const char * pData , INT32 nSize);
		virtual void		FromBson(const _bson::bsonobj & objBson);
		virtual void		ToCompress(std::string & __buf); 
		virtual void		FromCompress(const char* data,INT32 size);
		virtual void		FromCompress(const std::string & strBuf);

	public:
		virtual INT64		HashMake(INT64 llSeed);
		virtual INT64		CurHash(){ return __hash; }
		virtual void		HashUpdate(INT64 llHash);

	public:
		virtual void		AutoIncrease(INT64 llKey); 
		virtual void		SetMasterID(INT64 llID);
		virtual void		SetMasterID(const char* pID);
		virtual INT64		GetMasterID();
		virtual const char*	GetMasterStrID();   

	public:
		const char* get_name() const;
		const char* get_pswd() const;
		bool get_sysuser() const;

		void set_name(const char* value);
		void set_pswd(const char* value);
		void set_sysuser(bool value);

	public:
		bool sysuser;
		LibCore::StringEx<64> name;
		LibCore::StringEx<64> pswd;

	public:
		INT64 __hash;
	};

}


#endif