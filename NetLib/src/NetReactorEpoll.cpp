#include "NetReactorEpoll.h"

namespace Net
{ 
	INT32 NetReactorEpoll::Init( void )
	{

		return ERR_NET_FAILURE;
	}

	INT32 NetReactorEpoll::Cleanup( void )
	{

		return ERR_NET_FAILURE;
	}

	INT32 NetReactorEpoll::Update( void )
	{

		return ERR_NET_FAILURE;
	}

	INT32 NetReactorEpoll::AddNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/ )
	{

		return ERR_NET_FAILURE;
	}

	INT32 NetReactorEpoll::DelNetHandler( INetHandlerPtr  pNetHandler  )
	{

		return ERR_NET_FAILURE;
	}

	INT32 NetReactorEpoll::ModNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask )
	{

		return ERR_NET_FAILURE;
	}

}