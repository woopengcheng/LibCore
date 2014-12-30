#include "LibCore.h" 
#include "TestObject.h"
#include "Chunk.h" 
#include "TimerHelp.h"
#include "MsgNameDefine.h" 
#include "RpcInstance.h"
#include "Object.h"

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

	int n = 1000000;
	while (n)
	{
		Client::RpcInstance::GetInstance().Update(); 

 		if( 0 < Client::local_call_TestObject('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , Msg::Object(0) , 1))
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