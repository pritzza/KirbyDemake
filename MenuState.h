#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class MenuState : public GameState
{
public:

	//Menuer
	//World
	sf::CircleShape shape;

	void draw();
	void update();
	void handleInput();

	void startGame();

	MenuState(Game* game);
	//~MenuState();
};