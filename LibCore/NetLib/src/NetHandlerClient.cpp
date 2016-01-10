extern "C"
{
#include "zmq.h" 
}
#include "RakPeerInterface.h"
#include "BitStream.h"
#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include "NetLib/inc/NetHandlerClient.h"
#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/INetReactor.h" 
#include "CUtil/inc/CUtil.h"
#include "NetLib/inc/NetReactorUDP.h"
#include "NetLib/inc/NetReactorRakNet.h"

namespace Net
{
	NetHandlerClient::NetHandlerClient(INetReactor * pNetReactor, ISession * pSession, MsgProcess * pMsgProcess /*= NULL*/)
		: NetHandlerTransit(pNetReactor, pSession)
		, m_pMsgProcess(pMsgProcess)
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
			case REACTOR_TYPE_UDS:
			{
				InitUDS();
			}break;
			case REACTOR_TYPE_RAKNET:
			{
				InitRakNet();
			}break;
			default:
				break;
		}
	}

	NetHandlerClient::~NetHandlerClient()
	{
		if (IsZMQ())
		{
			MsgAssert(zmq_close(m_pZmqSocket), "error in zmq_close" << zmq_strerror(errno));

			MsgAssert(zmq_term(m_pZmqContext), "error in zmq_term:" << zmq_strerror(errno));

			SAFE_DELETE(m_pZmqMsg);
		}
	}

	CErrno NetHandlerClient::InitZMQ()
	{
		m_pZmqContext = zmq_init(1);
		MsgAssert_ReF(m_pZmqContext, "error in zmq_init" << zmq_strerror(errno));

		void * pSocket = zmq_socket(m_pZmqContext, ZMQ_PUSH);
		MsgAssert_ReF(pSocket, "error in zmq_socket" << zmq_strerror(errno));
		m_pZmqSocket = pSocket;

		INT32 nTime = 100;
		zmq_setsockopt(m_pZmqSocket, ZMQ_RECONNECT_IVL, (void *)&nTime, sizeof(nTime));

		m_pZmqMsg = new zmq_msg_t;

		return CErrno::Success();
	}

	CErrno NetHandlerClient::InitUDS()
	{
		Net::UDSContext * pContext = new Net::UDSContext;
		m_pSession->SetContext(pContext);

		return CErrno::Success();
	}

	BOOL NetHandlerClient::IsZMQ()
	{
		if (m_pNetReactor && m_pNetReactor->GetReactorType() == REACTOR_TYPE_ZMQ)
		{
			return TRUE;
		}

		return FALSE;
	}

	CErrno NetHandlerClient::Init(void)
	{
		if (m_pSession)
		{
			return Init(m_pSession->GetAddress(), m_pSession->GetPort());
		}

		return CErrno::Failure();
	}

	CErrno NetHandlerClient::Init(const char* ip, int port)
	{
		m_pSession->SetAddress(ip);
		m_pSession->SetSocktPort(port);

		if (m_pSession->IsClosed() && !Connect(ip, port))
		{
			gDebugStream("Connect Init success" << m_pSession->GetRemoteName());
			m_pSession->SetClosed(FALSE);
			return NetHandlerTransit::Init();
		}
		return CErrno::Failure();
	}

	CErrno NetHandlerClient::Cleanup(void)
	{
		return NetHandlerTransit::Cleanup();
	}

	INT32 NetHandlerClient::Connect(const char* ip, int port)
	{
		Assert_ReF1(m_pSession && ip);
		INT32 nResult = -1;

		switch (m_pSession->GetReactorType())
		{
		case REACTOR_TYPE_UDP:
		{
			nResult = ConnectUDP(ip, port);
		}break;
		case REACTOR_TYPE_ZMQ:
		{
			nResult = ConnectZMQ(ip, port);
		}break;
		case REACTOR_TYPE_UDS:
		{
			nResult = ConnectUDS(ip, port);
		}break;
		case REACTOR_TYPE_RAKNET:
		{
			nResult = ConnectRakNet(ip, port);
		}break;
		default:
		{
			nResult = ConnectCommon(ip, port);
		}break;
		}

		return  nResult;
	}

	INT32 NetHandlerClient::ConnectUDS(const char* ip, int port)
	{
#ifdef _LINUX
		struct sockaddr_un address;

		memset(&address, 0, sizeof(address));
		address.sin_family = AF_UNIX;
		
		std::string strFile = pAddress;
		strFile += ".";
		strFile += itoa(port);

		if (判断文件是否存在)
		{
			创建文件
		}

		strncpy(addr->sun_path, strFile.c_str(), sizeof(addr->sun_path) - 1);
		addr->sun_path[sizeof(addr->sun_path) - 1] = '\0';
		
		NetSocket socket = m_pSession->GetSocket();
		if (socket == -1)
		{
			socket = NetHelper::CreateSocket(AF_UNIX, SOCK_STREAM, 0);
			m_pSession->SetSocket(socket);
			 
			NetHelper::SetDefaultSocket(socket);
		}

		return 0;
#endif
		return -1;
	}

	INT32 NetHandlerClient::ConnectUDP(const char* ip, int port)
	{
		struct sockaddr_in address;

		memset(&address, 0, sizeof(address));
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr(ip);
		address.sin_port = htons(port);

		Net::UDPContext * pContext = new Net::UDPContext;
		pContext->SetPeerAddr(address);

		m_pSession->SetContext(pContext);

		NetSocket socket = m_pSession->GetSocket();
		if (socket == -1)
		{
			socket = NetHelper::CreateSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
			m_pSession->SetSocket(socket);

			if (NetHelper::IsUDPBroadCast(ip))
			{
				int valuetrue = 1;
				setsockopt(socket, SOL_SOCKET, SO_BROADCAST, (char*)&valuetrue, sizeof(valuetrue));
			}
			NetHelper::SetDefaultSocket(socket);
		}
		
		return 0;
	}

	INT32 NetHandlerClient::ConnectZMQ(const char* ip, int port)
	{
		std::string str = "tcp://";
		str += ip;
		str += ":";
		str += CUtil::itoa((INT64)port);

		INT32 nResult = zmq_connect(m_pZmqSocket, str.c_str());
		if (nResult != 0)
		{
			gErrorStream("error in zmq_connect: %s\n" << zmq_strerror(errno));
			return -1;
		}

		return  nResult;
	}
	
	INT32 NetHandlerClient::ConnectCommon(const char* ip, int port)
	{
		NetSocket socket = m_pSession->GetSocket();
		if (socket == -1)
		{
			socket = NetHelper::CreateSocket(AF_INET, SOCK_STREAM, 0);
			m_pSession->SetSocket(socket);
		}
		int aio = 0;
		NetHelper::SetIOCtrl(socket, FIONBIO, &aio);
		NetHelper::SetDefaultSocket(socket);

		sockaddr_in addr = { 0 };
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		NetHelper::NetToN(ip, &addr.sin_addr);

		int nResult = ::connect(socket, (sockaddr*)&addr, sizeof(addr));
		if (nResult != 0)
		{
			NetHelper::CloseSocket(socket);
			m_pSession->SetSocket(-1);

			gErrorStream("Connect failure ip:" << m_pSession->GetRemoteName() << "socket:" << socket);
		}
		else
			gDebugStream("Connect success ip:" << m_pSession->GetRemoteName() << "socket:" << socket);

		return  nResult;
	}

	INT32 NetHandlerClient::SendMsgZMQ(const char * pBuf, UINT32 unSize)
	{
		int nResult = zmq_msg_init_data(m_pZmqMsg, (void *)pBuf, unSize, NULL, NULL);
		if (nResult != 0)
		{
			gErrorStream("error in zmq_msg_init_size: %s\n" << zmq_strerror(errno));
			return -1;
		}

		int nCount = zmq_sendmsg(m_pZmqSocket, m_pZmqMsg, 0);
		if (nCount < 0)
		{
			gErrorStream("error in zmq_sendmsg: %s\n" << zmq_strerror(errno));
			return -1;
		}

		nResult = zmq_msg_close(m_pZmqMsg);
		if (nResult != 0) {
			printf("error in zmq_msg_close: %s\n", zmq_strerror(errno));
			return -1;
		}

		return nCount;
	}

	CErrno NetHandlerClient::OnClose(void)
	{
		return NetHandlerTransit::OnClose();
	}

	BOOL NetHandlerClient::Reconnect(void)
	{
		if (m_pSession && ((Net::ClientSession *)m_pSession)->IsReconnect() &&
			m_pSession->GetNetState() == NET_STATE_LOSTED && m_pSession->IsClosed())
		{
			OnReconnect();
		}
		return TRUE;
	}

	CErrno NetHandlerClient::OnReconnect(void)
	{
		int nResult = -1;
		CErrno result(CErrno::ERR_FAILURE);
		if (m_pSession)
		{
			nResult = Connect(m_pSession->GetAddress(), m_pSession->GetPort());
			if (!nResult)
			{
				m_pSession->SetNetState(Net::NET_STATE_CONNECTED);
				m_pSession->SetClosed(FALSE);

				m_pNetReactor->AddNetHandler(NetHandlerTransitPtr(this));
				result = CErrno::Success();
			}
		}
		return  result;
	}

	CErrno NetHandlerClient::Update(void)
	{
		Reconnect();

		return NetHandlerTransit::Update();
	}

	INT32 NetHandlerClient::SendMsg(const char * pBuf, UINT32 unSize)
	{
		if (IsZMQ())
		{
			return SendMsgZMQ(pBuf, unSize);
		}

		return NetHandlerTransit::SendMsg(pBuf, unSize);
	}

	CErrno  NetHandlerClient::HandleMsg(ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength)
	{
		if (m_pMsgProcess)
		{
			return m_pMsgProcess->Process(pSession, unMsgID, pBuffer, unLength);
		}

		return CErrno::Failure();
	}


}