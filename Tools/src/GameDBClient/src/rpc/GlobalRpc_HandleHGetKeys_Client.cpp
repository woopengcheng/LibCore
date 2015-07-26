#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGetKeys_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/) 
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

	std::cout << "HandleHGetKeys_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGetKeys_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHGetKeys_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

