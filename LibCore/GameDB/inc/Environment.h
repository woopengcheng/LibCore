#ifndef __gamedb_environment_h__ 
#define __gamedb_environment_h__
#include "GameDB/inc/DatabaseCommon.h"
#include "leveldb/options.h"
#include "leveldb/env.h"
#include "json/value.h"

namespace GameDB
{
	class Database;
	class Comparator;

	class Environment 
	{
	public:
		typedef std_unordered_map<std::string , Database *> CollectionDatabasesT;

	public:
		Environment(const std::string strDirectory , Json::Value & objValue);
		~Environment(){}
		
	public:
		Database * OpenDatabase(const std::string & strName);
		BOOL       CloseDatabase(const std::string & strName);
		Database * CreateDatabase(const std::string & strName);
		BOOL       RemoveDatabase(const std::string & strName);
		BOOL       RepairDatabase(const std::string & strName);
		Database * GetDatabase(const std::string & strName);
		void       GetAllDatabase(std::vector<std::string> & vecDatabases);

	public:
		leveldb::Env * GetLevelDBEnv() const { return m_pLevelDBEnv; } 

	protected:
		void       MakeOptions(leveldb::Options & objOptions);

	protected:
		std::string		  	  m_strDirectory; 
		leveldb::Env		* m_pLevelDBEnv;
		Comparator          * m_pComparator;		//5 ���ݿ�����ʹ�õıȽϺ���. 
		Json::Value           m_objDefaultOptions;
		CollectionDatabasesT  m_mapDatabases;
	};
}



#endif