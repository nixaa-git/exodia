#include "../Gui.h"
#include "../../SDK/SDK.h"
#include <thread>
#include "../lua functions/LuaFunctions.h"

void InitLuaStuff(lua_State* state)
{
	static bool bDidInit = false;

	if (bDidInit)
	{
		return;
	}

	if (!state)
	{
		return;
	}
	
	luaL_openlibs(state);

	lua_register(state, "log", lua_LogToConsole);
	lua_register(state, "SendPacket", lua_SendPacket);

	auto langDef = TextEditor::LanguageDefinition::Lua();

	TextEditor::Identifier tid;
	langDef.mIdentifiers.insert({ "log", tid });
	langDef.mIdentifiers.insert({ "SendPacket", tid });

	g_pGlobals->m_textEditor.SetLanguageDefinition(langDef);

	bDidInit = true;
}

void LuaExecute(lua_State* state, const std::string& script)
{
	luaL_dostring(state, script.c_str());
}

void Gui::DrawLuaTab()
{
	// todo ~~~ Add ImGui text editor
	// render it
	// set language style to lua
	// define our custom functions

	lua_State* pLuaState = SDK::Get()->m_pLuaState;
	InitLuaStuff(pLuaState);

	ImGui::BeginChild("##executorbuttons", { ImGui::GetContentRegionAvail().x, 35 }, true);
	{
		if (ImGui::Button("execute"))
		{
			// todo ~~ keep track of our running threads.
			std::thread t(LuaExecute, pLuaState, g_pGlobals->m_textEditor.GetText());
			t.detach();
		}
	}
	ImGui::EndChild();

	g_pGlobals->m_textEditor.Render("executor", ImGui::GetContentRegionAvail(), true);
}