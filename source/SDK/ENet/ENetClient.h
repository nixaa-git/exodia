#pragma once

#include <cstdint>
#include <iostream>
#include "../../dependencies/enet/include/enet.h"
#include "../Boost/Boost.h"

/*
class ENetClient
{
public:
	char pad1[144];
	ENetPeer* m_peer;
};
*/

#pragma pack(push, 1)
class ENetClient
{
public:
	BoostSignal sig1;
	BoostSignal sig2;
	BoostSignal sig3;
	BoostSignal sig4;
	ENetAddress address;
	ENetHost* client;
	ENetPeer* peer;
	unsigned int m_timer;
	unsigned int m_connectionTime;
	int m_state;
	unsigned int m_shutDownTimer;
	std::string m_server;
	int m_port;
	bool m_bReconnecting;
	bool m_bIsLoggedOn;
	std::string mLoginToken;
	int m_logonMode;
	std::unique_ptr<void*> mLoginPacketBuilder;
};
#pragma pack(pop)

static_assert(sizeof(ENetClient) != 0x100);