#include "../Funcs.h"
#include "../../../Globals.h"
#include "../../HookManager.h"
#include "../../../gui/Gui.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT hkWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	
	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam))
		return true;


	/*
	bool mouse =
		msg == WM_LBUTTONDOWN ||
		msg == WM_RBUTTONDOWN ||
		msg == WM_LBUTTONDBLCLK ||
		msg == WM_RBUTTONDBLCLK ||
		msg == WM_MOUSEWHEEL;

	ImGuiIO io = ImGui::GetIO();
	if (io.WantTextInput || (io.WantCaptureKeyboard && mouse))
		return true;
	*/

	return CallWindowProcW(g_pGlobals->m_gameWndProc, hwnd, msg, wparam, lparam);
}