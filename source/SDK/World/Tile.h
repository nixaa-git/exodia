#pragma once

#include <iostream>
#include "TileExtra.h"
#include "../Boost/Boost.h"

class Tile
{
public:
	unsigned int currentColor;
	unsigned short m_itemID;
	void* mStampData;
	std::shared_ptr<void> mRenderState;
	std::shared_ptr<void> mBackgroundRenderState;
	BoostTrackableSignal mItemInfoConnection;
	void* mRenderObject;
	void* mBackgroundRenderObject;
	unsigned short m_itemBGID;
	unsigned short m_flags;
	uint8_t x;
	uint8_t y;
	unsigned short m_mapIndex;
	unsigned short m_visual;
	unsigned short m_visualBG;
	bool m_collidable;
	int m_collisionType;
	float m_worldRect[4];
	TileExtra* m_pTileExtra;
	uint8_t m_damage;
	unsigned int m_lastDamageTimer;
	unsigned int m_deathTime;
	uint8_t m_earthShattered;
	uint8_t m_flipStamp;
	unsigned int m_damageSource;
	unsigned int m_tileTint;
	uint8_t m_hitCounter;
	int m_animationCounterMS;
	unsigned int m_effectTimer;
	float m_darkness;
	float m_nextDark;
	bool m_bNotRendered;
	unsigned short m_shadowItemID;
	bool m_bEffectTriggered;
	unsigned int m_BGeffectTimer;
	bool m_bBGEffectTriggered;
	unsigned int fadingStartTime;
	unsigned short m_tileExtraParentIndex;
	float m_factionJammerStartDelay;
	int m_factionJammerCountdownVal;
	bool m_factionDelayInit;
	bool m_factionCountDownActive;
	unsigned int m_lastTick;
	unsigned int stateChangedTime;
	int disguiseID;
	unsigned int m_lastEditTime;
	unsigned int m_lastProjectileHit;
	std::unique_ptr<void> mExtraData;
};

static_assert(sizeof(Tile) == 0xF0);