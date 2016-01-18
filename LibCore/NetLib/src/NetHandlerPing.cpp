#include "NetLib/inc/NetHandlerPing.h"
#include "NetLib/inc/INetReactor.h"
#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/NetThread.h"
#include "Timer/inc/TimerHelp.h"

namespace Net
{
	CErrno NetHandlerPing::Update(void)
	{
		return UpdatePing();
	}

	CErrno NetHandlerPing::UpdatePing(void)
	{
		if (m_pNetReactor && m_pNetReactor->GetNetThread())
		{
			INT64 ullCurTime = Timer::TimerHelper::GetTickMicroSecond();
			if (ullCurTime - m_llLastSendPing >= DEFAULT_PING_TIME_OUT_MICROSECOND)
			{
				m_llLastSendPing = Timer::TimerHelper::GetTickMicroSecond();

				return Ping();
			}
		}

		return CErrno::Success();
	}

	CErrno NetHandlerPing::Ping(void)
	{
		if (m_pNetReactor && m_pNetReactor->GetNetThread())
		{
			NetThread * pNetThread = m_pNetReactor->GetNetThread();

			char pBuf[1024] = { 0 };
			SPing * pPing = (SPing *)(pBuf + sizeof(MsgHeader));
			pPing->usPeerPort = pNetThread->GetServerPort();
			memcpy(pPing->szAddress, pNetThread->GetServerAddress(), strlen(pNetThread->GetServerAddress()) + 1);
			memcpy(pPing->szNodeName, pNetThread->GetNetNodeName(), strlen(pNetThread->GetNetNodeName()) + 1);

			((MsgHeader*)pBuf)->unMsgID = DEFAULT_MSG_PING_ID;
			((MsgHeader*)pBuf)->unMsgLength = sizeof(SPing) + sizeof(MsgHeader);

			if (SendMsg((const char *)(pBuf), ((MsgHeader*)pBuf)->unMsgLength) <= 0)
			{
				return CErrno::Failure();
			}
		}

		return CErrno::Success();

	}

	CErrno NetHandlerPing::HandleMsg(ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength)
	{
		if (m_pNetReactor->IsMutilThread())
		{
			switch (unMsgID)
			{
				case DEFAULT_MSG_PING_ID:
				{
					Assert_ReF(pBuffer && unLength == sizeof(SPing));

					SPing * pPing = (SPing *)pBuffer;

					return HandlePing(pSession, pPing);
				}break;
			}
		}
		return NetHandlerTransit::HandleMsg(pBuffer, unLength);
	}

	CErrno NetHandlerPing::HandlePing(ISession * pSession, SPing * pPing)
	{
		if (pPing && m_pNetReactor && m_pNetReactor->GetNetThread())
		{
			NetThread * pThread = m_pNetReactor->GetNetThread();

			INetHandlerPtr pHandler = pThread->CreateClientHandler(pPing->szNodeName , pPing->szAddress, pPing->usPeerPort);
			if (!pHandler)
			{
				return CErrno::Failure();
			}
		}

		return CErrno::Success();
	}
}