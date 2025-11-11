#pragma once

// util
#include "../utilities/memory/Module.h"

// sdk stuff
#include "App/App.h"
#include "ENet/Packet.h"

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

	c_module m_procModule = c_module(nullptr); // public access so we can use ::FindPattern() from outside

public:
	// getters
	App* (__cdecl* GetAppFn)() = NULL;

	// funcs we need
	void (__cdecl* SendPacketFn)(int, std::string&, ENetPeer*) = NULL;
	void (__fastcall* SendPacketRawFn)(int, unsigned char*, int, void*, ENetPeer*, unsigned int) = NULL;
	int (__fastcall* LogToConsoleFn)(const char*, ...) = NULL;
	int (__fastcall* EnetPeerSendFn)(ENetPeer*, enet_uint8, ENetPacket*) = NULL;

private:
	//
};