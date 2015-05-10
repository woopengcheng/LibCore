// GenRpcs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>

#include "TimerLib/inc/TimerHelp.h"
#include "Common/LibCore.h" 
#include "json/json.h"
#include "ServerHandler.h"  
#include "DBServer.h"
#include "DBMaster.h"

int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBServer"); 

	std::string defaultConf = "./gdbServer.conf";
	if(argc > 1)
		defaultConf = argv[1];
	 
	Json::Value root;
	Json::JsonParase(defaultConf.c_str() , root); 

	Json::Value objDBServer = root.get("db_server" , Json::Value());
	Server::DBServer::GetInstance().Init(objDBServer); 

	Json::Value objMaster = root.get("master_server" , Json::Value());
	Server::DBMaster::GetInstance().Init(objMaster);

	Server::ServerHandler  ObjTestObject(&Server::DBServer::GetInstance());   
	while (1)
	{
		Server::DBServer::GetInstance().Update();
	}

	Server::DBServer::GetInstance().Cleanup();  
	LibCore::Cleanup();
	 
	return 0;
}

