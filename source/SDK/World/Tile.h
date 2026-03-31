#pragma once

#include <iostream>
#include "TileExtra.h"
#include "../Boost/Boost.h"

class Tile
{
public:
	unsigned int currentColor;
	unsigned __int16 m_itemID;
	void* mStampData;
	std::shared_ptr<void*> mRenderState;
	std::shared_ptr<void*> mBackgroundRenderState;
	BoostTrackableSignal mItemInfoConnection;
	void* mRenderObject;
	void* mBackgroundRenderObject;
	unsigned __int16 m_itemBGID;
	unsigned __int16 m_flags;
	unsigned __int8 x;
	unsigned __int8 y;
	unsigned __int16 m_mapIndex;
	unsigned __int16 m_visual;
	unsigned __int16 m_visualBG;
	bool m_collidable;
	int m_collisionType;
	float m_worldRect[4];
	TileExtra* m_pTileExtra;
	unsigned __int8 m_damage;
	unsigned int m_lastDamageTimer;
	unsigned int m_deathTime;
	unsigned __int8 m_earthShattered;
	unsigned __int8 m_flipStamp;
	unsigned int m_damageSource;
	unsigned int m_tileTint;
	unsigned __int8 m_hitCounter;
	int m_animationCounterMS;
	unsigned int m_effectTimer;
	float m_darkness;
	float m_nextDark;
	bool m_bNotRendered;
	unsigned __int16 m_shadowItemID;
	bool m_bEffectTriggered;
	unsigned int m_BGeffectTimer;
	bool m_bBGEffectTriggered;
	unsigned int fadingStartTime;
	unsigned __int16 m_tileExtraParentIndex;
	float m_factionJammerStartDelay;
	int m_factionJammerCountdownVal;
	bool m_factionDelayInit;
	bool m_factionCountDownActive;
	unsigned int m_lastTick;
	unsigned int stateChangedTime;
	int disguiseID;
	unsigned int m_lastEditTime;
	unsigned int m_lastProjectileHit;
	std::unique_ptr<void*> mExtraData;
};

static_assert(sizeof(Tile) != 0xF0);