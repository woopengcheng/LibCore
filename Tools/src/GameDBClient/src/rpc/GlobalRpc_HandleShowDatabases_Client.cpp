#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleShowDatabases_RpcClient(Net::ISession * pSession, Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/) 
{
	LibCore::CStream cs((const char*)res.GetBuf() , res.GetDataLen());

	UINT32 unCount = 0;
	cs >> unCount;

	MsgAssert_Re0(unCount < 1000000 && unCount >= 0 , "showdatabases wrong count.");

	std::string strDBName;
	while(unCount--)
	{
		strDBName.clear();
		cs >> strDBName;

		gOtherStream("num:" << unCount << " dbname: " << strDBName);
	}

	std::cout << "HandleShowDatabases_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleShowDatabases_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc) 
{


	std::cout << "HandleShowDatabases_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

