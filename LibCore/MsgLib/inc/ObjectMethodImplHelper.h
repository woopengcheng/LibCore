#ifndef __msg_object_method_impl_helper_h__
#define __msg_object_method_impl_helper_h__ 
#include "MsgLib/inc/MethodImpl.h" 
#include "MsgLib/inc/ParaseMsgCall.h"
#include "MsgLib/inc/ParameterHelper.h"
#include "MsgLib/inc/Object.h"

namespace Msg
{  
	class DLL_EXPORT  ObjectMethodImplHelper
	{
	public:
		template< typename ClassObject , typename Func>
		static ObjectMsgCall * CallFuncEntry(ParaseMsgCall * pPMC)   //5 ���Ա�������������
		{
			Assert_Re0(pPMC && pPMC->m_pMehtodImpl && pPMC->m_pMsgCall && pPMC->m_pObj);

			ClassObject * pObj = static_cast<ClassObject*>(pPMC->m_pObj); 

			ObjectMethodImpl< ClassObject , Func> * pMehtodImpl = static_cast<ObjectMethodImpl< ClassObject , Func>*>(pPMC->m_pMehtodImpl);
			return CallFunc< ClassObject>(pPMC, *pObj , pMehtodImpl->m_objFunc);
		}

	public:
		template< typename ClassObject>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc);
		}

		template< typename ClassObject , typename P1>
		static ObjectMsgCall *  CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]));
		}

		template< typename ClassObject , typename P1 , typename P2>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]));
		}

		template< typename ClassObject , typename P1 , typename P2 , typename P3>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 , P3 ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]));
		}

		template< typename ClassObject , typename P1 , typename P2 , typename P3 , typename P4>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 , P3 , P4 ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]));
		}

		template< typename ClassObject , typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 , P3 , P4 , P5 ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]));
		}

		template< typename ClassObject , typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 >
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 , P3 , P4 , P5 , P6 ))
		{ 
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				ParameterHelper<P6>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[5]));
		}

		template< typename ClassObject , typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 , P3 , P4 , P5 , P6 , P7 ))
		{ 
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				ParameterHelper<P6>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[5]) ,
				ParameterHelper<P7>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[6]));
		}

		template< typename ClassObject , typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ClassObject & obj , ObjectMsgCall * (ClassObject::*func)(std::vector<Object>  , Object , P1 , P2 , P3 , P4 , P5 , P6 , P7 , P8 ))	
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (obj.*func)(vecTargets , objSrc , 
				ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				ParameterHelper<P6>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[5]) ,
				ParameterHelper<P7>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[6]) ,
				ParameterHelper<P8>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[7]));
		}

	};     
	   
}

#endif