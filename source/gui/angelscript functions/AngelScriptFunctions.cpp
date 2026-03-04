#include "AngelScriptFunctions.h"
#include "../../Globals.h"

std::map<std::string, std::vector<asIScriptFunction*>> g_callbacks;

void AS_Print(std::string& msg)
{
	printf("%s\n", msg.c_str());
}

void AS_LogToConsole(std::string& msg)
{
	SDK::Get()->LogToConsoleFn(msg.c_str());
}

void AS_SendPacket(int type, std::string& msg)
{
	SDK::Get()->SendPacket(type, msg);
}

void AS_AddCallback(std::string& name, asIScriptFunction* pFunc)
{
    if (!pFunc)
        return;

    pFunc->AddRef(); // store reference
    g_callbacks[name].push_back(pFunc);
}