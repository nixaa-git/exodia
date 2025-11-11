#pragma once

#include <iostream>
#include "../dependencies/minhook/include/MinHook.h"

struct hook_t
{
public:
	void Setup(void* fnAddr, void* dst, const std::string& hkName);
	void Enable();
	void Disable();

	void* m_origFn{};
	void* m_hookedFn{};
	std::string m_hkName = "undefined hook name";
	bool m_bHookIsEnabled = false;
};