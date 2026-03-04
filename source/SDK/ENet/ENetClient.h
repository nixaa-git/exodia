#pragma once

#include <cstdint>
#include "../../dependencies/enet/include/enet.h"

#pragma pack(push, 1)

class ENetClient
{
public:
	char pad1[200];
	ENetPeer* m_peer;
};

#pragma pack(pop)