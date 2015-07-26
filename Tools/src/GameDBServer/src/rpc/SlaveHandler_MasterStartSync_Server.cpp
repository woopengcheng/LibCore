#include "GlobalRpc.h"
#include "SlaveHandler.h"

Msg::ObjectMsgCall * Server::SlaveHandler::MasterStartSync_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/  )
{
	INT32 res = 0;
		
	RecvFile(m_objSlaveInfo.strDir , filename , m_objSlaveInfo.strDBName , filesize , sendtype , value ); 

	std::cout << "MasterStartSync_RpcServer "<< std::endl;
	RPCReturn1(res);
}

