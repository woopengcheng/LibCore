#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleCreateDatabase_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gOtherStream("createdb success.");
	}
	else
	{
		gOtherStream("createdb failure.");
	} 

	std::cout << "HandleCreateDatabase_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleCreateDatabase_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & dbname/* = std::string()*/) 
{


	std::cout << "HandleCreateDatabase_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

