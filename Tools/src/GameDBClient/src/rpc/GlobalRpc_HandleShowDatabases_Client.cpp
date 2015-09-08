#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleShowDatabases_RpcClient(Net::ISession * pSession, Msg::Object objSrc , CUtilChunk & res/* = CUtil::Chunk()*/) 
{
	CUtil::CStream cs((const char*)res.Begin() , res.GetDataLen());

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
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleShowDatabases_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc) 
{


	std::cout << "HandleShowDatabases_RpcTimeout" << std::endl;
	ReturnNULL;
}

