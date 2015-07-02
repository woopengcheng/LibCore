// GenRpcs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>

#include "Common/LibCore.h" 
#include "Common/Chunk.h" 
#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/Object.h"
#include "TimerLib/inc/TimerHelp.h" 
#include "Common/carg_parser.h"
#include "json/json.h" 
#include "MsgNameDefine.h"  
#include "RPCCallFuncs.h"
#include "DBClient.h" 
#include "ClientCommands.h"

enum ClientError
{
	ERROR_ARGS = 0,
};

char * ReadLine()
{
	static char line[1024] = "";

	std::cout << "GameDBClient>";
	Timer::TimerHelper::sleep(1000);
	
	if (!std::cin.good())
	{
		return NULL;
	}

	std::cin.getline(line , sizeof(line));

	return line;
}

void ParseLine( char * line , INT32 & argc , char ** argv)
{ 
	int result = 0;
	char* curr = line;
	char* last = curr;
	char  pre = ' ';
	while(*curr != 0)
	{
		if (*curr == ' ' && pre == ' ')
		{
			pre = *curr;
			++curr;
			continue;
		}

		if(*curr == ' ')
		{
			argv[result] = last;
			last = &curr[1];
			++result;
			*curr = 0;
		}
		pre = *curr;
		++curr;
	}
	if(*last != 0)
	{
		argv[result] = last;
		result++;
	}
	argc = result;
} 

int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBClient"); 

	std::string defaultConf = "./gdbClient.conf";
	if(argc > 1)
		defaultConf = argv[1];
	
	Json::Value root;
	JsonParase(defaultConf.c_str() , root); 
	 
	//5 连接服务器,并建立双连接..
	Client::DBClient::GetInstance().Init(root);  
	while (!Client::DBClient::GetInstance().GetRpcClientManager()->IsAllConnected())
	{
		Client::DBClient::GetInstance().Update(); 
		Timer::TimerHelper::sleep(1);
	}
	
	Client::ClientCommands clientComands; 
	std::string strName = root.get("user" , "admin" ).asString();
	std::string strPwd = root.get("pwd" , "admin").asString();

	std::vector<Msg::Object> vecTargets;
	vecTargets.push_back(Msg::Object(1));
	Client::rpc_HandleUserAuth("tcp://127.0.0.1:8001" , strName , strPwd , vecTargets , Msg::Object(1) , 0 , Msg::SYNC_TYPE_NONSYNC);

	int nargc = 0;
	char pargv[10][256];
	char **parg = (char **)pargv;
	while (1)
	{
		Client::DBClient::GetInstance().Update(); 

		if (!Client::DBClient::GetInstance().GetRpcClientManager()->IsAllConnected())
		{ 
			continue;
		}

		if (Client::DBClient::GetInstance().GetRpcClientManager()->IsAllConnected())
		{
			char * pLine = ReadLine();
			if (pLine == NULL)
			{
				break;
			}
			if (strcmp("exit" , pLine) == 0)
			{
				return -1;
			}

			ParseLine(pLine , nargc , parg);
			 
			clientComands.Execute(&Client::DBClient::GetInstance() , nargc , parg);
		}
// 		if( 0 < Client::rpc_HandleHSet("tcp://127.0.0.1:8001" , 1 , 2 , targets , Msg::Object(0) , 1))
// 		{ 
// 		}   
	}

	Client::DBClient::GetInstance().Cleanup(); 
	LibCore::Cleanup();
	 
	system("pause");
	return 0;














	LibCore::Cleanup(); 
	return 0;
}

