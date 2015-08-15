#ifndef __net_net_common_h__
#define __net_net_common_h__
#include "tbb/concurrent_unordered_map.h"
#include "tbb/concurrent_hash_map.h"
#include "tbb/concurrent_queue.h"
#include "Common/inc/Common.h"
#include "Common/inc/BoostHelper.h"
#include "LogLib/inc/Log.h"


#ifdef WIN32
#pragma warning(disable : 4710)
#endif

namespace Net
{    
#define DEFAULT_MAX_INCOMING_CONNECTION 8   //5  ���õ����������.RakNetʹ��.
#define ID_DEFAULT_RAKNET_USER_PACKET 	254


#define DEFAULT_THREAD_PRIORITY       0
#define DEFAULT_THREAD_PRIORITY_COUNT 2
#define MAX_CLIENT_NUMBER             0xfffffff
#define MAX_RECURSION_TIMERS          1000
#define MAX_MESSAGE_LENGTH            (4 * 1024) 

#define DEFAULT_SESSION_TIME_OUT      5 * 1000   //5 session�ĳ�ʱʱ�����Ϊ5��.
#define DEFAULT_MAX_CONNECTION_COUNT  100000      //5 ����������ӿͻ��˵�����
#define DEFAULT_LISTENER_COUNT        10
#define DEFAULT_SOCKET_BUFFER_SIZE    (40 * 1024)
#define DEFAULT_CIRCLE_BUFFER_SIZE    (DEFAULT_SOCKET_BUFFER_SIZE * 10)

#define tbb_unordered_map tbb::concurrent_unordered_map 
#define tbb_hash_map      tbb::concurrent_hash_map  
	  
#ifdef WIN32 
	typedef UINT32 NetSocket;
#endif

#define NET_TYPE_TCP  "tcp"
#define NET_TYPE_UDP  "udp"
#define NET_TYPE_UNIX "unix"

	struct MsgHeader 
	{
		UINT32 unMsgLength;    //5 ��һ�������ǳ���
		UINT32 unMsgID;

	public:
		MsgHeader() : unMsgLength(0) , unMsgID(0){}
		MsgHeader(UINT32 msgLength , UINT32 msgID) : unMsgLength(msgLength) , unMsgID(msgID){}
		~MsgHeader(){}
	};

	extern INT32 DLL_EXPORT InitNet() ;

	extern INT32 DLL_EXPORT CleanNet(); 

} //Net

#endif