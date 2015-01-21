#ifndef __msg_object_msg_call_h__
#define __msg_object_msg_call_h__
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/Parameters.h"
#include "MsgLib/inc/Object.h"

#ifdef WIN32
#pragma warning(disable : 4200)
#endif

namespace Msg
{ 
	class DLL_EXPORT  ObjectMsgCall : public LibCore::Marshal
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
		// Qualifier: ����New.���ֻ�Ǽ򵥵ĵ��õײ��New.ֻ�Ǵ�С��ȷ��.���������������һ��.ÿ��ֻ������������Ĵ�С�Ͳ����Ĵ�С�Լ�����Ĵ�С.
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
			return m_usPriority > obj.m_usPriority;  //5 ��С����,m_usPriorityС�����ȼ���
		}

	public: 
		virtual UINT32 RefreshSize();                                  //5 ע��:�����˷��Ͷ��������.һ��Ҫ�����������.
		virtual void   RefreshTargets();
// 		virtual UINT32 Serialization(char * pMsg);
// 		virtual UINT32 UnSerialization(const char * pMsg);
		virtual UINT32 GetPacketSize( void );

	public:
		void    SetMethodName(const char * pName){ memcpy(m_szMsgMethod , pName , strlen(pName) + 1);}
		void    SetMethodNameByAddSuffix(const char * pName){ memcpy(m_szMsgMethod + strlen(m_szMsgMethod), pName , strlen(pName) + 1);}
		void    SetMethodNameBySubSuffix(const char * pName){ Assert((strlen(m_szMsgMethod) - strlen(pName)) > 0);	m_szMsgMethod[strlen(m_szMsgMethod) - strlen(pName)] = '\0'; }
		UINT32  Copy(ObjectMsgCall *& pMsg);
		UINT32  GetTargetsCount(){ return m_unTargetsCount; }
		void    SetTargetsCount(UINT32 unTargetsCount){ m_unTargetsCount = unTargetsCount; RefreshTargets(); RefreshSize(); }

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	public:      
		UINT64             m_ullMsgID;                                 //5 ��Ϣ��ID,�ڽ����ڲ�.�������������������.
		UINT32             m_unMsgLength;                              //5 ������Ϣ�ĳ���,����ֻ��¼������Ϣ�ĳ���.
		char               m_szMsgMethod[MAX_MSG_METHOD_NAME_LENGTH];  //5 ������Ϣ�ĺ���
		Parameters         m_objParams;                                //5 ��Ϣ�����Ĳ���. 
		UINT16             m_usPriority;							   //5 ���ȼ�
		Object			   m_objSource;								   //5 ��ϢԴ

		UINT32			   m_unTargetsCount;
		Object		*	   m_aTargets;      //5 �����������������.����Ҫ�̳оͲ�����.���Ծ��滻�˷���.
	};

	
}
#endif