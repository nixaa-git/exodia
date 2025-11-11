#include "functions/Funcs.h"
#include "HookManager.h"
#include "../Globals.h"

HookManager::~HookManager()
{
	this->Cleanup();
}

void HookManager::Initialize()
{
	if (MH_STATUS minhookStatus = MH_Initialize(); minhookStatus != MH_OK)
	{
		std::printf("HookManager::Initialize() Fatal error : Minhook failed to initialize! Got status code %d.\n", static_cast<int>(minhookStatus));
		return;
	}

	this->m_bDidInit = true;
	std::printf("HookManager::Initialize() finished!\n");
}

void HookManager::Cleanup()
{
	std::printf("HookManager::Cleanup() : Complete!\n");
}

void HookManager::SetupHooks()
{
	SDK* sdk = SDK::Get();

	if (!sdk)
	{
		return;
	}

	this->hkSendPacket.Setup(sdk->SendPacketFn, hkSendPacketFn, "SendPacket");
	this->hkSendPacketRaw.Setup(sdk->SendPacketRawFn, hkSendPacketRawFn, "SendPacketRaw");
	this->hkLogToConsole.Setup(sdk->LogToConsoleFn, hkLogToConsoleFn, "LogToConsole");

	MH_EnableHook(NULL); // this enables all current hooks
}