#ifndef __net_raknet_udp_manager_h__
#define __net_raknet_udp_manager_h__
#include "NetLib/inc/NetCommon.h"
#include "NetLib/inc/NetBase.h"

namespace RakNet
{
	struct Packet;
	class  RakPeerInterface; 
}

namespace Net
{
	class RaknetUDPManager : public NetBase
	{
	public:
		RaknetUDPManager();
		virtual ~RaknetUDPManager();

	public:
		virtual INT32 Init(void);
		virtual INT32 Cleanup(void);
		virtual INT32 Connect(char* pIPAddress, UINT16 usPort);
		virtual INT32 CloseConnection(void);
		virtual INT32 CloseConnection(UINT32 unIndex);
		virtual INT32 SendMsg(MsgWrapper* pMsg);
		virtual MsgWrapper *   RecvMsg(void);

	public:
		//		virtual INT32 SendSpace(); 
		virtual void Run(void);  

	private:
		unsigned char GetPacketIdentifier(RakNet::Packet * pPacket);
		MsgWrapper  * RecvMsgInStream(RakNet::Packet * pPacket);

	private:
		RakNet::RakPeerInterface * m_pRakPeerInstance;
	}; 
}
#endif