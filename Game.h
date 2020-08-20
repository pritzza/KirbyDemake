#pragma once

#include <iostream>

#include <vector>
#include <SFML/Graphics.hpp>

class GameState;

class Game
{
public:
	std::vector<GameState*> states;

	sf::RenderWindow window;

public:
	void gameLoop();

	void popState();
	GameState* currentState();
	void pushState(GameState* state);

	Game(GameState* state);
	~Game();
};