#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

void __fastcall hkSendPacketRawFn(int type, unsigned char* pData, int szData, void* pPacketSender, ENetPeer* pPeer, unsigned int enetFlags)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->SendPacketRawFn)>(HookManager::Get()->hkSendPacketRaw.m_origFn);

	std::printf("SendPacketRaw called!\n");

	GameUpdatePacket* pkt = (GameUpdatePacket*)pData;
	if (!pkt || !pData)
	{
		return;
	}

	bool bCancelPacket = false;

	switch (pkt->m_type)
	{
		case NET_GAME_PACKET_APP_CHECK_RESPONSE:
		case NET_GAME_PACKET_APP_INTEGRITY_FAIL:
		{
			bCancelPacket = true;
		} break;
		case NET_GAME_PACKET_PING_REPLY:
		{
			::printf("Client sending ping reply\n");
		} break;
	}

	if (bCancelPacket == false)
	{
		orig(type, pData, szData, pPacketSender, pPeer, enetFlags);
	}
}