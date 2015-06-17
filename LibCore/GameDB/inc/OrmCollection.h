#ifndef __gamedb_orm_collection_h__
#define __gamedb_orm_collection_h__
#include "GameDB/inc/DBCommon.h"
#include <string>
#include "bson/bson.h"

namespace GameDB
{
	//5 这里MasterType只能为INT64或者string,其他类型需要更改工具。
	template<typename MasterType>
	class OrmCollection
	{
	public:
		OrmCollection()
		{ 
		}
	};

	
	template<>
	class OrmCollection<INT64>
	{
	public:
		OrmCollection()
			: m_vMasterId(0)
		{ 
		}
	public:
		void SetMasterID(INT64 id) { m_vMasterId = id; }
	protected:
		INT64 m_vMasterId;
	};

	template<>
	class OrmCollection<std::string>
	{
	public:
		OrmCollection()
			: m_vMasterId("")
		{ 
		}
	public:
		void SetMasterID(std::string id) { m_vMasterId = id; }

	protected:
		std::string m_vMasterId;
	};


}

#endif
