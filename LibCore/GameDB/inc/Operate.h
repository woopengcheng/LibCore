#ifndef __gamedb_operate_h__
#define __gamedb_operate_h__ 
#include "GameDB/inc/DBCommon.h"
#include "GameDB/inc/OperateRecord.h"
#include "GameDB/inc/OperateReturns.h"

namespace GameDB
{
// 	class OperateEnv
// 	{
// 	public:
// 		OperateEnv(Database * pDB)
// 			: m_pDB(pDB->GetLevelDB())
// 			, m_pDataBase(pDB)
// 		{
// 
// 		}
// 
// 	public:
// 		leveldb::DB * m_pDB;
// 		Database    * m_pDataBase;
// 	};

	class DLL_EXPORT Operate
	{
	public:
		Operate()
			: m_nErrorCode(ERR_FAILURE)
		{

		}
		virtual ~Operate()
		{

		}
	public:
		bool		IsSuccess(){ return m_nErrorCode == ERR_SUCCESS; }
		bool		IsNotFound(){ return m_nErrorCode == ERR_NOTFOUND; }
		void		SetErrorCode(ErrCode code){ m_nErrorCode = code; }
		void		SetErrorCode(const leveldb::Status& status)
		{
			if(status.ok())
				m_nErrorCode = ERR_SUCCESS;
			else if(status.IsIOError())
				m_nErrorCode = ERR_IOERROR;
			else if(status.IsCorruption())
				m_nErrorCode = ERR_CORRUPTION;
			else if(status.IsNotFound())
				m_nErrorCode = ERR_NOTFOUND;
			else
				m_nErrorCode = ERR_INVALIDARGUMENT;
		}
		ErrCode  GetErrorCode(){ return m_nErrorCode; }
		std::string GetErrorString(){ return g_szErrorString[m_nErrorCode]; }

	public:
		OperateRecord * GetOperateRecord()
		{
			if (m_pOperateRecord == NULL)
			{
				m_pOperateRecord = new OperateRecord;
			}

			return m_pOperateRecord;
		}
		OperateReturns & GetOperateReturns(){ return m_objOperateReturns; }
		Parameters     & GetParamters(){ return m_objOperateReturns.GetWriter(); }
		LibCore::CStream & GetStream(){ return m_objOperateReturns.GetStream(); }

	private:
		ErrCode	         m_nErrorCode;
		OperateRecord  * m_pOperateRecord;
		OperateReturns   m_objOperateReturns;
	};
}

#endif
