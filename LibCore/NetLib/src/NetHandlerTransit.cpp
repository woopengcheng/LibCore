#include "NetHandlerTransit.h"
#include "NetHelper.h"
#include "ByteOrder.h"
#include "ISession.h"
#include "INetReactor.h"
#include "TimerHelp.h"

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
	}

	NetHandlerTransit::~NetHandlerTransit( void )
	{
		m_objSendBuf.Cleanup();
		m_objRecvBuf.Cleanup();
	}
	 
	INT32 NetHandlerTransit::OnMsgRecving( void )
	{
		char szBuf[DEFAULT_CIRCLE_BUFFER_SIZE];  

		SOCKET socket  = m_pSession->GetSocket();
		INT32  nBufSize = sizeof(szBuf);
		UINT32 unMaxBufSize = sizeof(szBuf);

		do
		{
			nBufSize = NetHelper::RecvMsg(socket , szBuf , sizeof(szBuf));
			if( nBufSize <  0 && NetHelper::IsSocketEagain())
				return 0;
			if( nBufSize <= 0 )
				return ERR_NET_FAILURE;

			int result = RecvToCircleBuffer( szBuf , nBufSize);
			if( result < 0 )
				return result;
		}while(0);

		return ERR_SUCCESS;
	}

	INT32 NetHandlerTransit::RecvToCircleBuffer( char * pBuf , UINT32 unSize )
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
			MsgAssert_Re(0 , ERR_NET_FAILURE , "buffer full.");  
			this->m_objRecvBuf.SkipBytes(m_objRecvBuf.GetDataLength());
			return ERR_NET_FAILURE;
		}
		return ERR_SUCCESS;
	}

	INT32 NetHandlerTransit::ParaseRecvMsg()
	{
		while(m_objRecvBuf.GetDataLength() > 0)
		{
			UINT32 unMsgLength = 0; 

			INT32 nRecvBuf = (size_t)m_objRecvBuf.TryGetBuffer((char*)&unMsgLength , sizeof(UINT32));

			if(nRecvBuf < sizeof(UINT32))
			{
				gErrorStream( "parase msg header failed.");
				return ERR_NET_FAILURE; 
			}

//			Convert<UINT32>::ToHostOrder(unMsgLength);
			 
			if(unMsgLength > MAX_MESSAGE_LENGTH || unMsgLength <= 0)
			{
				gErrorStream( "error package len ,discard connection");
				return ERR_NET_FAILURE;   
			}

			if(m_objRecvBuf.GetDataLength() < unMsgLength)
				return ERR_SUCCESS;

			char szBuf[MAX_MESSAGE_LENGTH];
			m_objRecvBuf.GetBuffer(szBuf , unMsgLength);
			 
			MsgHeader * pHeader = (MsgHeader*)szBuf;

			HandleMsg(m_pSession , pHeader->unMsgID , szBuf + sizeof(MsgHeader) , pHeader->unMsgLength - sizeof(MsgHeader) );
		}

		return ERR_SUCCESS;
	}

	INT32 NetHandlerTransit::OnMsgSending( void )
	{
		if (m_pSession)
		{
			m_pSession->SetCanWrite(TRUE);
		}
		return FlushSendBuffer();
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

#ifndef WIN32
			INT32 nSendLength = ::send(m_pSession->GetSocket(),szBuf,nLength,MSG_DONTWAIT);
#else
			INT32 nSendLength = ::send(m_pSession->GetSocket(),szBuf,nLength,0);
#endif 
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
						return ERR_FAILURE;
					}
					else if(nSendBytes != unSize)
					{
						gErrorStream("sendbuffer.length=0,direct send failed");
						return ERR_FAILURE; 
					}

					return (nSendBytes > 0) ? nSendBytes : ERR_FAILURE;
				}
				else
				{
					gErrorStream("sendbuff not empty");
					return ERR_FAILURE;  
				}
			}
			return unSize;
		}

		return Send(pBuf , unSize);

	}

	INT32 NetHandlerTransit::Send( const char * pBuf , UINT32 unSize)
	{ 
		if(m_pSession && !m_pSession->IsCanWrite())
		{
			return ERR_NET_FAILURE;
		} 

		UINT32 unTotalSendBytes = 0;
		while((unSize > unTotalSendBytes))
		{
#ifdef WIN32
			int nSendBytes = ::send(m_pSession->GetSocket(),&pBuf[unTotalSendBytes] , unSize - unTotalSendBytes , 0);
#else
			int nSendBytes = ::send(m_pSession->GetSocket(),&pBuf[unTotalSendBytes] , unSize - unTotalSendBytes,MSG_DONTWAIT);
#endif
			if(nSendBytes > 0)
			{
				unTotalSendBytes += nSendBytes;
			} 
			else if(nSendBytes < 0 && NetHelper::IsSocketEagain())
			{
				m_pSession->SetCanWrite(FALSE);
				break;
			} 
			else
			{
				gErrorStream("send error , close it."); 
				m_pSession->SetClosed(TRUE);
			}
			Timer::TimerHelper::sleep(1);
		}
		return unTotalSendBytes;
	}

	INT32 NetHandlerTransit::HandleMsg( ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		return ERR_SUCCESS;
	}

	INT32 NetHandlerTransit::OnClose( void )
	{ 
		if (m_pSession)
		{
			m_pSession->OnClose();
		} 
		return ERR_SUCCESS;
	}
	  
	INT32 NetHandlerTransit::Update( void )
	{   
		return INetHandler::Update();
	}

	INT32 NetHandlerTransit::Init( void )
	{
		return INetHandler::Init();
	}

	INT32 NetHandlerTransit::Cleanup( void )
	{
		return INetHandler::Cleanup();
	}

}

