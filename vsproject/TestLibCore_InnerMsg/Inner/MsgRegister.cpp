#include "MsgLib/inc/MsgCommon.h"
#include "MsgInstance.h"
#include "MsgNameDefine.h" 
#include "MsgDefines.h"
#include "WorldObject.h"

namespace Client
{    
	void MsgInstance::OnRegisterMsgs( void )
	{    
		RegisterFunc(Client::g_szLocal_Test, Client::local_run_Test); 
		RegisterFunc<WorldObject>(Client::g_szLocal_TestObject , &WorldObject::local_run_Object_Test); 
	}
	  
}  