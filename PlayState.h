#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:

	//Player
	//World

	void draw();
	void update();
	void handleInput();

	void quitGame();

	PlayState(Game* game);
	//~PlayState();
};