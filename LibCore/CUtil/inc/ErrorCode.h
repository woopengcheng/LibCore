#ifndef __error_code_h__
#define __error_code_h__ 

enum ErrCode
{
	ERR_WRONG = -1,						//5 ���еĴ��� 
	ERR_SUCCESS = 0,					//5 ���еĳɹ���Ƕ���Ϊ0
	ERR_FAILURE = 1,					//5 ʧ�ܱ��
	ERR_IOERROR,						//5 IO����

	ERR_NOTFOUND ,						//5 ���ݿ�δ�ҵ�
	ERR_CORRUPTION,						//5 ���ݿⱻռ��
	ERR_INVALIDARGUMENT,				//5 ��Ч�ֶ�
	ERR_HAS_EXISTS,						//5 ���ݿ��Ѿ�����������¼,����ʧ��.
	ERR_INVALID_DATA,					//5 ��Ч����.

	ERR_NUM,
};
extern const char * g_szErrorString[ERR_NUM];

#endif

