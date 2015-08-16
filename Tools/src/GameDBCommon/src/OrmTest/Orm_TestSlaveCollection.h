/************************************
FileName	:	Orm_TestSlaveCollection.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-17 00:08:59
Description	:	���orm�ӱ�����ļ�����.
************************************/
#ifndef __Orm_Orm_TestSlave_collection_h__
#define __Orm_Orm_TestSlave_collection_h__
#include "GameDB/inc/DBCommon.h"
#include "GameDB/inc/OrmCollection.h"
#include "GameDB/inc/OrmVector.h"
#include "GameDB/inc/DBCommon.h"

#include "Orm_TestSlave1.h"
#include "Orm_TestSlave.h"
#include "Orm_TestSlave2.h"

namespace Orm
{
	class TestSlaveCollection : public  GameDB::OrmCollection<INT64>
	{ 
		public:
			TestSlaveCollection();
			virtual ~TestSlaveCollection();
		
		private:
			TestSlaveCollection( const TestSlave &);
			const TestSlaveCollection & operator=( const TestSlaveCollection &);
		
		public:
			virtual void		ToBson(std::string & strBuf);
			virtual void		ToBson(mongo::BSONObj  & objBson);
			virtual void		FromBson(std::string & compressedBuf);
			virtual void		FromBson(const char * pData , UINT32 nSize);
		
		public:
		template<class VISITOR,class PARAM> void visit(VISITOR visitor,PARAM& param)
		{
			if(!visitor(m_pTestSlave1 , param))
				return ;
		
			if(!visitor(m_pTestSlave , param))
				return ;
		
			for(GameDB::OrmVectorEx< TestSlave2 *>::iterator iter = m_vTestSlave2.begin(); iter != m_vTestSlave2.end(); ++iter)
			{
				if(!visitor(*iter,param))
					return ;
			}
		
		}
		
		public:
			TestSlave1 * GetTestSlave1();
			void CleanupTestSlave1();
			TestSlave * GetTestSlave();
			void CleanupTestSlave();
		
		public:
			GameDB::OrmVectorEx< TestSlave2 *> & GetTestSlave2(){ return m_vecTestSlave2; }
			TestSlave2 * CreateTestSlave2(BOOL bAddToManager = TRUE);
			BOOL DeleteTestSlave2(TestSlave2 * pValue , bool bFree = false);
			void LoadTestSlave2(mongo::BSONObj & obj);
			void SaveTestSlave2(mongo::BSONArrayBuilder & bab);
		
		protected:
			TestSlave1	 * m_pTestSlave1;
			TestSlave	 * m_pTestSlave;
			GameDB::OrmVectorEx<TestSlave2 *>	 m_vecTestSlave2;
		
	}; 
 
}//Orm

#endif
