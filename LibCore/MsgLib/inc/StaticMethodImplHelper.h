#ifndef __msg_static_method_impl_helper_h__
#define __msg_static_method_impl_helper_h__ 
#include "MsgLib/inc/MethodImpl.h" 
#include "MsgLib/inc/ParaseMsgCall.h"
#include "MsgLib/inc/Object.h"

namespace Msg
{  
	class DLL_EXPORT StaticMethodImplHelper 
	{
	public:
		template< typename Func>
		static ObjectMsgCall *  CallFuncEntry(ParaseMsgCall * pPMC)  //5 静态方法函数的入口
		{ 
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			StaticMethodImpl< Func> * pFunc = (StaticMethodImpl< Func> *)(pPMC->m_pMehtodImpl);

			return CallFunc(pPMC , pFunc->m_objFunc);       //5 这里会根据传递进来的函数找到对应的参数.
		}

	public: 
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(vecTargets , objSrc);
		}

		template< typename P1>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]),
				vecTargets , objSrc);
		}

		template< typename P1 , typename P2>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				vecTargets , objSrc); 
		}

		template< typename P1 , typename P2 , typename P3>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , P3 , std::vector<Object>  , Object  ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				vecTargets , objSrc);
		}

		template< typename P1 , typename P2 , typename P3 , typename P4>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , P3 , P4 , std::vector<Object>  , Object  ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				vecTargets , objSrc);
		}
		template< typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , P3 , P4 , P5 , std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				vecTargets , objSrc);
		}

		template< typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 >
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , P3 , P4 , P5 , P6 , std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				ParameterHelper<P6>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[5]) , 
				vecTargets , objSrc); 
		}

		template< typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , P3 , P4 , P5 , P6 , P7 , std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				ParameterHelper<P6>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[5]) ,
				ParameterHelper<P7>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[6]) ,
				vecTargets , objSrc);
		}

		template< typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		static ObjectMsgCall * CallFunc(ParaseMsgCall * pPMC,ObjectMsgCall * (*func)(P1 , P2 , P3 , P4 , P5 , P6 , P7 , P8 , std::vector<Object>  , Object ))
		{
			Assert_Re0(pPMC && pPMC->m_pMsgCall);
			std::vector<Object> vecTargets;
			for (UINT32 i = 0;i < pPMC->m_pMsgCall->GetTargetsCount();++i)
			{
				vecTargets.push_back(pPMC->m_pMsgCall->m_aTargets[i]);
			}
			Object objSrc = pPMC->m_pMsgCall->m_objSource;

			return (*func)(ParameterHelper<P1>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[0]) , 
				ParameterHelper<P2>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[1]) ,
				ParameterHelper<P3>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[2]) ,
				ParameterHelper<P4>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[3]) ,
				ParameterHelper<P5>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[4]) ,
				ParameterHelper<P6>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[5]) ,
				ParameterHelper<P7>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[6]) ,
				ParameterHelper<P8>::GetParameterValue(pPMC->m_pMsgCall->m_objParams.m_aParameter[7]) ,
				vecTargets , objSrc); 
		}
	};  
}

#endif