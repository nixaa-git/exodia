#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

// angel script
#include "../../dependencies/angelscript/add_on/scriptstdstring/scriptstdstring.h"
#include "../../dependencies/angelscript/add_on/scripthelper/scripthelper.h"
#include "../../dependencies/angelscript/add_on/scriptarray/scriptarray.h"

extern std::map<std::string, std::vector<asIScriptFunction*>> g_callbacks;

void AS_Print(std::string& msg);
void AS_LogToConsole(std::string& msg);
void AS_SendPacket(int type, std::string& msg);
void AS_AddCallback(std::string& name, asIScriptFunction* pFunc);