#include "ClientCommands.h"
#include "RPCCallFuncs.h"
#include "GameDB/inc/User.h"
#include "OrmHelper.h"

namespace Client
{ 
#define CHECK_ARGS_GREAT_COUNT(argc , count) if( argc < count){ std::cout << "need " << count << " args." << std::endl; return ;}
#define CHECK_ARGS_EQUAL_COUNT(argc , count) if( argc != count){ std::cout << "need least " << count << " args." << std::endl; return ;}

	ClientCommands::ClientCommands()
	{
		InitCommands();
	}

	void ClientCommands::InitCommands()
	{
		m_mapCommands["hset"] = &ClientCommands::pfnHandleHSet;
		m_mapCommands["hget"] = &ClientCommands::pfnHandleHGet;
	} 

	void ClientCommands::Execute(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_GREAT_COUNT(argc , 1);

		CollectionClientCommandsT::iterator iter = m_mapCommands.find(argv[0]);
		if (iter != m_mapCommands.end())
		{
			iter->second(pClient , argc , argv);
		}
	}

	void ClientCommands::pfnHandleHSet(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

// 		std::vector<Msg::Object> targets;
// 		targets.push_back(Msg::Object(1));   
// 		Client::local_call_HandleHSet("tcp://127.0.0.1:8001" , argv[1] , argv[2] , argv[3] , targets , Msg::Object(0) , 1);

		GameDB::User user;
		user.set_name("Woo");
		user.set_pswd("peng");
		user.set_sysuser(true);

		GameDB::OrmHelper::OrmInsert(&user);

		std::cout << "pfnHandleHSet" << std::endl;
	}

	void ClientCommands::pfnHandleHGet(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 3);
// 
// 		std::vector<Msg::Object> targets;
// 		targets.push_back(Msg::Object(1));   
// 		Client::local_call_HandleHGet("tcp://127.0.0.1:8001" , argv[1] , argv[2]  , targets , Msg::Object(0) , 1);
// 		

		GameDB::User user;
		user.set_name("Woo");
		user.set_pswd("cheng");
		user.set_sysuser(true);

		GameDB::OrmHelper::OrmUpdate(&user);
		std::cout << "pfnHandleHGet" << std::endl;
	}


}