#ifndef __msg_parameters_h__
#define __msg_parameters_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/Parameter.h"

namespace Msg
{ 
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
			MsgAssert_Re(nPos <= MSG_MAX_PARAMETER_NUMBER && nPos > 0 , t , "pos error."); 

			LibCore::CStream cs;
			m_aParameter[nPos].marshal(cs);
			cs >> t;
			
			return t;
		}

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	public:
		UINT32     m_unParamCount;
		Parameter  m_aParameter[MSG_MAX_PARAMETER_NUMBER];
	};

}
#endif