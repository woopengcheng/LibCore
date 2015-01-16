#ifndef __libcore_h__
#define __libcore_h__
#include "Common.h"
 
namespace LibCore
{ 
	extern INT32  DLL_EXPORT  Init(std::string strLogFile = "LibCore");
	extern INT32  DLL_EXPORT  Cleanup( void );


	///////////////////////////////Í¨ÓÃº¯Êý///////////////////////////////////////////

	extern INT32  DLL_EXPORT  strcmp(const char* str1,const char* str2);
	extern INT32  DLL_EXPORT  stricmp(const char* str1,const char* str2);
	extern INT64  DLL_EXPORT  atoi(const char* str);
	extern double DLL_EXPORT  atof(const char* str);
	extern void   DLL_EXPORT  itoa(char* str,INT64 val);
	extern std::string  DLL_EXPORT  itoa(INT64 val); 
	extern void   DLL_EXPORT  ftoa(char* str,double val);
	extern INT32  DLL_EXPORT  floatcmp(float value1,float value2);
	extern char   DLL_EXPORT* strncpy(char* dst,const char* src,size_t len);
	extern INT64  DLL_EXPORT  rdtsc();
	extern INT64  DLL_EXPORT  random();
	extern INT32  DLL_EXPORT  random(INT32 start,INT32 end);
	extern float  DLL_EXPORT  random(float start,float end);
	extern char   DLL_EXPORT* strupper(char* str);
	extern char   DLL_EXPORT* strlower(char* str);
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
	extern void   DLL_EXPORT  FastMemmove(void * dst , const void * src , UINT32 unSize);

	extern void   DLL_EXPORT GenerateUUIDBySys( char* buf );
 	extern INT64  DLL_EXPORT GenerateUUIDByTime( void );
}

#endif
