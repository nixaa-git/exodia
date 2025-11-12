#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

void __fastcall hkBaseAppSetFPSLimitFn(App* _this, float fps)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->BaseAppSetFPSLimitFn)>(HookManager::Get()->hkBaseAppSetFPSLimit.m_origFn);

	fps = 0.f; // unlocked

	orig(_this, fps);
}