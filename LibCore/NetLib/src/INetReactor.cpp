#include "NetLib/inc/INetReactor.h"

namespace Net
{
	CErrno INetReactor::AddNetHandler(INetHandlerPtr pNetHandler, ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/)
	{
		if (!pNetHandler || !pNetHandler->GetSession())
		{
			return CErrno::Failure();
		}

		m_mapNetHandlersBySession.insert(std::make_pair(pNetHandler->GetSession()->GetSessionID(), pNetHandler));
		return CErrno::Success();
	}

	CErrno INetReactor::DelNetHandler(INetHandlerPtr pNetHandler, BOOL bEraseHandler /*= TRUE*/)
	{
		if (!pNetHandler || !pNetHandler->GetSession())
		{
			return CErrno::Failure();
		}

		m_mapNetHandlersBySession.erase(pNetHandler->GetSession()->GetSessionID());

		return CErrno::Success();
	}

	CErrno INetReactor::ModNetHandler(INetHandlerPtr pNetHandler, ENetHandlerFuncMask objMask)
	{

		return CErrno::Success();
	}

	INetHandlerPtr INetReactor::GetNetHandlerByID(INT32 nSessionID)
	{
		CollectNetHandlersT::accessor iter;
		bool bFind = m_mapNetHandlersBySession.find(iter, nSessionID);
		if (bFind)
		{
			return iter->second;
		}

		return NULL;
	}
}