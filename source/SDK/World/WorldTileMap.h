#pragma once

#include <iostream>
#include <vector>

#include "../Clanlib/Clanlib.h"
#include "Tile.h"

class World;

class WorldTileMap
{
public:
    Tile* GetTileAtPos(CL_Vec2i tilePos)
    {
        if (m_tiles.size() <= 0)
        {
            return nullptr;
        }

        return &m_tiles[tilePos.x + tilePos.y * m_sizeX];
    }

	void* vftable;
	int m_sizeX;
	int m_sizeY;
	unsigned __int16 m_firesLit;
	char pad1[0x6];
	std::vector<Tile> m_tiles;
	World* m_pParent;
};

static_assert(sizeof(WorldTileMap) == 0x38);