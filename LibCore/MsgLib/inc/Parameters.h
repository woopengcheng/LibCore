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
		//************************************
		// Method:    GetSize
		// FullName:  Msg::Parameters::GetSize
		// Access:    public 
		// Returns:   UINT32
		// Qualifier: ���������ʹ��һ��Ҫ���ڶԲ����Ѿ�ģ�廯�˺�ʹ��.�����������ֻ��ȡ���в����Ĵ�С.���������������.
		//************************************
		UINT32     GetSize();
		UINT32     Copy(Parameters & pParam);
		UINT32     Serialization(char * pMsg);
		UINT32     UnSerialization(const char * pMsg);
		void       Clear(void);

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	public:
		UINT32     m_unParamCount;
		Parameter  m_aParameter[MSG_MAX_PARAMETER_NUMBER];
	};

}
#endif