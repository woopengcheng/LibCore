#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSet_RpcServer(INT32 userid/* = 0*/ , INT32 localid/* = 1*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 resCode = 0;


	std::cout << "HandleHSet_RpcServer "<< std::endl;
	RPCReturn1(resCode);
}

