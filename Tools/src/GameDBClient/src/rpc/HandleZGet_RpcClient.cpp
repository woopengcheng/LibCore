#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZGet_RpcClient(INT64 score/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	RPCMsgCall * pMsg = GetRpcMsgCall();
	if (pMsg)
	{
		gDebugStream("zget table:" << pMsg->m_objParams.GetValue<std::string>(0) << "key:" << pMsg->m_objParams.GetValue<std::string>(1) << "score:" << score);
	}

	std::cout << "HandleZGet_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZGet_RpcTimeout(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleZGet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

