#include "GlobalRpc.h"
#include "SlaveHandler.h"

Msg::ObjectMsgCall * Server::SlaveHandler::SyncMasterHandler_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc ,INT32 id/* = 0*/)
{
	INT32 res = 0;
	
	Server::DBSlave::GetInstance().SetMasterSessionID(objSrc);
	std::cout << "SyncMasterHandler_RpcServer "<< std::endl;
	RPCReturn1(res);
}
