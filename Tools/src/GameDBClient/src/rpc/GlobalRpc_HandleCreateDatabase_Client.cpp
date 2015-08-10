#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleCreateDatabase_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
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
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleCreateDatabase_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & dbname/* = std::string()*/) 
{


	std::cout << "HandleCreateDatabase_RpcTimeout" << std::endl;
	ReturnNULL;
}

