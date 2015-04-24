// GenRpcs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>

#include "DBClient.h"
#include "Common/LibCore.h" 
#include "json/json.h"
#include "TimerLib/inc/TimerHelp.h"

int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBServer"); 

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

	DB::DBClient db;
	db.Init(root);

	while(1)
	{
		db.Update();

		char pBuf[1024]; 
		((Net::MsgHeader*)pBuf)->unMsgID = 0;
		((Net::MsgHeader*)pBuf)->unMsgLength = 6+ sizeof(Net::MsgHeader);
		memcpy(pBuf + sizeof(Net::MsgHeader) , "asdfa" , 6);

		if (db.GetNetHandler())
		{
			db.GetNetHandler()->SendMsg(pBuf , 6 + sizeof(Net::MsgHeader));
		} 
		Timer::TimerHelper::sleep(1);
	}

	db.Cleanup();

	LibCore::Cleanup(); 
	return 0;
}

