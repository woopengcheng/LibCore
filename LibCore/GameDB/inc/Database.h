#ifndef __gamedb_database_h__ 
#define __gamedb_database_h__
#include "DatabaseCommon.h"
#include "leveldb/db.h"
#include "leveldb/write_batch.h"

namespace GameDB
{
	class BackupEnvironment;

	class Database
	{
	public:
		Database(const std::string& strName,const std::string& strDirectory,const leveldb::Options& objOptions , BackupEnvironment * pBackupEnv);
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
		BOOL     Backup(const std::string & strBackupName , const std::string & strDir);
		BOOL	 RemoveDatabase();
		void	 RemoveDatas();
		void	 UpdateCache(const Slice & objKey , const Slice & objVal);  //5 也可能回被leveldb递归调用.

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