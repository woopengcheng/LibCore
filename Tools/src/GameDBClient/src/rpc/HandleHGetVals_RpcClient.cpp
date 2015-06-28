#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGetVals_RpcClient(LibCore_Chunk res/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	if (res.GetDataLen() != 0)
	{
		LibCore::CStream cs;
		cs << res;

		INT32 nCount = 0;
		cs >> nCount;
		 
		std::string strVal;
		for (INT32 i = 0;i < nCount;++i)
		{
			cs >> strVal;
			gOtherStream("i:" << i << "value:" << strVal);
		}
	}
	else
	{
		gWarniStream("get error.");
	}



	std::cout << "HandleHGetVals_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGetVals_RpcTimeout(std_string table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHGetVals_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

