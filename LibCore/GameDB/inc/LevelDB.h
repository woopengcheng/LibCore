// #ifndef __game_db_leveldb_h__ 
// #define __game_db_leveldb_h__
// #include "Common/Common.h"  
// #include "Marshal/CStream.h"
// #include "Marshal/Marshal.h"
// #include "leveldb/db.h"
// #include "leveldb/iterator.h"
// #include "leveldb/comparator.h"
// #include "leveldb/write_batch.h"
// 
// namespace GameDB
// { 
// 	typedef leveldb::Status			 Status;
// 	typedef leveldb::WriteBatch		 WriteBatch;   
// //	typedef leveldb::Iterator		 Iterator;
// 
// 	class DLL_EXPORT Iterator : public leveldb::Iterator
// 	{
// 
// 	};
// 
// 	class DLL_EXPORT Options : public leveldb::Options
// 	{
// 
// 	};
// 
// 	class DLL_EXPORT Slice : public leveldb::Slice , public LibCore::Marshal
// 	{
// 	public:
// 		// Create an empty slice.
// 		Slice() 
// 			: leveldb::Slice()
// 		{
// 
// 		}
// 
// 		// Create a slice that refers to d[0,n-1].
// 		Slice(const char* d, size_t n) 
// 			: leveldb::Slice(d , n) { }
// 
// 		// Create a slice that refers to the contents of "s"
// 		Slice(const std::string& s) 
// 			: leveldb::Slice(s) { } 
// 
// 		// Create a slice that refers to s[0,strlen(s)-1]
// 		Slice(const char* s)
// 			: leveldb::Slice(s) { } 
// 
// 	public: 
// 		LibCore::CStream & marshal( LibCore::CStream & cs )
// 		{ 
// 			cs << (UINT64)size();
// 			cs.Pushback((void*)data() , size());
// 			return cs; 
// 		} 
// 		LibCore::CStream & unMarshal( LibCore::CStream & cs )
// 		{ 
// 			UINT64 ullSize = 0; 
// 			cs >> ullSize;
// 
// 			void * pBuf = NULL;
// 			cs.Pop(pBuf , ullSize); 
// 
// 			data_ = (const char *)pBuf;
// 			size_ = (SIZEB)ullSize;
// 			return cs;
// 		}
// 	};
// 	typedef std::vector<Slice> CollectionSlicesT;
// 
// 
// 	class Database;
// 	class CustomDefinedCacheHandler : public leveldb::WriteBatch::Handler
// 	{
// 	public:
// 		CustomDefinedCacheHandler(Database * pDatabase)
// 			: m_pDB(pDatabase)
// 		{
// 
// 		}
// 
// 	public:
// 		virtual void Put(const leveldb::Slice& objKey, const leveldb::Slice& objValue)
// 		{
// 
// 		}
// 		virtual void Delete(const leveldb::Slice& objKey)
// 		{
// 
// 		}
// 
// 	private:
// 		Database * m_pDB;
// 	};
// 	 
// 	static void fnCustomCacheDeleter(const leveldb::Slice & objKey,void* pValue) 
// 	{
// 		std::string * p = (std::string*)pValue;
// 		delete p;
// 	}
// }
// 
// 
// 
// #endif