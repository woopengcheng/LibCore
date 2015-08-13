#ifndef __cutil_h__
#define __cutil_h__
#include "Common/Common.h"

namespace Json
{
	class Value;
}
 
namespace CUtil
{ 
#ifndef __min
#define __min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef __max
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

	extern INT32  DLL_EXPORT  Init(std::string strLogFile = "CUtil");
	extern INT32  DLL_EXPORT  Cleanup( void );


	///////////////////////////////Í¨ÓÃº¯Êý///////////////////////////////////////////

	extern INT32  DLL_EXPORT  strcmp(const char* str1,const char* str2);
	extern INT32  DLL_EXPORT  stricmp(const char* str1,const char* str2);
	extern INT64  DLL_EXPORT  atoi(const char* str);
	extern INT64  DLL_EXPORT  atoi(const std::string & str);
	extern UINT64  DLL_EXPORT atoull(const char* str);
	extern INT64  DLL_EXPORT  strtoll(const char* str, char** endptr = NULL, INT32 base = 10);
	extern UINT64  DLL_EXPORT strtoull(const char* str, char** endptr = NULL, INT32 base = 10);
	extern double DLL_EXPORT  atof(const char* str);
	extern double DLL_EXPORT  atof(const std::string & str);
	extern void   DLL_EXPORT  itoa(char* str,INT64 val);
	extern std::string  DLL_EXPORT  itoa(INT64 val); 
	extern void   DLL_EXPORT  ftoa(char* str,double val);
	extern INT32  DLL_EXPORT  floatcmp(float value1,float value2);
	extern char   DLL_EXPORT* strncpy(char* dst,size_t len,const char* src);
	extern INT64  DLL_EXPORT  rdtsc();
	extern INT64  DLL_EXPORT  random();
	extern INT32  DLL_EXPORT  random(INT32 start,INT32 end);
	extern float  DLL_EXPORT  random(float start,float end);
	extern std::string   DLL_EXPORT strupper(const char* szBuf);
	extern std::string   DLL_EXPORT strlower(const char* szBuf); 
	extern BOOL	  DLL_EXPORT  is_between(float start,float end,float value);
	extern BOOL	  DLL_EXPORT  is_between(INT64 start,INT64 end,INT64 value);
	extern BOOL	  DLL_EXPORT  is_between(INT32 start,INT32 end,INT32 value);
	extern float  DLL_EXPORT  clamp(float ho,float lo,float value);
	extern INT32  DLL_EXPORT  clamp(INT32 ho,INT32 lo,INT32 value);
	extern BOOL	  DLL_EXPORT  strtobool(const char* text);
	extern BOOL	  DLL_EXPORT  isNumber(const char* text);
	extern void   DLL_EXPORT  tohex(INT64 val,char* obuf,size_t len);
	extern void   DLL_EXPORT  tohex(const char* ibuf,size_t ilen,char* obuf,size_t& olen);
	extern void	  DLL_EXPORT  create_token(char* buf,size_t len);
	extern char   DLL_EXPORT* strncat(char* dest,const char* src,size_t destlen); 
	extern void   DLL_EXPORT  FastMemmove(void * dst , const void * src , INT64 unSize);
	extern INT64  DLL_EXPORT  ParseHumanSizeFromString(const std::string strSize);
	extern INT64  DLL_EXPORT  ParseHumanSizeFromJson(const Json::Value & value);
	extern UINT64 DLL_EXPORT  CityHash(const void* pBuf,INT64 len,INT64 seed); 
	extern INT64  DLL_EXPORT  BKDRHash(const char* pBuf);
	extern INT64  DLL_EXPORT  BKDRHashSum(const char* pBuf);
	extern UINT32 DLL_EXPORT  Compress(const char * pBuf , UINT32 unLength , std::string & strUncompressed);
	extern bool   DLL_EXPORT  UnCompress(const char * pBuf , UINT32 unLength , std::string & strUncompressed);

	extern void   DLL_EXPORT GenerateUUIDBySys( char* buf );
 	extern INT64  DLL_EXPORT GenerateUUIDByTime( void );
}

#endif
