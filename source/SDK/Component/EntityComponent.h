#pragma once

#include <iostream>
#include "../Boost/Boost.h"

class EntityComponent : BoostTrackableSignal
{
public:
	void* vftable;
	std::string* m_name;
	void* m_parent;
	char m_sharedDB[0x90];
};