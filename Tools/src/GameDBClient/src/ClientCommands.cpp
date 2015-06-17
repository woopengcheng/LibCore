#include "ClientCommands.h"
#include "RPCCallFuncs.h"
#include "GameDB/inc/User.h"
#include "RoleCollection.h"
#include "RoleItems.h"
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
		m_mapCommands["hormset"] = &ClientCommands::pfnHandleOrmHSet;
		m_mapCommands["hormcollectinsert"] = &ClientCommands::pfnHandleOrmCollectInsert;
		m_mapCommands["dump"] = &ClientCommands::pfnHandleDump;
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

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHSet("tcp://127.0.0.1:8001" , argv[1] , argv[2] , argv[3] , targets , Msg::Object(0) , 1);

		gDebugStream( "pfnHandleHSet");
	}

	void ClientCommands::pfnHandleHGet(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 3);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHGet("tcp://127.0.0.1:8001" , argv[1] , argv[2]  , targets , Msg::Object(0) , 1);
		
		gDebugStream( "pfnHandleHGet");
	}

	void ClientCommands::pfnHandleOrmHSet(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 3);

		std::string strName = argv[1];
		std::string strPwd = argv[2];

		GameDB::User user;
		user.set_name(strName.c_str());
		user.set_pswd(strPwd.c_str());
		user.set_sysuser(true);

		GameDB::OrmHelper::OrmInsert(&user);

		gDebugStream( "pfnHandleOrmHSet");
	}

	void ClientCommands::pfnHandleOrmCollectInsert(DBClient * pClient , INT32 argc , char ** argv)
	{
//		CHECK_ARGS_EQUAL_COUNT(argc , 3);

		Orm::RoleCollection * pRoleCollection = new Orm::RoleCollection; 
		pRoleCollection->SetMasterID(1);

		Orm::Role * pRole = pRoleCollection->GetRole();
		if (pRole)
		{
			pRole->set_name("role");
			pRole->set_name("role pwd");
		}
		GameDB::OrmHelper::OrmUpdate(pRole);

		Orm::RoleItems * pRoleItems = pRoleCollection->NewRoleItems();
		pRoleItems->set_name("roleitems");
		pRoleItems->set_name("roleitems pwd");

		GameDB::OrmVectorEx<Orm::RoleItems *> & objRoleItems = pRoleCollection->GetRoleItems(); 
		for (int i = 0;i < objRoleItems.size();++i)
		{
			GameDB::OrmHelper::OrmInsert(objRoleItems[i]);
		}

		pRoleCollection->GetRoleItems().Cleanup(TRUE);
		gDebugStream( "pfnHandleOrmCollectInsert" );
	}

	void ClientCommands::pfnHandleDump(DBClient * pClient , INT32 argc , char ** argv)
	{   
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleDump("tcp://127.0.0.1:8001" , targets , Msg::Object(0) , 1);

		gDebugStream( "pfnHandleHGet"); 
	}
}