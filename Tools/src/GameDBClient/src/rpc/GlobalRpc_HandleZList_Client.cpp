#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleZList_RpcClient(Net::ISession * pSession, Msg::Object objSrc , CUtilChunk & res/* = 0*/) 
{

	if (res.GetDataLen() != 0)
	{
		CUtil::CStream cs;
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
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleZList_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc ) 
{


	std::cout << "HandleZList_RpcTimeout" << std::endl;
	ReturnNULL;
}

