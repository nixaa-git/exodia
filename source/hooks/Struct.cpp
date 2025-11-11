#include "Struct.h"

void hook_t::Setup(void* fnAddr, void* dst, const std::string& hkName)
{
	if (!fnAddr || !dst)
	{
		std::printf("Failed to setup hook %s as fnAddr or dst pointer was null!\n", hkName.c_str());
		return;
	}

	this->m_origFn = fnAddr;
	this->m_hookedFn = dst;
	this->m_hkName = hkName;

	std::printf("Hooked %s!\n", hkName.c_str());

	MH_CreateHook(reinterpret_cast<void*>(fnAddr), reinterpret_cast<void*>(dst), (void**)&m_origFn);
}