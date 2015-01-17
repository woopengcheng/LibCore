#ifndef __net_net_interface_h__
#define __net_net_interface_h__
#include "NetLib/inc/NetCommon.h" 

namespace Net
{
	class MsgProcess;
	class MsgHandler;
	class NetBase;

	class DLL_EXPORT NetInterface
	{
	public:
		NetInterface(void);
		virtual ~NetInterface(void); 

	public:
		static NetInterface & GetInstance();

	public:
		//************************************
		// Method:    Init
		// FullName:  Net::NetInterface::Init
		// Access:    virtual public 
		// Returns:   INT32
		// Qualifier: 这里就是开2个线程.然后执行网络.
		// Parameter: void
		//************************************
		virtual INT32  Init(void);

		//************************************
		// Method:    Cleanup
		// FullName:  Net::NetInterface::Cleanup
		// Access:    virtual public 
		// Returns:   INT32
		// Qualifier:
		// Parameter: void
		//************************************
		virtual INT32  Cleanup(void);

		//************************************
		// Method:    AddClient
		// FullName:  Net::NetInterface::AddClient
		// Access:    virtual public 
		// Returns:   INT32 返回连接的网络ID.错误返回NET_ERROR_FAILURE
		// Qualifier:
		// Parameter: MsgHandler * pMsgHandler
		// Parameter: char * szAddress
		// Parameter: UINT16 usPort
		//************************************
		virtual INT32 AddClient(MsgProcess * pMsgProcess , char* pAddress, UINT16 usPort , BOOL bAutoManagerMemeory = FALSE);   
		
		//************************************
		// Method:    IsConnected
		// FullName:  Net::NetInterface::IsConnected
		// Access:    virtual public 
		// Returns:   BOOL 返回当前的连接是否成功
		// Qualifier:
		// Parameter: UINT32 unIndex
		//************************************
		virtual BOOL  IsConnected(UINT32 unClientIndex);
		 
		//************************************
		// Method:    SendMsg
		// FullName:  Net::NetInterface::SendMsg
		// Access:    virtual public 
		// Returns:   INT32
		// Qualifier:
		// Parameter: UINT32 unClientIndex
		// Parameter: UINT32 unMsgID
		// Parameter: const char * pBuffer
		// Parameter: UINT32 unLength
		//************************************
		virtual INT32  SendMsg(UINT32 unClientIndex , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);
	  
	private: 
		MsgHandler   *   m_pMsgHandler; 

	};
}
#endif
