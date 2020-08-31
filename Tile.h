#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Tile
{
public:
	sf::RectangleShape shape;
	sf::Color color{ sf::Color::Black }; // for collision debugging

	const float length{ 50.0f };
	bool isSolid{ false };

public:
	Tile(float x, float y);
	~Tile();

	virtual void init(float x, float y);

	void update();
	void render(sf::RenderTarget& target);

	//virtual void bottomCollide();
	//virual void hit();

	
};