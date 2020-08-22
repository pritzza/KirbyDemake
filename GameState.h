#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class GameStateManager;

class GameState
{
public:
	GameStateManager* stateMachine;
	sf::RenderWindow* window;

public:
	GameState(GameStateManager* stateMachine, sf::RenderWindow* window) {
		if (window == nullptr)
			std::cout << "window nullptr GAMESTATE\n"; this->stateMachine = stateMachine; this->window = window; }

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};