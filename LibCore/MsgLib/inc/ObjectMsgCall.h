#ifndef __msg_object_msg_call_h__
#define __msg_object_msg_call_h__
#include "MsgLib/inc/MsgCommon.h"
#include "CUtil/inc/Parameters.h"
#include "MsgLib/inc/Object.h"

#ifdef WIN32
#pragma warning(disable : 4200)
#endif

namespace Msg
{ 
	class DLL_EXPORT  ObjectMsgCall : public CUtil::Marshal
	{ 
	public:
		ObjectMsgCall()
			: m_ullMsgID(0) 
			, m_unTargetsCount(0) 
			, m_usPriority(0) 
			, m_aTargets(NULL)
		{  
			RefreshTargets();
		}
		~ObjectMsgCall()
		{ 
		}

	public:
		
		//5 ����New.���ֻ�Ǽ򵥵ĵ��õײ��New.ֻ�Ǵ�С��ȷ��.���������������һ��.ÿ��ֻ������������Ĵ�С�Ͳ����Ĵ�С�Լ�����Ĵ�С.
		static void * operator new(size_t size , UINT32 unExtra)throw()
		{
			return malloc(size + unExtra); 
		}

		void operator delete(void * p , UINT32 unExtra)throw()
		{
			free(p); 
		}

		bool operator < (const ObjectMsgCall & obj)
		{
			return m_usPriority > obj.m_usPriority;  //5 ��С����,m_usPriorityС�����ȼ���
		}

	public: 
		virtual UINT32				RefreshSize();   //5 ע��:�����˷��Ͷ��������.һ��Ҫ�����������.
		virtual void				RefreshTargets();
		virtual UINT32				GetPacketSize( void );

	public:
		void						SetMethodName(const char * pName){ memcpy(m_szMsgMethod , pName , strlen(pName) + 1);}
		void						SetMethodNameByAddSuffix(const char * pName){ memcpy(m_szMsgMethod + strlen(m_szMsgMethod), pName , strlen(pName) + 1);}
		void						SetMethodNameBySubSuffix(const char * pName){ Assert((strlen(m_szMsgMethod) - strlen(pName)) > 0);	m_szMsgMethod[strlen(m_szMsgMethod) - strlen(pName)] = '\0'; }
		CErrno						CopyTo(ObjectMsgCall *& pMsg);
		CErrno						CopyExcludeParams(ObjectMsgCall *& pMsg);
		CErrno						CopyExcludeParamsAndTargets(ObjectMsgCall *& pMsg ,const std::vector<Msg::Object> & vecTargets , Msg::Object objSrc);
		UINT32						GetTargetsCount(){ return m_unTargetsCount; }
		void						SetTargetsCount(UINT32 unTargetsCount){ m_unTargetsCount = unTargetsCount;  }

	public: 
		virtual CUtil::CStream &	marshal(CUtil::CStream & cs) const override;
		virtual CUtil::CStream &	unMarshal(CUtil::CStream & cs) override;

	public:      
		UINT64						m_ullMsgID;                                 //5 ��Ϣ��ID,�ڽ����ڲ�.�������������������.
		CUtil::Parameters			m_objParams;                                //5 ��Ϣ�����Ĳ���. 
		UINT16						m_usPriority;								//5 ���ȼ�
		Object						m_objSource;								//5 ��ϢԴ
		char						m_szMsgMethod[MAX_MSG_METHOD_NAME_LENGTH];  //5 ������Ϣ�ĺ���
		UINT32						m_unTargetsCount;
		Object		*				m_aTargets;									//5 �����������������.����Ҫ�̳оͲ�����.���Ծ��滻�˷���.
	};

	
}
#endif