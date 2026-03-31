#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>


typedef int eItemType;

enum eItemMaterial : __int32
{
	ITEM_MATERIAL_WOOD = 0x0,
	ITEM_MATERIAL_GLASS = 0x1,
	ITEM_MATERIAL_ROCK = 0x2,
	ITEM_MATERIAL_METAL = 0x3,
};

enum eItemElement : __int32
{
	ITEM_ELEMENT_EARTH = 0x0,
	ITEM_ELEMENT_FIRE = 0x1,
	ITEM_ELEMENT_AIR = 0x2,
	ITEM_ELEMENT_WATER = 0x3,
	ITEM_ELEMENT_CLOTHES = 0x4,
};

enum eTileVisualEffect : __int32
{
	TILE_VISUAL_EFFECT_NONE = 0x0,
	TILE_VISUAL_EFFECT_FLAME_LICK = 0x1,
	TILE_VISUAL_EFFECT_SMOKING = 0x2,
	TILE_VISUAL_EFFECT_GLOW_TINT1 = 0x3,
	TILE_VISUAL_EFFECT_ANIM = 0x4,
	TILE_VISUAL_EFFECT_BUBBLES = 0x5,
	TILE_VISUAL_EFFECT_PET = 0x6,
	TILE_VISUAL_EFFECT_PETANIM = 0x7,
	TILE_VISUAL_EFFECT_NO_ARMS = 0x8,
	TILE_VISUAL_EFFECT_WAVEY = 0x9,
	TILE_VISUAL_EFFECT_WAVEY_ANIM = 0xA,
	TILE_VISUAL_EFFECT_BOTHARMS = 0xB,
	TILE_VISUAL_EFFECT_LOWHAIR = 0xC,
	TILE_VISUAL_EFFECT_UNDERFACE = 0xD,
	TILE_VISUAL_EFFECT_SKINTINT = 0xE,
	TILE_VISUAL_EFFECT_MASK = 0xF,
	TILE_VISUAL_EFFECT_ANIM_MASK = 0x10,
	TILE_VISUAL_EFFECT_LOWHAIR_MASK = 0x11,
	TILE_VISUAL_EFFECT_GHOST = 0x12,
	TILE_VISUAL_EFFECT_PULSE = 0x13,
	TILE_VISUAL_EFFECT_COLORIZE = 0x14,
	TILE_VISUAL_EFFECT_COLORIZE_TO_SHIRT = 0x15,
	TILE_VISUAL_EFFECT_COLORIZE_ANIM = 0x16,
	TILE_VISUAL_EFFECT_HIGHFACE = 0x17,
	TILE_VISUAL_EFFECT_HIGHFACE_ANIM = 0x18,
	TILE_VISUAL_EFFECT_RAINBOW_SHIFT = 0x19,
	TILE_VISUAL_EFFECT_BACKFORE = 0x1A,
	TILE_VISUAL_EFFECT_COLORIZE_WITH_SKIN = 0x1B,
	TILE_VISUAL_EFFECT_NO_RENDER = 0x1C,
	TILE_VISUAL_EFFECT_SPIN = 0x1D,
	TILE_VISUAL_EFFECT_OFFHAND = 0x1E,
	TILE_VISUAL_EFFECT_WINGED = 0x1F,
	TILE_VISUAL_EFFECT_SINK = 0x20,
	TILE_VISUAL_EFFECT_DARKNESS = 0x21,
	TILE_VISUAL_EFFECT_LIGHTSOURCE = 0x22,
	TILE_VISUAL_EFFECT_LIGHT_IF_ON = 0x23,
	TILE_VISUAL_EFFECT_DISCOLOR = 0x24,
	TILE_VISUAL_EFFECT_STEP_SPIN = 0x25,
	TILE_VISUAL_EFFECT_PETCOLORED = 0x26,
	TILE_VISUAL_EFFECT_SILKFOOT = 0x27,
	TILE_VISUAL_EFFECT_TILTY = 0x28,
	TILE_VISUAL_EFFECT_TILTY_DARK = 0x29,
	TILE_VISUAL_EFFECT_NEXT_FRAME_IF_ON = 0x2A,
	TILE_VISUAL_EFFECT_WOBBLE = 0x2B,
	TILE_VISUAL_EFFECT_SCROLL = 0x2C,
	TILE_VISUAL_EFFECT_LIGHTSOURCE_PULSE = 0x2D,
	TILE_VISUAL_EFFECT_BUBBLE_MACHINE = 0x2E,
	TILE_VISUAL_EFFECT_VERYLOWHAIR = 0x2F,
	TILE_VISUAL_EFFECT_VERYLOWHAIR_MASK = 0x30,
	TILE_VISUAL_EFFECT_COUNT = 0x31,
};

enum eItemImageStorage : __int32
{
	ITEM_IMAGE_STORAGE_SINGLE_FRAME_IN_TILESHEET_ALONE = 0x0,
	ITEM_IMAGE_STORAGE_SINGLE_FRAME_IN_TILESHEET = 0x1,
	ITEM_IMAGE_STORAGE_SMART_EDGE = 0x2,
	ITEM_IMAGE_STORAGE_SMART_EDGE_HORIZ = 0x3,
	ITEM_IMAGE_STORAGE_SMART_CLING = 0x4,
	ITEM_IMAGE_STORAGE_SMART_EDGE_OUTER = 0x5,
	ITEM_IMAGE_STORAGE_RANDOM = 0x6,
	ITEM_IMAGE_STORAGE_SMART_EDGE_VERT = 0x7,
	ITEM_IMAGE_STORAGE_SMART_EDGE_HORIZ_CAVE = 0x8,
	ITEM_IMAGE_STORAGE_SMART_CLING2 = 0x9,
	ITEM_IMAGE_STORAGE_SMART_EDGE_DIAGON = 0xA,
};

struct GrowInfo
{
	unsigned __int8 m_seedBaseImageFrame;
	unsigned __int8 m_seedOverlayImageFrame;
	unsigned __int8 m_treeBaseImageFrame;
	unsigned __int8 m_treeOverlayImageFrame;
	unsigned int m_baseColor;
	unsigned int m_overlayColor;
	unsigned __int16 m_seed[2];
	unsigned int m_secondsRequiredToBloom;
	int m_maxFruit;
	unsigned __int8 m_growMultiplier;
	unsigned __int16 m_BountifulSeed;
	float m_BountifulChance;
};

class ItemInfo
{
public:
	int m_itemID;
	eItemType m_type;
	eItemMaterial m_material;
	eItemElement m_element;
	std::string m_displayName;
	unsigned int m_checksumOfFile;
	int pad1;
	std::string m_fileName;
	eTileVisualEffect m_visualEffect;
	int m_cook;
	unsigned __int8 m_frameX;
	unsigned __int8 m_frameY;
	short pad2;
	eItemImageStorage m_imageStorage;
	char m_layer;
	char pad3[0x3];
	int m_collisionType;
	uint8_t m_hp;
	char pad4;
	unsigned __int16 m_flags;
	unsigned int m_flags2;
	unsigned __int8 m_hideAvatarPartsFlag;
	char pad5[0x3];
	int m_clientdata[15];
	unsigned __int16 m_serverFlags;
	short pad6;
	int m_secondsToHeal;
	int m_bodyPart;
	GrowInfo m_growInfo;
	int pad7;
	std::string gachaDropNameOnFruitHarvested;
	std::string gachaDropNameOnItemDestroyed;
	int gachaRollCountOnItemDestroyed;
	float gachaDropChanceOnItemDestroyed;
	int replacementItemOnDestroyed;
	bool dontDrawFrame;
	char pad8;
	unsigned __int16 m_rarity;
	unsigned __int8 m_maxCanHold;
	void* pad9;
	std::string m_extraString;
	unsigned int m_extraStringChecksum;
	int m_effectTimeMS;
	std::string m_description;
	int m_playModID;
	int m_minimum_protocol;
	int m_originalVersionItemID;
	int m_recycleValue;
	std::string m_petName[4];
	char m_goodieInfo[0x18];
	unsigned int m_antiHackChecksum;
	int pad10;
	std::string m_itemEffects[8];
	int m_numEffects;
	unsigned int m_renderFx;
	std::string m_animFrames;
	std::string m_animFrames2;
	std::string m_secondaryTexture;
	int m_layer2Coords[2];
	bool AutoBreakerActionEnabled;
	char pad11[0x3];
	int m_lightsourceRange;
	bool m_pveTechParticle;
	char pad12[0x3];
	int m_pveParticleID;
	int m_pveParticleColorR;
	int m_pveParticleColorG;
	int m_pveParticleColorB;
	int m_pveParticleSpeedX;
	int m_pveParticleSpeedY;
	bool m_pveParticleSoundOn;
	char pad13[0x3];
	int m_pveParticlePosOffsetX;
	int m_pveParticlePosOffsetY;
	bool m_pveParticleIsProjectile;
	char pad14[0x3];
	unsigned int m_TileRange;
	unsigned int m_PileSize;
	int m_extraSlots[9];
	int m_numExtraSlots;
	int pad15;
	std::string m_CustomizedPunchInfoStr;
	char m_pveNpcSettings[0x258];
	char m_pveInfo[0x28];
	char chairInfo[0x40];
	char m_RandomSpriteReplacement[0xC];
	int mDisplayShelfClothingOption;
	std::string configName;
	unsigned int configFileChecksum;
	bool HasVariableSetFromServer;
	bool IsTransform;
	short pad16;
	std::string WrenchButtonImage;
	std::string DialogToOpenOnWrench;
	std::string DialogToOpenOnAttack;
	int otherPlayerHitParticle;
	int MaxCountInWorld;
	int mSlipType;
	int pad17;
};

class ItemInfoManager
{
public:
	void* vftable;
	std::vector<ItemInfo> m_itemInfo;
	char pad2[0x69];
};

static_assert(sizeof(ItemInfo) != 0x798);
static_assert(sizeof(ItemInfoManager) != 0x88);