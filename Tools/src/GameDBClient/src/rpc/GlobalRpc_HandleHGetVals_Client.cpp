#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHGetVals_RpcClient(Net::ISession * pSession, Msg::Object objSrc , CUtilChunk & res/* = CUtil::Chunk()*/) 
{
	if (res.GetDataLen() != 0)
	{
		CUtil::CStream cs;
		cs.Pushback(res.GetBuf() , res.GetDataLen());

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
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHGetVals_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHGetVals_RpcTimeout" << std::endl;
	ReturnNULL;
}

