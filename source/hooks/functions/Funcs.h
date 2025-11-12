#pragma once

#include "../../Globals.h"

extern void __fastcall hkSendPacketFn(int, std::string&, void*);
extern void __fastcall hkSendPacketRawFn(int, unsigned char*, int, void*, ENetPeer*, unsigned int);
extern int __fastcall hkLogToConsoleFn(const char* data, ...);
extern void __fastcall hkBaseAppSetFPSLimitFn(App* _this, float fps);
extern BOOL wglSwapBuffersFn(HDC hdc);
LRESULT hkWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);