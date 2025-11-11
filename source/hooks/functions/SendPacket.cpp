#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

void __cdecl hkSendPacketFn(int messageType, std::string& genericText, ENetPeer* pPeer)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->SendPacketFn)>(HookManager::Get()->hkSendPacket.m_origFn);

	std::printf("SendPacket called! %s\n\tpeer = %llX\n", genericText.c_str(), pPeer);

	orig(messageType, genericText, pPeer);
}