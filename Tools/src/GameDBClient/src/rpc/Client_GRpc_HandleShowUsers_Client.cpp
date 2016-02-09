#include "GRpc.h"

Msg::ObjectMsgCall * Client::GRpc::HandleShowUsers_RpcClient(INT32 nSessionID , Msg::Object objSrc , CUtilChunk & res/* = CUtil::Chunk()*/)
{
	if (res.GetDataLen() != 0)
	{
		CUtil::CStream cs(res.Begin() , res.GetDataLen());

		INT32 nCount = 0;
		cs >> nCount;

		std::string strKey;
		for (INT32 i = 0;i < nCount;++i)
		{
			cs >> strKey;
			gOtherStream("num:" << i << "user:" << strKey);
		}
	}
	else
	{
		gWarniStream("get error.");
	}

	std::cout << "HandleShowUsers_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GRpc::HandleShowUsers_RpcTimeout(INT32 nSessionID , Msg::Object objSrc )
{


	std::cout << "HandleShowUsers_RpcTimeout" << std::endl;
	ReturnNULL;
}

