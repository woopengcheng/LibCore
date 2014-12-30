#ifndef __net_net_handler_transit_h__
#define __net_net_handler_transit_h__ 
#include "INetHandler.h"
#include "CircleBuffer.h"

namespace Net 
{  
	class INetReactor; 

	class DLL_EXPORT NetHandlerTransit :public INetHandler
	{
	public:
		NetHandlerTransit( INetReactor * pNetReactor , ISession * pSession); 
		virtual ~NetHandlerTransit( void );

	public:
		virtual INT32  Init( void ); 
		virtual INT32  Cleanup( void ); 
		virtual INT32  Update( void );
		virtual INT32  OnClose( void ) ;  
		virtual INT32  OnMsgRecving( void ); 
		virtual INT32  OnMsgSending( void ); 

	public:                         
		virtual INT32  Send( const char * pBuf , UINT32 unSize);
		virtual INT32  SendMsg( const char * pBuf , UINT32 unSize );
		virtual INT32  HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);
		virtual INT32  ParaseRecvMsg();     
		virtual INT32  RecvToCircleBuffer(char * pBuf , UINT32 unSize);   //5 将消息扔给CircleBuffer 

	private:
		INT32   FlushSendBuffer( void );

	private:
		LibCore::CircleBuffer    m_objSendBuf;
		LibCore::CircleBuffer    m_objRecvBuf;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerTransit);
}

#endif


