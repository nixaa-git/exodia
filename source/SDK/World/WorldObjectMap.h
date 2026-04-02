#pragma once

#include <iostream>
#include <list>
#include "WorldObject.h"

class WorldObjectMap
{
public:
	void* vftable;
	char pad1[0x40];
	unsigned int m_uniqueNumberGen;
	int pad2;
	std::list<WorldObject> m_objects;
};

static_assert(sizeof(WorldObjectMap) == 0x60);