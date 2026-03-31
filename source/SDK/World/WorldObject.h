#pragma once

#include <iostream>

class WorldObject
{
public:
	void* vftable;
	float m_vPos[2];
	unsigned __int16 m_itemID;
	unsigned __int8 m_count;
	unsigned __int8 m_flags;
	unsigned int m_objectID;
	unsigned int m_timeCreated;
	unsigned int m_timeTouched;
};

static_assert(sizeof(WorldObject) != 0x20);