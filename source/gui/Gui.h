#pragma once

#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/backends/imgui_impl_win32.h"

// macro for if the gt version we target uses opengl vs dx9
//#ifdef _EXODIA_RENDERING_OPENGL

#include "../dependencies/imgui/backends/imgui_impl_opengl2.h"
#include <GL/gl.h>

//#elif _EXODIA_RENDERING_DX9
//
//#include "../dependencies/imgui/backends/imgui_impl_dx9.h"
//
//#endif // !_EXODIA_RENDERING_OPENGL

enum class GuiTab
{
	EXECUTOR = 1,
};

class Gui
{
public:
	Gui() = default;

	static Gui* Get()
	{
		static Gui gui;
		return &gui;
	}

	void Initialize();
	void SetupStyle();
	void DrawMenu();

	/*
	~~~ tabs ~~~
	*/
	void DrawLuaTab(); // first arg will be SDK lua state ptr?
	//

//#ifdef _EXODIA_RENDERING_OPENGL
	void RenderForOpenGL(HDC hdc);
//#elif _EXODIA_RENDERING_DX9
//	void RenderForDX9();
//#endif

	bool m_bDidInit = false;
	bool m_bShowMenu = true;
	bool m_currentTab = 1;
private:
};