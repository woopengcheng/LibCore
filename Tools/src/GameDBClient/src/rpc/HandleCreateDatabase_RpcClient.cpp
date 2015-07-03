#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleCreateDatabase_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleCreateDatabase_RpcTimeout(std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleCreateDatabase_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

