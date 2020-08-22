#pragma once

#include <SFML/Graphics.hpp>

class GameStateManager;

class GameState
{
public:
	GameStateManager* stateMachine;
	sf::RenderWindow* window;

public:
	GameState(GameStateManager* stateMachine, sf::RenderWindow* window)
	{
		this->stateMachine = stateMachine; this->window = window;
	}

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};