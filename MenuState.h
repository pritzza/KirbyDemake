#pragma once

#include "GameState.h"

class MenuState : public GameState
{
public:
	//World w
	//Player p

public:
	MenuState(GameStateManager* stateMachine, sf::RenderWindow* window) : GameState{ stateMachine, window } {}

	void handleInput();
	void update();
	void draw();
};