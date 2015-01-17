#pragma once
#include "MsgInstance.h"
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/IMsgCallableObject.h"
#include "TimerLib/inc/TimerHelp.h"
#include "MsgFuncCalls.h"
#include "MsgNameDefine.h" 
#include "MsgLib/inc/Object.h" 
#include "Common/Chunk.h"
#include "Common/LibCore.h"
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
