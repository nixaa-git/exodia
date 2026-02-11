#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

void __fastcall hkSendPacketFn(int messageType, std::string& genericText, void* pPeer)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->SendPacketFn)>(HookManager::Get()->hkSendPacket.m_origFn);

	std::printf("SendPacket called! %s\n", genericText.c_str());

	orig(messageType, genericText, pPeer);
}