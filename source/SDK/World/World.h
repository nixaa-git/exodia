#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include "../Boost/Boost.h"

#include "WorldTileMap.h"
#include "WorldObjectMap.h"

class World
{
public:
	bool XboxLiveExclusive;
	unsigned __int16 m_version;
	BoostSignal TileRemoved;
	BoostSignal TileAdded;
	std::unordered_map<int, Tile*> tilesByItemId;
	WorldTileMap m_tiles;
	WorldObjectMap m_objects;
	std::unique_ptr<void*> mDungeonWorldInfo;
	std::string m_name;
	unsigned int m_flags;
	unsigned short m_baseWeatherType;
	unsigned short m_terraformType;
	unsigned short m_currentWeatherType;
	unsigned short m_unused2;
	unsigned int m_unused3;
	int m_blockInvite;
	unsigned int m_timeLastSolidAdded;
	std::string m_worldBalancerBaseName;
	std::string m_description;
	std::string m_creationDate;
	std::list<void*> m_doors;
	std::list<void*> m_heartMonitors;
	std::vector<void*> m_autoDeleteBlocks;
	std::vector<void*> m_blockSpawners;
	int m_searchLightCount;
	int m_givingTreeCount;
	int m_steamStompers;
	int m_steamItems;
	int m_silkworms;
	int m_cameras;
	int m_blasters;
	int m_robots;
	int m_StorageBoxExtreme;
	Tile* m_pJammerTile;
	Tile* m_pWorldLockTile;
	int m_lockCount;
	Tile* m_pZombieJammerTile;
	Tile* m_pDropJammerTile;
	Tile* m_pGravityJammerTile;
	Tile* m_pMusicAmplifierTile;
	Tile* m_pConsumableJammerTile;
	Tile* m_pPunchJammerTile;
	Tile* m_pXenoniteTile;
	Tile* m_pFirehouseTile;
	Tile* m_pGhostCharmTile;
	Tile* m_pBalloonJammerTile;
	Tile* m_pArchitectMachineTile;
	Tile* m_pDwarvenDoorTile;
	Tile* m_pDoomsdayWeatherTile;
	Tile* m_pInfinityWeatherMachineTile;
	std::list<Tile*> m_containmentNodes;
	std::vector<std::vector<Tile*>> m_activeNodeGroups;
	std::list<Tile*> m_ArchitectMachineTiles;
	std::list<Tile*> m_DimensionBlockTiles;
	std::list<Tile*> m_DeathTrapWalls;
	std::list<Tile*> lightningClouds;
	std::list<Tile*> checkoutCounters;
	std::list<Tile*> m_PlayingCards;
	std::list<Tile*> m_otherWorldlyWarningLights;
	std::list<Tile*> m_starshipComponents;
	std::list<Tile*> m_starshipHull;
	std::list<Tile*> m_autoActionBlocks;
	std::list<Tile*> m_PressingPads;
	std::list<Tile*> m_DunckingBuckets;
	std::set<Tile*> m_Tricksters;
	Tile* m_pDataTile;
	Tile* m_pMainDoor;
	bool m_IsTilesDirty;
	unsigned int m_TilesDirtyVersion;
	bool m_magplantCountDirty;
	int m_magplantCount;
	Tile* m_pPVEBossSwitch;
	char mDungeonNPCList[0x14B08]; // absolute bullshit garbage why the FUCK is this so big???????
	std::list<Tile*> m_PVENPCTiles;
	std::list<Tile*> m_AnzuTiles;
	Tile* m_pAirshipBaseTile;
	bool m_mapLoaded;
	Tile* starDataTile;
	int entityID;
	char m_particleSystem[0xA8];
	char m_renderObjects[0x80];
	char mEntityManager[0x50];
	char mComponentManagersContainer[0x20];
};

static_assert(sizeof(World) != 0x150C0);