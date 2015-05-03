#include "MsgLib/inc/NetHandlerRpcListener.h" 
#include "MsgLib/inc/RpcManager.h"
#include "NetLib/inc/NetHelper.h"
#include "MsgLib/inc/RpcInterface.h"

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

			if(NULL == m_pRpcManager->CreateNetHandler(strRemoteRPCName.c_str() , szAddress , usPort , socket))
			{
				gErrorStream("Accept client error," << strRemoteRPCName);
			}
			else
			{
				gDebugStream( "Accpet client , address:" << szAddress << ",port:" << usPort);
			}
		}
	}   
}