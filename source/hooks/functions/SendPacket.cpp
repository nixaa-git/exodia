#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

#include <string>
#include <regex>

void __fastcall hkSendPacketFn(int messageType, std::string& genericText, void* pPeer)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->SendPacketFn)>(HookManager::Get()->hkSendPacket.m_origFn);


	if (genericText.find("platformID") != std::string::npos)
	{
		std::regex pattern(R"(platformID\|\d+,\d+,\d+)");
		std::string result = std::regex_replace(genericText, pattern, "platformID|12");
		SDK::Get()->LogToConsoleFn("`2Spoofed platform ID to 12!");
		orig(messageType, result, pPeer);
		return;
	}

	std::printf("SendPacket called! %s\n", genericText.c_str());

	orig(messageType, genericText, pPeer);
}