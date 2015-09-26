#ifndef __cutil_crtti_h__
#define __cutil_crtti_h__
#include "CUtil/inc/Common.h"
#include "CUtil/inc/CObject.h"

#define MAX_RTTI_PARENT_COUNT 4

typedef CObject * (*pCreateFunc)();

#define BASE(ParanetClassName) &m_sClassName##ParanetClassName

#define DECLARE_RTTI_CLASS(ClassName)\
	static CRTTI			m_sClass##ClassName;\
	static ClassName	*	CreateObject();\
	static CRTTI		*	GetClass(){ return & ClassName::m_sClass##ClassName; }\
	virtual CRTTI		*	GetRuntimeClass() {return & ClassName::m_sClass##ClassName; }

#define DEFINE_RTTI_CLASS(ClassName ,nClassGUID , ...)\
	CRTTI ClassName::m_sClass##ClassName(#ClassName , nClassGUID , pCreateFunc , sizeof(ClassName) , __VA_ARGS__\
	CRTTI * ClassName::CreateObject(){ return new ClassName; }


namespace CUtil
{
	class CRTTI
	{
	public:
		typedef std::unordered_map<INT32 , CRTTI *> CollectionRTTIByGUIDT;
		typedef std::unordered_map<std::string , CRTTI *> CollectionRTTIByNameT;

	public:
		CRTTI(const char * pName , INT32 nGUID , pCreateFunc pFunc , INT32 nClassSize , CRTTI * pP0 = NULL , CRTTI * pP1 = NULL , CRTTI * pP2 = NULL , CRTTI * pP3 = NULL);
		~CRTTI();

	public:
		inline	CRTTI	**	GetParents() { return m_pParent; }
		inline	BOOL		IsDerivedFrom( const CRTTI * pBase);
		inline	INT32		GetClassSize()	const { return m_nClassSize; }
		inline	INT32		GetClassGUID()	const { return m_nClassGUID; }
		inline	std::string GetClassName()	const { return m_strClassName; }
		CObject	*	CreateObject()
		{
			return m_pCreateFunc();
		}

	public:
		static	BOOL		InsertRuntimeClass(INT32 nClassGUID , const std::string & strName , CRTTI * pClass);
		static	CRTTI	*	GetRuntimeClass(const std::string & strName);
		static	CRTTI	*	GetRuntimeClass(INT32 nClassGUID);

	private:
		CRTTI		*	m_pParent[MAX_RTTI_PARENT_COUNT];
		INT32			m_nClassGUID;
		INT32			m_nClassSize;
		std::string		m_strClassName;
		pCreateFunc		m_pCreateFunc;

	public:
		static CollectionRTTIByGUIDT m_sRTTIByGUID;
		static CollectionRTTIByNameT m_sRTTIByName;
	};

}


#endif