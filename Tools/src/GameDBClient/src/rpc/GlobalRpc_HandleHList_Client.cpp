#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHList_RpcClient(Net::ISession * pSession, Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/) 
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


	std::cout << "HandleHList_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHList_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc) 
{


	std::cout << "HandleHList_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

