extern "C"
{
#include "zmq.h" 
}
#include "NetLib/inc/NetHandlerServer.h"
#include "NetLib/inc/ISession.h"
#include "NetLib/inc/NetHelper.h" 
#include "NetLib/inc/INetReactor.h" 
#include "NetLib/inc/NetReactorUDP.h" 
#include "CUtil/inc/CUtil.h"

namespace Net
{

	NetHandlerServer::NetHandlerServer(INetReactor * pNetReactor, ISession * pSession)
		: NetHandlerTransit(pNetReactor, pSession)
		, m_pZmqContext(NULL)
		, m_pZmqMsg(NULL)
		, m_pZmqSocket(NULL)
	{
		Assert(m_pSession);
		switch (m_pSession->GetReactorType())
		{
			case REACTOR_TYPE_ZMQ:
			{
				InitZMQ();
			}break;
			case REACTOR_TYPE_UDP:
			{
				InitUDP();
			}break;
			case REACTOR_TYPE_UDS:
			{
				InitUDS();
			}break;
			default:
				break;
		}
	}

	CErrno NetHandlerServer::InitUDP()
	{
		struct sockaddr_in address;

		memset(&address, 0, sizeof(address));
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(m_pSession->GetPort());

		Net::UDPContext * pContext = new Net::UDPContext;
		pContext->SetPeerAddr(address);

		m_pSession->SetContext(pContext);

		NetSocket socket = m_pSession->GetSocket();
		if (socket == -1)
		{
			socket = NetHelper::CreateSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
			m_pSession->SetSocket(socket);

			NetHelper::SetDefaultSocket(socket);

			bind(socket, (struct sockaddr *)&address, sizeof(address));
		}

		return CErrno::Success();
	}

	CErrno NetHandlerServer::InitUDS()
	{
		Net::UDSContext * pContext = new Net::UDSContext;
		m_pSession->SetContext(pContext);

		return CErrno::Success();
	}

	NetHandlerServer::~NetHandlerServer()
	{
		if (IsZMQ())
		{
			MsgAssert(!zmq_close(m_pZmqSocket), zmq_strerror(errno) << "error in zmq_close");
			MsgAssert(!zmq_term(m_pZmqContext), zmq_strerror(errno) << "error in zmq_term:");

			SAFE_DELETE(m_pZmqMsg);
		}
	}

	CErrno NetHandlerServer::OnClose( void )
	{ 
		return NetHandlerTransit::OnClose();
	}

	CErrno NetHandlerServer::OnMsgRecving(void)
	{
		if (IsZMQ())
		{
			return OnMsgRecvingZMQ();
		}

		return NetHandlerTransit::OnMsgRecving();
	}

	INT32 NetHandlerServer::SendMsg(const char * pBuf, UINT32 unSize)
	{
		return NetHandlerTransit::SendMsg(pBuf, unSize);
	}

	CErrno NetHandlerServer::Init(const char* ip, int port)
	{
		m_pSession->SetAddress(ip);
		m_pSession->SetSocktPort(port);

		std::string str = "tcp://";
		str += ip;
		str += ":";
		str += CUtil::itoa(port);

		MsgAssert_ReF(!zmq_bind(m_pZmqSocket, str.c_str()), zmq_strerror(errno));

		return NetHandlerTransit::Init();
	}

	CErrno NetHandlerServer::OnMsgRecvingZMQ(void)
	{

		int nResult = zmq_msg_init(m_pZmqMsg);
		if (nResult != 0)
		{
			gErrorStream("error in zmq_msg_init: %s\n" << zmq_strerror(errno));
			return CErrno::Failure();
		}

		nResult = zmq_recvmsg(m_pZmqSocket, m_pZmqMsg, ZMQ_DONTWAIT);
		if (nResult < 0)
		{
			if (zmq_errno() == EAGAIN)
			{
				nResult = zmq_msg_close(m_pZmqMsg);
				if (nResult != 0) {
					printf("error in zmq_msg_close: %s\n", zmq_strerror(errno));
					return  CErrno::Failure();
				}
				return CErrno::Success();
			}

			printf("error in zmq_recvmsg: %s\n", zmq_strerror(errno));
			return CErrno::Failure();
		}
		void * pBuf = zmq_msg_data(m_pZmqMsg);
		size_t usSize = zmq_msg_size(m_pZmqMsg);
		MsgHeader * pHeader = (MsgHeader*)pBuf;

		HandleMsg(m_pSession, pHeader->unMsgID, (char *)pBuf + sizeof(MsgHeader), (UINT32)(usSize - sizeof(MsgHeader)));

		nResult = zmq_msg_close(m_pZmqMsg);
		if (nResult != 0) {
			printf("error in zmq_msg_close: %s\n", zmq_strerror(errno));
			return CErrno::Failure();
		}

		return  CErrno::Success();
	}

	BOOL NetHandlerServer::IsZMQ()
	{
		if (m_pNetReactor && m_pNetReactor->GetReactorType() == REACTOR_TYPE_ZMQ)
		{
			return TRUE;
		}

		return FALSE;
	}

	CErrno NetHandlerServer::InitZMQ()
	{
		void * pContext = zmq_init(1);
		MsgAssert_ReF(pContext, zmq_strerror(errno) << "error in zmq_init");

		m_pZmqContext = pContext;

		void * pSocket = zmq_socket(pContext, ZMQ_PULL);
		MsgAssert_ReF(pSocket, zmq_strerror(errno) << "error in zmq_socket");

		m_pZmqSocket = pSocket;

		m_pZmqMsg = new zmq_msg_t;

		return Init(m_pSession->GetAddress(), m_pSession->GetPort());
	}

	CErrno  NetHandlerServer::HandleMsg(ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength)
	{
		printf("%s", pBuffer);

		if (pSession->GetReactorType() != REACTOR_TYPE_UDP && pSession->GetReactorType() != REACTOR_TYPE_ZMQ)
		{
			char pBuf[1024];

			const char * kSendMsg = "server sendmsg.\n";
			UINT32 unLen = (UINT32)(strlen(kSendMsg) + 1);

			((Net::MsgHeader*)pBuf)->unMsgID = 0;
			((Net::MsgHeader*)pBuf)->unMsgLength = unLen + sizeof(Net::MsgHeader);
			memcpy(pBuf + sizeof(Net::MsgHeader), kSendMsg , unLen);
			SendMsg(pBuf, unLen + sizeof(Net::MsgHeader));
		}

		return CErrno::Success();
	}

}