#pragma once

#include "GameState.h"
#include "World.h"
#include "Player.h"

#include <vector>

class PlayState : public GameState
{
public:
	std::vector<Entity*> entities;

	World w;
	Player p { entities };

public:
	PlayState(GameData* data, sf::RenderWindow* window);
	~PlayState();

	void init();

	void handleInput();
	void update();
	void draw();
};