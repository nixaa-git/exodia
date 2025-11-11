#pragma once

extern "C"
{
	#include "dependencies/enet/include/enet.h"
}

#include <Windows.h>
#include "SDK/SDK.h"

class Globals
{
public:
	HMODULE m_procModule{};

	bool m_bShouldUnload = false;
};

extern Globals* g_pGlobals;