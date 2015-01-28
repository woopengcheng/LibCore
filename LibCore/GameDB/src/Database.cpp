#include "GameDB/inc/Database.h"
#include "leveldb/env.h"
#include "leveldb/cache.h"
#include "GameDB/inc/CustomDefinedCacheHandler.h"

namespace GameDB
{  
	 
	Database::Database(const std::string& strName,const std::string& strDirectory,const leveldb::Options& objOptions)
		: m_strName(strName)
		, m_strDirectory(strDirectory)
		, m_objOptions(objOptions)
		, m_pLevelDB(NULL) 
		, m_pCustomCache(NULL)
	{ 
		m_strDirectory = strDirectory + m_strName;
//		m_pCustomCache = leveldb::NewLRUCache(500*1024*1024);
	}

	Database::~Database()
	{ 
		Close();
		SAFE_DELETE(m_pCustomCache);
	}

	void Database::Close()
	{
		SAFE_DELETE(m_objOptions.block_cache);
	}

	Status Database::QuickGet(const Slice & objKey , std::string & strVal)
	{
		if (m_pCustomCache)
		{
			leveldb::Cache::Handle * pHandle = m_pCustomCache->Lookup(objKey);
			if (pHandle)
			{
				std::string * pOldValue = (std::string *)m_pCustomCache->Value(pHandle);
				strVal.assign(*pOldValue);
				m_pCustomCache->Release(pHandle);

				return Status::OK();
			}
		}

		//5 如果用户自定义缓存没有或者没有自定义缓存.就去数据库中查找.
		m_pLevelDB->Get(leveldb::ReadOptions() , objKey , &strVal);
	}

	Status Database::QuickWrite(const Slice & objKey , const Slice & objVal)
	{
		Status objStatus = m_pLevelDB->Put(leveldb::WriteOptions() , objKey , objVal);

		if (objStatus.ok() && m_pCustomCache)
		{ 
			UpdateCache(objKey , objVal);
		}

		return objStatus;

	}

	Status Database::QuickWrite(leveldb::WriteBatch * pBatch)
	{ 
		Status objStatus = m_pLevelDB->Write(leveldb::WriteOptions() , pBatch);

		if (objStatus.ok() && m_pCustomCache)
		{ 
			CustomDefinedCacheHandler objHandler(this);
			pBatch->Iterate(&objHandler); 
		}

		return objStatus;
	}

	Status Database::QuickDel(const Slice & objKey)
	{
		leveldb::Status objStatus = m_pLevelDB->Delete(leveldb::WriteOptions() , objKey);
		if (objStatus.ok() && m_pCustomCache)
		{
			m_pCustomCache->Erase(objKey);
		}

		return objStatus;
	}

	void Database::UpdateCache(const Slice & objKey , const Slice & objVal)
	{
		leveldb::Cache::Handle * pHandle = m_pCustomCache->Lookup(objKey);
		if (pHandle)
		{
			std::string * pOldValue = (std::string *)m_pCustomCache->Value(pHandle);
			pOldValue->clear();
			pOldValue->append(objVal.data() , objVal.size());

			m_pCustomCache->Release(pHandle);
		}
		else
		{
			std::string * pNewValue = new std::string(objVal.data(),objVal.size());
			m_pCustomCache->Insert(objKey , pNewValue , objVal.size() , fnCustomCacheDeleter);
		} 
	}

}