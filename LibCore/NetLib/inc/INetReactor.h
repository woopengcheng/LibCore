#ifndef __net_i_net_reactor_h__
#define __net_i_net_reactor_h__ 
#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/NetCommon.h"

#ifdef WIN32
#include <Windows.h>
#endif

namespace Net 
{  
	enum ENetHandlerFuncMask
	{
		NET_FUNC_READ    = 0x0001 ,
		NET_FUNC_WRITE   = 0x0002 ,
		NET_FUNC_ACCEPT  = 0x0004 ,
		NET_FUNC_EXCEPT  = 0x0008 ,
		NET_FUNC_EPOLLET = 0x0010 ,   //5 默认使用ET模式,只通知一次,然后不断的去接收数据.
		NET_FUNC_EPOLLLT = 0x0020 ,   //5 使用LT模式,只要有数据就不停的通知,然后一直接收
		NET_FUNC_TIMEOUT = 0x0040 ,

		NET_FUNC_DEFAULT = NET_FUNC_READ | NET_FUNC_WRITE | NET_FUNC_EXCEPT | NET_FUNC_TIMEOUT,
		NET_FUNC_ACCEPT_DEFAULT = NET_FUNC_EXCEPT | NET_FUNC_ACCEPT | NET_FUNC_TIMEOUT,
		NET_FUNC_DEFAULT_AND_TIMEOUT = NET_FUNC_READ | NET_FUNC_WRITE | NET_FUNC_ACCEPT | NET_FUNC_EXCEPT ,
	};

	class DLL_EXPORT INetReactor
	{
	public:
		INetReactor(EReactorType objType = REACTOR_TYPE_VAILID)
			: m_objReactorType(objType)
		{
		}
		virtual ~INetReactor( void )
		{
		}

	public:
		virtual CErrno   Init( void ) = 0;
		virtual CErrno   Cleanup( void ) = 0;
		virtual CErrno   Update( void ) = 0;
	public:
		virtual CErrno   AddNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT) = 0;
		virtual CErrno   DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler = TRUE) = 0;
		virtual CErrno   ModNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask) = 0;

	public:
		EReactorType	GetReactorType() const { return m_objReactorType; }
		void			SetReactorType(EReactorType val) { m_objReactorType = val; }

	protected:
		EReactorType m_objReactorType;
	}; 
	 
}

#endif
