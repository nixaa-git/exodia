#include "LuaFunctions.h"
#include "../../SDK/SDK.h"

int lua_LogToConsole(lua_State* state)
{
	if (lua_isstring(state, 1))
	{
		SDK::Get()->LogToConsoleFn(lua_tostring(state, 1));
	}
	else
	{
		return luaL_error(state, "First argument is nil.");
	}

	return 1;
}

int lua_SendPacket(lua_State* state)
{
	if (!lua_isnumber(state, 1))
	{
		return 0;
	}

	if (!lua_isstring(state, 2))
	{
		return 0;
	}

	int type = lua_tonumber(state, 1);
	std::string packetText = lua_tostring(state, 2);

	SDK::Get()->SendPacket(type, packetText);

	return 1;
}