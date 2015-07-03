#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDump_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = 0*/) 
{
	std::string strKey, strVal;
	 
	LibCore::CStream objStream;
	objStream.Pushback(res.Begin() , res.GetDataLen());
	if (res.GetDataLen() == 0)
	{
		RPCReturnNULL;
	}

	INT32 nCount = 0; 
	objStream >> nCount;
	for (int i = 0 ;i < nCount;++i)
	{
		strKey = "";
		strVal = "";
		objStream >> strKey >> strVal;

		std::cout << strKey << strVal << std::endl;
	}

	std::cout << "HandleDump_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDump_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleDump_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

