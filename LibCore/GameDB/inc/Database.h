#ifndef __gamedb_database_h__ 
#define __gamedb_database_h__
#include "DBCommon.h"
#include "leveldb/db.h"
#include "leveldb/write_batch.h"

namespace GameDB
{
	class BackupEnvironment;

	class DLL_EXPORT Database
	{
	public:
		Database(const std::string& strName,const std::string& strDirectory,const leveldb::Options& objOptions , BackupEnvironment * pBackupEnv = NULL);
		~Database();

	public:
		Status   QuickGet(const Slice & objKey , std::string & strVal);
		Status   QuickWrite(const Slice & objKey , const Slice & objVal);
		Status   QuickWrite(leveldb::WriteBatch * pBatch);
		Status   QuickDel(const Slice & objKey);

	public:
		BOOL	 Open();
		void	 Close();
		BOOL	 Create();
		BOOL     Backup(const std::string & strBackupName , std::string & strDir);
		BOOL	 RemoveDatabase();
		void	 RemoveDatas();
		void	 UpdateCache(const Slice & objKey , const Slice & objVal);  //5 也可能回被leveldb递归调用.
		BOOL     IsSystemDatabase()
		{
			if (m_strName == g_szSystemDatabase)
			{
				return TRUE;
			}
			
			return FALSE;
		}

	public:
		std::string		 GetName() const { return m_strName; } 
		std::string		 GetDirectory() const { return m_strDirectory; }
		leveldb::DB	   * GetLevelDB() const { return m_pLevelDB; } 
		leveldb::Options GetObjOptions() const { return m_objOptions; } 
		   
	private:
		std::string			m_strName;
		std::string			m_strDirectory; 
		leveldb::DB		  * m_pLevelDB;
		leveldb::Options	m_objOptions;
		leveldb::Cache	  * m_pCustomCache;   //5 用户自定义缓存
		BackupEnvironment * m_pBackupEnv;
	};
}



#endif