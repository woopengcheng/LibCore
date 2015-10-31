#include "NetLib/inc/NetHandlerHttpServer.h"
#include "NetLib/inc/INetReactor.h"
#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/ServerSession.h"
#include "NetLib/inc/HttpProtocol.h"

namespace Net
{

	void HttpServerListener::OnAccept(NetSocket socket , sockaddr_in * addr)
	{
		if (m_pHttpServer)
		{
			m_pHttpServer->OnAccept(socket , addr);
		}
	}

	HttpServer::HttpServer(INetReactor * pNetReactor)
		: m_pListener(NULL)
		, m_pNetReactor(pNetReactor)
	{ 
	}

	HttpServer::~HttpServer(void)
	{

	}

	CErrno HttpServer::Init(const char * pAddress , INT32 nPort , BOOL bResueAddr /*= TRUE */, INT32 nListenerCount /*= DEFAULT_LISTENER_COUNT*/)
	{
		CErrno err;
		if (m_pListener == NULL)
		{
			m_pListener = HttpServerListenerPtr(new HttpServerListener(this , m_pNetReactor , new ServerSession(pAddress , nPort , Net::NetHelper::GenerateRemoteName(NET_TYPE_TCP , pAddress , nPort).c_str())));
			err = m_pListener->Init(pAddress , nPort , bResueAddr , nListenerCount);

			if (err.IsSuccess())
			{
				m_pListener->GetSession()->SetClosed(FALSE);
				m_pNetReactor->AddNetHandler(m_pListener , NET_FUNC_ACCEPT);
			}
		}
		return err;
	}

	CErrno HttpServer::Cleanup()
	{
		return CErrno::Success();
	}

	void HttpServer::OnAccept(NetSocket socket , sockaddr_in * addr)
	{
		if (m_pNetReactor)
		{
			char szAddress[MAX_NAME_LENGTH];
			UINT16 usPort = 0;
			Net::NetHelper::GetAddressAndPortByAddrIn(addr , szAddress , usPort);
			std::string strName = Net::NetHelper::GenerateRemoteName(NET_TYPE_TCP , szAddress , usPort);

			ServerSession * pServerSession = new HttpSession(szAddress , usPort , strName.c_str() , 0 , -1 , socket);
			pServerSession->SetClosed(FALSE);
			NetHandlerHttpServerPtr pServer( new NetHandlerHttpServer(this , m_pNetReactor , pServerSession) ); 
			m_pNetReactor->AddNetHandler(pServer); 
		} 
	}
	 
	 
	CErrno NetHandlerHttpServer::OnMsgRecving(const char * pBuf , UINT32 unSize)
	{
		INT32 remaineLen = unSize;
		HttpProtocol objRequest;
		while(remaineLen > 0)
		{
			if(objRequest.Parse(&pBuf[unSize - remaineLen],remaineLen,&remaineLen))
			{
				HttpProtocol response;
				if(!(m_pServer->HttpHandler((HttpSession *)m_pSession , objRequest , response).IsSuccess()))
					return CErrno::Failure();
				objRequest.Clear();
				Send(response);
			}
			else
			{
				break;
			}
		}

		return CErrno::Success();
	}

	INT32 NetHandlerHttpServer::Send(HttpProtocol& response)
	{
		return SendMsg(response.GetBuf(),response.GetLen());
	}


}
