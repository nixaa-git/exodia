#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_

#include <Windows.h>
#include <iostream>

#include "hooks/HookManager.h"
#include "Globals.h"

void OnInject()
{
	FILE* pFile = nullptr;

	AllocConsole();
	freopen_s(&pFile, "conout$", "w", stdout);

	if (!g_pGlobals)
	{
		std::printf("Fatal error: g_pGlobals is nullptr!\n");
		return;
	}

	SDK::Get()->Initialize();
	HookManager::Get()->Initialize();
	HookManager::Get()->SetupHooks();

	while (!g_pGlobals->m_bShouldUnload)
	{
		if (GetAsyncKeyState(VK_F2) & 1)
		{
			App* pApp = SDK::Get()->GetAppFn();
			if (!pApp) continue;

			std::printf("App: %llX\nENetClient: %llX && m_peer: %llX\n", pApp, pApp->m_pENetClient);
			Sleep(100);
		}

		Sleep(10);
	}

	// exit routine
	if (pFile)
	{
		fclose(pFile);
	}

	FreeConsole();
	FreeLibraryAndExitThread(g_pGlobals->m_procModule, EXIT_SUCCESS);
}

// TODO MAYBE: add a compile config to do a dinput8.dll shim that is auto loaded by the client
// all needed to do is drop that dll to %LocalAppData%/Growtopia/ and run GT
BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID param)
{
	DisableThreadLibraryCalls(module);

	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	{
		g_pGlobals->m_procModule = module;
		CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(OnInject), NULL, NULL, NULL);
		return true;
	}
	}

	return false;
}