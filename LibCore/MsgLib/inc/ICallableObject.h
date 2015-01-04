#ifndef __msg_i_msg_object_h__
#define __msg_i_msg_object_h__ 
#include "MsgCommon.h" 

namespace Msg
{  
	
	class DLL_EXPORT  ICallableObject
	{
	public:
		ICallableObject(Object obj):m_objID(obj){}
		virtual ~ICallableObject(){}
	
	public:
		//************************************
		// Method:    Update
		// FullName:  Msg::ICallableObject::Update
		// Access:    virtual public 
		// Returns:   INT32
		// Qualifier: Update����Ϊ���󹩸���������õ�ʱ��ʹ��.
		//************************************
		virtual INT32 Update(){ return 0; } 

	public:
		virtual Object  GetObjectID(){ return m_objID; }                   //5 �������Ҳ��������.����û�������Ҫ.
		virtual void    SetObjectID(Object objID){ m_objID = objID; }
	
	protected:
		Object      m_objID;
	};
	
	class DLL_EXPORT IMsgCallableObject : public ICallableObject
	{
		public:
			IMsgCallableObject(Object id):ICallableObject(id){}
	};

}
#endif