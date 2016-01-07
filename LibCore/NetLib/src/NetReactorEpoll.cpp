#ifdef _LINUX
#include "NetLib/inc/NetReactorEpoll.h"
#include "Timer/inc/TimerHelp.h"
#include "LogLib/inc/Log.h"

namespace Net
{ 

	NetReactorEpoll::NetReactorEpoll(UINT32 unMaxConnectionCount)
		: m_unMaxConnectionCount(unMaxConnectionCount)
		, INetReactor(REACTOR_TYPE_EPOLL)
	{
		m_nEpoll = epoll_create(m_unMaxConnectionCount);  //5 ����һ��epollר�õ��ļ�������,��ʵ�����ں�����һ�ռ䣬������������ע��socket fd���Ƿ����Լ�������ʲô�¼���
		m_pEvents = (struct epoll_event*)malloc(sizeof(struct epoll_event) * m_unMaxConnectionCount);
	}

	NetReactorEpoll::~NetReactorEpoll(void)
	{
		Cleanup();
		::close(m_nEpoll);
		m_nEpoll = -1;
		free(m_pEvents);
	}

	CErrno NetReactorEpoll::Init(void)
	{

		return CErrno::Success();
	}

	CErrno NetReactorEpoll::Cleanup( void )
	{

		return CErrno::Success();
	}

	CErrno NetReactorEpoll::AddNetHandler(INetHandlerPtr  pNetHandler, ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/)
	{
		INT32 nEvent = 0;
		if (objMask & NET_FUNC_READ)
			nEvent |= EPOLLIN;
		if (objMask & NET_FUNC_EXCEPT)
			nEvent |= EPOLLPRI;
		if (objMask & NET_FUNC_WRITE)
			nEvent |= EPOLLOUT;
		if (objMask & NET_FUNC_ACCEPT)
			nEvent |= EPOLLIN;
		if (objMask & NET_FUNC_EPOLLET)
			nEvent |= EPOLLET;

		epoll_event ev;
		ev.events = nEvent;
		ev.data.ptr = pNetHandler.get();

		//5 �ú������ڿ���ĳ��epoll�ļ��������ϵ��¼�������ע���¼����޸��¼���ɾ���¼��� 
		if (epoll_ctl(m_nEpoll, EPOLL_CTL_ADD, pNetHandler->GetSession()->GetSocket(), &ev) == -1)
			return CErrno::Failure();

		return CErrno::Success();
	}

	CErrno NetReactorEpoll::DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler/* = TRUE*/)
	{
		epoll_event ev;
		ev.events = 0;
		ev.data.ptr = pNetHandler.get();

		//5 �ú������ڿ���ĳ��epoll�ļ��������ϵ��¼�������ע���¼����޸��¼���ɾ���¼��� 
		if (epoll_ctl(m_nEpoll, EPOLL_CTL_DEL, pNetHandler->GetSession()->GetSocket(), &ev) == -1)
			return CErrno::Failure();

		return CErrno::Success();
	}

	CErrno NetReactorEpoll::ModNetHandler(INetHandlerPtr  pNetHandler, ENetHandlerFuncMask objMask)
	{
		INT32 nEvent = 0;
		if (objMask & NET_FUNC_READ)
			nEvent |= EPOLLIN;
		if (objMask & NET_FUNC_EXCEPT)
			nEvent |= EPOLLPRI;
		if (objMask & NET_FUNC_WRITE)
			nEvent |= EPOLLOUT;
		if (objMask & NET_FUNC_ACCEPT)
			nEvent |= EPOLLIN;
		if (objMask & NET_FUNC_EPOLLET)
			nEvent |= EPOLLET;

		epoll_event ev;
		ev.events = nEvent;
		ev.data.ptr = pNetHandler.get();

		//5 �ú������ڿ���ĳ��epoll�ļ��������ϵ��¼�������ע���¼����޸��¼���ɾ���¼��� 
		if (epoll_ctl(m_nEpoll, EPOLL_CTL_MOD, pNetHandler->GetSession()->GetSocket(), &ev) == -1)
			return CErrno::Failure();

		return CErrno::Success();
	}

	CErrno NetReactorEpoll::Update( void )
	{
		int nfds, ret;
		memset(m_pEvents, 0, sizeof(struct epoll_event) * m_unMaxConnectionCount);
		
		//5 �ȴ�EPOLL�¼��ķ������൱�ڼ�����������صĶ˿ڣ���Ҫ�ڳ�ʼ��EPOLL��ʱ��󶨡� 
		nfds = epoll_wait(m_nEpoll, m_pEvents, m_unMaxConnectionCount, kMAX_EPOOL_WAIT_TIME_OUT);

		if (nfds <= 0)
			return CErrno::Success();

		for (int i = 0; i < nfds; ++i)
		{
			bool closed = false;
			INetHandler * pHandler = (INetHandler *)m_pEvents[i].data.ptr;
			if (pHandler)
			{
				if (m_pEvents[i].events & EPOLLIN)
				{
					closed = !pHandler->OnMsgRecving().IsSuccess() || closed;
				}
				if (m_pEvents[i].events & EPOLLOUT)
				{
					closed = !pHandler->OnMsgSending().IsSuccess() || closed;
				}

				ISession	* pSession = pHandler->GetSession();
				if (pSession && pSession->GetObjTimeout().IsExpired() || pSession->IsClosed() || m_pEvents[i].events & EPOLLPRI)
				{
					closed = true;
				}

				if (closed)
				{
					gDebugStream("delete " << pHandler->GetSession()->GetRemoteName());
					DelNetHandler(INetHandlerPtr(pHandler));
				}
			}
		}
		
		return CErrno::Success();
	}

	//////////////////////////////////////////////////////////////////////////UDS///

	NetReactorUDS::NetReactorUDS(UINT32 unMaxConnectionCount)
		: m_unMaxConnectionCount(unMaxConnectionCount)
		, INetReactor(REACTOR_TYPE_UDS)
	{
	}

	NetReactorUDS::~NetReactorUDS(void)
	{
	}

}

#endif