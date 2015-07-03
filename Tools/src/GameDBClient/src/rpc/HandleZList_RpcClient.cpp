#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZList_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = 0*/) 
{

	if (res.GetDataLen() != 0)
	{
		LibCore::CStream cs;
		cs.Pushback(res.GetBuf() , res.GetDataLen());

		INT32 nCount = 0;
		cs >> nCount;

		std::string strKey;
		for (INT32 i = 0;i < nCount;++i)
		{
			cs >> strKey;
			gOtherStream("i:" << i << "key:" << strKey);
		}
	}
	else
	{
		gWarniStream("get error.");
	}

	std::cout << "HandleZList_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZList_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc ) 
{


	std::cout << "HandleZList_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

