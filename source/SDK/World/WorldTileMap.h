#pragma once

#include <iostream>
#include <vector>

#include "Tile.h"

class World;

class WorldTileMap
{
public:
	void* vftable;
	int m_sizeX;
	int m_sizeY;
	unsigned __int16 m_firesLit;
	void* pad1;
	std::vector<Tile> m_tiles;
	World* m_pParent;
};

static_assert(sizeof(WorldTileMap) != 0x38);