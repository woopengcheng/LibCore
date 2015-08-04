#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGetKeyVals_RpcClient(Net::ISession * pSession, Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/) 
{ 
	if (res.GetDataLen() != 0)
	{
		LibCore::CStream cs;
		cs.Pushback(res.GetBuf() , res.GetDataLen());

		INT32 nCount = 0;
		cs >> nCount;

		std::string strKey;
		std::string strVal;
		for (INT32 i = 0;i < nCount;++i)
		{
			cs >> strKey >> strVal;
			gOtherStream("i:" << i << "key:" << strKey << "value:" << strVal);
		}
	}
	else
	{
		gWarniStream("get error.");
	}


	std::cout << "HandleHGetKeyVals_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGetKeyVals_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHGetKeyVals_RpcTimeout" << std::endl;
	ReturnNULL;
}

