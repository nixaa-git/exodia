#pragma once

#include <iostream>
#include <vector>
#include "../Boost/Boost.h"

struct RTFont
{
public:
	char pad1[0x178];
};

#pragma pack(push, 1)
class BaseApp
{
public:
	void* vftable;
	BoostSignal m_sig_input;
	BoostSignal m_sig_init_video;
	BoostSignal m_sig_input_move;
	BoostSignal m_sig_os;
	BoostSignal m_sig_update;
	BoostSignal m_sig_render;
	BoostSignal m_sig_pre_enterbackground;
	BoostSignal m_sig_enterbackground;
	BoostSignal m_sig_enterforeground;
	BoostSignal m_sig_accel;
	BoostSignal m_sig_trackball;
	BoostSignal m_sig_arcade_input;
	BoostSignal m_sig_raw_keyboard;
	BoostSignal m_sig_hardware;
	BoostSignal m_sig_unloadSurfaces;
	BoostSignal m_sig_loadSurfaces;
	BoostSignal m_sig_joypad_events;
	BoostSignal m_sig_lol1; //	native input state changed
	BoostSignal m_sig_lol2;
	BoostSignal m_sig_lol3;
	BoostSignal m_sig_lol4;
	BoostSignal m_sig_lol5;
	BoostSignal m_sig_lol6;
	//
	bool m_bConsoleVisible;
	bool m_bFPSVisible;
	bool m_bInitted;
	char pad1[0x5];
	char m_gameTimer[0x60];
	void* m_console;
	RTFont m_fontArray[4];
	char pad2[0x28];
	bool m_bManualRotation;
	char pad3[0x7];
	char m_resourceManager[0x18];
	int m_inputMode;
	int m_memUsed;
	int m_texMemUsed;
	int m_error;
	bool m_bIsInBackground;
	char pad4[0x7];
	std::vector<std::string> m_commandLineParms;
	char m_projectionMatrix[0x40];
	void* m_pEntityRoot;
	bool m_bCheatMode;
	char pad5[0x7];
	char m_touchTracker[0x18];
	char mouseInputTracker[0x18];
	char keyboardInputTracker[0x18];
	std::string m_version;
	bool m_bDisableSubPixelBlits;
	char pad6[0x7];
	std::string* savedVideoMode;
	unsigned int* isBorderlessWindowModeOn;
	unsigned int* isFullscreenModeOn;
	unsigned int* savedResolutionX;
	unsigned int* savedResolutionY;
	unsigned short m_vendorID;
	char pad7[0x6];
	void* m_pProfileManager;
	bool m_isShuttingDown;
	char pad8[0x7];
};
#pragma pack(pop)

static_assert(sizeof(BaseApp) == 0xAB0);