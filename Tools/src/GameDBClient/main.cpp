// GenRpcs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>

#include "CUtil/inc/CUtil.h" 
#include "CUtil/inc/Chunk.h" 
#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/Object.h"
#include "Timer/inc/TimerHelp.h" 
#include "CUtil/inc/carg_parser.h"
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

void PackParams( std::vector<std::string> & vecParams , INT32 argc , char ** argv)
{ 
	if (argc <= 0)
	{
		return;
	}
	else
	{
		int i = 0;
		while(i < argc)
		{
			vecParams.push_back(argv[i]);
			++i;
		}
	}
} 
int _tmain(int argc, _TCHAR* argv[])
{  
	CUtil::Init("DBClient"); 

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
	 
	Client::rpc_HandleUserAuth("tcp://127.0.0.1:8001" , 1 , 0 , strName , strPwd, 0 , Msg::SYNC_TYPE_NONSYNC);

	std::vector<std::string> vecParams;
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

			vecParams.clear();
			ParseLine(pLine , nargc , parg);
			PackParams(vecParams , nargc , parg);
			 
			clientComands.Execute(&Client::DBClient::GetInstance() , vecParams);
		}
	}

	Client::DBClient::GetInstance().Cleanup(); 
	CUtil::Cleanup();
	 
	system("pause");
	return 0;














	CUtil::Cleanup(); 
	return 0;
}

