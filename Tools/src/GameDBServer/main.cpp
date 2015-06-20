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
#include "DBSlave.h"
#include "MasterHandler.h"
#include "SlaveHandler.h"

int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBServer"); 

	std::string defaultConf = "./gdbServer.conf";
	if(argc > 1)
		defaultConf = argv[1];
	 
	Json::Value root;
	Json::JsonParase(defaultConf.c_str() , root); 

	std::string strRunMode = root.get("mode" , "master").asString();

	std::string strName , strPwd;
	if (strRunMode.compare("master") == 0)
	{
		Json::Value objMaster = root.get("master" , Json::Value());
		Server::DBMaster::GetInstance().Init(objMaster);

		Json::Value objDBServer = root.get("server" , Json::Value());
		Server::DBServer::GetInstance().Init(objDBServer);  

		static Server::ServerHandler  ObjTestObject(&Server::DBServer::GetInstance()); 
		static Server::MasterHandler  ObjMasterHandler(&Server::DBMaster::GetInstance()); 
	}
	else if (strRunMode.compare("slave") == 0)
	{
		Json::Value objSlave = root.get("slave" , Json::Value());
		Server::DBSlave::GetInstance().Init(objSlave);
		static Server::SlaveHandler  ObjSlaveHandler(&Server::DBSlave::GetInstance()); 

		strName = objSlave.get("login_user" , "test").asString();
		strPwd = objSlave.get("login_pswd" , "test").asString();
	}
	else
	{
		gErrorStream("wrong mode in " << defaultConf);
		return 0;
	}

	gDebugStream("waiting slave connect master.");
	//5 等待slave连接成功,并且请求数据
	while(1)
	{
		if (strRunMode.compare("slave") != 0 && Server::DBServer::GetInstance().GetRpcClientManager()->IsAllConnected())
		{
			Server::DBSlave::GetInstance().StartAuth(strName , strPwd);
			gDebugStream("slave connect success.");
			break;
		}
	}

	while (1)
	{
		if (strRunMode.compare("slave") != 0)
			Server::DBSlave::GetInstance().Update();

		Timer::TimerHelper::sleep(1);
	}

	Server::DBServer::GetInstance().Cleanup();  
	LibCore::Cleanup();
	 
	return 0;
}

