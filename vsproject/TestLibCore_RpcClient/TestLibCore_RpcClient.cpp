#include "Common/LibCore.h" 
#include "RPCCallFuncs.h"
#include "Common/Chunk.h" 
#include "TimerLib/inc/TimerHelp.h"
#include "MsgNameDefine.h" 
#include "RpcInstance.h"
#include "MsgLib/inc/Object.h"

INT64 g_time = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("ClientClient"); 
	Client::RpcInstance::GetInstance().Init("RPCClientConfigs.xml"); 

	g_time = Timer::TimerHelper::GetTickSecond();
	int gime = g_time;
	std::vector<Msg::Object> targets;
	targets.push_back(Msg::Object(1));  
	int m_asd = 9;

	int n = 100000;
	while (n)
	{
		Client::RpcInstance::GetInstance().Update(); 

 		if( 0 < Client::local_call_TestObject("tcp://127.0.0.1:8002" , 'a' , 1 , 2 , 3 , 4 , "HelloWorld." , LibCore::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(0) , 1))
		{
			n--;
		} 

		if (n % 100 == 0)
		{
			std::cout << "n " << n << std::endl;
			int nRemain = Timer::TimerHelper::GetTickSecond() - gime;
			gime = Timer::TimerHelper::GetTickSecond();
			std::cout << "timer " << nRemain << std::endl;
		}
	}
	g_time = Timer::TimerHelper::GetTickSecond() - g_time;
	std::cout << "timer" << g_time << std::endl;

	Client::RpcInstance::GetInstance().Cleanup(); 
	LibCore::Cleanup();

	system("pause");
	return 0;
}
