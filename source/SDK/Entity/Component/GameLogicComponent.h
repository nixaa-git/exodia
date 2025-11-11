#pragma once

#include "EntityComponent.h"

#pragma pack(push, 1)

// todo: maybe make this inherit a base component class.
// todo: integrate 1:1 vfuncs.
class GameLogicComponent : EntityComponent
{
public:
	virtual ~GameLogicComponent();

};

#pragma pack(pop)