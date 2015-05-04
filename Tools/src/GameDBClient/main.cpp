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
#include "json/json.h" 
#include "MsgNameDefine.h"  
#include "RPCCallFuncs.h"
#include "DBClient.h" 
#include "Common/carg_parser.h"

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

INT32 HandLine(INT32 argc , char ** argv)
{ 
	struct Arg_parser::Option options[] = 
	{
		{ 'h',"hset",Arg_parser::yes, },
		{ 'p',"hget",Arg_parser::yes, },
		{ 'n',"prefix",Arg_parser::yes, },
		{ 's',"start",Arg_parser::yes, },
		{ 'e',"ended",Arg_parser::yes, },
		{ 'g',"spec pswd",Arg_parser::yes, },

		{ 'U',"user",Arg_parser::yes, },
		{ 'P',"pswd",Arg_parser::yes, },
		{ 'D',"dbname",Arg_parser::yes, },
	};

	Arg_parser parser(argc,argv,options,false);
	if(parser.error().length() > 0)
	{
		gErrorStream("error args:" << parser.error().c_str());
		return ERROR_ARGS;
	}

	std::string account;
	int start = 0;
	int ended = 0;

	for( int i = 0; i < parser.arguments(); ++i)
	{
		int code = parser.code(i);
		const char* arg = parser.argument(i).c_str();

		switch(code)
		{
		case 'N':
			account = arg;
			break;

		}
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{  
	LibCore::Init("DBClient"); 

	std::string defaultConf = "./gdbClient.conf";
	if(argc > 1)
		defaultConf = argv[1];
	
	Json::Value root;
	JsonParase(defaultConf.c_str() , root); 
	 
	Client::DBClient::GetInstance().Init(root); 
	  
	std::vector<Msg::Object> targets;
	targets.push_back(Msg::Object(1));   
	 
	while (1)
	{
		Client::DBClient::GetInstance().Update(); 
		 
		if (Client::DBClient::GetInstance().GetRpcClientManager()->IsAllConnected())
		{
			char * pLine = ReadLine();
			if (pLine == NULL)
			{
				break;
			}

			int argc = 0;
			char ** argv = NULL;
			ParseLine(pLine , argc , argv);
			
			INT32 nRes = HandLine(argc , argv);
			if (nRes > 0)
			{
				break;
			}
		}
		if( 0 < Client::local_call_HandleHSet("tcp://127.0.0.1:8001" , 1 , 2 , targets , Msg::Object(0) , 1))
		{ 
		}   
	}

	Client::DBClient::GetInstance().Cleanup(); 
	LibCore::Cleanup();
	 
	system("pause");
	return 0;














	LibCore::Cleanup(); 
	return 0;
}

