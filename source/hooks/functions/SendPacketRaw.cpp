#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"
#include <cstdio>

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
		case NET_GAME_PACKET_BATTLE_JOIN:
		case NET_GAME_PACKET_BATTLE_EVENT:
		{
			pkt->m_data = (uint8_t*)std::malloc(900);
			pkt->m_data_size = 900;
		} break;
	}

	if (bCancelPacket == false)
	{
		orig(type, pData, szData, pPacketSender, pPeer, enetFlags);
	}
}