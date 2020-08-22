#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:
	//World w
	//Player p

public:
	PlayState(GameStateManager* stateMachine, sf::RenderWindow* window) : GameState{ stateMachine, window } {}

	void handleInput();
	void update();
	void draw();
};