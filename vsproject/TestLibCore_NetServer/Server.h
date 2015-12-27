#ifndef __server_h__
#define __server_h__
#include "NetLib/inc/Netlib.h"
#include "Timer/inc/TimerHelp.h"
#include "NetLib/inc/NetHandlerListener.h"

class Server
{
public:
	Server()
		: m_pNetReactor(NULL)
	{ 
	}
	~Server(){  }

public:
	virtual INT32  Init();
	virtual INT32  Cleanup();
	virtual INT32  Update();

private:
	Net::INetReactor *  m_pNetReactor;
};
#endif