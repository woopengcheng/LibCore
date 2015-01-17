#ifndef __msg_msg_dispatcher_h__
#define __msg_msg_dispatcher_h__
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/MethodImpl.h"
#include "MsgLib/inc/ParaseMsgCall.h" 
#include "MsgLib/inc/StaticMethodImplHelper.h"
#include "MsgLib/inc/ObjectMethodImplHelper.h"

namespace Msg 
{ 
	
	class DLL_EXPORT  MsgDispatcher
	{
	public:
		MsgDispatcher(){}
		virtual ~MsgDispatcher();
	public:
		typedef  std_unordered_map<std::string , MethodImpl *> MapMethodImplT;
		typedef  std_unordered_map<Object , ICallableObject * , ObjectHashFunc> MapCallableObjectsT; 

	public:
		INT32   AddCallableObject(ICallableObject * pCallableObject);
		INT32   DelCallableObject(ICallableObject * pCallableObject);

		MethodImpl *   GetMethodImpl(std::string strFuncName); 
		ICallableObject * GetCallableObject(Object obj);

	public:
		BOOL    HasSimilarRegisterFunc(std::string strFuncName ,  std::string strFuncType);
		INT32   Dispatcher(ObjectMsgCall * pObjectMsgCall ,Object obj);

	public: 
		//5 ע�ᾲ̬��ĺ��� 
		template< typename Func>
		INT32 RegisterFunc(const char * pFuncName , Func pFunc)
		{ 
			StaticMethodImpl< Func> * pSMI = new StaticMethodImpl< Func>;   //5 ���ｫ������װ�ھ�̬��������.
			pSMI->m_cMethodType = METHOD_TYPE_STATIC;  
			STRCPY_SAFE(pSMI->m_pMehtodName , MAX_MSG_METHOD_NAME_LENGTH , pFuncName ); 
			pSMI->m_objFunc = pFunc;
			pSMI->m_pMethodImpl = StaticMethodImplHelper::CallFuncEntry< Func>;
			 
			MapMethodImplT::iterator result = m_mapMethodImpls.find(pFuncName); 
			if (result == m_mapMethodImpls.end())
			{
				m_mapMethodImpls.insert(std::make_pair(pFuncName , pSMI));
			}
			else
			{
				MsgAssert_ReF1(0 , "repeat Methodfunc register.");

				result->second = pSMI;
				SAFE_DELETE(pSMI);

				return ERR_FAILURE;
			}

			return ERR_SUCCESS;
		}
		 
		//5 ע�������ĺ��� , ����ʹ����һ��С����.ֻ���������.Func�ǿ��ԴӲ����Ƶ�������. 
		template< typename ClassObject , typename Func>
		INT32 RegisterFunc(const char * pFuncName , Func pFunc)
		{ 
			ObjectMethodImpl< ClassObject , Func> * pOMI = new ObjectMethodImpl< ClassObject , Func>; 
			pOMI->m_cMethodType = METHOD_TYPE_OBJECT;
			memcpy(pOMI->m_pMehtodName , pFuncName , MAX_MSG_METHOD_NAME_LENGTH);

			pOMI->m_objFunc = pFunc;
			pOMI->m_pObj = NULL;
			pOMI->m_pMethodImpl = ObjectMethodImplHelper::CallFuncEntry< ClassObject , Func>; 

			MapMethodImplT::iterator result = m_mapMethodImpls.find(pFuncName); 
			if (result == m_mapMethodImpls.end())
			{
				m_mapMethodImpls.insert(std::make_pair(pFuncName , pOMI));
			}
			else
			{
				MsgAssert_ReF1(0 , "Methodfunc repeat register.");

				result->second = pOMI;
				SAFE_DELETE(pOMI);

				return ERR_FAILURE;
			} 

			return ERR_SUCCESS;
		}

	protected:
		MapMethodImplT       m_mapMethodImpls;
		MapCallableObjectsT  m_mapCallableObjects;
	}; 
	 
}

#endif
