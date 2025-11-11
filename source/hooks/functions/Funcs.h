#pragma once

#include "../../Globals.h"

extern void __fastcall hkSendPacketFn(int, std::string&, ENetPeer*);
extern void __fastcall hkSendPacketRawFn(int, unsigned char*, int, void*, ENetPeer*, unsigned int);
extern int __fastcall hkLogToConsoleFn(const char* data, ...);