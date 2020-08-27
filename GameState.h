#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GameData;

class GameState
{
public:
	GameData* data;
	sf::RenderWindow* window;

public:
	GameState(GameData* data, sf::RenderWindow* window)
		: data{ data }, window{ window } { }

	//~GameState() { assets->textures.clear(); assets->fonts.clear(); }

	virtual void init() = 0;

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};