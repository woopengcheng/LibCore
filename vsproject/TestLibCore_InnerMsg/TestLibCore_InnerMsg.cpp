// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InnerMsg.h"
#include "ObjectMsgCall.h"
#include "TimerHelp.h"
#include "ICallableObject.h"
#include "MsgProxy.h"
#include "MsgNameDefine.h" 
#include "Chunk.h"


class WorldObject : public Msg::IMsgCallableObject
{ 
	DECLARE_MSG_WORLD_OBJECT
public:
	WorldObject():IMsgCallableObject(1){}
	~WorldObject(){}

public:
	INT32 Handle(){ printf("WorldObject\n");return 1;}

};

void  WorldObject::local_run_Object_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 ,Msg:: Chunk p7 , std::vector<MSG_ID> vecTargets , MSG_ID objSrc)
{
	printf("local_call_Object_Test."); 
}


int _tmain(int argc, _TCHAR* argv[])
{
	Msg::InnerMsg<MSG_ID>::GetInstance().Init(); 

	WorldObject objWorldObject;

	Msg::InnerMsg<MSG_ID>::GetInstance().AddCallableObject(&objWorldObject);
	Msg::InnerMsg<MSG_ID>::GetInstance().RegisterFunc<MSG_ID>(Msg::sz_local_call_Test , Msg::local_run_Test<MSG_ID>); 
	Msg::InnerMsg<MSG_ID>::GetInstance().RegisterFunc<MSG_ID , WorldObject>(Msg::sz_local_call_WorldTest , &WorldObject::local_run_Object_Test); 

	std::vector<MSG_ID> targets;
	targets.push_back(1); 
	Msg::local_call_Test<MSG_ID>('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , 1 , 1); 

	Msg::local_call_WorldTest<MSG_ID>('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , 1 , 1); 
	while (1)
	{
		Timer::TimerHelper::sleep(1000);  
	}

	Msg::InnerMsg<UINT64>::GetInstance().Cleanup(); 
	return 0;
}

