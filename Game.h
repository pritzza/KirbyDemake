#pragma once

#include <SFML/Graphics.hpp>

#include "GameData.h"

class Game
{
public:
	sf::RenderWindow window;
	GameData gameData;

public:
	Game();
	//~Game();

	void gameLoop();

};