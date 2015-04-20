#ifndef __error_code_h__
#define __error_code_h__ 

enum ERROR_CODE
{
	ERR_SUCCESS = 0,					//5 ���еĳɹ���Ƕ���Ϊ0
	ERR_FAILURE = 1,					//5 ���еĴ��� 
	ERR_IOERROR,						//5 IO����

	ERR_NOTFOUND ,						//5 ���ݿ�δ�ҵ�
	ERR_CORRUPTION,						//5 ���ݿⱻռ��
	ERR_INVALIDARGUMENT,				//5 ���ݿⱻռ��

	ERR_NUM,
};
const char * g_szErrorString[ERR_NUM]=
{
	"ERR_SUCCESS",
	"ERR_FAILURE",
	"ERR_NOTFOUND",
	"ERR_CORRUPTION",
	"ERROR_NOTSUPPORTED",
	"ERROR_INVALIDARGUMENT",
	"ERROR_IOERROR",
	"__INVALID_ERROR_6",
	"__INVALID_ERROR_7",
	"__INVALID_ERROR_8",
	"__INVALID_ERROR_9",

	"ERROR_EXISTS",
	"ERROR_EXISTS_INVALID_DATA",

};
#endif

