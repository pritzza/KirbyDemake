#pragma once

#include "GameState.h"

class MenuState : public GameState
{
public:
	//World w
	//Player p
	sf::CircleShape shape;

public:
	MenuState(GameStateManager* stateMachine, sf::RenderWindow* window);

	void handleInput();
	void update();
	void draw();
};