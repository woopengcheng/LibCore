// InnerMsgLib.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MsgInstance.h"
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/IMsgCallableObject.h"
#include "Timer/inc/TimerHelp.h"
#include "MsgLib/inc/Object.h" 
#include "MsgFuncCalls.h"
#include "MsgNameDefine.h" 
#include "CUtil/inc/Chunk.h"
#include "CUtil/inc/CUtil.h"
#include "MsgDefines.h"
#include "WorldObject.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CUtil::Init("InnerMsg");  
	Client::MsgInstance::GetInstance().Init(); 

	WorldObject objWorldObject;
	  
	std::vector<Msg::Object> targets;  //5 ��ʹ��Ӷ���Ҳ����Ч��.
	targets.push_back(Msg::Object(1)); 
	Client::rpc_Test('a' , 1 , 2 , 3 , 4 , "HelloWorld." , CUtil::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 

	Client::rpc_WorldTest('a' , 1 , 2 , 3 , 4 , "HelloWorld." , CUtil::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(1) , 1); 
	while (1)
	{
		Client::MsgInstance::GetInstance().Update();
		Timer::TimerHelper::sleep(10);  
	}

	Client::MsgInstance::GetInstance().Cleanup(); 
	return 0;
}

