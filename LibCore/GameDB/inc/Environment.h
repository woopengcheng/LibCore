#ifndef __gamedb_environment_h__ 
#define __gamedb_environment_h__
#include "GameDB/inc/DatabaseCommon.h"
#include "leveldb/options.h"
#include "leveldb/env.h"
#include "json/value.h"

namespace GameDB
{
	class Environment 
	{
	public:
		Environment(const std::string strDirectory , Json::Value & objValue);
		~Environment(){}
		
	public:
		leveldb::Env * GetLevelDBEnv() const { return m_pLevelDBEnv; } 

	protected:
		leveldb::Env * m_pLevelDBEnv;
	};
}



#endif
