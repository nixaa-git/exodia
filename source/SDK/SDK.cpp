#include "SDK.h"

bool SDK::Initialize()
{
	// patch integrity check firstly
	//void* pIntegrityCheck = m_procModule.FindPattern("00 3B C1 75 ? 85 C9", "integrity check").Get();

	// nop the ptr it checks against
	//WriteMemory(pIntegrityCheck, "00 3B C1 90 90");

	// remove vmprotect antihooking for vers 4.20+
	c_module ntdll("ntdll.dll");
	void* ntProtFn = ntdll.GetProcAddress("NtProtectVirtualMemory").Get();

	if (WriteMemory(ntProtFn, "4C 8B D1 B8 50"))
	{
		std::printf("Patched NtProtectVirtualMemory!\n");
	}

	void* nigger = m_procModule.FindPattern("75 08 85 C9 0F 85 8B 00 00 00", "integrity check").Get();

	if (WriteMemory(nigger, "74"))
	{
		std::printf("fucked up that integrity check\n");
	}

	/*
	void* mutex = m_procModule.FindPattern("E8 ? ? ? ? 33 D2 4C 8D 05", "mutex").Get();

	if (WriteMemory(mutex, "E9 1E 00 00 00"))
	{
		std::printf("patched mutex");
	}
	*/

	this->SetupFunctions();

	m_pLuaState = luaL_newstate();

	return true;
}

void SDK::SetupFunctions()
{
	this->SendPacketFn = m_procModule.FindPattern("4D 85 C0 74 78", "SendPacket").Get<decltype(SendPacketFn)>();
	this->SendPacketRawFn = m_procModule.FindPattern("E8 ? ? ? ? FF 15 ? ? ? ? 4C 8D 5C 24 70", "SendPacketRaw").Relative().Get<decltype(SendPacketRawFn)>();
	this->GameLogicComponent_ProcessTankUpdatePacketFn = m_procModule.FindPattern("E8 ? ? ? ? EB 4C 48 8D 0D ? ? ? ? E8 ? ? ? ? EB 3E", "GameLogicComponent::ProcessTankUpdatePacket").Relative().Get<decltype(GameLogicComponent_ProcessTankUpdatePacketFn)>();
	//this->EnetPacketCreateFn = m_procModule.FindPattern("E8 ? ? ? ? 48 89 44 24 20 48 8B 44 24 20 48 8B 40 10", "enet_packet_create").Get<decltype(EnetPacketCreateFn)>();
	//this->EnetPeerSendFn = m_procModule.FindPattern("E8 ? ? ? ? 90 48 83 C4 38 5F", "enet_peer_send").Relative().Get<decltype(EnetPeerSendFn)>();
	//this->LogToConsoleFn = m_procModule.FindPattern("E8 ? ? ? ? 32 C0 48 83 C4 ? C3 B9", "LogToConsole").Relative().Get<decltype(LogToConsoleFn)>();
	//this->GetAppFn = m_procModule.FindPattern("E8 ? ? ? ? 48 8D 53 60", "GetApp").Relative().Get<decltype(GetAppFn)>();
	this->GetENetClientFn = m_procModule.FindPattern("48 8B 05 ? ? ? ? 48 8B 80 98", "GetENetClient").Get<decltype(GetENetClientFn)>();
	this->BaseAppSetFPSLimitFn = m_procModule.FindPattern("E8 ? ? ? ? 90 48 8D 4D 10 E8 ? ? ? ? 48 8B 4D 30", "BaseApp::SetFPSLimit").Relative().Get<decltype(BaseAppSetFPSLimitFn)>();
	//this->GameLogicComponent_CreateDummyWorldForTestingFn = m_procModule.FindPattern("48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 F0", "CreateDummyWorldForTesting").Get<decltype(GameLogicComponent_CreateDummyWorldForTestingFn)>();
	//this->WorldConstructorFn = m_procModule.FindPattern("48 89 4C 24 08 55 53 56 57 41 54 41 56 41 57 48 8D 6C 24 D9", "WorldConstructor").Get<decltype(WorldConstructorFn)>();

	std::printf("SDK Finished setting up game functions.\n");

	if (GetAppFn && BaseAppSetFPSLimitFn)
	{
		BaseAppSetFPSLimitFn(GetAppFn(), 0.f);
		::printf("FPS Unlocked!\n");
	}
}

void SDK::SendPacket(int type, const std::string& genericText)
{
	if (!this->GetENetClientFn)
	{
		::printf("SDK::SendPacket() : SDK::GetENetClientFn is nullptr!!\n");
		return;
	}

	ENetClient* pClient = this->GetENetClientFn();
	if (!pClient)
	{
		return;
	}

	if (!pClient->m_peer)
	{
		return;
	}

	/* keeping this here incase sum goes wrong in the future.
	* 
	ENetPacket* pkt = this->EnetPacketCreateFn(NULL, genericText.length() + 5, ENET_PACKET_FLAG_RELIABLE);
	::memcpy(pkt->data, &type, sizeof(int));
	::memcpy(pkt->data + sizeof(int), genericText.c_str(), genericText.length());
	this->EnetPeerSendFn(pClient->m_peer, 0, pkt);
	*/

	std::string strCopy = genericText;
	this->SendPacketFn(type, strCopy, (void*)pClient->m_peer);
}

void SDK::SendPacketRaw(int type, unsigned char* pData, unsigned int dataLen, int enetFlag)
{
	App* pApp = this->GetAppFn();
	if (!pApp)
	{
		return;
	}

	ENetClient* pClient = pApp->m_pENetClient;
	if (!pClient)
	{
		return;
	}

	if (!pClient->m_peer)
	{
		return;
	}

	this->SendPacketRawFn(type, pData, dataLen, NULL, pClient->m_peer, enetFlag);

	//ENetPacket* pkt = enet_packet_create(pData, dataLen, enetFlag);
	//this->EnetPeerSendFn(pClient->m_peer, NULL, pkt);

	//::free(pkt);
}