#include "NetLib/inc/NetCommon.h"

namespace Net
{
	namespace HttpConsts
	{
		extern DLL_EXPORT const char* LF;
		extern DLL_EXPORT const char* LF2X;

		extern DLL_EXPORT const char* METHOD_GET;
		extern DLL_EXPORT const char* METHOD_PUT;
		extern DLL_EXPORT const char* METHOD_POST;

		extern DLL_EXPORT const char* VERSION_10;
		extern DLL_EXPORT const char* VERSION_11;

		extern DLL_EXPORT const char* HEADER_HOST;
		extern DLL_EXPORT const char* HEADER_USER_AGENT;
		extern DLL_EXPORT const char* HEADER_CONTENT_TYPE;
		extern DLL_EXPORT const char* HEADER_CONTENT_LENGTH;
		extern DLL_EXPORT const char* HEADER_CONTENT_ENCODING;

		extern DLL_EXPORT const char* HEADER_ACCEPT;
		extern DLL_EXPORT const char* HEADER_ACCEPT_CHARSET;
		extern DLL_EXPORT const char* HEADER_ACCEPT_ENCODING;
		extern DLL_EXPORT const char* HEADER_ACCEPT_LANGUAGE;

		extern DLL_EXPORT const char* HEADER_COOKIE;
		extern DLL_EXPORT const char* HEADER_CONNECTION;
		extern DLL_EXPORT const char* HEADER_AUTHORIZATION;

		extern DLL_EXPORT const char* VALUE_CONNECTION_KEEP_ALIVE;

		extern DLL_EXPORT const char* HEADER_LOCATION;
	}

	class DLL_EXPORT HttpProtocol
	{
	public:
		HttpProtocol();
		virtual ~HttpProtocol();
	public:
		char* GetBuf() const { return m_pBuf; }
		INT32 GetLen() const { return m_nLenUsed; }
		char* GetContent() const { return &m_pBuf[m_nLenUsed - m_nContentLength]; }
		INT32 GetContentLength() const { return m_nContentLength; } 
	public:
		virtual void Clear();
		virtual bool Parse(const char* buf = NULL,INT32 len = 0, INT32* remainLen = NULL);
	public:
		virtual void Reserve(INT32 len);
	public:
		static INT32 GetHeaderLength(char* header);
		static INT32 GetHeaderValueLength(char* header);
	public:
		std::string GetInputUrl();
		std::string GetInputParam();
	public:
		void WriteBuffer(const char* buf);
		void WriteBuffer(const char* buf,INT32 len);
		void WriteHeader(const char* name,const char* value);
		void WriteHeader(const char* name,INT32 value);
		void WriteHeaderTerminator();
		void WriteRequestHeader(const char* method,const char* url = "/",const char* version = HttpConsts::VERSION_11);
		void WriteResponseHeader(INT32 statusCode,const char* statusText,const char* version = HttpConsts::VERSION_11);
		void WriteContent(const void* buf,INT32 len);
	protected:
		bool ParseHeader(char* header,INT32 len);
		bool ParseHeader(char* header);
		bool ParseProtocolHeader(char* header,INT32 len);
	protected:
		virtual bool OnHeaderSet(const char* name,char* value);
		virtual void OnBufferRealloced(char* oldbuf,char* newbuf);
	protected:
		char* m_pBuf;
		INT32 m_nLen;
		INT32 m_nLenUsed;
		INT32 m_nContentLength;
		bool  m_bNeedReleaseBuf;
	public:
		enum 
		{
			PARSE_MODE_NONE,
			PARSE_MODE_HEADER,
			PARSE_MODE_CONTENT,
			PARSE_MODE_OK,
		};
		INT32 m_nMode;
		INT32 m_nLastParsePosition;
	public:
		char* m_phStatusCode;
		char* m_phStatusText;

		char* m_phMethod;
		char* m_phUrl;
		char* m_phVersion;
		char* m_phHost;
		char* m_phCookie;
		char* m_phConnection;
		char* m_phAccept;
		char* m_phAcceptEncoding;
		char* m_phAcceptLanguage;
		char* m_phAcceptCharset;
		char* m_phContentType;
		char* m_phContentLength;
		char* m_phContentEndcoding;
		char* m_phAuthorization;

		char* m_phSetCookie;
		char* m_phReferer;
		char* m_phLocation;
	};

	class HttpProtocolEx : public HttpProtocol
	{
	protected:
		typedef std::map<std::string,char*> CollectionHeadersT;
	public:
		virtual void Clear();
	public:
		char* GetHeader(const std::string& name) 
		{
			CollectionHeadersT::iterator iter = m_mapHeaders.find(name);
			if(iter != m_mapHeaders.end())
				return iter->second;
			return NULL;
		}
	protected:
		virtual bool OnHeaderSet(const char* name,char* value);
		virtual void OnBufferRealloced(char* oldbuf,char* newbuf);
	protected:
		CollectionHeadersT m_mapHeaders;
	};

	class HttpProtocolFast : public HttpProtocol
	{
	public:
		HttpProtocolFast(char* buf,INT32 len)
		{
			m_pBuf = buf;
			m_nLen = len;
			m_bNeedReleaseBuf = false;
		}
	public:
		virtual void Reserve(INT32 len);
	};

	class HttpProtocolUtils
	{
	public:
		static bool IsRedirectCode(INT32 code);
		static bool Parse(const char* iurl,char* host,INT32& port,char* path,char* params);
	};
}
