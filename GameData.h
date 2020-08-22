#pragma once

#include "GameStateManager.h"
//#include "ResourceManager.h"
//include whatever else

class GameData
{
public:
	GameStateManager stateMachine;
	//resource manager
	// othe guy had an input manager here

public:
	GameData(sf::RenderWindow* window);
	//~GameData();
};