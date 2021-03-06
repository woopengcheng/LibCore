#ifndef __msg_gen_msg_helper_h__
#define __msg_gen_msg_helper_h__ 
#include "CUtil/inc/ParameterHelper.h" 
#include "CUtil/inc/CUtil.h"

namespace CUtil
{
	class Parameters;
	class DLL_EXPORT  GenParamHelper
	{ 
	public:
		static UINT32 GenParams(CUtil::Parameters & objParams); 

		template<typename P1>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 1; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);

			return unSize;
		}

		template<typename P1 , typename P2>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 2; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 

			return unSize;
		}

		template<typename P1 , typename P2 , typename P3>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 3; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 
			unSize += ParameterHelper<P3>::MakeParameter(objParams.m_aParameter[2] , p3); 

			return unSize;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 4; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 
			unSize += ParameterHelper<P3>::MakeParameter(objParams.m_aParameter[2] , p3); 
			unSize += ParameterHelper<P4>::MakeParameter(objParams.m_aParameter[3] , p4);  

			return unSize;
		} 

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 5; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 
			unSize += ParameterHelper<P3>::MakeParameter(objParams.m_aParameter[2] , p3); 
			unSize += ParameterHelper<P4>::MakeParameter(objParams.m_aParameter[3] , p4); 
			unSize += ParameterHelper<P5>::MakeParameter(objParams.m_aParameter[4] , p5); 

			return unSize;
		} 

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 6; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 
			unSize += ParameterHelper<P3>::MakeParameter(objParams.m_aParameter[2] , p3); 
			unSize += ParameterHelper<P4>::MakeParameter(objParams.m_aParameter[3] , p4); 
			unSize += ParameterHelper<P5>::MakeParameter(objParams.m_aParameter[4] , p5); 
			unSize += ParameterHelper<P6>::MakeParameter(objParams.m_aParameter[5] , p6); 

			return unSize;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 7; 
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 
			unSize += ParameterHelper<P3>::MakeParameter(objParams.m_aParameter[2] , p3); 
			unSize += ParameterHelper<P4>::MakeParameter(objParams.m_aParameter[3] , p4); 
			unSize += ParameterHelper<P5>::MakeParameter(objParams.m_aParameter[4] , p5); 
			unSize += ParameterHelper<P6>::MakeParameter(objParams.m_aParameter[5] , p6); 
			unSize += ParameterHelper<P7>::MakeParameter(objParams.m_aParameter[6] , p7); 

			return unSize;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		static UINT32 GenParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8)
		{
			UINT32 unSize = 0;
			objParams.m_unParamCount = 8;
			unSize += ParameterHelper<P1>::MakeParameter(objParams.m_aParameter[0] , p1);
			unSize += ParameterHelper<P2>::MakeParameter(objParams.m_aParameter[1] , p2); 
			unSize += ParameterHelper<P3>::MakeParameter(objParams.m_aParameter[2] , p3); 
			unSize += ParameterHelper<P4>::MakeParameter(objParams.m_aParameter[3] , p4); 
			unSize += ParameterHelper<P5>::MakeParameter(objParams.m_aParameter[4] , p5); 
			unSize += ParameterHelper<P6>::MakeParameter(objParams.m_aParameter[5] , p6); 
			unSize += ParameterHelper<P7>::MakeParameter(objParams.m_aParameter[6] , p7); 
			unSize += ParameterHelper<P8>::MakeParameter(objParams.m_aParameter[7] , p8); 

			return unSize;
		}

	public:
		static BOOL CheckParams(CUtil::Parameters & objParams); 

		template<typename P1>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 1)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;   
			}

			return bResult;
		}


		template<typename P1 , typename P2>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 2)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult;  
			}

			return bResult;
		}

		template<typename P1 , typename P2 , typename P3>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 3)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult; 
				bResult = ParameterHelper<P3>::CheckParamType(objParams.m_aParameter[2] ) && bResult;  
			}

			return bResult;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 4)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult; 
				bResult = ParameterHelper<P3>::CheckParamType(objParams.m_aParameter[2] ) && bResult; 
				bResult = ParameterHelper<P4>::CheckParamType(objParams.m_aParameter[3] ) && bResult;  
			}

			return bResult;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 5)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult; 
				bResult = ParameterHelper<P3>::CheckParamType(objParams.m_aParameter[2] ) && bResult; 
				bResult = ParameterHelper<P4>::CheckParamType(objParams.m_aParameter[3] ) && bResult; 
				bResult = ParameterHelper<P5>::CheckParamType(objParams.m_aParameter[4] ) && bResult;  
			}

			return bResult;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 6)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult; 
				bResult = ParameterHelper<P3>::CheckParamType(objParams.m_aParameter[2] ) && bResult; 
				bResult = ParameterHelper<P4>::CheckParamType(objParams.m_aParameter[3] ) && bResult; 
				bResult = ParameterHelper<P5>::CheckParamType(objParams.m_aParameter[4] ) && bResult; 
				bResult = ParameterHelper<P6>::CheckParamType(objParams.m_aParameter[5] ) && bResult;   
			}

			return bResult;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 7)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult; 
				bResult = ParameterHelper<P3>::CheckParamType(objParams.m_aParameter[2] ) && bResult; 
				bResult = ParameterHelper<P4>::CheckParamType(objParams.m_aParameter[3] ) && bResult; 
				bResult = ParameterHelper<P5>::CheckParamType(objParams.m_aParameter[4] ) && bResult; 
				bResult = ParameterHelper<P6>::CheckParamType(objParams.m_aParameter[5] ) && bResult; 
				bResult = ParameterHelper<P7>::CheckParamType(objParams.m_aParameter[6] ) && bResult;  
			}

			return bResult;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		static BOOL CheckParams(CUtil::Parameters & objParams , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8)
		{
			bool bResult = true;
			if(objParams.m_unParamCount != 8)
			{
				bResult = false;
			}
			else
			{
				bResult = ParameterHelper<P1>::CheckParamType(objParams.m_aParameter[0] ) && bResult;
				bResult = ParameterHelper<P2>::CheckParamType(objParams.m_aParameter[1]) && bResult; 
				bResult = ParameterHelper<P3>::CheckParamType(objParams.m_aParameter[2] ) && bResult; 
				bResult = ParameterHelper<P4>::CheckParamType(objParams.m_aParameter[3] ) && bResult; 
				bResult = ParameterHelper<P5>::CheckParamType(objParams.m_aParameter[4] ) && bResult; 
				bResult = ParameterHelper<P6>::CheckParamType(objParams.m_aParameter[5] ) && bResult; 
				bResult = ParameterHelper<P7>::CheckParamType(objParams.m_aParameter[6] ) && bResult; 
				bResult = ParameterHelper<P8>::CheckParamType(objParams.m_aParameter[7] ) && bResult;  
			}

			return bResult;
		}

	};      
}

#endif