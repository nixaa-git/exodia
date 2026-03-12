#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

#include <string>
#include <regex>

#include "../../gui/angelscript functions/AngelScriptFunctions.h"
#include "../../gui/Gui.h"

void __fastcall hkGameLogicComponent_ProcessTankUpdatePacketFn(void* logic, GameUpdatePacket* pPacket)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->GameLogicComponent_ProcessTankUpdatePacketFn)>(HookManager::Get()->hkProcessTankUpdate.m_origFn);

	if (!pPacket)
	{
		return;
	}

	GameUpdatePacket pkt = *pPacket;

	switch (pkt.m_type)
	{
		case NET_GAME_PACKET_BATTLE_JOIN:
		case NET_GAME_PACKET_BATTLE_EVENT:
		{
			std::printf("got packet battle event\n");

			//uint8_t* pBuffer = reinterpret_cast<uint8_t*>(&pkt.m_data);

			std::printf("we got %d bytes from the battle event packet!\n", pkt.m_data_size);
		} break;
	}

	orig(logic, pPacket);
}