#ifndef __msg_parameters_h__
#define __msg_parameters_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/Parameter.h"

namespace Msg
{ 
	class GenMsgHelper;

	class DLL_EXPORT Parameters : public LibCore::Marshal
	{
	public: 
		Parameters() : m_unParamCount(0){}
		~Parameters(){}

		Parameters(const Parameters & objParameters) 
		{ 
			m_unParamCount = objParameters.m_unParamCount;
			for (int i = 0;i < MSG_MAX_PARAMETER_NUMBER;++i)
			{
				m_aParameter[i] = objParameters.m_aParameter[i];
			}
		}

	public:
		Parameters & operator = (const Parameters & objParameters)
		{
			m_unParamCount = objParameters.m_unParamCount;
			for (int i = 0;i < MSG_MAX_PARAMETER_NUMBER;++i)
			{
				m_aParameter[i] = objParameters.m_aParameter[i];
			}
			return *this;
		} 

	public:  
		UINT32     GetSize();
		UINT32     Copy(Parameters & pParam); 
		void       Clear(void);

		//5 性能不够高,这里需要改进.
		template<typename T>
		T GetValue(INT32 nPos = 0)
		{
			T t;
			UINT32 unType = 0;
			MsgAssert_Re( nPos >= 0 && nPos <= MSG_MAX_PARAMETER_NUMBER , t , "pos error."); 

			m_aParameter[nPos].GetParamStream() >> unType;
			
			m_aParameter[nPos].GetParamStream() >> t;
			
			return t;
		}

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	public:
// 		void GenMsgParams()
// 		{
// 			GenMsgHelper::GenMsgParams(*this);
// 		} 
// 
		template<typename P1>
		void GenMsgParams(P1 &p1)
		{
			GenMsgHelper::GenMsgParams(*this , p1);
		}

		template<typename P1 , typename P2>
		void GenMsgParams(P1 &p1 , P2 &p2)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2);
		}

		template<typename P1 , typename P2 , typename P3>
		void GenMsgParams(P1 &p1 , P2 &p2 , P3 &p3)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2 , p3);
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		void GenMsgParams(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2 , p3 , p4);
		} 

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		void GenMsgParams(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2 , p3 , p4 , p5 );
		} 

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		void GenMsgParams(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2 , p3 , p4 , p5 , p6 );
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		void GenMsgParams(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2 , p3 , p4 , p5 , p6 , p7);
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		void GenMsgParams(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8)
		{
			GenMsgHelper::GenMsgParams(*this , p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8);
		}

	public:
		UINT32     m_unParamCount;
		Parameter  m_aParameter[MSG_MAX_PARAMETER_NUMBER];
	};

}
#endif