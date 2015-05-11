#include "MsgLib/inc/RpcCheckParams.h"

namespace Msg
{ 
	RpcCheckParams * g_pRpcCheckParams = new RpcCheckParams;

	Parameters * RpcCheckParams::GetReturnParams( std::string strFunName )
	{
		MapCollectParametersT::iterator iter = m_mapReturnParams.find(strFunName);
		if (iter != m_mapReturnParams.end())
		{
			return &iter->second;
		}

		return NULL;
	}


	Parameters * RpcCheckParams::GetDeliverParams( std::string strFunName )
	{
		MapCollectParametersT::iterator iter = m_mapDeliverParams.find(strFunName);
		if (iter != m_mapDeliverParams.end())
		{
			return &iter->second;
		}

		return NULL;
	}

	void RpcCheckParams::InsertReturnParams( std::string strFunName , Parameters & objParam )
	{
		MapCollectParametersT::iterator iter = m_mapReturnParams.find(strFunName);
		if (iter == m_mapReturnParams.end())
		{
			m_mapReturnParams.insert(std::make_pair(strFunName , objParam));
		}
		else
		{
			gWarniStream(strFunName << "Has return params");
		} 
	}


	void RpcCheckParams::InsertDeliverParams( std::string strFunName , Parameters & objParam )
	{
		MapCollectParametersT::iterator iter = m_mapDeliverParams.find(strFunName);
		if (iter == m_mapDeliverParams.end())
		{
			m_mapDeliverParams.insert(std::make_pair(strFunName , objParam)); //5 这里有问题.里面的字符串指针.没有copy.后续采用流式管理.
		}
		else
		{
			gWarniStream(strFunName << "Has deliver params");
		}
	} 

}