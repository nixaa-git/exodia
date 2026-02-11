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

	this->SetupFunctions();

	m_pLuaState = luaL_newstate();

	return true;
}

void SDK::SetupFunctions()
{
	this->SendPacketFn = m_procModule.FindPattern("4C 89 44 24 ? 48 89 54 24 ? 89 4C 24", "SendPacket").Get<decltype(SendPacketFn)>();
	this->SendPacketRawFn = m_procModule.FindPattern("4C 89 4C 24 ? 44 89 44 24 ? 48 89 54 24 ? 89 4C 24", "SendPacketRaw").Get<decltype(SendPacketRawFn)>();
	this->EnetPacketCreateFn = m_procModule.FindPattern("E8 ? ? ? ? 48 89 44 24 20 48 8B 44 24 20 48 8B 40 10", "enet_packet_create").Get<decltype(EnetPacketCreateFn)>();
	this->EnetPeerSendFn = m_procModule.FindPattern("E8 ? ? ? ? 90 48 83 C4 38 5F", "enet_peer_send").Relative().Get<decltype(EnetPeerSendFn)>();
	this->LogToConsoleFn = m_procModule.FindPattern("E8 ? ? ? ? 32 C0 48 83 C4 ? C3 B9", "LogToConsole").Relative().Get<decltype(LogToConsoleFn)>();
	this->GetAppFn = m_procModule.FindPattern("E8 ? ? ? ? 44 88 A0 ? ? ? ? E9", "GetApp").Relative().Get<decltype(GetAppFn)>();
	this->GetENetClientFn = m_procModule.FindPattern("E8 ? ? ? ? 89 74 24 28", "GetENetClient").Relative().Get<decltype(GetENetClientFn)>();
	this->BaseAppSetFPSLimitFn = m_procModule.FindPattern("E8 ? ? ? ? E8 ? ? ? ? 83 E8 ? 74", "BaseApp::SetFPSLimit").Relative().Get<decltype(BaseAppSetFPSLimitFn)>();

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

	ENetPacket* pkt = enet_packet_create(pData, dataLen, enetFlag);
	this->EnetPeerSendFn(pClient->m_peer, NULL, pkt);

	::free(pkt);
}