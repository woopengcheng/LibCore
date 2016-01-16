#ifndef __error_code_h__
#define __error_code_h__ 

class CErrno
{
public:
	enum Code
	{
		// 0-4
		ERR_INVALID = -1,					//5 ��Ч������ 
		ERR_SUCCESS = 0,					//5 ���еĳɹ���Ƕ���Ϊ0
		ERR_FAILURE = 1,					//5 ʧ�ܱ��
		ERR_IOERROR,						//5 IO����
		ERR_NOTFOUND ,						//5 δ�ҵ�
		ERR_CORRUPTION,						//5 ���ݿⱻռ��

		// 5-9
		ERR_INVALIDARGUMENT,				//5 ��Ч�ֶ�
		ERR_HAS_EXISTS,						//5 ���ݿ��Ѿ�����������¼.
		ERR_INVALID_DATA,					//5 ��Ч����.

		ERR_COUNT,
	};
public:
	CErrno()
	:m_eCode(ERR_SUCCESS)
	{}
	CErrno(Code code)
		: m_eCode(code)
	{}

	CErrno(Code code , std::string strMsg)
		: m_eCode(code)
		, m_strExtend(strMsg)
	{} 
	CErrno(const CErrno & s)
	{
		m_eCode = s.GetCode();
		m_strExtend = s.GetExtendSting();
	}
	void operator=(const CErrno& s)
	{
		m_eCode = s.GetCode();
		m_strExtend = s.GetExtendSting();
	}
	bool operator==(const CErrno& s)
	{
		if(m_eCode == s.GetCode())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const CErrno& s)
	{
		if(m_eCode != s.GetCode())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Code GetCode(){	return m_eCode;	}
	Code GetCode() const { return m_eCode; }
	std::string GetExtendSting(){ return m_strExtend; }
	std::string GetExtendSting() const { return m_strExtend; }

	bool IsSuccess()
	{
		return m_eCode == ERR_SUCCESS;
	}

	bool IsFailure()
	{
		return m_eCode != ERR_SUCCESS;
	}

	std::string ToString()
	{
		std::string strResult;
		if (m_eCode > ERR_INVALID && m_eCode < ERR_COUNT)
		{
			strResult += s_strErrorMsg[m_eCode];
		}

		strResult += m_strExtend;

		return strResult;
	}

public:
	static CErrno Success() { return CErrno(); }
	static CErrno Failure(std::string strExtend = "") { return CErrno(ERR_FAILURE , strExtend); }
	static CErrno NotFound(std::string strExtend = "") { return CErrno(ERR_NOTFOUND , strExtend); }
	static CErrno IOError(std::string strExtend = "") { return CErrno(ERR_IOERROR , strExtend); }
	static CErrno Corruption(std::string strExtend = "") { return CErrno(ERR_CORRUPTION , strExtend); }
	static CErrno InvaildArgument(std::string strExtend = "") { return CErrno(ERR_INVALIDARGUMENT , strExtend); }
	static CErrno InvaildData(std::string strExtend = "") { return CErrno(ERR_INVALID_DATA , strExtend); }
	 
private:
	Code				m_eCode;
	std::string			m_strExtend;
	static std::string	s_strErrorMsg[ERR_COUNT];
};

#endif

