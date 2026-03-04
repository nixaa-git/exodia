#include <iostream>
#include <thread>
#include "../Gui.h"
#include "../../SDK/SDK.h"

// func decls
#include "../angelscript functions/AngelScriptFunctions.h"

void MessageCallback(const asSMessageInfo* msg, void* param)
{
	const char* type = "ERR";
	if (msg->type == asMSGTYPE_WARNING) type = "WARN";
	else if (msg->type == asMSGTYPE_INFORMATION) type = "INFO";

	printf("%s (%d, %d) : %s : %s\n",
		msg->section,
		msg->row,
		msg->col,
		type,
		msg->message);
}

void InitAngelScript()
{
	static bool bDidInitAngelScript = false;

	if (bDidInitAngelScript)
	{
		return;
	}

	Gui::Get()->asEngine = asCreateScriptEngine();
	

	auto asEngine = Gui::Get()->asEngine;
	assert(asEngine);

	int r;
	RegisterStdString(asEngine);

	asEngine->SetMessageCallback(
		asFUNCTION(MessageCallback),
		0,
		asCALL_CDECL
	);

	r = asEngine->RegisterGlobalFunction(
		"void print(const string &in)",
		asFUNCTION(AS_Print),
		asCALL_CDECL
	);

	assert(r >= 0);

	r = asEngine->RegisterGlobalFunction(
		"void LogToConsole(const string &in)",
		asFUNCTION(AS_LogToConsole),
		asCALL_CDECL
	);

	assert(r >= 0);

	r = asEngine->RegisterGlobalFunction(
		"void SendPacket(int type, const string &in)",
		asFUNCTION(AS_SendPacket),
		asCALL_CDECL
	);

	assert(r >= 0);

	r = asEngine->RegisterFuncdef("void SendPacketCallback(int, const string &in)");

	assert(r >= 0);

	r = asEngine->RegisterGlobalFunction(
		"void AddCallback(const string &in, SendPacketCallback @)",
		asFUNCTION(AS_AddCallback),
		asCALL_CDECL
	);

	assert(r >= 0);

	auto langDef = TextEditor::LanguageDefinition::AngelScript();

	TextEditor::Identifier tid{};
	langDef.mIdentifiers.insert_or_assign({ "print" }, tid);
	langDef.mIdentifiers.insert_or_assign({ "LogToConsole" }, tid);
	langDef.mIdentifiers.insert_or_assign({ "SendPacket" }, tid);
	langDef.mIdentifiers.insert_or_assign({ "AddCallback" }, tid);

	g_pGlobals->m_textEditor.SetLanguageDefinition(langDef);
	g_pGlobals->m_textEditor.SetText("void main()\n{\n\tLogToConsole(\"exodia\");\n}");

	bDidInitAngelScript = true;
}

void RunScript(const std::string& code)
{
	auto asEngine = Gui::Get()->asEngine;

	if (!asEngine)
	{
		printf("Engine not initialized!\n");
		return;
	}

	asIScriptModule* mod = asEngine->GetModule("console", asGM_ALWAYS_CREATE);
	mod->AddScriptSection("script", code.c_str());
	int r = mod->Build();

	if (r < 0)
	{
		printf("Build failed!\n");
		return;
	}

	asIScriptFunction* func = mod->GetFunctionByDecl("void main()");
	if (!func)
	{
		printf("No main() function found!\n");
		return;
	}

	asIScriptContext* ctx = asEngine->CreateContext();
	ctx->Prepare(func);

	r = ctx->Execute();

	if (r == asEXECUTION_EXCEPTION)
	{
		printf("Script exception: %s\n", ctx->GetExceptionString());
	}
	else if (r != asEXECUTION_FINISHED)
	{
		printf("Script did not finish properly (code %d)\n", r);
	}

	ctx->Release();
}

void Gui::DrawAngelScriptTab()
{
	InitAngelScript();

	ImGui::BeginChild("##executorbuttonsxd", { ImGui::GetContentRegionAvail().x, 35 }, true);
	{
		if (ImGui::Button("execute angelscript"))
		{
			// todo ~~ keep track of our running threads.

			RunScript(g_pGlobals->m_textEditor.GetText());
		}

		/*

		ImGui::SameLine();

		if (ImGui::Button("create dummy world"))
		{
			auto sdk = SDK::Get();

			void* pWorld = sdk->WorldConstructorFn(operator new(0x150C0));

			if (!pWorld)
			{
				std::printf("pWorld was nullptr\n");
				return;
			}
			else
			{
				std::printf("pWorld at %llX\n", pWorld);
			}

			sdk->GameLogicComponent_CreateDummyWorldForTestingFn(pWorld);
		}
		*/
	}
	ImGui::EndChild();

	g_pGlobals->m_textEditor.Render("executor", ImGui::GetContentRegionAvail(), true);
}