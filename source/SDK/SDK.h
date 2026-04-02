#pragma once

// util
#include "../utilities/memory/Module.h"

// sdk stuff
#include "App/App.h"
#include "ENet/Packet.h"

#include "../dependencies/lua/Lua.hpp"
#include <angelscript.h>

class SDK
{
public:
	static SDK* Get()
	{
		static SDK sdk;
		return &sdk;
	}

	bool Initialize();
	void SetupFunctions();

	// helper functions for sending packets and variants if we wanted
	void SendPacket(int type, const std::string& genericText);
	void SendPacketRaw(int type, unsigned char* pData, unsigned int dataLen, int enetFlag = ENET_PACKET_FLAG_RELIABLE);
	void SendVariant(void* pVarlist); // todo ~~

	c_module m_procModule = c_module(nullptr); // public access so we can use ::FindPattern() from outside

public:
	// getters
	App* (__cdecl* GetAppFn)() = NULL;
	GameLogicComponent* (__cdecl* GetGameLogicFn)() = NULL;
	ENetClient* (__cdecl* GetENetClientFn)() = NULL;
	ItemInfoManager* (__fastcall* GetItemInfoManagerFn)() = NULL;

	// funcs we need
	void (__fastcall* SendPacketFn)(int, std::string&, void*) = NULL;
	void (__fastcall* SendPacketRawFn)(int, unsigned char*, int, void*, ENetPeer*, unsigned int) = NULL;
	int (__fastcall* LogToConsoleFn)(const char*, ...) = NULL;
	ENetPacket* (__fastcall* EnetPacketCreateFn)(__int64, __int64, int) = NULL;
	int (__fastcall* EnetPeerSendFn)(ENetPeer*, enet_uint8, ENetPacket*) = NULL;
	App* (__fastcall* BaseAppSetFPSLimitFn)(App*, float) = NULL;

	// our lua state
	lua_State* m_pLuaState = NULL;

private:
	//
};