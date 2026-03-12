#include "functions/Funcs.h"
#include "HookManager.h"
#include "../Globals.h"
#include "../dependencies/kiero/kiero.h"

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

	g_renderer->Initialize();

	this->hkSendPacket.Setup(sdk->SendPacketFn, hkSendPacketFn, "SendPacket");
	this->hkSendPacketRaw.Setup(sdk->SendPacketRawFn, hkSendPacketRawFn, "SendPacketRaw");
	this->hkProcessTankUpdate.Setup(sdk->GameLogicComponent_ProcessTankUpdatePacketFn, hkGameLogicComponent_ProcessTankUpdatePacketFn, "GameLogicComponent::ProcessTankUpdatePacket");
	//this->hkLogToConsole.Setup(sdk->LogToConsoleFn, hkLogToConsoleFn, "LogToConsole");
	//this->hkBaseAppSetFPSLimit.Setup(sdk->BaseAppSetFPSLimitFn, hkBaseAppSetFPSLimitFn, "BaseApp::SetFPSLimit");
	//this->hkWglSwapBuffers.Setup((void*)GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers"), wglSwapBuffersFn, "wglSwapBuffers");
	this->hkEndScene.Setup((void*)g_renderer->get_methods_table()[42], hkEndSceneFn, "EndScene");

	MH_EnableHook(NULL); // this enables all current hooks

	g_pGlobals->m_gameWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(g_pGlobals->m_hwnd, GWLP_WNDPROC, (LONG_PTR)hkWndProc));
}