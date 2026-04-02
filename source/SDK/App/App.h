#pragma once

#include "BaseApp.h"
#include "../ENet/ENetClient.h"
#include "ItemInfoManager.h"
#include "../Component/GameLogicComponent.h"

//char pad1[2832];

#pragma pack(push, 1)
class App : BaseApp
{
public:
	bool m_enableInventoryTab;
	char pad1[0x7];
	char m_audioCache[0x58];
	ENetClient* m_pENetClient;
	bool m_bForceUsingMainServer;
	char pad2[0x7];
	void* m_globalLog;
	bool m_bDidPostInit;
	char pad3[0x7];
	char m_varDB[0x90];
	bool m_bAutomated;
	char pad4[0x7];
	std::string m_serverURLOverride;
	int m_serverPortOverride;
	int m_hashOverride;
	std::string mWebLoginDomainOverride;
	bool m_bTalkTest;
	char pad5[0x7];
	char m_frameOverlaySurf[0x78];
	char m_invSelectSurf[0x78];
	char m_gridOverlaySurf[0x78];
	std::string m_cachePath;
	float m_graphicDetail;
	float speechBubbleOpacity;
	int m_ScreenUIMode;
	unsigned int m_timeLostFocus;
	int m_serverType;
	bool m_bUsingBetaServer;
	bool m_bUsingBetaFiles;
	bool m_bUsingBeta2Server;
	bool m_bUsingBeta3Server;
	bool m_bUsingModBetaFiles;
	char pad6[0x7];
	std::string m_choose_world_music;
	int m_serverProtocol;
	int pad7;
	std::string m_sidOverride;
	unsigned int m_bootCount;
	int m_GDPRSetting;
	int m_playerAge;
	int pad8;
	std::string m_houstonRegion;
	int mTrackingStatus;
	bool m_KilledIsCalled;
	bool m_sendPlayerInfo;
	short pad9;
	char m_mountOperationLock[0x50];
	unsigned int m_sessionStartTime;
	bool m_usingEncryption;
	char pad10[0x3];
	int m_itemCacheID;
	unsigned int m_RightUIsSwitch;
	unsigned int m_LeftUIsSwitch;
	int pad11;
	void* m_pAnzuManager;
	bool m_enableMsgIcon;
	char pad12[0x3];
	int nextUpdateForStopData;
	void* helpShiftAdapter;
	void* ironSourceAdapter;
	void* appReviewAdapter;
	void* firebaseCloudMessagingAdapter;
	bool m_enableInventoryTabExculseMobile;
	bool m_usingStoreNavigation;
	bool m_usingIgnoreSeal;
	bool m_usingTransmutationIcon;
	int legalMenuShowTime;
	std::string purchasePrice;
	std::string purchaseCurrency;
	bool m_bIsRunningOn64BitWindows;
	char pad13[0x3];
	float m_antiHackConstChecksum;
	unsigned int m_gametimerCopy;
	int pad14;
	char m_IAPManager[0x140];
	char m_adManager[0x110];
	char m_playerTributeManger[0x90];
	char m_swearFilterManager[0x18];
	char m_tileSheetManager[0x20];
	ItemInfoManager m_itemInfoManager;
	void* m_pTrackHandlerComponent;
	GameLogicComponent* m_pGameLogicComponent;
	std::shared_ptr<void*> mRootController;
	short mBGFXTextureHandler;
	short mBGFXOffscreenFrameBuffer;
	short mVertexBufferHandle;
	short mIndexBufferHandle;
	int mAdWatchedNumber;
	int pad15;
};
#pragma pack(pop)

static_assert(sizeof(App) == 0x1300);