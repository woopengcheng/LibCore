#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDump_RpcClient(Net::ISession * pSession, Msg::Object objSrc , LibCore_Chunk & res/* = 0*/) 
{
	std::string strKey, strVal;
	 
	LibCore::CStream objStream;
	objStream.Pushback(res.Begin() , res.GetDataLen());
	if (res.GetDataLen() == 0)
	{
		ReturnNULL;
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
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDump_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc) 
{


	std::cout << "HandleDump_RpcTimeout" << std::endl;
	ReturnNULL;
}

