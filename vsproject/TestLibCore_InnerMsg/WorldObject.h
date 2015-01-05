#pragma once
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


class WorldObject : public Msg::IMsgCallableObject
{  
	MSG_DEFINE_Object_Test

public:
	WorldObject()
		:IMsgCallableObject(&Client::MsgInstance::GetInstance() , Msg::Object(1))
	{}
	~WorldObject(){}

public:
	INT32 Handle(){ printf("WorldObject\n");return 1;}

};
