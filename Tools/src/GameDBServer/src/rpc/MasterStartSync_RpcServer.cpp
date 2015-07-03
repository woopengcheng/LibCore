#include "GlobalRpc.h"
#include "SlaveHandler.h"

Msg::ObjectMsgCall * Server::SlaveHandler::MasterStartSync_RpcServer(std_string &filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = 0;

	if (GetSession() && GetSession()->GetOtherSession())
	{
		GameDB::SlaveSession * pSession = (GameDB::SlaveSession *)GetSession()->GetOtherSession();
		RecvFile(pSession->GetSlaveInfo().strDir , filename , pSession->GetSlaveInfo().strDBName , filesize , sendtype , value ); 
	}


	std::cout << "MasterStartSync_RpcServer "<< std::endl;
	RPCReturn1(res);
}

