// GenRpcs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>

#include "Common/LibCore.h" 
#include "Common/Chunk.h" 
#include "TimerLib/inc/TimerHelp.h"
#include "MsgNameDefine.h" 
#include "RPCCallFuncs.h"
#include "DBClient.h"
#include "MsgLib/inc/Object.h"
#include "DBClient.h"
#include "Common/LibCore.h" 
#include "json/json.h"
#include "TimerLib/inc/TimerHelp.h"
#include "DBClient.h"

INT64 g_time = 0;
int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBClient"); 

	std::string defaultConf = "./gdbClient.conf";
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
	 
	 
	Client::DBClient::GetInstance().Init(root); 

	g_time = Timer::TimerHelper::GetTickSecond();
	int gime = g_time;
	std::vector<Msg::Object> targets;
	targets.push_back(Msg::Object(1));  
	int m_asd = 9;

	int n = 100000;
	while (n)
	{
		Client::DBClient::GetInstance().Update(); 

		if( 0 < Client::local_call_HandleHSet("tcp://127.0.0.1:8001" , 1 , 2 , targets , Msg::Object(0) , 1))
		{
			n--;
		} 

		if (n % 100 == 0)
		{
			std::cout << "n " << n << std::endl;
			int nRemain = Timer::TimerHelper::GetTickSecond() - gime;
			gime = Timer::TimerHelper::GetTickSecond();
			std::cout << "timer " << nRemain << std::endl;
		}
	}
	g_time = Timer::TimerHelper::GetTickSecond() - g_time;
	std::cout << "timer" << g_time << std::endl;

	Client::DBClient::GetInstance().Cleanup(); 
	LibCore::Cleanup();


	system("pause");
	return 0;














	LibCore::Cleanup(); 
	return 0;
}

