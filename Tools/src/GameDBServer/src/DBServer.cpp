#include "DBServer.h"

namespace Server
{   
	INT32 DBServer::Update( void )
	{ 
		GameDB::Database * pDB = m_pEnvironment->GetDatabase(g_szSystemDatabase);
		if (!pDB)
		{
			return 1;
		}
					 
// 			GameDB::Status s = pDB->QuickWrite("woo" , "peng"); 
// 			if (s.ok())
// 			{
// 				gDebugStream("HSet: "  << "success."); 
// 			}
// 
// 			std::string val;
// 			GameDB::Status s2 = pDB->QuickGet("woo" , val);
// 			if (s2.ok())
// 			{
// 				gDebugStream("HGet: " << val << " success."); 
// 			}
// 		
// 			leveldb::Iterator* iter = pDB->GetLevelDB()->NewIterator(leveldb::ReadOptions());
// 			iter->SeekToFirst();
// 			while(iter->Valid())
// 			{
// 				GameDB::Slice key = iter->key();
// 				GameDB::Slice val = iter->value();
// 
// 				gDebugStream("HGet: "<< (char *)key.data()  << "  "  << (char *)val.data() << " success."); 
// 				iter->Next();
// 			}
// 			delete iter;

		return DBServerInterface::Update();
	}
	 
}