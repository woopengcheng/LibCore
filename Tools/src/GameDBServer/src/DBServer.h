#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBServerInterface.h"


#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"

namespace Server
{  
	class  DBServer : public GameDB::DBServerInterface
	{ 
	public:
		DBServer(void)  
		{ 
		}
		virtual ~DBServer(void){} 

	public:
		static DBServer & GetInstance()
		{
			static DBServer m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public: 
		virtual void OnRegisterRpcs(void); 
		virtual INT32 Update(void)
		{ 
			GameDB::Database * pDB = m_pEnvironment->GetDatabase(".sys");
			if (!pDB)
			{
				return 1;
			}
// 			 
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
	};  
	 

}


#endif