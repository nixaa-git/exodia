#include "../Funcs.h"
#include "../../../Globals.h"
#include "../../HookManager.h"
#include "../../../gui/Gui.h"

BOOL __stdcall wglSwapBuffersFn(HDC hdc)
{
	static auto orig = reinterpret_cast<BOOL(__stdcall*)(HDC)>(HookManager::Get()->hkWglSwapBuffers.m_origFn);

	if (!Gui::Get()->m_bDidInit)
	{
		Gui::Get()->Initialize();
	}
	
	Gui::Get()->RenderForOpenGL(hdc);

	return orig(hdc);
}