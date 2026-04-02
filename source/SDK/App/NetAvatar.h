#pragma once

#include <iostream>
#include <map>
#include "../Clanlib/Clanlib.h"

class Tile;

#pragma pack(push, 1)
class LockFloat
{
public:
	char pad1[0x10];
};

class NetBase
{
public:
	void* vftable;
	CL_Vec2f m_vPos;
	CL_Vec2f m_vSize;
	CL_Vec2f m_movementVerify;
	CL_Vec2f m_vSizeVerify;
	std::string m_name;
	int m_netID;
	bool m_deleteFlag;
	char pad1[0x3];
	std::unique_ptr<void> m_component;
};

class NetMoving : public NetBase
{
public:
	CL_Vec2f m_origin;
	bool m_collidable;
	bool m_bFacingLeft;
	short pad1;
	float _moveX;
	float _moveY;
	int pad2;
};

class NetAvatar : public NetMoving
{
public:
	unsigned int mNextPveAttackMinTick;
	unsigned int m_raceTimeStart;
	int m_countDownScore;
	float m_countDownTime;
	unsigned int m_inWaterTime;
	LockFloat m_punchReload;
	unsigned int m_pantsColor;
	char GuildClientModelObj[0x10];
	std::string OnlineID;
	float m_bJumpKeyDownTime;
	int worldEntityID;
	int m_jumpsSinceLastGround;
	int m_nextPacketTileX;
	int m_nextPacketTileY;
	int m_maxJumpsSinceLastGround;
	bool m_bOnSolid;
	bool m_bOnIce;
	bool m_bOnMud;
	bool m_bHandItemActive;
	bool m_bBackItemActive;
	bool m_bDoubleJumpActive;
	short pad1;
	LockFloat m_speedX;
	LockFloat m_speedY;
	bool m_bDidGravity;
	bool m_bRequestedJump;
	bool m_isCommunicationDisabled;
	char pad2;
	unsigned int m_lastHackSendTimer;
	int m_emotion;
	float m_emotionTime;
	void* m_pController;
	void* m_pPacketReceiver;
	void* m_pPacketSender;
	bool m_bJumpKeyDown;
	bool m_bTouchedLavaOnLastBounce;
	short pad3;
	unsigned int m_flagsToAddToNextPacketSent;
	int m_freezeState;
	unsigned int m_playerID;
	bool m_bAllowJumpForOneFrameExtra;
	char pad4[0x3];
	CL_Vec2f m_predictionChange;
	int pad5;
	std::string m_country;
	void* m_pFlagSurf;
	bool m_bInvisible;
	bool m_bIsMod;
	bool m_bIsSuperMod;
	char pad6;
	int m_nextPacketTileID;
	unsigned int m_audioTimer;
	int m_iconState;
	unsigned int m_flags;
	unsigned int m_flags2;
	unsigned int m_flagsMay2019;
	unsigned int m_hairDye;
	unsigned int m_eyeColor;
	unsigned int m_pupilColor;
	bool m_bDownKeyDown;
	bool m_bUnderwater;
	bool m_bDontSendMovementUntilUnfrozen;
	char pad7;
	int m_punchType;
	char m_ExtraMods;
	bool m_IsChargedJump;
	bool m_HasDoubleTapDashMove;
	bool m_IsPerformingDoubleTapDash;
	unsigned int doubleTapTick;
	bool m_HasFastFallJump;
	bool m_bFastFallJumpAvailable;
	bool isPerformingFastFallJump;
	bool m_IsKeyTap;
	float m_TapDownTimer;
	float m_TimerSinceTap;
	bool m_bMoveLeftKeyDown;
	bool m_bMoveRightKeyDown;
	short pad8;
	int lastKeyPressed;
	CL_Vec2f punchButtonInputDirection;
	LockFloat m_playerGravity;
	LockFloat m_baseAccel;
	LockFloat m_maxSpeedX;
	float m_maxSpeedWaterX;
	bool m_bDoubleJumpAvailable;
	char pad9[0x3];
	LockFloat m_knockBackPower;
	int pad10;
	std::string m_forceWeaponSfx;
	std::string m_forceWepPainSfx;
	std::string m_forceDeathScream;
	float m_health;
	float m_visHealth;
	bool m_bCheated;
	char pad11[0x3];
	int m_lastPortal;
	int m_hCheck;
	int m_respawnIndex;
	int m_faction;
	int m_bountyLevel;
	int m_bountyScore;
	bool m_FactionWarActive;
	unsigned __int8 m_battleTeam;
	unsigned __int8 m_battleFlagInHand;
	char pad12;
	int m_battleScore;
	int m_onSpikeCheck;
	int m_onLavaCheck;
	int m_balloonHitFromFaction;
	int m_balloonWetModActive;
	CL_Vec2f m_toolTouchPosCenterScreen;
	unsigned __int16 transmutatedClothingItems[9];
	unsigned __int16 clothingItems[9];
	int artifactItem;
	int equippedItemCount;
	char m_adventure[0x40];
	char m_avatarData[0x38];
	char m_renderData[0x3308];
	unsigned int m_checkItemsForHackTimer;
	int pad13;
	Tile* m_pLastTileOver;
	Tile* m_pLastTileUnderUs;
	int m_activeBattlePet;
	int m_petBattleID;
	int m_pvpCardBattleVisualsID;
	bool m_bBumpedByGrowga;
	char pad14[0x3];
	Tile * m_challengeStartFlag;
	Tile* m_challengeEndFlag;
	CL_Vec2f m_jumpOrigin;
	bool m_bHitMomentumTrampoline;
	char pad15[0x3];
	float m_momentumHitSpeed;
	LockFloat m_punchPowerTimer;
	LockFloat m_doingPunchPowerUp;
	LockFloat m_doingPowerUpWithButton;
	LockFloat m_punchPowerLevel;
	LockFloat m_raymanEquippedKey1;
	LockFloat m_raymanEquippedKey2;
	bool m_bInGuild;
	bool m_bDisplayGuildMascot;
	bool m_bIsMaxLevel;
	bool m_bIsMaster;
	bool m_bIsDoctor;
	bool m_bIsDonor;
	bool hasContentCreatorBadge;
	bool hasTikTokCreatorBadge;
	bool hasEuphoriaTitle;
	char pad16[0x3];
	int roleIcon;
	Tile* pDisguisedTile;
	int disguiseTileID;
	unsigned __int16 disguiseTileBGID;
	short pad17;
	int disguiseParticleEmitterIndex;
	int pad18;
	std::shared_ptr<void> disguiseParticleTimer;
	int m_PreviousSolidFloorMapIndex;
	bool m_simFloatHack;
	bool m_simOneHitHack;
	short pad19;
	void* m_pXLogoSurf;
	bool m_isXBLAccount;
	bool isShowingTitleIcon;
	char pad20[0x6];
	std::map<int, int> m_TransmutatedLinkPairs;
	std::map<int, int> m_TemporalTransmutatedLinkPairs;
	bool m_bIsFriendOfWorldOwnerUnsafe;
	bool inittedAvatarRenderData;
	bool mClothLoaded;
	bool mIsInFashionShow;
	int pad21;
};
#pragma pack(pop)

static_assert(sizeof(NetBase) == 0x58);
static_assert(sizeof(NetMoving) == 0x70);
static_assert(sizeof(NetAvatar) == 0x3788);