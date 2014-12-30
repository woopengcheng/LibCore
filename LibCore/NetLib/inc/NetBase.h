#ifndef __net_net_base_h__
#define __net_net_base_h__
#include "NetCommon.h"

namespace Net
{
	class MsgWrapper;

	class NetBase
	{
	public:
		NetBase() : m_bConnected(false){};
		virtual ~NetBase(){};

	public:
		virtual INT32          Init(void) = 0;
		virtual INT32          Cleanup(void) = 0;
		virtual INT32          Connect(char* pIPAddress, UINT16 usPort) = 0;
		virtual INT32          CloseConnection(void) = 0;
		virtual INT32          SendMsg(MsgWrapper* pMsg) = 0;
		virtual MsgWrapper *   RecvMsg(void) = 0;
		virtual void           Run(void) = 0;
		virtual BOOL           IsConnected(void){ return ERR_NET_FAILURE; }

	public:
//		virtual INT32 SendSpace() = 0;

	protected:
		BOOL    m_bConnected;
	}; 

}

#endif