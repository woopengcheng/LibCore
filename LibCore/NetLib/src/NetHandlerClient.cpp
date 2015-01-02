#include "NetHandlerClient.h"
#include "NetHelper.h"
#include "INetReactor.h" 

namespace Net
{   
	 INT32  NetHandlerClient::HandleMsg( ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		if (m_pMsgProcess)
		{
			return m_pMsgProcess->Process(pSession , unMsgID , pBuffer , unLength);
		}

		return -1;
	}

	 INT32 NetHandlerClient::Init( const char* ip,int port )
	 { 
		 m_pSession->SetAddress(ip);
		 m_pSession->SetSocktPort(port);
		  
		 if (m_pSession->IsClosed() && !Connect(ip , port))
		 {
			 gDebugStream("Connect Init " << m_pSession->GetRemoteName());
			 return NetHandlerTransit::Init();
		 }
		 return -1;  
	 }

	 INT32 NetHandlerClient::Cleanup(void)
	 { 
		 return NetHandlerTransit::Cleanup();
	 }

	 INT32 NetHandlerClient::Connect( const char* ip,int port )
	 {
		 Assert_ReF1(m_pSession && ip); 
		  
		 SOCKET socket = m_pSession->GetSocket();
		 if (socket == -1)
		 { 
			 socket =  NetHelper::CreateSocket(AF_INET , SOCK_STREAM , 0);  
			 m_pSession->SetSocket(socket);  
		 }
		 int aio = 0;
		 NetHelper::SetIOCtrl(socket , FIONBIO , &aio);
		 NetHelper::SetDefaultSocket(socket);

		 sockaddr_in addr = {0};
		 addr.sin_family = AF_INET;
		 addr.sin_port = htons(port);
		 NetHelper::NetToN(ip , &addr.sin_addr);

		 int nResult = ::connect(socket ,(sockaddr*)&addr,sizeof(addr)); 
		 if (nResult != 0)
		 {
			 NetHelper::CloseSocket(socket);
			 m_pSession->SetSocket(-1);  
		 }
		 gDebugStream("Connect " << m_pSession->GetRemoteName());
		 return  nResult;
	 }

	 INT32 NetHandlerClient::OnClose(void)
	 {
		 return NetHandlerTransit::OnClose();
	 }

	 INT32 NetHandlerClient::OnReconnect(void)
	 {
		 int nResult = -1;
		 if (m_pSession)
		 {
			 nResult = Connect(m_pSession->GetAddress() , m_pSession->GetPort());
			 if (!nResult)
			 {
				 m_pSession->SetNetState(Net::NET_STATE_CONNECTED);
				 m_pSession->SetClosed(FALSE);

				 m_pNetReactor->AddNetHandler(NetHandlerTransitPtr(this));
			 } 
		 }
		 return  nResult;
	 }

	 NetHandlerClient::NetHandlerClient( INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess /*= NULL*/ ) 
		 : NetHandlerTransit(pNetReactor , pSession)  
		 , m_pMsgProcess(pMsgProcess)
	 {  
	 }

	 NetHandlerClient::~NetHandlerClient()
	 {  
	 }

	 INT32 NetHandlerClient::Update( void )
	 { 
		 Reconnect();

		 return NetHandlerTransit::Update();
	 }

}