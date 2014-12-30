#ifndef __net_i_net_reactor_h__
#define __net_i_net_reactor_h__ 
#include "INetHandler.h"
#include "NetCommon.h"

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
		NET_FUNC_EPOLLET = 0x0010 ,   //5 Ĭ��ʹ��ETģʽ,ֻ֪ͨһ��,Ȼ�󲻶ϵ�ȥ��������.
		NET_FUNC_EPOLLLT = 0x0020 ,   //5 ʹ��LTģʽ,ֻҪ�����ݾͲ�ͣ��֪ͨ,Ȼ��һֱ����
		NET_FUNC_TIMEOUT = 0x0040 ,

		NET_FUNC_DEFAULT = NET_FUNC_READ | NET_FUNC_WRITE | NET_FUNC_ACCEPT | NET_FUNC_EXCEPT | NET_FUNC_TIMEOUT,
		NET_FUNC_DEFAULT_AND_TIMEOUT = NET_FUNC_READ | NET_FUNC_WRITE | NET_FUNC_ACCEPT | NET_FUNC_EXCEPT ,
	};

	class DLL_EXPORT INetReactor
	{
	public:
		INetReactor( void )
		{
		}
		virtual ~INetReactor( void )
		{
		}

	public:
		virtual INT32   Init( void ) = 0;
		virtual INT32   Cleanup( void ) = 0;
		virtual INT32   Update( void ) = 0;
	public:
		virtual INT32   AddNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT) = 0;
		virtual INT32   DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler = TRUE) = 0;
		virtual INT32   ModNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask) = 0;
		virtual INetHandlerPtr  GetNetHandler(UINT32  unNetHandlerIndex) = 0;
	}; 
	 
}

#endif