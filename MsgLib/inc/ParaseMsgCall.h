#ifndef __msg_parase_msg_call_h__
#define __msg_parase_msg_call_h__ 
#include "ICallableObject.h"
#include "MethodImpl.h"

namespace Msg
{   
	//5 开始有对消息的封装,这里需要对消息的函数进行具体的解析.	 
	
	class DLL_EXPORT  ParaseMsgCall
	{
	public:
		ParaseMsgCall():m_pObj(NULL) , m_pMsgCall(NULL) , m_pMehtodImpl(NULL){}

	public:
		ICallableObject * m_pObj;          //5 处理消息的对象 
		ObjectMsgCall   * m_pMsgCall;      //5 具体的消息
		MethodImpl      * m_pMehtodImpl;   //5 具体消息用来处理的函数指针
	}; 
}

#endif