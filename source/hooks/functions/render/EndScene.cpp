#include "../Funcs.h"
#include "../../../Globals.h"
#include "../../HookManager.h"
#include "../../../gui/Gui.h"

long __stdcall hkEndSceneFn(LPDIRECT3DDEVICE9 pDevice)
{
	static auto orig = reinterpret_cast<long(__stdcall*)(LPDIRECT3DDEVICE9)>(HookManager::Get()->hkEndScene.m_origFn);

	if (!Gui::Get()->m_bDidInit)
	{
		D3DDEVICE_CREATION_PARAMETERS params;
		pDevice->GetCreationParameters(&params);
		g_pGlobals->m_hwnd = params.hFocusWindow;
		Gui::Get()->Initialize();
	}

	Gui::Get()->RenderForDX9(pDevice);

	return orig(pDevice);
}