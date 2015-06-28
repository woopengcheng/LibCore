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
		m_mapCommands["help"] = &ClientCommands::pfnHandleHelp;

		//5 数据库相关操作
		m_mapCommands["selectdb"] = &ClientCommands::pfnHandleSelectDatabase;
		m_mapCommands["createdb"] = &ClientCommands::pfnHandleCreateDatabase;
		m_mapCommands["deletedb"] = &ClientCommands::pfnHandleDeleteDatabase;
		m_mapCommands["showdatabases"] = &ClientCommands::pfnHandleShowDatabases;

		//5 添加,删除,修改用户权限 
		m_mapCommands["createuser"] = &ClientCommands::pfnHandleCreateUser;
		m_mapCommands["deleteuser"] = &ClientCommands::pfnHandleDeleteUser;
		m_mapCommands["modifyuser"] = &ClientCommands::pfnHandleModifyUser;

		//5 数据库数据修改
		m_mapCommands["hset"] = &ClientCommands::pfnHandleHSet;
		m_mapCommands["hget"] = &ClientCommands::pfnHandleHGet;
		m_mapCommands["hsetnx"] = &ClientCommands::pfnHandleHSetNX;
		m_mapCommands["hsetow"] = &ClientCommands::pfnHandleHSetOW;
		m_mapCommands["hdel"] = &ClientCommands::pfnHandleHDel;
		m_mapCommands["hmultiset"] = &ClientCommands::pfnHandleHMultiSet;
		m_mapCommands["hmultiget"] = &ClientCommands::pfnHandleHMultiGet;
		m_mapCommands["hmultidel"] = &ClientCommands::pfnHandleHMultiDel;
		m_mapCommands["hsetincr"] = &ClientCommands::pfnHandleHSetIncr;
		m_mapCommands["hsetincrfloat"] = &ClientCommands::pfnHandleHSetIncrFloat;
		m_mapCommands["hgetkeys"] = &ClientCommands::pfnHandleHGetKeys; 
		m_mapCommands["hgetvals"] = &ClientCommands::pfnHandleHGetVals;
		m_mapCommands["hgetkeyvals"] = &ClientCommands::pfnHandleHKeyVals;
		m_mapCommands["hscan"] = &ClientCommands::pfnHandleHScan;
		m_mapCommands["hcount"] = &ClientCommands::pfnHandleHCount;
		m_mapCommands["hdrop"] = &ClientCommands::pfnHandleHDrop;
		m_mapCommands["hlist"] = &ClientCommands::pfnHandleHList;

		m_mapCommands["zset"] = &ClientCommands::pfnHandleZSet;
		m_mapCommands["zget"] = &ClientCommands::pfnHandleZGet;
		m_mapCommands["ztop"] = &ClientCommands::pfnHandleZTop;
		m_mapCommands["zrtop"] = &ClientCommands::pfnHandleZRTop;
		m_mapCommands["zdel"] = &ClientCommands::pfnHandleZDel;
		m_mapCommands["zdrop"] = &ClientCommands::pfnHandleZDrop;
		m_mapCommands["zcount"] = &ClientCommands::pfnHandleZCount;
		m_mapCommands["zlist"] = &ClientCommands::pfnHandleZList; 

		m_mapCommands["dump"] = &ClientCommands::pfnHandleDump;

		m_mapCommands["hormset"] = &ClientCommands::pfnHandleOrmHSet;
		m_mapCommands["hormcollectinsert"] = &ClientCommands::pfnHandleOrmCollectInsert;

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

	void ClientCommands::pfnHandleHelp(DBClient * pClient , INT32 argc , char ** argv)
	{
		printf("command list: \n"
			"\t""showdatabases"                      "\n" 
			"\t""createdb dbname"                      "\n"
			"\t""selectdb dbname"                      "\n"
			"\t""deletedb dbname"                      "\n"
			"\n"
			"\t""createuser name"                      "\n" 
			"\t""deleteuser name"                      "\n"
			"\t""modifyuser name"                      "\n"
			"\n"
			"\t""hget table key"                      "\n"
			"\t""hset table key value"                "\n"
			"\t""hdel table key"                      "\n"
			"\t""hsetnx table key value"              "\n"
			"\t""hmultiset table key1 val1 key2 val2 ..." "\n"
			"\t""hmultiget table key1 key2 ..."       "\n"
			"\t""hmultidel table key1 key2 ..."           "\n"
			"\t""hsetincr table key int64value"            "\n"
			"\t""hsetincrfloat table key doublevalue"      "\n"
			"\t""hkeysvals table"                              "\n"
			"\t""hkeys table"                              "\n"
			"\t""hvals table"                              "\n"
			"\t""hdrop table"                            "\n"
			"\t""hcount table"								"\n"
			"\t""hlist"								"\n"
			"\n" 
			"\t""zget table key"                          "\n"
			"\t""zset table key score"                    "\n"
			"\t""zdel table key"                          "\n"
			"\t""ztop table min max"                      "\n"
			"\t""zrtop table min max"                     "\n"
			"\t""zdrop table"                            "\n"
			"\t""zcount table"                            "\n"
			"\t""zlist "                            "\n"
			"\n"
			"\t""dump"                                   "\n"
			);
	}

	void ClientCommands::pfnHandleShowDatabases(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));  
		
		Client::local_call_HandleShowDatabases("tcp://127.0.0.1:8001" ,  targets , Msg::Object(0) , 1);
	}

	void ClientCommands::pfnHandleSelectDatabase(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));  
		 
		Client::local_call_HandleSelectDatabase("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1);
	}

	void ClientCommands::pfnHandleCreateDatabase(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));  


		Client::local_call_HandleCreateDatabase("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1);
	}

	void ClientCommands::pfnHandleDeleteDatabase(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   

		Client::local_call_HandleDeleteDatabase("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1);
	} 

	void ClientCommands::pfnHandleCreateUser(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

		SINT8 isSys = atoi(argv[3]);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleCreateUser("tcp://127.0.0.1:8001" , argv[1] , argv[2] , isSys , targets , Msg::Object(0) , 1);

		gDebugStream( "pfnHandleCreateUser"); 
	}

	void ClientCommands::pfnHandleDeleteUser(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));  
		 
		Client::local_call_HandleDeleteUser("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1);
	}

	void ClientCommands::pfnHandleModifyUser(DBClient * pClient , INT32 argc , char ** argv)
	{ 
		SINT8 isSys = LibCore::atoi(argv[3]);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleCreateUser("tcp://127.0.0.1:8001" , argv[1] , argv[2] , isSys , targets , Msg::Object(0) , 1);
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


	void ClientCommands::pfnHandleHSetNX(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHSetNX("tcp://127.0.0.1:8001" , argv[1] , argv[2] , argv[3] , targets , Msg::Object(0) , 1);
		
	}

	void ClientCommands::pfnHandleHSetOW(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHSetOW("tcp://127.0.0.1:8001" , argv[1] , argv[2] , argv[3] , targets , Msg::Object(0) , 1);

	}

	void ClientCommands::pfnHandleHDel(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 3);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHDel("tcp://127.0.0.1:8001" , argv[1] , argv[2] , targets , Msg::Object(0) , 1);

	}

	void ClientCommands::pfnHandleHMultiSet(DBClient * pClient , INT32 argc , char ** argv)
	{

	}

	void ClientCommands::pfnHandleHMultiGet(DBClient * pClient , INT32 argc , char ** argv)
	{

	}

	void ClientCommands::pfnHandleHMultiDel(DBClient * pClient , INT32 argc , char ** argv)
	{

	}

	void ClientCommands::pfnHandleHSetIncr(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

		INT64 llCount = LibCore::atoi(argv[3]);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHSetIncr("tcp://127.0.0.1:8001" , argv[1] , argv[2] ,llCount , targets , Msg::Object(0) , 1);

	}

	void ClientCommands::pfnHandleHSetIncrFloat(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

		double llCount = LibCore::atof(argv[3]);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHSetIncr("tcp://127.0.0.1:8001" , argv[1] , argv[2] ,llCount , targets , Msg::Object(0) , 1);

	}

	void ClientCommands::pfnHandleHGetKeys(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2); 

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHGetKeys("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1);

	}

	void ClientCommands::pfnHandleHGetVals(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2); 

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHGetVals("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1);

	}

	void ClientCommands::pfnHandleHKeyVals(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2); 

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHGetKeyVals("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1); 
	}

	void ClientCommands::pfnHandleHScan(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 5); 
		INT64 llLimit = LibCore::atoi(argv[4]);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHScan("tcp://127.0.0.1:8001" , argv[1] , argv[2] , argv[3] , llLimit , targets , Msg::Object(0) , 1); 

	}

	void ClientCommands::pfnHandleHCount(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2); 

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHCount("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1); 

	}

	void ClientCommands::pfnHandleHDrop(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2); 

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHDrop("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1); 

	}

	void ClientCommands::pfnHandleHList(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleHList("tcp://127.0.0.1:8001" , targets , Msg::Object(0) , 1); 

	}

	void ClientCommands::pfnHandleDump(DBClient * pClient , INT32 argc , char ** argv)
	{   
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleDump("tcp://127.0.0.1:8001" , targets , Msg::Object(0) , 1);

		gDebugStream( "pfnHandleDump"); 
	}
	
	void ClientCommands::pfnHandleZSet(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 4);

		INT64 llScore = LibCore::atoi(argv[3]);
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleZSet("tcp://127.0.0.1:8001" , argv[1] , argv[2] , llScore , targets , Msg::Object(0) , 1);

		gDebugStream( "pfnHandleZSet");

	}

	void ClientCommands::pfnHandleZGet(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 3);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleZGet("tcp://127.0.0.1:8001" , argv[1] , argv[2]  , targets , Msg::Object(0) , 1);

		gDebugStream( "pfnHandleZGet");

	}
	void ClientCommands::pfnHandleZTop(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_GREAT_COUNT(argc , 3);

		INT64 llStart = 0, llEnd = 0, llLimit = 0;
		if (argc == 5)
		{
			llStart = LibCore::atoi(argv[2]);
			llEnd = LibCore::atoi(argv[3]);
			llLimit = LibCore::atoi(argv[4]);
		}
		else
		{
			llLimit = LibCore::atoi(argv[2]);
		}
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1)); 

		Client::local_call_HandleZTop("tcp://127.0.0.1:8001" , argv[1] , llStart  , llEnd , llLimit , targets , Msg::Object(0) , 1);
		
		gDebugStream( "pfnHandleZTop");

	}
	void ClientCommands::pfnHandleZRTop(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_GREAT_COUNT(argc , 3);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));  

		INT64 llStart = 0, llEnd = 0, llLimit = 0;
		
		if (argc == 5)
		{
			llStart = LibCore::atoi(argv[2]);
			llEnd = LibCore::atoi(argv[3]);
			llLimit = LibCore::atoi(argv[4]);
		}
		else
		{
			llLimit = LibCore::atoi(argv[2]);
		} 
		
		Client::local_call_HandleZRTop("tcp://127.0.0.1:8001" , argv[1] , llStart , llEnd , llLimit, targets , Msg::Object(0) , 1);
		 
		gDebugStream("pfnHandleZRTop"); 
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

	void ClientCommands::pfnHandleZDel(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 3);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleZDel("tcp://127.0.0.1:8001" , argv[1] , argv[2] , targets , Msg::Object(0) , 1); 

	}

	void ClientCommands::pfnHandleZDrop(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleZDrop("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1); 
	}

	void ClientCommands::pfnHandleZCount(DBClient * pClient , INT32 argc , char ** argv)
	{
		CHECK_ARGS_EQUAL_COUNT(argc , 2);

		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleZDrop("tcp://127.0.0.1:8001" , argv[1] , targets , Msg::Object(0) , 1); 

	}

	void ClientCommands::pfnHandleZList(DBClient * pClient , INT32 argc , char ** argv)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Client::local_call_HandleZList("tcp://127.0.0.1:8001" , targets , Msg::Object(0) , 1);  
	}

}