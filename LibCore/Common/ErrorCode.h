#ifndef __error_code_h__
#define __error_code_h__ 

enum ERROR_CODE
{
	ERR_SUCCESS = 0,					//5 所有的成功标记都是为0
	ERR_FAILURE = 1,					//5 所有的错误 
	ERR_IOERROR,						//5 IO错误

	ERR_NOTFOUND ,						//5 数据库未找到
	ERR_CORRUPTION,						//5 数据库被占用
	ERR_INVALIDARGUMENT,				//5 数据库被占用

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

