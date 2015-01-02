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
			Assert_Re(false && "buffer full." , ERR_NET_FAILURE);  
			this->m_objRecvBuf.SkipBytes(m_objRecvBuf.GetDataLength());
			return -1;
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
				Assert_Re(0 && "msg header failed." , -1);

//			Convert<UINT32>::ToHostOrder(unMsgLength);

			// ´íÎóµÄ°ü³¤,Ö±½Ó¶Ï¿ª
			if(unMsgLength > MAX_MESSAGE_LENGTH || unMsgLength <= 0)
			{
				Assert_Re( 0 && "error package len ,discard connection " , -1);  
			}

			if(m_objRecvBuf.GetDataLength() < unMsgLength)
				return 1;

			char szBuf[MAX_MESSAGE_LENGTH];
			m_objRecvBuf.GetBuffer(szBuf , unMsgLength);

			// ½«³¤¶ÈºÍÏûÏ¢id×ª»¯Îª±¾»ú×Ö½ÚË³Ðò
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
					// ´óÓÚ»º´æÇø´óÐ¡,ÔòÖ±½Ó·¢ËÍ
					INT32 nSendBytes = Send(pBuf  , unSize);
					if( nSendBytes <= 0)
					{
						Assert_Re(" sendbuffer.length=0,direct send failed,discard=%d\n" , -1); 
					}
					else if(nSendBytes != unSize)
					{
						Assert_Re(" sendbuffer.length=0,len=%d sent=%d\n" , -1); 
					}

					return (nSendBytes > 0) ? nSendBytes : 0;
				}
				else
				{
					Assert_Re(" sendbuff not empty,discard len=%d\n" , -1);  
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
			return -1;
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
		return TRUE;
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

