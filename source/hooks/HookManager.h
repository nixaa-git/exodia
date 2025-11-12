#pragma once

#include <iostream>
#include "../dependencies/minhook/include/MinHook.h"
#include "Struct.h"

class HookManager
{
public:
	HookManager() = default;
	~HookManager();

	static HookManager* Get()
	{
		static HookManager mgr;
		return &mgr;
	}

	void Initialize();
	void Cleanup();
	void SetupHooks();

public:
	bool m_bDidInit = false;
	hook_t hkSendPacket{};
	hook_t hkSendPacketRaw{};
	hook_t hkLogToConsole{};
	hook_t hkWglSwapBuffers{};
	hook_t hkBaseAppSetFPSLimit{};
private:
};