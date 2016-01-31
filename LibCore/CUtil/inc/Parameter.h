#ifndef __cutil_parameter_h__
#define __cutil_parameter_h__ 
#include "CUtil/inc/Common.h"
#include "Marshal/inc/Marshal.h"
#include "Marshal/inc/CStream.h"

namespace CUtil
{ 
	//5 ��������.��Ҫ���⼸��.�����Ĳ������Ϳ��Ը��������ȡģ���ػ��ķ�ʽ����ת��.
	enum PARAMETER_TYPE
	{ 
		PARAMETER_TYPE_NIL  = 0 ,
		PARAMETER_TYPE_BOOL  , 
		PARAMETER_TYPE_SINT8  , 
		PARAMETER_TYPE_UINT8  , 
		PARAMETER_TYPE_INT16  , 
		PARAMETER_TYPE_UINT16  , 
		PARAMETER_TYPE_INT32  , 
		PARAMETER_TYPE_LONG  , 
		PARAMETER_TYPE_UINT32  , 
		PARAMETER_TYPE_INT64  , 
		PARAMETER_TYPE_UINT64  , 
		PARAMETER_TYPE_FLOAT ,
		PARAMETER_TYPE_DOUBLE ,
		PARAMETER_TYPE_STRING ,
		PARAMETER_TYPE_STD_STRING ,
		PARAMETER_TYPE_CHUNK  ,
		PARAMETER_TYPE_PARAMETER  ,
		PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS  ,  //5 ����������,������д��CString�Ķ�֧��.

		PARAMETER_TYPE_SYSTEM_COUNT ,

		PARAMETER_TYPE_USER_DEFINE = 32 ,   //5 �û��Զ�������.��32���濪ʼ��.
	};

	struct DLL_EXPORT Parameter : public CUtil::Marshal
	{
	public:
		Parameter(); 
		Parameter(const Parameter & objParameter) ;
		template<typename T>
		explicit Parameter(T & t)
		{
			m_unSize = MakeParameter(t);
		}

		virtual ~Parameter(){}

		Parameter & operator = (const Parameter & objParameter);
		bool operator !=(const Parameter & objParam) const
		{ 
			return m_objParamStream!=objParam.GetParamStream() || m_unSize != objParam.GetSize();
		}
		bool operator ==(const Parameter & objParam) const
		{
			return m_objParamStream==objParam.GetParamStream() && m_unSize == objParam.GetSize();
		}
		friend	std::ostream&	operator<<(std::ostream&os,const Parameter & objStream)
		{
			return os << "Parameter:type=" << remove_const(objStream).GetType() << ":size=" << remove_const(objStream).GetSize() << ":datalen=" << remove_const(objStream).GetDataLen() << ":data=" << remove_const(objStream).GetValue();
		}

	public:
		void		Clear(void);
		void		SetSize(UINT32  unSize){ m_unSize = unSize;}
		UINT32		GetSize( void ) const;
		UINT8		GetType( void );
		void	*	GetValue( void );
		UINT32		GetDataLen( void ) const { return m_objParamStream.GetDataLen(); }
		void	*	GetStreamData( void );
		CErrno		CopyTo(Parameter & objParam);
		CUtil::CStream & GetParamStream() { return m_objParamStream; } 
		const CUtil::CStream & GetParamStream() const { return m_objParamStream; } 

	public:
		bool		IsNil(){ return GetType() == PARAMETER_TYPE_NIL; }
		bool		IsBoolean(){ return GetType() == PARAMETER_TYPE_BOOL; }
		bool		IsInt8(){ return GetType() == PARAMETER_TYPE_SINT8; }
		bool		IsUInt8(){ return GetType() == PARAMETER_TYPE_UINT8; }
		bool		IsInt16(){ return GetType() == PARAMETER_TYPE_INT16; }
		bool		IsUInt16(){ return GetType() == PARAMETER_TYPE_UINT16; }
		bool		IsInt32(){ return GetType() == PARAMETER_TYPE_INT32; }
		bool		IsUInt32(){ return GetType() == PARAMETER_TYPE_UINT32; }
		bool		IsLong(){ return GetType() == PARAMETER_TYPE_LONG; }
		bool		IsInt64(){ return GetType() == PARAMETER_TYPE_INT64; }
		bool		IsUInt64(){ return GetType() == PARAMETER_TYPE_UINT64; } 
		bool		IsFloat(){ return GetType() == PARAMETER_TYPE_FLOAT; }
		bool		IsDouble(){ return GetType() == PARAMETER_TYPE_DOUBLE; }
		bool		IsString(){ return GetType() == PARAMETER_TYPE_STRING; }
		bool		IsStdString(){ return GetType() == PARAMETER_TYPE_STD_STRING; }
		bool		IsChunk(){ return GetType() == PARAMETER_TYPE_CHUNK; }  
		bool		IsParamter(){ return GetType() == PARAMETER_TYPE_PARAMETER; }  
		bool		IsContainerOrOthers(){ return GetType() == PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS; }  
		bool		IsUserDefine(){ return GetType() >= PARAMETER_TYPE_USER_DEFINE; }  

	public:
		//5 std::string ����ʹ�á���������Ϊģ��̫�࣬����ʶ��c++11��auto���Խ��������⡣�����Լ���ȡ�Լ����������߸�ֵ���캯�������Ի�ȡ�Լ�������GetParamValue��
		//5 ������ʹ����vs2015��Ҫͨ������ķ�ʽ���ֵ.����:		std::vector<INT32> p15 = objParamter;
		template<typename T>
		operator T ()
		{
			Parameter p;
			T t;
			p.MakeParameter(t);

			MsgAssert_Re(p.GetType() == GetType() , t , "not convert , type error.");
			return GetParameterValue<T>();
		}
						
	public: 
		virtual CUtil::CStream & marshal(CUtil::CStream & cs) const;
		virtual CUtil::CStream & unMarshal(CUtil::CStream & cs);

	public:
		template<typename P1>
		UINT32 MakeParameter(P1 & p1)
		{
			return ParameterHelper<P1>::MakeParameter(*this , p1);
		} 

		template<typename P1>
		void GetParameterValue(P1 & p1)
		{
			ParameterHelper<P1>::GetParameterValue(*this , p1);
		} 

		template<typename P1>
		P1 GetParameterValue()
		{
			return ParameterHelper<P1>::GetParameterValue(*this);
		} 
	private:
		UINT32			m_unSize;
		CUtil::CStream	m_objParamStream;
	};

}
#endif