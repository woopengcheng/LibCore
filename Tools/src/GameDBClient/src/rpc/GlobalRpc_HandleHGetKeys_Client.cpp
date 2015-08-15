#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHGetKeys_RpcClient(Net::ISession * pSession, Msg::Object objSrc , CUtilChunk & res/* = CUtil::Chunk()*/) 
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

	std::cout << "HandleHGetKeys_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHGetKeys_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHGetKeys_RpcTimeout" << std::endl;
	ReturnNULL;
}
