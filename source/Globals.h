#pragma once

/* !!!!IMPORTANT !!!!
*
*  Before compiling make sure to toggle the correct preprocessor macros to target the games renderer API for that version
*  ex: 3.xx upto 5.17 uses DirectX9/DX9 and 5.17 onwards uses OpenGL
*
*  !!!!IMPORTANT !!!!
*/

#define KIERO_INCLUDE_D3D9   1 // 1 if you need D3D9 hook

#define _EXODIA_RENDERING_OPENGL 0
#define _EXODIA_RENDERING_DX9 1

extern "C"
{
	#include "dependencies/enet/include/enet.h"
}

#include <Windows.h>
#include "SDK/SDK.h"
#include "gui/TextEditor.h"
#include "SDK/Renderer/Renderer.h"

class Globals
{
public:
	HMODULE m_procModule{};
	HWND m_hwnd{};
	WNDPROC m_gameWndProc{};

	TextEditor m_textEditor{};

	bool m_bShouldUnload = false;
};

extern Globals* g_pGlobals;