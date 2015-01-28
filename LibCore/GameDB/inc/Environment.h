#ifndef __gamedb_environment_h__ 
#define __gamedb_environment_h__
#include "GameDB/inc/DatabaseCommon.h"
#include "leveldb/options.h"
#include "leveldb/env.h"

namespace GameDB
{
	class Environment 
	{
	public:
		Environment(){}

	protected:
		leveldb::Env * m_pLevelDBEnv;
	};
}



#endif
