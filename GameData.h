#pragma once

#include "GameStateManager.h"
#include "AssetManager.h"
//include whatever else

class GameData
{
public:
	GameStateManager stateMachine;
	AssetManager assets;
	// othe guy had an input manager here

public:
	GameData();
	//~GameData();
};