#include "Funcs.h"
#include "../../Globals.h"
#include "../HookManager.h"

#include <string>
#include <regex>

#include "../../gui/angelscript functions/AngelScriptFunctions.h"
#include "../../gui/Gui.h"

void __fastcall hkSendPacketFn(int messageType, std::string& genericText, void* pPeer)
{
	static auto orig = reinterpret_cast<decltype(SDK::Get()->SendPacketFn)>(HookManager::Get()->hkSendPacket.m_origFn);

	/* dont include ts in prod builds
	if (genericText.find("platformID") != std::string::npos)
	{
		std::regex pattern(R"(platformID\|\d+,\d+,\d+)");
		std::string result = std::regex_replace(genericText, pattern, "platformID|12");
		SDK::Get()->LogToConsoleFn("`2Spoofed platform ID to 12!");
		orig(messageType, result, pPeer);
		return;
	}*/

    bool shouldSend = true;

    auto it = g_callbacks.find("SendPacket");
    if (it != g_callbacks.end())
    {
        for (auto* func : it->second)
        {
            asIScriptContext* ctx = Gui::Get()->asEngine->CreateContext();
            ctx->Prepare(func);

            ctx->SetArgDWord(0, messageType);
            ctx->SetArgObject(1, (void*)&genericText);

            int r = ctx->Execute();

            if (r == asEXECUTION_EXCEPTION)
            {
                printf("Script exception: %s\n",
                    ctx->GetExceptionString());
            }

            // OPTIONAL: If callback returns bool (cancel packet)
            if (r == asEXECUTION_FINISHED &&
                func->GetReturnTypeId() == asTYPEID_BOOL)
            {
                if (!ctx->GetReturnByte())
                    shouldSend = false;
            }

            ctx->Release();
        }
    }

    if (!shouldSend)
    {
        printf("Packet blocked by script\n");
        return;
    }

    if (messageType != 8)
    {
	    std::printf("SendPacket called! %s\n", genericText.c_str());
    }

	orig(messageType, genericText, pPeer);
}