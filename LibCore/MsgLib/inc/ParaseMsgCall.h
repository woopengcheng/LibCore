#ifndef __msg_parase_msg_call_h__
#define __msg_parase_msg_call_h__ 
#include "MsgLib/inc/ICallableObject.h"
#include "MsgLib/inc/MethodImpl.h"
#include "NetLib/inc/ISession.h"

namespace Msg
{   
	//5 ��ʼ�ж���Ϣ�ķ�װ,������Ҫ����Ϣ�ĺ������о���Ľ���.	 
	
	class DLL_EXPORT  ParaseMsgCall
	{
	public:
		ParaseMsgCall()
			: m_pObj(NULL)
			, m_pMsgCall(NULL)
			, m_pMehtodImpl(NULL)
			, m_nSessionID(-1)
		{}

	public:
		ICallableObject	*	m_pObj;          //5 ������Ϣ�Ķ��� 
		ObjectMsgCall	*	m_pMsgCall;      //5 �������Ϣ
		MethodImpl		*	m_pMehtodImpl;   //5 ������Ϣ��������ĺ���ָ��
		INT32				m_nSessionID;
	}; 
}

#endif