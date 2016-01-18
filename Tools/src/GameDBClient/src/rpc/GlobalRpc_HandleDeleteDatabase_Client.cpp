#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleDeleteDatabase_RpcClient(INT32 nSessionID , Msg::Object objSrc , INT32 res/* = 0*/) 
{ 
	if (res == 0)
	{
		gOtherStream("DeleteDatabase success.");
	}
	else
	{
		gOtherStream("DeleteDatabase failure.");
	}

	std::cout << "HandleDeleteDatabase_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleDeleteDatabase_RpcTimeout(INT32 nSessionID , Msg::Object objSrc , std_string & dbname/* = std::string()*/) 
{


	std::cout << "HandleDeleteDatabase_RpcTimeout" << std::endl;
	ReturnNULL;
}

