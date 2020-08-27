#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Tile
{

public:
	sf::RectangleShape shape;

public:
	Tile(float x, float y, float gridSizef);
	virtual ~Tile();

	void update();
	void render(sf::RenderTarget& target);
	
};