#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

int __fastcall hkLogToConsoleFn(const char* data, ...)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->LogToConsoleFn)>(HookManager::Get()->hkLogToConsole.m_origFn);

	char buf[0x1000u];
	int len = -1;

	va_list va;
	va_start(va, data);
	len = _vsnprintf_s(buf, sizeof(buf), data, va);
	if (0 > len)
	{
		va_end(va);
		return 0;
	}

	std::printf("LogToConsole called! %s\n", buf);

	return orig(buf);
}