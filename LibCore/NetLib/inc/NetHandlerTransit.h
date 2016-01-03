#ifndef __net_net_handler_transit_h__
#define __net_net_handler_transit_h__ 
#include "NetLib/inc/INetHandler.h"
#include "CUtil/inc/CircleBuffer.h"

namespace Net 
{  
	class INetReactor; 

	class DLL_EXPORT NetHandlerTransit :public INetHandler
	{
	public:
		NetHandlerTransit( INetReactor * pNetReactor , ISession * pSession); 
		virtual ~NetHandlerTransit( void );

	public:
		virtual CErrno  Init( void ); 
		virtual CErrno  Cleanup( void ); 
		virtual CErrno  Update( void );
		virtual CErrno  OnClose( void ) ;   

	public:                   
		virtual CErrno  OnMsgRecving( void ); 
		virtual CErrno  OnMsgRecving( const char * pBuf , UINT32 unSize ); 
		virtual CErrno  OnMsgSending( void );      
		virtual INT32	SendMsg( const char * pBuf , UINT32 unSize );
		virtual CErrno  HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);

	protected:
		INT32			Send(const char * pBuf, UINT32 unSize);
		INT32			SendTo(const char * pBuf, UINT32 unSize);
		INT32			SendCommon(const char * pBuf, UINT32 unSize);
		INT32			SendIOCP(const char * pBuf, UINT32 unSize);
		CErrno			ParaseRecvMsg();     
		INT32			FlushSendBuffer( void );
		CErrno			RecvToCircleBuffer(const char * pBuf , UINT32 unSize);   //5 将消息扔给CircleBuffer 

	protected:
		CUtil::CircleBuffer    m_objSendBuf;
		CUtil::CircleBuffer    m_objRecvBuf;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerTransit);
	 
}

#endif


