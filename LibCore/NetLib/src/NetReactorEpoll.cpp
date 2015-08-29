#include "NetLib/inc/NetReactorEpoll.h"

namespace Net
{ 
	CErrno NetReactorEpoll::Init( void )
	{

		return CErrno::Failure();
	}

	CErrno NetReactorEpoll::Cleanup( void )
	{

		return CErrno::Failure();
	}

	CErrno NetReactorEpoll::Update( void )
	{

		return CErrno::Failure();
	}

	CErrno NetReactorEpoll::AddNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/ )
	{

		return CErrno::Failure();
	}

	CErrno NetReactorEpoll::DelNetHandler( INetHandlerPtr  pNetHandler  )
	{

		return CErrno::Failure();
	}

	CErrno NetReactorEpoll::ModNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask )
	{

		return CErrno::Failure();
	}

}