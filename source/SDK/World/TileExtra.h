#pragma once

#pragma once

#include <iostream>
#include <vector>
#include "../Boost/Boost.h"

class TileExtra
{
public:
	void* vftable;
	unsigned __int8 m_type;
	unsigned __int8 m_flags;
	int m_ownerID;
	std::string m_name;
	std::string m_text;
	std::string m_id;
	unsigned int m_timer;
	unsigned int m_growth;
	unsigned __int8 m_fruitsToSpawn;
	int m_otherData;
	unsigned __int8 m_Faction;
	__int64 m_placedTime;
	__int64 m_lastPunchedTime;
	std::vector<int> m_playerList;
	void* m_pAvatarData;
	void* m_pBattle;
	void* m_pTamagotchi;
	void* m_pFishgotchi;
	void* m_pitemSucker;
	std::vector<void*> m_commands;
	void* m_pPVE_NPC;
	int m_guildID;
	int m_guildEmblem;
	int m_guildLevel;
	int m_displayGuildEmblem;
	int m_startopiaCurrentSector;
	unsigned int m_startopiaLastFuelUpdate;
	int m_startopiaCurrentFuel;
	unsigned int m_startopiaStarMiles;
	int m_startopiaGrowlactisState;
	int m_startopiaCurrentSpaceWeather;
	int m_startopiaMissionIndex;
	int m_startopiaMaxFuel;
	int m_startopiaPostCount;
	int m_autoActionFuel;
	unsigned int m_autoActionLastUseTime;
	int m_autoActionSuckCheckBox;
	int m_autoActionIsActive;
	int offStateTime;
	int isCloudCollidable;
	int fadingTime;
	long m_AddressChangeTime;
	int m_playerMinEntryLevel;
	int m_sessionTimeLimit;
};

static_assert(sizeof(TileExtra) != 0x158);