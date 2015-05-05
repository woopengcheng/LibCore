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

int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBServer"); 

	std::string defaultConf = "./gdbServer.conf";
	if(argc > 1)
		defaultConf = argv[1];
	
	std::fstream fs;
	fs.open(defaultConf.c_str(),std::ios_base::in);
	if(!fs.good())
	{
		std::cerr << "Open Configure File " << defaultConf << " Failed" << std::endl;
		return 1;
	}
	Json::Value root;
	Json::Reader reader;
	if(!reader.parse(fs,root))
	{
		std::cerr << "Parse Configure File Failed:" << reader.getFormatedErrorMessages() << std::endl;
		return 1;
	}
	fs.close();

	Server::DBServer::GetInstance().Init(root); 

	Server::ServerHandler  ObjTestObject(&Server::DBServer::GetInstance());   
	while (1)
	{
		Server::DBServer::GetInstance().Update();
	}

	Server::DBServer::GetInstance().Cleanup();  
	LibCore::Cleanup();
	 
	return 0;
}

