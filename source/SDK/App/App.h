#pragma once

#include "../ENet/ENetClient.h"

#pragma pack(push, 1)

class App
{
public:
	char pad1[2832];
	ENetClient* m_pENetClient;
private:
};

#pragma pack(pop)