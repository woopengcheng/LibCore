#include "ThreadPool/inc/ThreadPoolInterface.h" 
#include "NetLib/inc/NetReactorSelect.h."
#include "NetLib/inc/HttpProtocol.h"
#include "DBClientHttpServer.h"

namespace Client
{
	CErrno DBClientHttpServer::Init(Json::Value & conf)
	{
		Json::Value http = conf.get("http" , Json::Value()); 
		std::string strType = http.get("type" , "tcp").asCString();
		std::string strAddress = http.get("address" , "127.0.0.1").asCString();
		INT32 nPort = http.get("port" , 8080).asInt();

		return Init(strAddress.c_str() , nPort);
	}

	CErrno DBClientHttpServer::Init(const char * pAddress , INT32 nPort , BOOL bResueAddr /*= TRUE */, INT32 nListenerCount /*= DEFAULT_LISTENER_COUNT*/)
	{
		CErrno err = Net::HttpServer::Init(pAddress , nPort , bResueAddr , nListenerCount);
		if (err.IsSuccess())
		{
			ThreadPool::ThreadPoolInterface::GetInstance().CreateThread(2 , 1);  
			ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);  
		}

		return err;
	}

	CErrno DBClientHttpServer::Cleanup()
	{

		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();
		return Net::HttpServer::Cleanup();
	} 

	CErrno DBClientHttpServer::Update(void)
	{ 
		m_pNetReactor->Update();
		return ThreadPool::ThreadSustainTask::Update();
	} 

	DBClientHttpServer::DBClientHttpServer(Net::INetReactor * pNetReactor /*= NULL*/)
		: HttpServer(pNetReactor)
		, ThreadPool::ThreadSustainTask(2 , "DBClientHttpServer" )
	{  
		if (!m_pNetReactor)
		{
			m_pNetReactor = new Net::NetReactorSelect; 

			if(CErrno::Success() != m_pNetReactor->Init())
			{
				SAFE_DELETE(m_pNetReactor);
			}
		}
	}

	CErrno DBClientHttpServer::HttpHandler(Net::HttpSession * pSession , Net::HttpProtocol& request,Net::HttpProtocol& response)
	{
		std::string strURL = request.GetInputUrl();

		if (strURL == "index")
		{
			std::string result = "<HTML>\n				<HEAD>\n				<TITLE>MiniWeb</TITLE>\n				</HEAD>\n				</HTML>";

			response.Reserve(result.length() + 512);
			response.WriteResponseHeader(200,"OK");
			response.WriteHeader(Net::HttpConsts::HEADER_CONNECTION,"Keep-Alive");
			response.WriteHeader(Net::HttpConsts::HEADER_CONTENT_TYPE,"text/html;charset=utf-8");
			response.WriteHeader(Net::HttpConsts::HEADER_CONTENT_LENGTH,result.length());
			response.WriteContent(result.c_str(), result.length());
		}
		else if(strURL == "pwd")
		{
			std::string strLic = "";
			if (!m_objAuths.HasRight(request.m_phAuthorization , strLic))
			{
				response.WriteResponseHeader(401, "Authorization failed");
				response.WriteHeader(Net::HttpConsts::HEADER_WWW_AUTHORIZATION, "Basic realm=\"woopengcheng.com.cn\"");
				response.WriteContent("Unauthorized.", sizeof("Unauthorized."));
			}
			else
			{
				std::string result = "<HTML>\n				<HEAD>\n				<TITLE>MiniWeb</TITLE>\n				</HEAD>\n				</HTML>";

				response.Reserve(result.length() + 512);
				response.WriteResponseHeader(200, "OK");
				response.WriteHeader(Net::HttpConsts::HEADER_CONNECTION, "Keep-Alive");
				response.WriteHeader(Net::HttpConsts::HEADER_CONTENT_TYPE, "text/html;charset=utf-8");
				response.WriteHeader(Net::HttpConsts::HEADER_CONTENT_LENGTH, result.length());
				response.WriteContent(result.c_str(), result.length());
			}
		}

		return CErrno::Success();
	}

}