#ifndef __cutil_common_marshal_h__
#define __cutil_common_marshal_h__
#include "Marshal/Marshal.h"


namespace CUtil
{
	class CStream;

	class DLL_EXPORT CharPtr : public CUtil::Marshal
	{ 
	public:
		CharPtr( void ): m_pBuf(NULL) , m_unLen(0) {}
		CharPtr(char * pBuf , UINT32 unLen) : m_pBuf(pBuf) , m_unLen(unLen) {}

	public:
		virtual CStream & marshal(CStream & cs);
		virtual CStream & unMarshal(CStream & cs);

	protected:
		char * m_pBuf;
		UINT32 m_unLen;
	};

	template<typename Container>
	class  STLContainer : public CUtil::Marshal
	{ 
	public: 
		STLContainer( Container & pContainer ): m_pContainer(&pContainer){}  //5 默认隐式转换.不加explicit
		STLContainer(STLContainer<Container> & stl)
		{
			std::copy(stl.GetContainer()->begin(), stl.GetContainer()->end(), std::back_inserter(*m_pContainer));  
		}
	public:
		virtual CStream & marshal( CStream & cs )
		{
			cs << m_pContainer->size();

			Container::iterator iter = m_pContainer->begin();
			for (;iter != m_pContainer->end(); ++iter)
			{
				cs << *iter;
			}

			return cs;
		}
		virtual CStream & unMarshal (CStream & cs)
		{
			m_pContainer->clear();
			size_t unCount = 0;
			cs >> unCount;
			for (;unCount > 0; --unCount)
			{
				typename Container::value_type val;
				cs >> val;

				m_pContainer->insert(m_pContainer->end() , val);
			}

			return cs;
		}

		Container * GetContainer(){ return  m_pContainer; }

	protected:
		Container * m_pContainer;
	};

	template<typename Container>
	class  STLContainer<typename Container &> : public CUtil::Marshal
	{ 
	public: 
		STLContainer( Container & pContainer ): m_pContainer(&pContainer){}  //5 默认隐式转换.不加explicit
		STLContainer(STLContainer<Container> & stl)
		{
			std::copy(stl.GetContainer()->begin(), stl.GetContainer()->end(), std::back_inserter(*m_pContainer));  
		}
	public:
		virtual CStream & marshal( CStream & cs )
		{
			cs << m_pContainer->size();

			Container::iterator iter = m_pContainer->begin();
			for (;iter != m_pContainer->end(); ++iter)
			{
				cs << *iter;
			}

			return cs;
		}
		virtual CStream & unMarshal (CStream & cs)
		{
			m_pContainer->clear();
			UINT32 unCount = 0;
			cs >> unCount;
			for (;unCount > 0; --unCount)
			{
				typename Container::value_type val;
				cs >> val;

				m_pContainer->insert(m_pContainer->end() , val);
			}

			return cs;
		}

		Container * GetContainer(){ return  m_pContainer; }

	protected:
		Container * m_pContainer;
	};
}

#endif