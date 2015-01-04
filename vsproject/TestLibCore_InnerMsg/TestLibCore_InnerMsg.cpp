// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InnerMsg.h"
#include "ObjectMsgCall.h"
#include "TimerHelp.h"
#include "ICallableObject.h"
#include "MsgProxy.h"
#include "MsgNameDefine.h" 
#include "Object.h" 
#include "Chunk.h"
#include "LibCore.h"


class WorldObject : public Msg::IMsgCallableObject
{ 
public:
	Msg::ObjectMsgCall *  local_run_Object_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 ,Msg:: Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc);

public:
	WorldObject():IMsgCallableObject(Msg::Object(1)){}
	~WorldObject(){}

public:
	INT32 Handle(){ printf("WorldObject\n");return 1;}

};

Msg::ObjectMsgCall *  WorldObject::local_run_Object_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 ,Msg:: Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc)
{
	printf("local_call_Object_Test."); 

	return NULL;
}


int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("InnerMsg");  
	Msg::InnerMsg::GetInstance().Init(); 

	WorldObject objWorldObject;

	Msg::InnerMsg::GetInstance().AddCallableObject(&objWorldObject);
 	Msg::InnerMsg::GetInstance().RegisterFunc(Msg::g_szLocal_Test, Msg::local_run_Test); 
	Msg::InnerMsg::GetInstance().RegisterFunc<WorldObject>(Msg::g_szLocal_TestObject , &WorldObject::local_run_Object_Test); 

	std::vector<Msg::Object> targets;
	targets.push_back(Msg::Object(1)); 
	Msg::local_call_Test('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 

	Msg::local_call_WorldTest('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 
	while (1)
	{
		Timer::TimerHelper::sleep(1000);  
	}

	Msg::InnerMsg::GetInstance().Cleanup(); 
	return 0;
}

