#ifndef __msg_object_msg_call_h__
#define __msg_object_msg_call_h__
#include "MsgCommon.h"
#include "Parameters.h"
#include "Object.h"

#ifdef WIN32
#pragma warning(disable : 4200)
#endif

namespace Msg
{ 
	class DLL_EXPORT  ObjectMsgCall
	{ 
	public:
		ObjectMsgCall() :m_ullMsgID(0) ,m_unMsgLength(0) , m_unTargetsCount(0) , m_usPriority(0) , m_aTargets(NULL)
		{  
		}
		~ObjectMsgCall()
		{ 
		}

	public:
		//************************************
		// Method:    GetSize
		// FullName:  Msg::ObjectMsgCall::GetSize
		// Access:    virtual public 
		// Returns:   UINT32
		// Qualifier: 重载New.这个只是简单的调用底层的New.只是大小不确定.所以在这里更改了一下.每次只传入柔性数组的大小和参数的大小以及本体的大小.
		//************************************
		static void * operator new(size_t size , size_t unExtra)
		{
			return malloc(size + unExtra); 
		}

		void operator delete(void * p , size_t unExtra)
		{
			free(p); 
		}

		bool operator < (const ObjectMsgCall & obj)
		{
			return m_usPriority > obj.m_usPriority;  //5 从小到达,m_usPriority小的优先级高
		}

	public: 
		virtual UINT32 RefreshSize();                                  //5 注意:更改了发送对象的数量.一定要调用这个函数.
		virtual void   RefreshTargets();
		virtual UINT32 Serialization(char * pMsg);
		virtual UINT32 UnSerialization(const char * pMsg);

	public:
		void    SetMethodName(const char * pName){ memcpy(m_szMsgMethod , pName , strlen(pName) + 1);}
		void    SetMethodNameByAddSuffix(const char * pName){ memcpy(m_szMsgMethod + strlen(m_szMsgMethod), pName , strlen(pName) + 1);}
		void    SetMethodNameBySubSuffix(const char * pName){ Assert((strlen(m_szMsgMethod) - strlen(pName)) > 0);	m_szMsgMethod[strlen(m_szMsgMethod) - strlen(pName)] = '\0'; }
		UINT32  Copy(ObjectMsgCall *& pMsg);
		UINT32  GetTargetsCount(){ return m_unTargetsCount; }
		void    SetTargetsCount(UINT32 unTargetsCount){ m_unTargetsCount = unTargetsCount; RefreshTargets(); RefreshSize(); }

	public:      
		UINT64             m_ullMsgID;                                 //5 消息的ID,在进程内部.这个变量基本上无用了.
		UINT32             m_unMsgLength;                              //5 整个消息的长度,这里只记录发送消息的长度.
		char               m_szMsgMethod[MAX_MSG_METHOD_NAME_LENGTH];  //5 调用消息的函数
		Parameters         m_objParams;                                //5 消息函数的参数. 
		UINT16             m_usPriority;

		Object			   m_objSource;       //5 消息源
		Object			 * m_aTargets;      //5 目标采用柔性数组来做,这样更节省空间.但是有一个问题.真正的不能保证这个数组的大小.如果是游戏客户端可能会产生Bug.这里是内部通信.数据是有保证的.
	
	private:
		UINT32			   m_unTargetsCount;
	};

	
}
#endif