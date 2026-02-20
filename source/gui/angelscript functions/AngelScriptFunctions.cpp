#include "AngelScriptFunctions.h"
#include "../../Globals.h"

void AS_Print(std::string& msg)
{
	printf("%s\n", msg.c_str());
}

void AS_LogToConsole(std::string& msg)
{
	SDK::Get()->LogToConsoleFn(msg.c_str());
}