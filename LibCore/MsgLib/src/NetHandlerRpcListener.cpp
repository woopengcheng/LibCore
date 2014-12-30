#include "NetHandlerRpcListener.h" 
#include "RpcManager.h"
#include "NetHelper.h"
#include "RpcInterface.h"

namespace Msg
{ 
	INT32 NetHandlerRpcListener::Init( const char * pAddress , INT32 nPort , BOOL bResueAddr /*= TRUE */, INT32 nListenerCount /*= DEFAULT_LISTENER_COUNT*/ )
	{
		return NetHandlerListener::Init(pAddress , nPort , bResueAddr , nListenerCount);
	}

	INT32 NetHandlerRpcListener::Cleanup()
	{
		return NetHandlerListener::Cleanup();
	} 

	void NetHandlerRpcListener::OnAccept( Net::SOCKET socket , sockaddr_in * addr )
	{
		if (m_pNetReactor)
		{
			Assert( m_pRpcManager );  

			char szAddress[MAX_NAME_LENGTH];
			UINT16 usPort;
			Net::NetHelper::GetAddressAndPortByAddrIn(addr , szAddress , usPort);

			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(m_pRpcManager->GetRpcInterface()->GetServerType()  , szAddress , usPort); 

			m_pRpcManager->CreateNetHandler(strRemoteRPCName.c_str() , szAddress , usPort , socket);

			gDebugStream( "Accpet one client , address is" << szAddress << "Port: " << usPort);
		}
	}   
}