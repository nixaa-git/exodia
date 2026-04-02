#pragma once

#include "../World/World.h"
#include "../App/NetObjectManager.h"
#include "EntityComponent.h"
#include "../Clanlib/Clanlib.h"
#include "../App/NetAvatar.h"

#include <map>

class GameLogicComponent : EntityComponent
{
public:
	BoostSignal m_sig_onPlayerClicked;
	int CurrentArtifact;
	int CurrentPlanter;
	int CurrentPlanterTileX;
	int CurrentPlanterTileY;
	int m_MagicCompassTrackingItemID;
	int m_userId;
	bool m_drop_lavacheck_faster;
	bool m_bItemPickerActive;
	char pad1[0x2];
	int bumpTimer;
	int m_tradeItemID;
	bool m_bIsInLocalMode;
	char pad2[0x3];
	int m_selectedTradeItemID;
	int pad3;
	CL_Vec2f* m_pPos2d;
	World* m_pWorld;
	void* m_pWorldRenderer;
	std::unique_ptr<void*> mWorldAudio;
	CL_Vec2f* m_pScale2d;
	CL_Vec2f*m_pSize2d;
	char m_currentCamLockState[0x14];
	char m_nextCamLockState[0x14];
	unsigned int mLastUpdateTimeMs;
	unsigned int mLastPlayerStateSend;
	unsigned int mPlayerUpdateAccumTime;
	int m_day;
	int m_localPlayerLevel;
	int m_month;
	int m_usingZodiacCycle;
	unsigned int totalPlayedTime;
	NetObjectManager m_objectManager;
	int m_fakeNetID;
	int pad4;
	NetAvatar* m_pLocalPlayer;
	char m_textManager[0x30];
	std::unique_ptr<void*> m_hudIndicatorManager;
	char m_items[0xB8];
	int m_activeItemID;
	bool m_bHasGrowID;
	bool m_bHasAccountSecured;
	short pad5;
	int m_gems;
	int m_pearls;
	int m_dungeonTokens;
	int m_vouchers;
	int m_sessionGems;
	bool m_bShowingNetworkProblem;
	char pad6[0x3];
	unsigned int m_networkProblemTimer;
	int pad7;
	char m_effectManager[0x18];
	bool m_bIsGameSupporter;
	bool m_bIsSGameSupporter;
	short pad8;
	unsigned int m_timeOfLastSendMS;
	bool m_bForcedMusicMode;
	char pad9[0x3];
	int m_punchRangeMod;
	int m_buildRangeMod;
	bool m_bSendIAPOnNextPing;
	char pad10[0x3];
	void* m_pTradeMenu;
	int m_baseTimeSecondsFromServer;
	bool m_baseTimeSecondsSet;
	char pad11[0x3];
	unsigned int m_timeThatTimeWasUpdated;
	int pad12;
	char m_battleStatus[0x60];
	char m_packetWatcher[0x10];
	int m_serverTimeMs;
	int m_serverTimeUpdateTick;
	int m_currentServerTimeMs;
	int m_activeHoliday;
	int m_currentWingWeekDay;
	unsigned int m_server_tick;
	unsigned int m_ClientTickWhenReceavingServerTick;
	bool m_ClashEventIsActive;
	char pad13[0x3];
	int m_uiFlowType;
	bool m_ftueWorldSwitchActive;
	bool m_dailyChallengeActive;
	short pad14;
	int m_dailyChallengePoints;
	int m_dailyChallengeStartTime;
	bool m_Paw2018SkinColor1Ability;
	bool m_Paw2018SkinColor2Ability;
	bool m_availableRoleSkins[6];
	bool m_availableRoleIcons[6];
	short pad15;
	std::map<int, int> m_gamePacketCounter;
	std::map<int, int> m_messageTypeCounter;
	std::map<std::string, int> m_functionPacketCounter;
	unsigned int m_lastCheckTime;
	unsigned int m_lastDialogTime;
	unsigned int CONST_ProgressUIAnimMS;
	unsigned int m_ProgressUIAnimTimer;
	char m_ProgressUIHelper[0x1C];
	int pad16;
	std::unique_ptr<void*> tutorialDataModel;
	char m_PVEPartyUIHelper[0x90];
	std::map<std::string, int> m_TabStatics;
	bool m_bBigBackpackEnabled;
	bool canSeeWOTDCoin;
	char pad17[0x6];
	void* m_pPVE_NPC_Manager;
	bool isHaveRespawnTimeout;
	char pad18[0x3];
	int onlineStatus;
	std::map<std::string, int> dialogCheckBoxMap;
	int maxFavItemsCount;
	char m_dailyChallengeInfo[0x1C];
	std::string mFileServerSite;
	std::string mFileRootPath;
	char mSeedDiaryManager[0x1090];
};