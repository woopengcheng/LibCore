#include "DBServer.h"
#include "RPCCallFuncs.h"
#include "Common/RemoteNodeDefine.h"

namespace Server
{   
	const int maxCount = 100;
	static UINT32 unCount = maxCount;
	INT32 DBServer::Update( void )
	{ 
		std::string strDB = "ll";
		while(unCount == 0)
		{
			Msg::VecObjects objTargets;
			objTargets.push_back(1);
			unCount = maxCount;
			rpc_testTheSameNode(g_netnodes[NETNODE_DBMASTER] , objTargets , 1 , strDB , LibCore::Chunk());
		}
		unCount--;

		return DBServerInterface::Update();
	}
	 
}