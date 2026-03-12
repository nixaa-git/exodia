#pragma once

#include "../../Globals.h"
#include <d3d9.h>

extern void __fastcall hkSendPacketFn(int, std::string&, void*);
extern void __fastcall hkSendPacketRawFn(int, unsigned char*, int, void*, ENetPeer*, unsigned int);
extern int __fastcall hkLogToConsoleFn(const char* data, ...);
extern void __fastcall hkBaseAppSetFPSLimitFn(App* _this, float fps);
extern void __fastcall hkGameLogicComponent_ProcessTankUpdatePacketFn(void*, GameUpdatePacket*);
extern BOOL wglSwapBuffersFn(HDC hdc);
long __stdcall hkEndSceneFn(LPDIRECT3DDEVICE9 pDevice);
LRESULT hkWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);