#ifdef _MSC_VER
#include "NetLib/inc/NetReactorIOCP.h"
#include "Timer/inc/TimerHelp.h"
#include "LogLib/inc/Log.h"

namespace Net
{ 

	NetReactorIOCP::NetReactorIOCP(UINT32 unMaxConnectionCount)
		: m_unMaxConnectionCount(unMaxConnectionCount)
	{
	}

	NetReactorIOCP::~NetReactorIOCP(void)
	{
	}

	CErrno NetReactorIOCP::Init(void)
	{

		return CErrno::Success();
	}

	CErrno NetReactorIOCP::Cleanup( void )
	{

		return CErrno::Success();
	}

	CErrno NetReactorIOCP::AddNetHandler(INetHandlerPtr  pNetHandler, ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/)
	{

		return CErrno::Success();
	}

	CErrno NetReactorIOCP::DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler/* = TRUE*/)
	{

		return CErrno::Success();
	}

	CErrno NetReactorIOCP::ModNetHandler(INetHandlerPtr  pNetHandler, ENetHandlerFuncMask objMask)
	{

		return CErrno::Success();
	}

	CErrno NetReactorIOCP::Update( void )
	{
		return CErrno::Success();
	}
}

#endif