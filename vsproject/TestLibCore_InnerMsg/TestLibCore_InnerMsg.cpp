// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MsgInstance.h"
#include "ObjectMsgCall.h"
#include "TimerHelp.h"
#include "IMsgCallableObject.h"
#include "MsgFuncCalls.h"
#include "MsgNameDefine.h" 
#include "Object.h" 
#include "Chunk.h"
#include "LibCore.h"
#include "MsgDefines.h"
#include "WorldObject.h"

int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("InnerMsg");  
	Client::MsgInstance::GetInstance().Init(); 

	WorldObject objWorldObject;
	  
	std::vector<Msg::Object> targets;
	targets.push_back(Msg::Object(1)); 
	Client::local_call_Test('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 

	Client::local_call_WorldTest('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 
	while (1)
	{
		Client::MsgInstance::GetInstance().Update();
		Timer::TimerHelper::sleep(10);  
	}

	Client::MsgInstance::GetInstance().Cleanup(); 
	return 0;
}

