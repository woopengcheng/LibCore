#include "NetLib/inc/NetHandlerTransit.h"
#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/ByteOrder.h"
#include "NetLib/inc/ISession.h"
#include "NetLib/inc/NetReactorUDP.h"
#include "NetLib/inc/INetReactor.h"
#include "Timer/inc/TimerHelp.h"

#ifdef WIN32
#include "Winsock.h"
#endif

namespace Net
{
	NetHandlerTransit::NetHandlerTransit( INetReactor * pNetReactor , ISession * pSession )
		: INetHandler(pNetReactor , pSession)
	{
		m_objRecvBuf.Init(DEFAULT_CIRCLE_BUFFER_SIZE);
 		m_objSendBuf.Init(DEFAULT_CIRCLE_BUFFER_SIZE);

		if (m_pSession && m_pNetReactor)
		{
			m_pSession->SetReactorType(m_pNetReactor->GetReactorType());
		}
	}

	NetHandlerTransit::~NetHandlerTransit( void )
	{
		m_objSendBuf.Cleanup();
		m_objRecvBuf.Cleanup();
	}
	 
	CErrno NetHandlerTransit::OnMsgRecving( void )
	{
		char szBuf[DEFAULT_CIRCLE_BUFFER_SIZE];  

		NetSocket socket  = m_pSession->GetSocket();
		INT32  nBufSize = 0;
		UINT32 unMaxBufSize = sizeof(szBuf);

		do
		{
			if (m_pSession->GetReactorType() == REACTOR_TYPE_UDP)
			{
				UDPContext * pContext = (UDPContext *)m_pSession->GetContext();
				if (pContext)
				{
					INT32 nRecLen = sizeof(pContext->GetPeerAddr());
					nBufSize = NetHelper::RecvMsg(socket, szBuf, sizeof(szBuf), (sockaddr*)&(pContext->GetPeerAddr()) , &nRecLen);
				}
			}
			else
			{
				nBufSize = NetHelper::RecvMsg(socket, szBuf, sizeof(szBuf));
			}
			if( nBufSize <  0 && NetHelper::IsSocketEagain())
				return CErrno::Success();
			if( nBufSize <= 0 )
				return CErrno::Failure();

			CErrno result = OnMsgRecving(szBuf , nBufSize);
			if( !result.IsSuccess() )
				return result;
		}while(0);

		return CErrno::Success();
	}

	CErrno NetHandlerTransit::OnMsgRecving(const char * pBuf , UINT32 unSize)
	{
		return RecvToCircleBuffer( pBuf , unSize);
	}

	CErrno NetHandlerTransit::RecvToCircleBuffer(const char * pBuf , UINT32 unSize )
	{
		if(m_objRecvBuf.GetSpace() > unSize)
		{
			if (m_pSession)
			{
				m_pSession->OnRecvMsg();
			} 

			m_objRecvBuf.PushBuffer(pBuf , unSize);
			ParaseRecvMsg();
		}
		else
		{
			MsgAssert_Re(0 , CErrno::Failure() , "buffer full.");  
			this->m_objRecvBuf.SkipBytes(m_objRecvBuf.GetDataLength());
			return CErrno::Failure();
		}
		return CErrno::Success();
	}

	CErrno NetHandlerTransit::ParaseRecvMsg()
	{
		while(m_objRecvBuf.GetDataLength() > 0)
		{
			UINT32 unMsgLength = 0; 

			INT32 nRecvBuf = (size_t)m_objRecvBuf.TryGetBuffer((char*)&unMsgLength , sizeof(UINT32));

			if(nRecvBuf < sizeof(UINT32))
			{
				gErrorStream( "parase msg header failed.");
				return CErrno::Failure(); 
			}

//			Convert<UINT32>::ToHostOrder(unMsgLength);
			 
			if(unMsgLength > MAX_MESSAGE_LENGTH || unMsgLength <= 0)
			{
				gErrorStream( "error package len ,discard connection");
				return CErrno::Failure();   
			}

			if(m_objRecvBuf.GetDataLength() < unMsgLength)
				return CErrno::Success();

			char szBuf[MAX_MESSAGE_LENGTH];
			m_objRecvBuf.GetBuffer(szBuf , unMsgLength);
			 
			MsgHeader * pHeader = (MsgHeader*)szBuf;

			HandleMsg(m_pSession , pHeader->unMsgID , szBuf + sizeof(MsgHeader) , pHeader->unMsgLength - sizeof(MsgHeader) );
		}

		return CErrno::Success();
	}

	CErrno NetHandlerTransit::OnMsgSending( void )
	{
		if (m_pSession)
		{
			m_pSession->SetCanWrite(TRUE);
		}
		FlushSendBuffer();
		return CErrno::Success();
	}

	INT32 NetHandlerTransit::FlushSendBuffer( void )
	{ 
		INT32  nSendBytes = 0;

		if (m_pSession)
		{
			m_pSession->OnSendMsg();
		}

		while(true)
		{
			if(!m_objSendBuf.IsVaild() || m_objSendBuf.GetDataLength() <= 0 || !m_pSession->IsCanWrite())
				break;

			char   szBuf[DEFAULT_CIRCLE_BUFFER_SIZE];
			INT32  nLength = m_objSendBuf.TryGetBuffer(szBuf,sizeof(szBuf));

			INT32 nSendLength = Send(szBuf, nLength);

// #ifndef WIN32
// 			INT32 nSendLength = ::send(m_pSession->GetSocket(),szBuf,nLength,MSG_DONTWAIT);
// #else
// 			INT32 nSendLength = ::send(m_pSession->GetSocket(),szBuf,nLength,0);
// #endif 
			if( nSendLength > 0 )
			{ 
				nSendBytes += nSendLength;
				m_objSendBuf.SkipBytes(nSendLength);
			}
			else if(nSendLength < 0 && NetHelper::IsSocketEagain())
			{
				if (m_pSession)
				{
					m_pSession->SetCanWrite(FALSE);
				}
				break;
			}
			else
			{ 
				gErrorStream("send error , close it.");
				m_pSession->SetClosed(TRUE); 
				break;
			}
		}

		return nSendBytes;  
	} 

	INT32 NetHandlerTransit::SendMsg( const char * pBuf , UINT32 unSize )
	{ 
		if(m_objSendBuf.IsVaild() && m_objSendBuf.GetDataLength() >= 0)
		{
			if(m_objSendBuf.GetSpace() > unSize)
			{
				m_objSendBuf.PushBuffer(pBuf , unSize);
				FlushSendBuffer();
			}
			else
			{
				FlushSendBuffer();

				if(m_objSendBuf.GetSpace() > unSize)
				{
					m_objSendBuf.PushBuffer(pBuf , unSize);
				}
				else if(m_objSendBuf.GetDataLength() == 0)
				{
					INT32 nSendBytes = Send(pBuf  , unSize);
					if( nSendBytes <= 0)
					{
						gErrorStream("sendbuffer.length=0,direct send failed");
						return -1;
					}
					else if(nSendBytes != unSize)
					{
						gErrorStream("sendbuffer.length=0,direct send failed");
						return -1; 
					}

					return (nSendBytes > 0) ? nSendBytes : -1;
				}
				else
				{
					gErrorStream("sendbuff not empty");
					return -1;  
				}
			}
			return unSize;
		}

		return Send(pBuf , unSize);

	}

	INT32 NetHandlerTransit::Send( const char * pBuf , UINT32 unSize)
	{ 
		if (m_pSession)
		{
			switch (m_pSession->GetReactorType())
			{
				case REACTOR_TYPE_IOCP:
				{
					return SendIOCP(pBuf, unSize);
				}break;
				case REACTOR_TYPE_UDP:
				{
					return SendTo(pBuf , unSize);
				}break;
				default:
				{
					return SendCommon(pBuf, unSize);
				}break;
			}
		}
		return -1;
	}

	INT32 NetHandlerTransit::SendIOCP(const char * pBuf, UINT32 unSize)
	{
		return NetHelper::WSASend(this, pBuf , unSize);
	}

	INT32 NetHandlerTransit::SendCommon(const char * pBuf, UINT32 unSize)
	{
		if (m_pSession && !m_pSession->IsCanWrite())
		{
			return -1;
		}

		UINT32 unTotalSendBytes = 0;
		while ((unSize > unTotalSendBytes))
		{
#ifdef WIN32
			int nSendBytes = ::send(m_pSession->GetSocket(), &pBuf[unTotalSendBytes], unSize - unTotalSendBytes, 0);
#else
			int nSendBytes = ::send(m_pSession->GetSocket(), &pBuf[unTotalSendBytes], unSize - unTotalSendBytes, MSG_DONTWAIT);
#endif
			if (nSendBytes > 0)
			{
				unTotalSendBytes += nSendBytes;
			}
			else if (nSendBytes < 0 && NetHelper::IsSocketEagain())
			{
				m_pSession->SetCanWrite(FALSE);
				break;
			}
			else
			{
				gErrorStream("send error , close it.addr:" << m_pSession->GetAddress() << "=port:" << m_pSession->GetPort());
				m_pSession->SetClosed(TRUE);
				break;
			}
			Timer::TimerHelper::sleep(1);
		}

		return unTotalSendBytes;
	}

	INT32 NetHandlerTransit::SendTo(const char * pBuf, UINT32 unSize)
	{
		if (m_pSession && !m_pSession->IsCanWrite())
		{
			return -1;
		}
		UDPContext * pContext = (UDPContext *)m_pSession->GetContext();
		if (!pContext)
		{
			return -1;
		}

		UINT32 unTotalSendBytes = 0;
		while ((unSize > unTotalSendBytes))
		{
#ifdef WIN32
			int nSendBytes = ::sendto(m_pSession->GetSocket(), &pBuf[unTotalSendBytes], unSize - unTotalSendBytes, 0 , (sockaddr*)&(pContext->GetPeerAddr()) , sizeof(pContext->GetPeerAddr()));
#else
			int nSendBytes = ::send(m_pSession->GetSocket(), &pBuf[unTotalSendBytes], unSize - unTotalSendBytes, MSG_DONTWAIT, (sockaddr*)&(pContext->GetPeerAddr()), sizeof(pContext->GetPeerAddr()));
#endif
			if (nSendBytes > 0)
			{
				unTotalSendBytes += nSendBytes;
			}
			else if (nSendBytes < 0 && NetHelper::IsSocketEagain())
			{
				m_pSession->SetCanWrite(FALSE);
				break;
			}
			else
			{
				gErrorStream("send error , close it.addr:" << m_pSession->GetAddress() << "=port:" << m_pSession->GetPort());
				m_pSession->SetClosed(TRUE);
				break;
			}
			Timer::TimerHelper::sleep(1);
		}

		return unTotalSendBytes;
	}

	CErrno NetHandlerTransit::HandleMsg(ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength)
	{
		return CErrno::Success();
	}

	CErrno NetHandlerTransit::OnClose( void )
	{ 
		if (m_pSession)
		{
			m_pSession->OnClose();
		} 
		return CErrno::Success();
	}
	  
	CErrno NetHandlerTransit::Update( void )
	{   
		return INetHandler::Update();
	}

	CErrno NetHandlerTransit::Init( void )
	{
		return INetHandler::Init();
	}

	CErrno NetHandlerTransit::Cleanup( void )
	{
		return INetHandler::Cleanup();
	}

}

