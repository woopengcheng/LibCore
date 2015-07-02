// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MsgInstance.h"
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/IMsgCallableObject.h"
#include "TimerLib/inc/TimerHelp.h"
#include "MsgLib/inc/Object.h" 
#include "MsgFuncCalls.h"
#include "MsgNameDefine.h" 
#include "Common/Chunk.h"
#include "Common/LibCore.h"
#include "MsgDefines.h"
#include "WorldObject.h"

int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("InnerMsg");  
	Client::MsgInstance::GetInstance().Init(); 

	WorldObject objWorldObject;
	  
	std::vector<Msg::Object> targets;  //5 即使添加对象也是无效的.
	targets.push_back(Msg::Object(1)); 
	Client::rpc_Test('a' , 1 , 2 , 3 , 4 , "HelloWorld." , LibCore::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 

	Client::rpc_WorldTest('a' , 1 , 2 , 3 , 4 , "HelloWorld." , LibCore::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 
	while (1)
	{
		Client::MsgInstance::GetInstance().Update();
		Timer::TimerHelper::sleep(10);  
	}

	Client::MsgInstance::GetInstance().Cleanup(); 
	return 0;
}

