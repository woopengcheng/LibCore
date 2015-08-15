#ifndef __error_code_h__
#define __error_code_h__ 

enum ErrCode
{
	ERR_WRONG = -1,						//5 所有的错误 
	ERR_SUCCESS = 0,					//5 所有的成功标记都是为0
	ERR_FAILURE = 1,					//5 失败标记
	ERR_IOERROR,						//5 IO错误

	ERR_NOTFOUND ,						//5 数据库未找到
	ERR_CORRUPTION,						//5 数据库被占用
	ERR_INVALIDARGUMENT,				//5 无效字段
	ERR_HAS_EXISTS,						//5 数据库已经存在这条记录,插入失败.
	ERR_INVALID_DATA,					//5 无效数据.

	ERR_NUM,
};
extern const char * g_szErrorString[ERR_NUM];

#endif

