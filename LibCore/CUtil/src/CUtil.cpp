#include "CUtil/inc/CUtil.h"
#include "CUtil/inc/Random.h"
#include "CUtil/inc/UnitTest.h"
#include "LogLib/inc/Log.h"
#include "NetLib/inc/NetCommon.h" 
#include "Timer/inc/TimerHelp.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "json/value.h"
#include "city.h"
#include "snappy.h"

#ifdef WIN32
#include <ObjBase.h>
#else
#include <uuid/uuid.h>
#endif

namespace CUtil
{
	void GenerateUUIDBySys( char* buf )
	{

#ifdef WIN32
		GUID FilterCLSID;
		CoCreateGuid(&FilterCLSID);

		sprintf(buf, "%08X_%04X_%04X_%02X%02X_%02X%02X%02X%02X%02X%02X",
			FilterCLSID.Data1, FilterCLSID.Data2, FilterCLSID.Data3,
			FilterCLSID.Data4[0], FilterCLSID.Data4[1], FilterCLSID.Data4[2], FilterCLSID.Data4[3], 
			FilterCLSID.Data4[4], FilterCLSID.Data4[5], FilterCLSID.Data4[6], FilterCLSID.Data4[7]
		);
#else
		uuid_t uid;
		uuid_generate(uid);
		uuid_unparse(uid,buf);
#endif 
	}

	INT64 GenerateUUIDByTime( void )
	{ 
		return (Timer::TimerHelper::GetTickCount());
	}

	INT32  Init(std::string strLogFile)
	{  
		Assert_ReF1(!Log::Init(strLogFile.c_str() , NULL , 0)) ; 
		Assert_ReF1(!Net::InitNet()); 

		UnitTestStart();

		return ERR_SUCCESS;
	}

	INT32  Cleanup( void)
	{ 
		Assert_ReF1(!Net::CleanNet());   
		Assert_ReF1(!Log::Cleanup()); 

		SAFE_DELETE(Msg::g_pRpcCheckParams);

		return ERR_SUCCESS;
	} 

	INT32   strcmp( const char* str1,const char* str2 )
	{
		return ::strcmp(str1,str2);
	}

	INT32   stricmp( const char* str1,const char* str2 )
	{
#ifdef WIN32
		return ::_stricmp(str1,str2);
#else 
		return ::strcasecmp(str1,str2);
#endif 
	}

	INT64   atoi( const char* str )
	{ 
		if(str == NULL)
			return 0LL;

#ifdef WIN32
		return _atoi64(str); 
#else
		return ::atoll(str);
#endif

	}

	INT64 atoi(const std::string & str)
	{
		return CUtil::atoi(str.c_str());
	}

	UINT64   atoull(const char* str)
	{
		if(str == NULL)
			return 0LL;

#ifdef WIN32
		return _strtoui64(str , NULL , 10); 
#else
		return ::strtouq(str);
#endif


	}
	double  atof( const char* str )
	{
		return ::atof(str);
	}

	double atof(const std::string & str)
	{
		return CUtil::atof(str.c_str());
	}

	std::string   itoa( INT64 val )
	{
		char buf[100] = "";
		itoa(buf,val);
		return std::string(buf);
	}

	void    itoa( char* str,INT64 val )
	{
#ifdef WIN32
		_i64toa(val,str,10);
#else
		sprintf(str,"%lld",val);
#endif
	}

	void    ftoa( char* str,double val )
	{
		sprintf(str,"%f",val);
	}

	char*   strncpy( char* dst,size_t len,const char* src )
	{
#ifdef WIN32
		strcpy_s(dst,len , src);
		return dst;
#else
		return ::strncpy(dst,src,len);
#endif

	}

	INT32   floatcmp( float value1,float value2 )
	{
		const float fEpsilon = 0.000001f;
		float fDelta = fabs(value1-value2);

		if (fDelta > fEpsilon)
			return 1;
		else
			return 0; 
	}

	INT64   rdtsc()
	{
#ifdef WIN32
//		_asm rdtsc;
		// 		LARGE_INTEGER result = {0};
		// 		if(!QueryPerformanceCounter(&result))
		// 			assert(false && "System NoSupport QueryPerformanceCounter");
		// 		return result.LowPart;
		// return (int)GetTickCount();
#else
//		unsigned int lo;
//		unsigned int hi;
//		__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
//		return (((sint64)hi) << 32) + lo;
#endif 
		return 0;
	}

	INT64   random()
	{
		return g_objRandomGenerator.Generator(); 
	}

	INT32   random( INT32 start,INT32 end )
	{
		if(start == end)
			return start;
		unsigned int r = random() % 0xffffffff;
		return (r % (end - start)) + start; 
	}

	float   random( float start,float end )
	{
		unsigned int r = random() % 0xffffffff;
		double d = (double)r / (double)0xffffffff;
		return (float)(start + (end - start) * d); 
	}

	std::string  strlower(const  char* szBuf )
	{
		std::locale loc;
		std::string str = szBuf;

		for(size_t i = 0;i < str.size();++i)
		{ 
#ifdef WIN32
			str[i] = ::tolower(str[i]);
#else
			str[i] = std::tolower(str[i],loc);
#endif
		}
		return str; 
	}

	std::string strupper(const  char* szBuf )
	{
		std::locale loc;
		std::string str = szBuf; 

		for(size_t i = 0;i < str.size();++i)
		{  
#ifdef WIN32
			str[i] = ::toupper(str[i]);
#else
			str[i] = std::toupper(str[i],loc);
#endif
		}
		return str;
	}

	BOOL	   is_between( float start,float end,float value )
	{
		if(start > end)
			std::swap(start,end);
		return value >= start && value <= end;

	}

	BOOL	   is_between( INT64 start,INT64 end,INT64 value )
	{
		if(start > end)
			std::swap(start,end);
		return value >= start && value <= end; 
	}

	BOOL	   is_between( INT32 start,INT32 end,INT32 value )
	{ 
		if(start > end)
			std::swap(start,end);
		return value >= start && value <= end;
	}

	float   clamp( float ho,float lo,float value )
	{
		if(value < lo)
			return lo;
		else if(value >= ho)
			return ho;
		return value;  
	}

	INT32   clamp( INT32 ho,INT32 lo,INT32 value )
	{
		if(value < lo)
			return lo;
		else if(value >= ho)
			return ho;
		return value; 
	}

	BOOL	   strtobool( const char* text )
	{ 
		if(stricmp(text,"true") == 0)
			return true;
		if(stricmp(text,"false") == 0)
			return false;
		if(stricmp(text,"1") == 0)
			return true;
		if(stricmp(text,"0") == 0)
			return false;
		return atoi(text) != 0;
	}

	BOOL	   isNumber( const char* text )
	{
		size_t len = strlen(text);
		for(size_t i = 0; i < len; ++i)
		{
			if(!(text[i] >= '0' && text[i] <= '9'))
			{
				return false;
			}
		}
		return true;
	}

	const char __HEX[16] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'a', 'b',
		'c', 'd', 'e', 'f'
	};

	void    tohex( INT64 val,char* obuf,size_t len )
	{
		std::stringstream ss;
		ss << std::hex << val << std::dec;
		strncpy(obuf,len,ss.str().c_str());
	}

	void    tohex( const char* ibuf,size_t ilen,char* obuf,size_t& olen )
	{
		size_t outlen = 0;
		for (size_t i = 0; i < ilen && outlen < olen; ++i) {
			int t = (unsigned char)ibuf[i];
			int a = t / 16;
			int b = t % 16;
			obuf[outlen] = __HEX[a];
			++outlen;
			obuf[outlen] = __HEX[b];
			++outlen;
		}
		obuf[outlen] = 0;
		olen = outlen; 
	}

	void	   create_token( char* buf,size_t len )
	{
		static const char s_objTokenPool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()-=+_";

		for(size_t i = 0; i < (len - 1); ++i)
		{
			int r = random(0,_countof(s_objTokenPool));
			buf[i] = s_objTokenPool[r];
		}
		buf[len - 1] = '\0';

	}

	char*   strncat( char* dest,const char* src,size_t destlen )
	{
		return ::strncat(dest,src,destlen); 
	}

	void  FastMemmove(void * dst , const void * src , INT64 unSize)
	{
		char * pDst = (char *)dst;
		char * pSrc = (char *)src;

		if ((pSrc < pDst && pSrc + unSize >= pDst) || (pSrc > pDst) && pDst + unSize >= pSrc )
		{
			memmove(dst , src , unSize);
		}
		else
		{
			memcpy(dst , src , unSize);
		} 
	} 

	INT64  ParseHumanSizeFromString(const std::string strSize)
	{  
		INT64 llFactor = 1;
		switch(strSize[strSize.length()])
		{
		case 'G':
		case 'g':
			llFactor = 1024*1024*1024;
			break;
		case 'M':
		case 'm':
			llFactor = 1024*1024;
			break;
		case 'k':
		case 'K':
			llFactor = 1024;
			break;
		}  

		return  atoi(strSize.c_str()) * llFactor;  //5 这里遇到字符串会自动截取掉后面的.
	}

	INT64  ParseHumanSizeFromJson(const Json::Value & objValue)
	{
		if(objValue.isInt() || objValue.isUInt() || objValue.isNumeric())
			return objValue.asInt();
		
		if(objValue.isString())
		{
			return ParseHumanSizeFromString(objValue.asString());
		}

		gErrorStream (" invalid value:" << objValue.toStyledString());
		
		return -1;
	}

	UINT64 CityHash(const void* pBuf,INT64 len,INT64 seed)
	{
		return (INT64)CityHash64WithSeed((const char*)pBuf,len,seed); 
	}

	UINT32 Compress(const char * pBuf , UINT32 unLength , std::string & strUncompressed)
	{
		return (UINT32)snappy::Compress(pBuf,unLength,&strUncompressed);
	}

	bool Uncompress(const char * pBuf , UINT32 unLength , std::string & strUncompressed)
	{
		return snappy::Uncompress(pBuf , unLength , &strUncompressed);
	}

	INT64 strtoll(const char* str, char** endptr, INT32 base)
	{
 		return _strtoui64(str, endptr, base);
	}

	UINT64 strtoull(const char* str, char** endptr, INT32 base)
	{
		return _strtoui64(str , NULL , 10); 
	}

	INT64 BKDRHash(const char* pBuf)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;

		while (*pBuf)
		{
			hash = hash * seed + (*pBuf++);
		}

		return (hash & 0x7FFFFFFF); 
	}

	INT64 BKDRHashSum(const char* pBuf)
	{
		INT64 sum = 0;
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;

		while (*pBuf)
		{
			sum += *pBuf;
			hash = hash * seed + (*pBuf++);
		}

		return (sum << 32) + (hash & 0x7FFFFFFF); 
	}


}