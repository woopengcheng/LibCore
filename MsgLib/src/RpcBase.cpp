#include "RpcBase.h"
#include "RpcInterface.h"
#include "ICallableObject.h"
#include "GenMsgHelper.h"
#include "Parameters.h"
#include "RPCMsgCall.h"
#include "Chunk.h"
#include "IRpcMsgCallableObject.h"

namespace Msg
{ 
	Parameters * Rpc::GetReturnParams( std::string strFunName )
	{
		MapCollectParametersT::iterator iter = m_mapReturnParams.find(strFunName);
		if (iter != m_mapReturnParams.end())
		{
			return &iter->second;
		}

		return NULL;
	}


	Parameters * Rpc::GetDeliverParams( std::string strFunName )
	{
		MapCollectParametersT::iterator iter = m_mapDeliverParams.find(strFunName);
		if (iter != m_mapDeliverParams.end())
		{
			return &iter->second;
		}

		return NULL;
	}

	void Rpc::InsertReturnParams( std::string strFunName , Parameters & objParam )
	{
		MapCollectParametersT::iterator iter = m_mapReturnParams.find(strFunName);
		if (iter == m_mapReturnParams.end())
		{
			m_mapReturnParams.insert(std::make_pair(strFunName , objParam));
		}
		else
		{
			Assert(0 && "Has return params");
		}
	}


	void Rpc::InsertDeliverParams( std::string strFunName , Parameters & objParam )
	{
		MapCollectParametersT::iterator iter = m_mapDeliverParams.find(strFunName);
		if (iter == m_mapDeliverParams.end())
		{
			m_mapDeliverParams.insert(std::make_pair(strFunName , objParam)); //5 ����������.������ַ���ָ��.û��copy.����������ʽ����.
		}
		else
		{
			Assert(0 && "Has deliver params");
		}
	} 

	INT32 Rpc::ProxySendBack()
	{
		Assert_ReF1("rpc packet is null." && m_pRpcMsgCall); 

		RPCMsgCall * pRpcMsgCall = NULL;
		m_pRpcMsgCall->Copy(pRpcMsgCall);
		return m_pRpcManager->SendMsg(m_pRpcMsgCall->GetSessionName() , pRpcMsgCall);   
	}  

	BOOL Rpc::CallObjectFunc( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall)
	{
		Assert_Re0(pMsg && m_pRpcManager);

		std::string strMethod = pMsg->m_szMsgMethod;
		switch (pMsg->GetRpcMsgCallType())
		{
		case RPCTYPE_CLIENT:
			strMethod += RPCClient;
			break;
		case RPCTYPE_SERVER_PROXY:
			strMethod += RPCServerProxy;
			break;
		case RPCTYPE_CLIENT_PROXY:
			strMethod += RPCClientProxy;
			break;
		case RPCTYPE_SERVER:
			strMethod += RPCServer;
			break;
		case RPCTYPE_TIMEOUT:
			strMethod += RPCTimeout;
			break;
		default: 
			return 0;
		}
		MethodImpl * pMethodImpl = m_pRpcManager->GetMethodImpl(strMethod.c_str());
		Assert_Re0(pMethodImpl);

		ParaseMsgCall objParaseMsgCall;
		objParaseMsgCall.m_pMehtodImpl = pMethodImpl;
		objParaseMsgCall.m_pMsgCall = pMsg;  
		objParaseMsgCall.m_pObj = this;

		IRpcMsgCallableObject * pICallableObject = NULL;

		if (!pMsg->m_bClientRequest)  //5 ���������
		{  
			if (pMsg->GetTargetsCount() != 0) 
			{ 
				for (UINT32 i = 0;i < pMsg->GetTargetsCount();++i)
				{
					pICallableObject = dynamic_cast<IRpcMsgCallableObject *>(m_pRpcManager->GetCallableObject(pMsg->m_aTargets[i]));
					if (!pICallableObject && pMsg->GetRpcMsgCallType() == RPCTYPE_SERVER_PROXY) 
					{
						pICallableObject = dynamic_cast<IRpcMsgCallableObject *>(m_pRpcManager->GetCallableObject(DEFAULT_RPC_CALLABLE_ID));   //5 �����RPC����Ļ�.���ܻ��Ҳ�����Ӧ�Ķ���.�������Ĭ�ϵ�.
						if (pICallableObject)
						{
							pMsg->SetProxySrcID(pMsg->m_objSource);  
							pMsg->m_objSource = pICallableObject->GetObjectID();
						}
					} 

					//5 ��������˵�.���������ҵ���Ӧ��.
					if (pICallableObject)
					{   
						pICallableObject->SetRpcMsgCall(pMsg);
						objParaseMsgCall.m_pObj = pICallableObject;

						vecObjectMsgCall.push_back(pMethodImpl->m_pMethodImpl(&objParaseMsgCall));
					} 
					else 
					{ 
						Assert_Re0(0 && "����������.�޴�RPC��object����.");
					}
				}   
			}   
		}
		else  //5 �ͻ�������
		{
			pICallableObject = dynamic_cast<IRpcMsgCallableObject *>(m_pRpcManager->GetCallableObject(pMsg->m_objSource)); 

			//5 �����ͻ��˵�.
			if (pICallableObject)
			{ 
				pICallableObject->SetRpcMsgCall(pMsg); 
				objParaseMsgCall.m_pObj = pICallableObject;

				vecObjectMsgCall.push_back(pMethodImpl->m_pMethodImpl(&objParaseMsgCall));
			} 
			else 
			{ 
				Assert_Re0(0 && "�ͻ��˽��ܵ�����Ķ���.�޴�RPC��object����.");
			} 
		}

		return 0;
	}


	BOOL Rpc::OnClient( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall )
	{  
		return  CallObjectFunc(pMsg , vecObjectMsgCall); 
	} 


	BOOL Rpc::OnProxy( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall )
	{
		return CallObjectFunc(pMsg , vecObjectMsgCall); 
	}


	BOOL Rpc::OnServer( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall )
	{  
		return CallObjectFunc(pMsg , vecObjectMsgCall);  
	}


	BOOL Rpc::OnTimeout( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall )
	{ 
		return CallObjectFunc(pMsg , vecObjectMsgCall);
	}


	void Rpc::SetTimeout( UINT64 unTimeout )
	{
		m_objTimeout.Start(unTimeout * 1000);
	}


	BOOL Rpc::IsTimeout()
	{
		return  m_objTimeout.IsExpired();
	}

//#include "rpc.crpc"  //5 
}