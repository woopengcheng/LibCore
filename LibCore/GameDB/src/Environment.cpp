#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Comparator.h"
#include "GameDB/inc/Database.h" 
#include "leveldb/cache.h"
#include "LogLib/inc/Log.h"
#include "Common/LibCore.h"

namespace GameDB
{


	Environment::Environment(const std::string strDirectory , Json::Value & objValue)
		: m_strDirectory(strDirectory)
		, m_objDefaultOptions(objValue) 
	{
		m_pLevelDBEnv = leveldb::Env::Default();
		m_pComparator = new Comparator;
// 		m_pLevelDBEnv = leveldb::NewBackupEnv(leveldb::Env::Default());
	
		std::vector<std::string> vecDatabases;
		leveldb::Env::Default()->CreateDir(m_strDirectory);
		leveldb::Env::Default()->GetChildren(m_strDirectory , &vecDatabases);

		std::vector<std::string>::iterator iter = vecDatabases.begin();
		for (;iter != vecDatabases.end();++iter)
		{
			if (*iter == "." || *iter == "..")
			{
				continue;
			}

			OpenDatabase(*iter); 
		}
	
		if (!GetDatabase(g_szSystemDatabase))
		{
			CreateDatabase(g_szSystemDatabase);
		}
	}

	Database * Environment::OpenDatabase(const std::string & strName)
	{
		Database * pDatabase = GetDatabase(strName);
		if (pDatabase)
		{
			return pDatabase;
		}

		leveldb::Options objOptions;
		MakeOptions(objOptions); 
		objOptions.create_if_missing = true;
		objOptions.error_if_exists = true;
		objOptions.comparator = m_pComparator;

		pDatabase = new Database(strName , m_strDirectory , objOptions);
		pDatabase->Open();
	
		if (pDatabase->GetLevelDB())
		{
			m_mapDatabases.insert(std::make_pair(strName , pDatabase));
		}
		else
		{
			SAFE_DELETE(pDatabase);
			MsgAssert_Re0(pDatabase , "open database error.");
		}

		return pDatabase;
	}

	BOOL Environment::CloseDatabase(const std::string & strName)
	{
		Database * pDatabase = GetDatabase(strName);
		if (pDatabase)
		{
			return FALSE;
		}

		m_mapDatabases.erase(strName);

		pDatabase->Close();
		SAFE_DELETE(pDatabase);

		return TRUE;
	}

	Database*  Environment::CreateDatabase(const std::string & strName)
	{
		Database * pDatabase = GetDatabase(strName);
		if (pDatabase)
		{
			return NULL;
		}

		leveldb::Options objOptions;
		MakeOptions(objOptions); 
		objOptions.create_if_missing = true;
		objOptions.error_if_exists = true;
		objOptions.comparator = m_pComparator;

		pDatabase = new Database(strName , m_strDirectory , objOptions);
		pDatabase->Create();

		if (pDatabase->GetLevelDB())
		{
			m_mapDatabases.insert(std::make_pair(strName , pDatabase));
		}
		else
		{
			SAFE_DELETE(pDatabase);
			MsgAssert_Re0(pDatabase , "open database error.");
		}

		return pDatabase;

	}

	BOOL Environment::RemoveDatabase(const std::string & strName)
	{
		Database * pDatabase = GetDatabase(strName);
		if (pDatabase)
		{
			return FALSE;
		}

		m_mapDatabases.erase(strName);
		 
		pDatabase->Close();
		pDatabase->RemoveDatabase();
		SAFE_DELETE(pDatabase);

		return TRUE;
	}

	BOOL Environment::RepairDatabase(const std::string & strName)
	{
		std::string strDatabaseDir = m_strDirectory + strName;
		
		Status objStatus = leveldb::RepairDB(strDatabaseDir , leveldb::Options());
		if (!objStatus.ok())
		{
			gErrorStream("repair db fail." << objStatus.ToString());
		}

		return objStatus.ok();
	}

	Database * Environment::GetDatabase(const std::string & strName)
	{
		CollectionDatabasesT::iterator iter = m_mapDatabases.find(strName);
		if(m_mapDatabases.end() != iter)
		{
			return iter->second;
		}

		return NULL;
	}

	void Environment::GetAllDatabase(std::vector<std::string> & vecDatabases)
	{
		CollectionDatabasesT::iterator iter = m_mapDatabases.begin();
		for(;m_mapDatabases.end() != iter; ++iter)
		{
			vecDatabases.push_back(iter->first);
		}
		
	}

	void Environment::MakeOptions(leveldb::Options & objOptions)
	{
		std::string  strCompress = "none";
		INT64        llCacheSize = -1;
		INT64        llMaxOpenFiles = -1;
		INT64        llBlockSize = -1;
		INT64        llWriteBufferSize = -1;
		Json::Value  objDefaultIntValue(Json::Int(-1));

		strCompress = m_objDefaultOptions.get("compress" , "none").asString();
		llCacheSize = LibCore::ParseHumanSizeFromJson(m_objDefaultOptions.get("cache_size",objDefaultIntValue));
		llMaxOpenFiles = LibCore::ParseHumanSizeFromJson(m_objDefaultOptions.get("max_open_files",objDefaultIntValue));
		llBlockSize = LibCore::ParseHumanSizeFromJson(m_objDefaultOptions.get("block_size",objDefaultIntValue));
		llWriteBufferSize = LibCore::ParseHumanSizeFromJson(m_objDefaultOptions.get("write_buffer_size",objDefaultIntValue));

		if (llMaxOpenFiles > 0) 
			objOptions.max_open_files = (INT32)llMaxOpenFiles;
		if (llBlockSize > 0) 
			objOptions.block_size = llBlockSize;
		if (llWriteBufferSize > 0) 
			objOptions.write_buffer_size = llWriteBufferSize;
		if (llCacheSize > 0) 
			objOptions.block_cache = leveldb::NewLRUCache(llCacheSize);;
		if (strCompress == "snappy") 
			objOptions.compression = leveldb::kSnappyCompression;

		objOptions.env = m_pLevelDBEnv;
	}

}